#include <iostream>
#include <cstring>

class String {
    char* buf;
public:
    String(const char* str): buf{new char[strlen(str) + 1]} {
        std::strcpy(buf, str);
    }

    char * getBuf()
    {
        return buf;
    }

    String& operator = (const String& other) {
// WERSJA 1 - najlepsze nie robimy kopii jak sam na siebie przypisuje
        if(this == &other)
            return *this;
        delete [] buf;
        buf = new char[std::strlen(other.buf) + 1];
        std::strcpy(buf, other.buf);
        return *this;


// WERSJA 2
//        char* tmp = new char[std::strlen(other.buf) + 1];
//        std::strcpy(tmp, other.buf);
//        delete [] buf;
//        buf = tmp;
//        return *this;

// WERSJA 3
//        String tmp(other);
//        std::swap(buf, tmp.buf);
//        return *this;

// zwracamy referencje bo a=b=c; wtedy dziala

    }

    String(const String& other):String(other.buf)
    {
//        buf = new char[std::strlen(other.buf) + 1];
//        std::strcpy(buf, other.buf);
    }

    ~String() {
        delete[] buf;
    }
};


int main() {
    String a{"Ala"};
    String b{a};
    String c{"Kot"};
    c = a;

    std::cout << c.getBuf() << std::endl;
    a = a;
    //nic nie wypisuje bo bufor zostal zniszczony przed przepisaniem
    std::cout << a.getBuf() << std::endl;
}
