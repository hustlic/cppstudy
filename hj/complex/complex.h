/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

//template<typename Complex_Type>

class Complex
{
    public:
        //default argument
        Complex(double r=0, double i = 0)
            :re(r), im(i) // initialization list
        {}

        //const
        double getIm() const {return im;}

        double getRe() const {return re;}

        //pass by reference
        Complex& operator +=(const Complex&);

        //pass by value
        Complex operator +(const Complex&);
        Complex& operator+();
        Complex operator-();

        void dump() const;

    private:
        double im, re;

};

Complex operator+(const Complex& a, const Complex b);

#endif