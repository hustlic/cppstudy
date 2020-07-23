#include <iostream>

#include "LicMessageLoop.h"
#include "LicAutoLock.h"
#include "MessageHandler.h"
#include "LicThread.h"

LicMessageLoop::LicMessageLoop(MessageHandler *msgHandler)
{
    mMsgHandler = msgHandler;
}

LicMessageLoop::~LicMessageLoop()
{
}

bool LicMessageLoop::threadLoop()
{
    std::unique_lock<std::mutex> lck(mMutex);
    Event event;
    {
        mEventListLock.lock();

        if(exitPending()) {
            mEventList.clear();
            mEventListLock.unlock();
            return false;
        }
        if(mEventList.empty()) {
            mEventListLock.unlock();
            mEventListConditon.wait(lck);
            return true;
        }

        int64_t whenMs = (*(mEventList.begin())).whenMs;
        int64_t nowMs = getNowMilliSec();
        
        if (whenMs > nowMs) {
            int64_t delayMs = whenMs - nowMs;
            mEventListConditon.wait_for(lck, std::chrono::milliseconds(delayMs));
            mEventListLock.unlock();
            return true;
        }

        event = *(mEventList.begin());
        mEventList.erase(mEventList.begin());
        mEventListLock.unlock();
    }

    if(mMsgHandler != NULL) {
        mMsgHandler->onReceiveMessage(event.message);
    }
    return true;

}

int LicMessageLoop::postMessage(const Message &msg, int delayMs)
{
    if(exitPending()) {
        return ERROR_INVALID_OPERATION;
    }
    Autolock _l(mEventListLock);

    int64_t whenMs;
    if (delayMs > 0) {
        whenMs = getNowMilliSec() + delayMs;
    } else {
        whenMs = getNowMilliSec();
    }

    std::list<Event>::iterator it = mEventList.begin();
    for(;it != mEventList.end(); ++it) {
        if((*it).whenMs > whenMs) {
            break;
        }
    }

    Event event;
    event.message = msg;
    event.whenMs = whenMs;

    if(it == mEventList.begin()) {
        mEventListConditon.notify_all();
    }
    mEventList.insert(it, event);

    return ERROR_UNKNOWN;
}

int LicMessageLoop::cancelMessage(int what)
{
    return ERROR_UNKNOWN;
}

bool LicMessageLoop::isCurrentThread()
{
    return false;
}

int64_t LicMessageLoop::getNowMilliSec()
{
    auto timeNow   = std::chrono::system_clock::now();
    int64_t nowMs  = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow.time_since_epoch()).count();

    return nowMs;

}
