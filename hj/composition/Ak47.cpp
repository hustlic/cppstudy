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

Ak47::Ak47():Guns("Ak47", 30, 30)
{
    std::cout<<"new Ak47 created" <<std::endl;
    this->m_ak47Impl = new Ak47Impl();
}


Ak47::~Ak47()
{
    //this->m_ak47Impl->~Ak47Impl();
    delete m_ak47Impl;
    std::cout<<"ak dtcor" <<std::endl;
}

