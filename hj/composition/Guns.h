/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#ifndef __GUNS_H_
#define __GUNS_H_

class Guns
{
    public:
        //default ctor
        Guns(const char* name, const int curBullet, const int maxBullet);

        //copy ctor
        Guns(const Guns&);

        //copy asign
        Guns& operator=(const Guns&);

        //dctor
        ~Guns();

        void reload(){this->m_curBullet = this->m_maxBullet;}
        virtual int  getCurBullet()const{return m_curBullet;}
        int  getMaxBullet()const{return m_maxBullet;}
        char* getName()const{return m_name;}
        void setCurBullet(int curBullet){this->m_curBullet = curBullet;}

        //virtual functions
        virtual void fire() = 0;
        

    private:
        int m_curBullet;
        int m_maxBullet;
        char *m_name;
    
};

#endif