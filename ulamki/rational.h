#ifndef RATIONAL_H
#define RATIONAL_H

#include <exception>
#include <ostream>

using namespace std;

//liczby wymierne

//sprowadzanie do ujednoliconej postaci:
//najmiejszy wspulny dzielnik
//nie zewoeosc mianownika
//jak mianownik <0 mnozymy gore i dol przez -1

int nwd(int i1, int i2);
//int nww(int i1, int i2);


class Rational
{
    int nominator;
    int denominator;

public:
    Rational(int nominator, int denominator):nominator{nominator}, denominator{denominator}{}

    Rational(int n): Rational{n,1}{}

    int getNominator(){return nominator;}
    int getDenominator(){return denominator;}

    //modyfikujace w ciele klasy
    Rational& operator += (Rational a)
    {
        //modyfikacje
        return *this;
    }



    //to jest gorsze bo nie pozwala na domyslna konwersje 1 arg
    // nie mozna:
    // new_rat=1+rat
    //Rational operator + (const Rational& r ) const;
};

inline Rational operator + (Rational a, Rational b);
inline Rational operator - (Rational a, Rational b);
inline Rational operator - (Rational a);

inline bool operator == (Rational a, Rational b);
inline bool operator != (Rational a, Rational b);
inline bool operator < (Rational a, Rational b);
inline bool operator <= (Rational a, Rational b);
inline bool operator > (Rational a, Rational b);
inline bool operator >= (Rational a, Rational b);


inline std::ostream& operator << (std::ostream& os, Rational a)
{
    os << "[" << a.getNominator() << "/" << a.getDenominator() << "]";
    return os;
}

#endif // RATIONAL_H
