#ifndef __LICLOOPERTHREAD_H__
#define __LICLOOPERTHREAD_H__

#include <list>
#include <mutex>
#include <condition_variable>


#include "Message.h"
#include "MessageHandler.h"
#include "LicThread.h"

class LicMessageLoop:public LicThread
{
public:
    LicMessageLoop(MessageHandler *msgHandler);
    virtual ~LicMessageLoop();

    virtual bool threadLoop();
    bool start();
    bool stop();
    bool join();

    int postMessage(const Message &msg, int delayMs = 0);
    int cancelMessage(int what);
    int64_t getNowMilliSec();
private:

    //DISABLE_COPY(LooperThread)
private:
    struct Event {
        int64_t whenMs;
        Message message;
    };
    MessageHandler*             mMsgHandler;
    std::mutex                  mMutex;
    std::mutex                  mEventListLock;
    std::condition_variable     mEventListConditon;
    std::list<Event>            mEventList;
};

#endif // LOOPERTHREAD_H

