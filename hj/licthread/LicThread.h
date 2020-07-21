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

enum{
    NO_ERROR = 0,
    ERROR_ALREADY_RUNNING,
};

typedef int32_t status_t;

class LicThread
{
public:
    LicThread();
    ~LicThread();

    void requestExit();

    status_t start();
    void threadFunc();


protected:
    // exitPending() returns true if requestExit() has been called.
    bool exitPending() const;
    
private:
    // Derived class must implement threadLoop(). The thread starts its life
    // here. There are two ways of using the Thread object:
    // 1) loop: if threadLoop() returns true, it will be called again if
    //          requestExit() wasn't called.
    // 2) once: if threadLoop() returns false, the thread will exit upon return.
    virtual bool threadLoop() = 0;


private:
    LicThread& operator=(const LicThread&);
    // note that all accesses of mExitPending and mRunning need to hold mLock
    volatile bool               mExitPending;
    volatile bool               mRunning;
    status_t                    mStatus;
    std::mutex                  mMutex;
    std::condition_variable     mCond;
    std::thread*                mThread;

};

#endif

