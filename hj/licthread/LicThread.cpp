/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#include <iostream>

#include "LicThread.h"

LicThread::LicThread()
            :mExitPending(false)
            ,mStatus(NO_ERROR)
            ,mRunning(false)
{

}

LicThread::~LicThread()
{
    std::cout<<"dtor LicThread"<<std::endl;
    if(mThread != nullptr)
        delete mThread;
}

status_t LicThread::start()
{
    Autolock _l(mLock);

    if(mRunning){
        return ERROR_ALREADY_RUNNING;
    }

    mThread = new std::thread(&LicThread::threadFunc, this);
    //this->detach();

    return NO_ERROR;
}

status_t LicThread::stop()
{
    requestExit();
    
}

void LicThread::threadFunc()
{
    bool again = true;
    mRunning = true;

    do{
        again = threadLoop();

        //return false to exit the loop
        if(!again)
            break;
    }
    while(mExitPending != true);

    Autolock _l(mLock);

    if (again == false || mExitPending) {
        mExitPending = true;
        mRunning = false;
        mExitedCondition.notify_all();
    }
}

void LicThread::requestExit()
{
    Autolock _l(mLock);
    mExitPending = true;
}

status_t LicThread::requestExitAndWait()
{
    std::unique_lock<std::mutex> lck(mMutex);

    if(mThread->get_id() == std::this_thread::get_id())
    {
        return ERROR_WOULD_BLOCK;
    }

    this->requestExit();

    while (mRunning == true) {
        std::cout<<"mRunning true, wait"<<std::endl;
        mExitedCondition.wait(lck);
    }
    std::cout<<"mRunning false, quit"<<std::endl;

    return mStatus;
}

status_t LicThread::requestExitAndWait(uint32_t timeoutMs)
{
    std::unique_lock<std::mutex> lck(mMutex);

    if(mThread->get_id() == std::this_thread::get_id())
    {
        return ERROR_WOULD_BLOCK;
    }

    this->requestExit();

    while (mRunning == true) {
        mExitedCondition.wait_for(lck, std::chrono::milliseconds(timeoutMs));
        break;
    }

    return mStatus;
}


void LicThread::join()
{
    mThread->join();
}

bool LicThread::joinable()
{
    return mThread->joinable();
}

void LicThread::detach()
{
    mThread->detach();
}

bool LicThread::isRunning()
{
    Autolock _l(mLock);
    return mRunning;
}

bool LicThread::exitPending() 
{
    Autolock _l(mLock);
    return mExitPending;
}

bool LicThread::isCurrentThread()
{
    return mThread->get_id() == std::this_thread::get_id();
}

