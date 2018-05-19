#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational {
    int numerator;
    int denominator;

public:
    Rational(int num, int denom = 1)
        : numerator(num), denominator(denom) { }

    int num() const { return numerator; }
    int denom() const { return denominator; }


    Rational& operator += (Rational a) {
        // modyfikacje
        return *this;
    }


};

inline bool operator == (Rational a, Rational b);
inline bool operator != (Rational a, Rational b);
inline bool operator < (Rational a, Rational b);
inline bool operator <= (Rational a, Rational b);
inline bool operator > (Rational a, Rational b);
inline bool operator >= (Rational a, Rational b);

inline Rational operator - (Rational a);

inline Rational operator + (Rational a, Rational b){
    a += b;
    return b;
}

inline std::ostream& operator << (std::ostream& os,
                                  Rational a) {
    return os << a.num() << "/" << a.denom();

}



#endif // RATIONAL_HPP

