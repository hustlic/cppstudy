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
#include "MyString.h"
#include "Ak47.h"
#include "Player.h"
#include "Fraction.h"

using namespace std;

void testComplex()
{
    Complex c1(1,2), c2(2,2);

    c1+=c2;

    c1.dump();

    //member override will be called
    Complex c3=c1+c2;

    c3.dump();

    Complex c4(5,6);
    c4.dump();

    c4+=c3+=c2+=c1;

    c4.dump();
    c4=-c4;
    c4.dump();

    c4=+c4;
    c4.dump();

    std::cout<<c4<<std::endl;

}

void testString()
{
    MyString s1("helloworld");
    std::cout << s1.getChar() << std::endl;
    std::cout << "s1="<<&s1 <<", s1->data="<<s1.getChar()<< std::endl;

    // will not call ctor, why?
    MyString s2();
    //std::cout << "s2="<<&s2 <<", s2->data="<<&(s2.getChar())<< std::endl;
    std::cout << "s2="<<&s2 << std::endl;

    // will call ctor
    MyString s3;
    std::cout << "s3="<<&s3 << std::endl;

    // will call ctor
    MyString s5 = MyString();
    std::cout << "s5="<<&s5 << std::endl;

    MyString *s4 = new MyString("test s4");
    std::cout << "s4="<<s4 <<", s4->data="<<s4->getChar()<< std::endl;

    delete s4;

    MyString s6 = s1;
    std::cout << "s6="<<&s6<<", s6->data="<<s6.getChar()<< std::endl;

    s6=s6;
    std::cout << "s6="<<&s6<<", s6->data="<<s6.getChar()<< std::endl;

    std::cout<<s6<<std::endl;
}

void testCs()
{
    Player p1(100, "cser1");
    Ak47 myAk47;
    myAk47.fire();
    p1.setMainGun(&myAk47);
    p1.fire();
    std::cout<<"p1 "<<p1.getMainGun()->getCurBullet()<<"bullet left"<<endl;

    //Player p2(100, "cser2");
    //p2.fire();
}

void testFraction()
{
    //1. change f1 to double(1.4)
    //2. 1.4+5.4=6.8
    //3. convert 6.8 to 6 , and call ctor Fraction(6, 1), so f2=6/1
    Fraction<int> f1{7, 5};
    //Fraction f2 = f1 + 5.4;
    Fraction<int> f2 = Fraction<int>(f1 + 5.4);
    std::cout <<"f2="<<f2.getNumerator()<<"/"<<f2.getDenominator()<<std::endl;

    //1. change f1 to double(1.4)
    //2. 3.0+1.4=4.4
    double i = 3.0 + f1;
    std::cout<<"i="<<i<<std::endl;

    Fraction<int> &&a=f1.getTemp();
    std::cout<<a.getNumerator()<<"/"<<a.getDenominator()<<std::endl;

}

int main(int argc, char*argv[])
{
    //testComplex();

    //testString();

    //testCs();

    testFraction();

    return 0;
}