/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#ifndef __LICAUTOLOCK_H__
#define __LICAUTOLOCK_H__


#include <mutex>

class     Autolock {
public:
    inline     Autolock(std::mutex& mutex) : mLock(mutex)  { mLock.lock(); }
    inline     Autolock(std::mutex* mutex) : mLock(*mutex) { mLock.lock(); }
    inline ~    Autolock() { mLock.unlock(); }
private:
    std::mutex& mLock;

};

#endif
