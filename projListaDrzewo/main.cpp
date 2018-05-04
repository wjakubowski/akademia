#include <iostream>
#include "tests.h"
#include <gtest/gtest.h>

using namespace std;







///##############################################################################################


//w konstruktorze domyslnym wskaznik na NULL, moga byc glembokosci poddrzew
//najlepiej pisac rekursyjnie nie iteracyjnie
//mozna tez sprobowac przeciazyc operatory np +=

/*class BinSearchTree {
    struct BSTNode
    {
        int value;
        BSTNode *pLeft;
        BSTNode *pRight;
    };

    BSTNode *pRoot;
public:
    BinSearchTree();
    BinSearchTree(int const arr[], int size);
    ~BinSearchTree();
    void insert(int value);
    List toList();
    void toString();
    bool contains();
    void mirror();//odbicie wagami wzglendem pionowej osi
    // ...
};*/


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    cout << "Hello World!" << endl;
    return RUN_ALL_TESTS();
}
