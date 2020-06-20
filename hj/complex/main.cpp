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

using namespace std;

int main(int argc, char*argv[])
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
    return 0;
}