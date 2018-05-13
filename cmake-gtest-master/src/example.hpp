#include <tuple>
using namespace std;
#pragma once

// Returns 5
int five();

struct Solution {
    double x1;
    double x2;
    int count;
    bool identity;
};

Solution roots(double a, double b, double c);

//tuple<int, double> krotka(1,2.3);
//get<1>(krotka);
