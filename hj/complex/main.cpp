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

    MyString *s4 = new MyString("test s4");
    std::cout << "s4="<<s4 <<", s4->data="<<s4->getChar()<< std::endl;


    delete s4;
}

int main(int argc, char*argv[])
{
    testComplex();

    testString();

    return 0;
}