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

#include "Player.h"
#define DEFAULT_PLAY_NAME "NewPlayer"

Player::Player(const int health, const char*name)
{
    std::cout<<"Player created" <<std::endl;
    this->m_health = health;
    this->m_mainGun = 0;
    if(name)
    {
        this->m_name = new char[strlen(name) +  1];
        strcpy(this->m_name, name);
    }
    else
    {
        this->m_name = new char[strlen(DEFAULT_PLAY_NAME) + 1];
        strcpy(this->m_name, DEFAULT_PLAY_NAME);
    }
    
}

Player::~Player()
{
    std::cout<<"Player dtor"<<std::endl;
    delete[] m_name;
}

void Player::fire()
{
    if(this->m_mainGun)
    {
        this->m_mainGun->fire();
    }
    else
    {
        std::cout<<"I have no weapon,using knife"<<std::endl;
    }
    
}
