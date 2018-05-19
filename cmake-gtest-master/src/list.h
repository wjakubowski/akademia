#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

/*
Do zaimplementowania:

plik .h

do edytowania - punkt startowy
trzeba to uogolniac - dwukierunkowo, szablon dla wartosci, mozna robic TDD,
mozna trzymac liczbe elementow
usuwanie elementow
dodawanie w srodku
*/



class List {
    struct Node {
        int value;
        Node *pNext;
    };

    Node *pHead;
    // ...
    Node *pTail;
    unsigned size;
public:
    List();
    List(const int arr[], unsigned size);
    ~List();
    void insert(int value);
    void insert(int value, unsigned position);
    void remove();
    void remove(unsigned position);
    void reverse();//moga byc 2 wersje: statyczna przyjmuje liste
                    //i zwraca odwrucona, druga odwraca sama siebie
    string toString();
    bool contains(int element);
    // ...
    unsigned getSize();
    int getIndex(unsigned index);
    static bool equal(List& l1, List& l2);
    static bool equal(List& list, const int tab[], unsigned tabSize);
    //TODO zrobic jakis iterator dla listy

protected:
    // do rekursywnego odwracania Listy
    Node * reverseNodes(Node * pPreviousFirst, Node * pNextFirst);
    Node * getNodeIndex(unsigned index);
};

#endif // QUEUE_H
