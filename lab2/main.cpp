#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;


///TO JEST POCZATEK TRESCI Z ZAJEC
/**
//#define llong(l) l

float f(){
    float x = 0;
    float dx = 0.125;
    while (x != 1.0){
        x += dx;
        cout << x << endl;
    }
    return x;
}

int f1(double x){
    return (int)x*x;
}

short * (*fun13(int))(double,int);
//(*p13(*double)


class C{
public:
    int x,y;
    float f;


    C(int x, float f):x(x),y(x), f(f){}



};
*/
///TO JEST KONIEC TRESCI Z ZAJEC


void printIntsFromRawMem(const char *pCh, int size){
    for(int i=0; i<size; ++i ){
        cout << (int)*(pCh + i);
    }
}

string unsigned2bits_mask (unsigned n){
    unsigned s = 8*sizeof(n);
    unsigned mask = 1<<(s-1);
    //cout << mask << endl;
    string bits = "";
    for(unsigned i=0; i<s; ++i){
        //cout << (mask) << endl;
        bits+=(mask&n)?"1":"0";
        mask>>=1;
    }
    return bits;
}




unsigned bits2unsigned_mask(const string & bits/*, bool revert = false*/){
    unsigned s = bits.size();
    unsigned mask = 1<<(s-1);
    unsigned n=0;

    for(unsigned i=0; i<s; ++i){
        if(bits[i]=='1'){
            n |= mask;
        }
        //cout << mask << endl;
        mask>>=1;
    }
    return n;
}

string unsigned2bits (unsigned n, bool bigEndian = false){
    unsigned s = 8*sizeof(n);
    unsigned position = 1<<(s-1);
    string bits = "";
    unsigned tmp;
    for(unsigned i=0; i<s; ++i){
        tmp = n/position;
        n -= tmp*position;
        bits+= to_string(tmp);
        position >>= 1;
    }

    if(!bigEndian)
        reverse(bits.begin(), bits.end());

    return bits;
}




unsigned bits2unsigned(const string & bits, bool bigEndian = false){
    unsigned s = bits.size();
    unsigned multiplicator = 1;
    unsigned n=0;
    unsigned position;

    for(unsigned i=0; i<s; ++i){
        position = (bigEndian?i:(s-1-i));
        if(bits[position]=='1'){
            n += multiplicator;
        }
        multiplicator <<= 1;
    }
    return n;
}






void castDemo1()
{
    long lN = 578437695752307201;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << lN << " as a byte stream = ";
    printIntsFromRawMem((char *) &lN, sizeof(lN));
    cout << endl;
}



struct IEEE754
{
    unsigned int mantissa: 23,
                 exponent: 8,
                 sign : 1;
};

void castDemo2()
{
    int ia1[2] = {84281096, 16909060};
    cout << "int ia1[2] = {84281096, 16909060} as a byte stream = ";
    printIntsFromRawMem((char *) ia1, 8);

    cout << endl;
    int ia2[2] = {67305985, 134678021};
    cout << "int ia2[2] = {67305985, 134678021} as a byte stream = ";
    printIntsFromRawMem((char *) ia2, 8);
    cout << endl;
}

void castDemo3()
{
    float dN = 1.5399896E-36;
    cout << dN << " as a byte stream = ";
    printIntsFromRawMem((char *) &dN, 4);
    cout << endl;
}

void castDemo4()
{
    float dN = 1.5399896E-36;

    cout << "sizeof(struct IEEE754) = " << sizeof(struct IEEE754) << endl;
    cout << dN << " decomposed with the use of bitfields: ";

    struct IEEE754 *pI3E754 = (struct IEEE754 *) &dN;
    cout << "sign = " << pI3E754->sign
         << ", exponent = " << pI3E754->exponent
         << ", mantissa = " << pI3E754->mantissa << endl;
}

