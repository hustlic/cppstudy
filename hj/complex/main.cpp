/* *************************************************
 * | |  | | |  | |/ ____|__   __| | | (_)       
 * | |__| | |  | | (___    | |    | |  _    ___ 
 * |  __  | |  | |\___ \   | |    | | | |  / __|
 * | |  | | |__| |____) |  | |    | | | | | (__ 
 * |_|  |_|\____/|_____/   |_|    |_| |_|  \___|
 * 
 * *************************************************/

#include <iostream>
#include <bitset>
#include <thread>

#include "complex.h"
#include "MyString.h"
#include "Ak47.h"
#include "Player.h"
#include "Fraction.h"
#include "common.h"
#include "LicThread.h"
#include "Message.h"
#include "MessageHandler.h"
#include "LicMessageLoop.h"

//using namespace std;

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
    std::cout<<"p1 "<<p1.getMainGun()->getCurBullet()<<"bullet left"<<std::endl;

    //Player p2(100, "cser2");
    //p2.fire();
}

void testFraction()
{
    //1. change f1 to double(1.4)
    //2. 1.4+5.4=6.8
    //3. convert 6.8 to 6 , and call ctor Fraction(6, 1), so f2=6/1
    const Fraction<int> f1{7, 5};
    //Fraction f2 = f1 + 5.4;
    Fraction<int> f2 = Fraction<int>(f1 + 5.4);
    std::cout <<"f2="<<f2.getNumerator()<<"/"<<f2.getDenominator()<<std::endl;

    //1. change f1 to double(1.4)
    //2. 3.0+1.4=4.4
    double i = 3.0 + f1;
    std::cout<<"i="<<i<<std::endl;

    Fraction<int> &&a=f1.getTemp();
    std::cout<<a.getNumerator()<<"/"<<a.getDenominator()<<std::endl;

    Fraction<double> f3 = Fraction<double>();
    Fraction<int> &&b=f2.getTemp();
    std::cout<<b.getNumerator()<<"/"<<b.getDenominator()<<std::endl;

    

}

void testFunctionTemplate()
{
    Fraction<int> f1(3, 4), f2(1,2);
    Fraction<int> f3 = min(f1, f2);
    f3.dump();

    Complex c1(10, 20), c2(5, 5);
    Complex c3 = min(c1, c2);

    c3.dump();
}


void print(){std::cout<<"nothing to print"<<std::endl;}

template<typename T,  typename... Types>
void print(const T& a, const Types&... Args)
{
    std::cout<<a<<std::endl;
    print(Args...);
}

void testVariadicTemplate()
{
    print(10, 20, std::bitset<4>(254), "hello");
}

void testAuto()
{
    for(auto& i:{1,2,3,4})
        std::cout<<i<<std::endl;
}


/*---------------------------
* thread test
*/
class MyThread:public LicThread
{
    public:
        MyThread():i(0){}
        ~MyThread(){}
        virtual bool threadLoop()
        {
            for(auto i = 0; i < 10; i++)
            {
                std::cout<<"hello thread_"<<i<<std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            return true;
        }
    private:
        int i;
};

enum
{
    TESTMSG_REQ_00=0,
    TESTMSG_REQ_01,
};

class MyMessageHandler:public MessageHandler
{
    public:
        MyMessageHandler():mMessageLoop(this){}

        virtual void onReceiveMessage(Message& msg)
        {
            switch(msg.what())
            {
                case TESTMSG_REQ_00:
                    std::cout<<"Get TESTMSG_REQ_00"<<std::endl;
                    break;
                case TESTMSG_REQ_01:
                    std::cout<<"Get TESTMSG_REQ_01"<<std::endl;
                    break;
                default:
                    break;
            }
        }
        status_t start()
        {
            mMessageLoop.start();
        }

        status_t stop()
        {
            //mMessageLoop.requestExitAndWait(0);
            mMessageLoop.stop();
            std::cout<<"try to join message loop"<<std::endl;
            mMessageLoop.join();
        }

        void testReq00(int delayMs)
        {
            mMessageLoop.postMessage(Message(TESTMSG_REQ_00), delayMs);
        }

        void testReq01(int delayMs)
        {
            mMessageLoop.postMessage(Message(TESTMSG_REQ_01), delayMs);
            //mMessageLoop.cancelMessage(TESTMSG_REQ_01);
        }

        
    private:
        LicMessageLoop   mMessageLoop;
};



void thread_task()
{
    std::cout<<"hello thread"<<std::endl;

    for(int i = 0 ; i < 10; i++)
    {
        std::cout <<"thread runing " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}

int testThread_01()
{
    unsigned int n = std::thread::hardware_concurrency();
    std::cout<< n << " concurrent threads are supported" << std::endl;

    std::thread *thd = new std::thread(thread_task);
    //thd->join();
    //t.detach();

    std::cout<<"main thread finish"<<std::endl;

    return EXIT_SUCCESS;
}

int testThread_02()
{
    MyThread* myThread = new MyThread();

    myThread->start();

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        myThread->requestExitAndWait(2*1000);
        if(myThread->isRunning())
            std::cout<<"myThread is still running, can't wait any more"<<std::endl;
        break;
    }
}


int testMsgThread()
{
    MyMessageHandler* myMessageHandler = new MyMessageHandler();
    myMessageHandler->start();
    
    do
    {
        //MyMessageHandler->testReq00(1500);
        //MyMessageHandler->testReq01(2000);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        myMessageHandler->testReq00(0);
        myMessageHandler->testReq01(0);
    }while(1);
}

int testThread()
{
    testThread_01();
    //testThread_02();
    testMsgThread();

    return 0;
}


int main(int argc, char*argv[])
{
    std::cout<<__cplusplus<<std::endl;

    //testComplex();

    //testString();

    //testCs();

    //testFraction();

    //testFunctionTemplate();

    //testVariadicTemplate();

    //testAuto();

    //testThread();
    std::thread *thd = new std::thread(thread_task);

    MyMessageHandler* myMessageHandler = new MyMessageHandler();
    myMessageHandler->start();
    
    int choice = 0;
    while(choice != 9)
    {
        std::cin>>choice;
        std::cout<<"choice is "<<choice<<std::endl;

        switch(choice)
        {
            case 0:
                myMessageHandler->testReq00(0);
                break;
            case 1:
                myMessageHandler->testReq01(0);
                break;
            case 9:
                break;
        }
    }
    std::cout<<"try to join thd"<<std::endl;
    thd->join();

    std::cout<<"try to stop message loop"<<std::endl;
    myMessageHandler->stop();

    std::cout<<"all thread quit"<<std::endl;

    return 0;
}

