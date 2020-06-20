/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#include <iostream>
#include "complex.h"

Complex & Complex::operator+=(const Complex& c)
{
    this->im += c.getIm();
    this->re += c.getRe();

    return *this;
}

Complex Complex::operator+(const Complex& c)
{
    Complex newItem;
    newItem.im += this->getIm()+c.getIm();
    newItem.re += this->getRe()+c.getRe();

    return newItem;
}

void Complex::dump() const
{
    std::cout<<"real("<<this->getRe()<<"),im("<<this->getIm()<<")"<<std::endl;
}