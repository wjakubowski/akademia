#include "example.hpp"
#include <tuple>
#include <cmath>

int five() {
    return 5;
}

Solution roots(double a, double b, double c)
{
    if(a==0 && b==0 && c==0)
    {
        return Solution{0,0,0,true};
    }
    double delta = b*b - 4.0*a*c;
    Solution s;
    if(delta > 0.0)
    {
        double x1 = (-b - sqrt(delta))/(2.0*a);
        double x2 = (-b + sqrt(delta))/(2.0*a);
        x1 = min(x1,x2);
        x2 = max(x1,x2);
        s.x1=x1;
        s.x2=x2;
        s.count = 2;
        s.identity = false;
    }
    else if(delta < 1e-10)
    {
        s.x1= -b /(2.0*a);
        s.x2= s.x1;
        s.count = 1;
        s.identity = false;
    }

    return s;
}
