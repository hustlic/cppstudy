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

class Fraction
{
    public:
        //explicit Fraction(const int a, const int b = 1)
        //:m_numerator(a),m_denominator(b){}
        explicit Fraction(const int a, const int b = 1)
        :m_numerator(a),m_denominator(b){}

        operator double()const{return (double)m_numerator/m_denominator;}
        
        //Fraction& operator+(const double& a) const;

        Fraction& operator+(const Fraction& a)const;

        inline int getNumerator()   const {return m_numerator;}
        inline int getDenominator() const {return m_denominator;}


    private:
        int m_numerator;
        int m_denominator;
    
};

#endif