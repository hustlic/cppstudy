/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/
#include <iostream>
#include "Fraction.h"

#if 0
Fraction& Fraction::operator+(const double& a)const
{
    std::cout<<"call Fraction+double operator+"<<std::endl;
    Fraction *b = new Fraction(this->m_numerator + (int)a, this->m_denominator);

    return *b;
}
#endif

