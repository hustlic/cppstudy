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
#include "MyString.h"

MyString::MyString()
{
    std::cout<<"ctor-->"<<this<<std::endl;
    this->m_data = new char[1];
    this->m_data = '\0';
}

MyString::MyString(const char* str)
{
    std::cout<<"ctor-->"<<this<<std::endl;
    if(str)
    {
        this->m_data = new char[strlen(str) + 1];
        strcpy(this->m_data, str);
    }
    else
    {
        this->m_data = new char[1];
        this->m_data = 0;
    }
    
}

MyString::~MyString()
{
    std::cout<<"dtor-->"<<this<<std::endl;
    delete[] this->m_data;
}

