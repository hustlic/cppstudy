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
    std::cout<<"member override +"<<std::endl;
    Complex newItem;
    newItem.im += this->getIm()+c.getIm();
    newItem.re += this->getRe()+c.getRe();

    return newItem;
}

Complex Complex::operator-()
{
    return Complex (-this->getRe(), -this->getIm());
}

Complex& Complex::operator+()
{
    return *this;
}

void Complex::dump() const
{
    std::cout<<"real("<<this->getRe()<<"),im("<<this->getIm()<<")"<<std::endl;
}

Complex operator+(const Complex& a, const Complex b)
{
    std::cout<<"global override +"<<std::endl;
    Complex c(a.getRe()+b.getRe(), a.getIm()+b.getRe());

    return c;

}