void castDemo5()
{
    float dN = 1.5399896E-36;

    struct IEEE754 *pI3E754 = (struct IEEE754 *) &dN;
    const unsigned int floatAsUInt = *(unsigned int *) pI3E754;

    const unsigned int signMask = 0x1;
    unsigned int sign = (floatAsUInt >> 31) & signMask;

    const unsigned int exponentMask = 0xFF;
    unsigned int exponent = (floatAsUInt  >> 23) & exponentMask;

    const unsigned int mantissaMask = 0x7FFFFF;
    unsigned int mantissa = floatAsUInt & mantissaMask;

    cout << dN << " decomposed with the use of bitmasks: ";
    cout << "sign = " << sign
         << ", exponent = " << exponent
         << ", mantissa = " << mantissa << endl;
}


void f2()
{
#define TBL_SIZE 2
    long i = 0;
    long lArr[TBL_SIZE] = {7, 15};
    for (i = 0; i <= TBL_SIZE; ++i) {
        cout << "lArr\t" << lArr << endl;
        cout << "lArr[TBL_SIZE-1]\t" << lArr[TBL_SIZE-1] << endl;
        cout << "&lArr[TBL_SIZE-1]\t" << &lArr[TBL_SIZE-1] << endl;
        cout << "&lArr[TBL_SIZE-1]-1\t" << &lArr[TBL_SIZE-1]-1 << endl;
        cout << "&i\t" << &i << endl;
        cout << "*(&lArr[TBL_SIZE-1]-i)\t" << *(&lArr[TBL_SIZE-1]-i) << endl;
        *(&lArr[TBL_SIZE - 1] - i) = 0;
        cout << "*(&lArr[TBL_SIZE-1]-i)\t" << *(&lArr[TBL_SIZE-1]-i) << endl << endl;
    }
}



class C1{
    int x;
    long y;
    int z;
};

class C2{
    int x;
    int z;
    long y;
};

class C3{
};

class C4{
    char c;
};


int ackerman(int m, int n)
{
    if(m==0)
        return n+1;
    else
    {
        if(m>0 && n==0)
            return ackerman(m-1,1);
        else
            return ackerman(m-1,ackerman(m,n-1));
    }
}

unsigned long factorial(unsigned long n)
{
    //cout << n << endl;
    return (n==0)?1:n*factorial(n-1);
}

