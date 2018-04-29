#include <iostream>

using namespace std;


/*
Do zaimplementowania:

plik .h

do edytowania - punkt startowy
trzeba to uogolniac - dwukierunkowo, szablon dla wartosci, mozna robic TDD, mozna trzymac liczbe elementow*/

#include <string>

class List {
    struct Node {
        int value;
        Node *pNext;
    };

    Node *pHead;
public:
    List();
    List(int const arr[], int size);
    ~List();
    void insert(int value);
    void reverse();//moga byc 2 wersje: statyczna przyjmuje liste i zwraca odwrucona, druga odwraca sama siebie
    string toString();
    bool contains(int element);
    // ...
};




///##############################################################################################


//w konstruktorze domyslnym wskaznik na NULL, moga byc glembokosci poddrzew
//najlepiej pisac rekursyjnie nie iteracyjnie
//mozna tez sprobowac przeciazyc operatory np +=

class BinSearchTree {
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
};

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
