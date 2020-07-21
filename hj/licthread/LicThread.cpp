/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#include "LicThread.h"

LicThread::LicThread()
            :mExitPending(false)
            ,mStatus(NO_ERROR)
            ,mRunning(false)
{

}

LicThread::~LicThread()
{

}

//create new instance of std::thread
status_t LicThread::start()
{
    Autolock _l(mMutex);

    if(mRunning){
        return ERROR_ALREADY_RUNNING;
    }

    mThread = new std::thread(&LicThread::threadFunc, this);
    mThread->detach();

    return NO_ERROR;
}


void LicThread::threadFunc()
{
    do{
        status_t res = threadLoop();

        if(!res)
            break;
    }
    while(mExitPending != true);
}

void LicThread::requestExit()
{
    Autolock _l(mMutex);
    mExitPending = true;

}




