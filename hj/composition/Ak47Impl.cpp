/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/
#include <iostream>
#include "Ak47Impl.h"

Ak47Impl::Ak47Impl():Guns("Ak47", 50, 50)
{
    std::cout<<"ak47 impl created"<<std::endl;
}

Ak47Impl::~Ak47Impl()
{
    std::cout<<"ak47 impl dtor"<<std::endl;
}

void Ak47Impl::fire()
{
    
    this->setCurBullet(this->getCurBullet() -  1);
    std::cout<<this->getName()<<" fired, "<<this->getCurBullet()<<" bullets left"<<std::endl;

    if(this-getCurBullet() == 0)
        this->reload();
    
}


