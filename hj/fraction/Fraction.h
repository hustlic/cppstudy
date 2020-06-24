/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/
#ifndef __FRACTION_H__
#define __FRACTION_H__

#include <iostream>
template<typename Fraction_Type>
class Fraction
{
    public:
        //explicit Fraction(const int a, const int b = 1)
        //:m_numerator(a),m_denominator(b){}
        explicit Fraction(const Fraction_Type a, const Fraction_Type b = 1)
        :m_numerator(a),m_denominator(b){std::cout<<"Fraction ctor"<<std::endl;}

        operator double()const{return (double)m_numerator/m_denominator;}
        
        //Fraction& operator+(const double& a) const;

        Fraction& operator+(const Fraction& a)const
        {
            std::cout<<"call Fraction+Fraction operator+"<<std::endl;

            Fraction<Fraction_Type> *b = new Fraction(this->m_numerator + a.m_numerator
                        , this->m_denominator+a.m_denominator);

            return *b;
        }

        Fraction& operator=(const Fraction& a)
        {
            std::cout<<"Fraction operator="<<std::endl;

            this->m_denominator = a.getDenominator();
            this->m_numerator   = a.getNumerator();

            return *this;
        }

        bool operator<(const Fraction& a)const
        {
            return this->m_numerator < a.m_numerator;
        }

        inline Fraction_Type getNumerator()   const {return m_numerator;}
        inline Fraction_Type getDenominator() const {return m_denominator;}

        Fraction getTemp(){return Fraction(1,1);}

        void dump()
        {
            std::cout<<"("<<m_numerator<<"/"<<m_denominator<<")"<<std::endl;
        }


    private:
        Fraction_Type m_numerator;
        Fraction_Type m_denominator;
    
};



#endif