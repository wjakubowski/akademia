#ifndef TESTY_H
#define TESTY_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "helper.h"

using namespace testing;
using namespace std;

//global behavior
const bool gb = false;
//global implement
const bool gi = false;
//test implementation state (bool li <- local implementation)
bool implementationDone(bool li){
    bool readyState;
    if(gb)
        readyState = gi;
    else
        readyState = li;
    if(readyState)
        cout << "RUN TEST AS IMPLEMENTED!" << endl;
    else
        cout << "RUN TEST AS NOT IMPLEMENTED!" << endl;
    return readyState;
}

TEST(lab2zd, swap_test)
{
    const bool implemented = implementationDone(true);

    int a = 1, b = 2;
    EXPECT_NE(a, b);
    int a_0 = a, b_0 = b;
    EXPECT_TRUE(a==a_0);
    EXPECT_TRUE(b==b_0);
    if(implemented){
        swap_template(&a, &b);
    }
    EXPECT_TRUE(a==b_0);
    EXPECT_TRUE(b==a_0);

}

TEST(lab2zd, reference_swap_test)
{
    const bool implemented = implementationDone(true);

    int a = 1, b = 2;
    EXPECT_NE(a, b);
    int a_0 = a, b_0 = b;
    EXPECT_TRUE(a==a_0);
    EXPECT_TRUE(b==b_0);
    if(implemented){
        swap_ref(a, b);
    }
    EXPECT_TRUE(a==b_0);
    EXPECT_TRUE(b==a_0);

}


#endif // TESTY_H
