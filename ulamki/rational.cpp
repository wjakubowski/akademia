#include "rational.h"
#include <algorithm>
#include <cmath>
#include <iostream>

int nwd(int a, int b)
{
    while(a!=b)
       if(a>b)
           a-=b; //lub a = a - b;
       else
           b-=a; //lub b = b-a
    return a; // lub b - obie zmienne przechowują wynik NWD(a,b)
}

Rational& Rational::operator += (Rational a)
{
    //nominator+=a.*denominator;
    return *this;
}
