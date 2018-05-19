#include "rational.h"
#include <algorithm>
#include <cmath>
#include <iostream>

int nwd(int i1, int i2)
{
    while(i1!=i2)
    {
        i1 = min(i1,i2);
        i2 = max(i1,i2);
        cout << i1 << "\t" << i2 << endl;
        i2 = i2-i1;


    }
    return i2;
}
