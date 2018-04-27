#include <iostream>
#include <string>
#include <algorithm>

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
    cout << "binary: " << binary_str << " to unsigned: " << bits2unsigned(binary_str,true) << endl;
    */

    f2();

    return 0;


}
