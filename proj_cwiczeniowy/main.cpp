#include <cstdint>
#include <iostream>
#include <math.h>
#include <bitset>
#include <Windows.h>
#include <string>
#include <typeinfo>
//#define float 1
#define xxx 5

extern int zmienna_extern;

void wypiszZmiennaGlobalZInnegoPliku();

int global = 5;
void staticVariableIncrement()
{
    static int s_x = 0;
    ++s_x;
    std::cout << s_x << std::endl;
}

void doSomething(unsigned int x)
{
    std::cout << x << std::endl; // Run some code x times
}

int add(int x, int y)
{
    return x + y;
}

namespace Foo{
    int x = 2;
    namespace Goo
    {
        const int g_x = 5;
    }
}
/*
namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
{

}*/

int main()
{
    doSomething(-1);
    unsigned a = -1;
    int_fast16_t fix{65536/2-1};
    std::cout<< sizeof(fix +1) << '\t' << sizeof(fix) << std::endl;
    long double ld(5l);
    std::cout<< std::bitset<16>(ld) << std::endl;
    std::cout << sizeof(bool) << std::endl;

    std::cout << std::boolalpha; // print bools as true or false
    std::cout << true << std::endl;
    std::cout << 1 << std::endl;

    std::cout << std::noboolalpha; // print bools as true or false
    std::cout << true << std::endl;
    std::cout << 1 << std::endl;

    SetConsoleOutputCP(CP_UTF8);
    //char ch = 'ś';
    //std::cout << ch << std::endl;
    //std::string s_utf8{u8"coś ń żź"};
    //std::cout << s_utf8 << std::endl;
    long llong = 100'000;
    std::cout << llong << std::endl;

    int xx = 7;
    (++xx)++;
    std::cout<<xx<<std::endl;
    xx = 1;
    xx = ++xx + 2;
    std::cout<<xx<<std::endl;
    xx = 1;
    xx = 2 + ++xx;
    std::cout<<xx<<std::endl;

    std::cout<<5 - -3<<std::endl;

    int x = 5;
    int value = add(x, ++x); // is this 5 + 6, or 6 + 6?  It depends on what order your compiler evaluates the function arguments in

    std::cout << value << std::endl; // value could be 11 or 12, depending on how the above line evaluates!

    x = 1;
    x = x++;
    std::cout << x << std::endl;

    int aa=1,bb=2;
    x=(aa,bb, 7);
    int z;
    z = aa, bb, 7;
    std::cout << x << std::endl << z << std::endl;

    double d1(100 - 99.99); // should equal 0.01
    double d2(10 - 9.99); // should equal 0.01

    if (d1 == d2)
        std::cout << "d1 == d2" << "\n";
    else if (d1 > d2)
        std::cout << "d1 > d2" << "\n";
    else if (d1 < d2)
        std::cout << "d1 < d2" << "\n";

    int global = 10;
    std::cout << global << '\t' << ::global << std::endl;

    staticVariableIncrement();
    //stat_x = 5;
    staticVariableIncrement();

    std::cout << zmienna_extern << std::endl;
    wypiszZmiennaGlobalZInnegoPliku();

    std::cout << Foo::x << '\t' << Foo::Goo::g_x << std::endl;
    short a1{10}, a2{20};

    std::cout << typeid(a1).name() << '\t' << typeid(a1+a2).name() << std::endl;
    //char tab[]{4,3,4,2};
    //std::cout << "smieci: " << int(tab) << std::endl;

    using distance_t = double;
    distance_t dist{7.8};
    std::cout << typeid(dist).name() << std::endl;


}
