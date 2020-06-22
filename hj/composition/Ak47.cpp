/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#include <iostream>

#include "Ak47.h"

#define AK47_MAX_BULLET (30)

Ak47::Ak47():Guns("Ak47", AK47_MAX_BULLET, AK47_MAX_BULLET)
{
    std::cout<<"new Ak47 created" <<std::endl;
}

void Ak47::fire()
{    
    this->setCurBullet(this->getCurBullet() -  1);
    std::cout<<this->getName()<<"fired, "<<this->getCurBullet()<<" bullets left"<<std::endl;

    if(this-getCurBullet() == 0)
        this->reload();
    
}

Ak47::~Ak47()
{
    std::cout<<"ak dtcor" <<std::endl;
}

