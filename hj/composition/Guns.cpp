/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#include <cstring>
#include <iostream>
#include "Guns.h"
#define FAKE_GUN "FAKE_GUN"

Guns::Guns(const char* name, const int curBullet, const int maxBullet)
{
    std::cout<<"Guns created"<<std::endl;
    if(!name)
    {
        this->m_name = new char[strlen(FAKE_GUN) + 1];
        strcpy(this->m_name, FAKE_GUN);
        
    }
    else
    {
        this->m_name = new char[strlen(name) + 1];
        strcpy(this->m_name, name);
    }
    this->m_curBullet = curBullet;
    this->m_maxBullet = maxBullet;
}

Guns::Guns(const Guns& gun)
{
    this->m_name = new char[strlen(gun.m_name) + 1];
    strcpy(this->m_name, gun.m_name);
    this->m_curBullet = gun.m_curBullet;
    this->m_maxBullet = gun.m_maxBullet;        
}

Guns& Guns::operator=(const Guns& gun)
{
    if(this == &gun)
    {
        return *this;
    }

    this->m_maxBullet = gun.m_maxBullet;
    this->m_curBullet = gun.m_curBullet;
    this->m_name = new char[strlen(gun.m_name) + 1];
    strcpy(this->m_name, gun.m_name);
    return *this;
}

Guns::~Guns()
{
    std::cout<<"Guns dtcor"<<std::endl;
    delete[] m_name;
}

