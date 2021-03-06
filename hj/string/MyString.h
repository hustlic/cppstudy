/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#ifndef __MYSTRING_H_
#define __MYSTRING_H_

#include <iostream>

class MyString
{
    public:
        MyString();

        MyString(const char* str);

        //copy constructor
        MyString(const MyString &);

        //copy assign
        MyString& operator=(const MyString &);

        ~MyString();

        char *getChar()const {return this->m_data;}

    private:
        char* m_data;
};

inline std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    return os<<str.getChar();
}

#endif