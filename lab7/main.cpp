#include <iostream>
#include <string>

using namespace std;

/*
struct A {
    string a;
    A() : a{"dfsdd"}
    {
        cout << "sdasdas" << endl;
    }
};

struct B: A {
    string a;
    string c;

    B(): c{"Ala"}, A{}, a{"Kota"}{}

    B(int): a{""}, c{"asdf"} {}
};*/

struct A {
    virtual void f() const {}
    virtual ~A() = default;
};

struct B: A {
    void f() const override {}
};

void f(A a) {
    a.f();
}

int main(int argc, char *argv[])
{
//    B b;
//    cout << "Hello World!" << endl;
//    return 0;
/////////////////////////////////////////////////
    B b;
    A a{b};
    f(a);
/////////////////////////////////////////////////


}
