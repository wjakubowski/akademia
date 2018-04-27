#include <iostream>
#include "testy.h"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    cout << "Hello World!" << endl;
    return RUN_ALL_TESTS();
}
