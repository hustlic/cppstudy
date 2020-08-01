/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#ifndef __LICThread_H__
#define __LICThread_H__

#include <thread>
#include <mutex>
#include <condition_variable>

#include "LicAutoLock.h"

#ifndef __uint32_t_defined  
typedef unsigned int            uint32_t;  
# define __uint32_t_defined  
#endif


enum{
    NO_ERROR = 0,
    ERROR_ALREADY_RUNNING,
    ERROR_WOULD_BLOCK,
    ERROR_INVALID_OPERATION,
    ERROR_UNKNOWN,
};

typedef int32_t status_t;

class LicThread
{
public:
    explicit LicThread();
    ~LicThread();

    void requestExit();

    status_t requestExitAndWait();
    status_t requestExitAndWait(uint32_t timeoutMs);

    status_t start();

    status_t stop();

    void join();

    bool joinable();

    void detach();

    bool isRunning();

    bool isCurrentThread();


protected:
    // exitPending() returns true if requestExit() has been called.
    bool exitPending();
    
private:
    // Derived class must implement threadLoop(). The thread starts its life
    // here. There are two ways of using the Thread object:
    // 1) loop: if threadLoop() returns true, it will be called again if
    //          requestExit() wasn't called.
    // 2) once: if threadLoop() returns false, the thread will exit upon return.
    virtual bool threadLoop() = 0;

    void threadFunc();


private:
    LicThread(const LicThread& thread) = delete;
    LicThread(const LicThread&&) = delete;
    LicThread& operator=(const LicThread&) = delete;


    // note that all accesses of mExitPending and mRunning need to hold mLock
    volatile bool               mExitPending;
    volatile bool               mRunning;
    status_t                    mStatus;
    std::mutex                  mLock;
    std::mutex                  mMutex;
    std::condition_variable     mExitedCondition;
    std::thread*                mThread;

};

#endif

