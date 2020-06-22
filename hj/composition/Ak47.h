/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/
#ifndef __AK47_H__
#define __AK47_H__

#include "Guns.h"
#include "Ak47Impl.h"

class Ak47:public Guns
{
    public:
        //default ctor
        Ak47();

        ~Ak47();

        virtual void fire(){m_ak47Impl->fire();}
        int getMaxBullet() const {return m_ak47Impl->getMaxBullet();}
        int setCurBullet(const int bullet) {m_ak47Impl->setCurBullet(bullet);}
        int getCurBullet() const {return m_ak47Impl->getCurBullet();}

    private:
        Ak47Impl *m_ak47Impl;
    
};

#endif