unsigned long fib(unsigned long n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

unsigned long miez_czas(unsigned int arg, unsigned long (*fun)(unsigned long))
{

    using ns = chrono::nanoseconds;
    using get_time = chrono::steady_clock;

    auto start = get_time::now();
    fun(arg);
    auto end = get_time::now();
    auto diff = end - start;
    //cout << "Elapsed time is : " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
    return chrono::duration_cast<ns>(diff).count();
}


int main()
{
    ///TO JEST POCZATEK TRESCI Z ZAJEC
    /**
    cout << "f()=" << f() << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    //cout << llong(99999999999999999999999999999999999999999999999999999999999999999999999999999999999) << endl;
    //int *** a;
    float y = 9;

    const float z = 4;

    const float * p3 = &z;

    //float * p7 = &z;

    int * pA[5]; //tablica wskaznikow
    int *( (* ptr_pA)[5] ) = &pA;
    int tab[5];
    //int tab2[10];
    int (* p9)[5] = &tab; //wskaznik do tablicy
    int ** gwiazdki = pA;

    int (* p11)(double) = f1;

    C c = C(1,1);
    cout << "size c " << sizeof(&c) << sizeof(c) << endl;



    C * d = new C(1,1);
    cout << "size d " << sizeof(d) << sizeof(*d) << endl;

    cout << sizeof(int*) << endl;

    cout << sizeof(C) << endl;

    int a[]{8*8*8+2,2};

    short* p1 = (short (*)) a;

    cout << p1[0] << "     " << p1[1] << endl;

    int inta =7;
    int & intaa = inta;
    int * intaaa = &intaa;


    f2();
    // HOMEWOREK
    //void printIntsFromRawMem(const char *pCh, int size)
    // HOMEWOREK
    //swap2int

    cout << "KONIEC" << endl;
    */
    ///TO JEST KONIEC TRESCI Z ZAJEC


    /*
    cout << "-----------------------------------------------" << endl;
    castDemo1();
    cout << "-----------------------------------------------" << endl;
    castDemo2();
    cout << "-----------------------------------------------" << endl;
    castDemo3();
    cout << "-----------------------------------------------" << endl;
    castDemo4();
    cout << "-----------------------------------------------" << endl;
    castDemo5();
    cout << "-----------------------------------------------" << endl;
    unsigned example_unsigned = 2049;
    cout << "unsigned: " << example_unsigned << " to binary: " << unsigned2bits_mask(example_unsigned) << endl;
    cout << "-----------------------------------------------" << endl;
    string binary_str = "00000000000000000000100000000001";
    cout << "binary: " << binary_str << " to unsigned: " << bits2unsigned_mask(binary_str) << endl;
    cout << "-----------------------------------------------" << endl;
    //unsigned example_unsigned = 2049;
    cout << "unsigned: " << example_unsigned << " to binary: " << unsigned2bits(example_unsigned,true) << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "binary: " << binary_str << " to unsigned: " << bits2unsigned(binary_str,true) << endl;*/


    //f2();
    /*
    unsigned u = 1;
    int ii = 1;

    cout << (u) << endl;
    cout << (ii) << endl;

    cout << (u<<1) << endl;
    cout << (ii<<1) << endl;

    cout << (u) << endl;
    cout << (ii) << endl;

    u <<= 31;
    ii <<= 31;

    cout << (u) << endl;
    cout << (ii) << endl;

    u >>= 31;
    ii >>= 31;

    cout << u << endl;
    cout << ii << endl;

    printIntsFromRawMem((char *) &ii,4);

    unsigned wzorzec_bitowy = 0x1234;
    unsigned maska = 0x00f0;
    unsigned rzut = wzorzec_bitowy & maska;
    cout << endl << rzut << endl;
    rzut >>= 4;
    cout << rzut << endl;

    int a1[]{1,2,3,4,5};

    short * p1 = (short *) a1;

    for(int i=0;i<10;++i){
        cout << *(p1+i) << endl;
    }


    cout << endl << "rozmiary klas C1-4:" << endl << sizeof(C1) << endl;
    cout << sizeof(C2) << endl;
    cout << sizeof(C3) << endl;
    cout << sizeof(C4) << endl;

    //w klasie jest 1 bajt mimo pustosci klasy bo wskaznik na klase musi na cos pokazywac
    C3 * p2 = new C3;
    cout << p2 << endl << sizeof(p2) << endl;


    cout << "ackerman(2,2):\t" << ackerman(2,2) << endl;
    cout << "ackerman(3,3):\t" << ackerman(3,3) << endl;
    //cout << "ackerman(4,1):\t" << ackerman(4,1) << endl;
    cout << "factorial(4):\t"  << factorial(4)  << endl;

    unsigned long i = 0xFFFFFFFFFFFFFFFF;

    double d = i;
    cout << std::setprecision(22) << i << '\t' << d << endl;
    printf("%lu \t%f",i,d);

    double d2 = (int)123456789;
    cout << endl;
    printf("%d \t%f",(int)123456789,d2);

    cout << endl << static_cast<double>(123123) << endl;
    cout << static_cast<int>(33.3) << endl;*/


    /*
    #include <chrono>

    using namespace std;

    int main()
    {
        using ns = chrono::nanoseconds;
        using get_time = chrono::steady_clock;

        auto start = get_time::now();
        //...
        auto end = get_time::now();
        auto diff = end - start;
        cout << "Elapsed time is : " << chrono::duration_cast<ns>(diff).count() << " ns " << endl;
        return 0;
    }
    */




    for(int i=0;i<10;i+=1)
    {
        cout << i << '\t' << miez_czas(i, fib) ;
        //cout << endl;
        //cout << i;
        cout << miez_czas(i,factorial) << endl;
    }

    //for(int i=0;i<100;++i)
      // cout << i << '\t' << factorial(i) << endl;


    return 0;


}
