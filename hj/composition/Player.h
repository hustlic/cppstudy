/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Guns.h"

class Player
{
    public:
        //default ctor
        Player(const int health=100, const char*name=0);

        //dtor
        ~Player();

        void fire();

        void setMainGun(Guns *gun){this->m_mainGun = gun;}

    private:
        int   m_health;
        Guns* m_mainGun;
        char* m_name;
    private:
        //copy asign
        Player& operator=(const Player&){};
        //copy ctor
        Player(const Player&){};
};


#endif