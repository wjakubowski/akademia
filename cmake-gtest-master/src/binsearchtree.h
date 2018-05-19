#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>
using namespace std;

/*
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
*/
struct BSTNode;

class BinSearchTree {
    BSTNode *m_pRoot {nullptr};
    int m_elemCount {0};
    bool m_isIncr {true};

    BSTNode* insertRecur(int elem, BSTNode *pCurrRoot);
    std::string toStringRecur(BSTNode *pCurrRoot) const;
    BSTNode* mirrorRecur(BSTNode *pCurrRoot) const;
    int depthRecur(BSTNode *pCurrRoot) const;
    bool containsRecur(int elem, BSTNode *pCurrRoot) const;
    BSTNode* newBSTNode(int elem) const;
    void deleteElems(BSTNode *pCurrRoot);

public:
    static BinSearchTree* fromArray(int const arr[], int size);
    //BinSearchTree(int const arr[], int size);
    BinSearchTree() {}
    ~BinSearchTree();
    void insert(int value);
    std::string toString();
    bool contains(int elem) const;
    void mirror();
    int depth() const;
};

void runBinSearchTreeMethods();

struct BSTNode
{
    int value;
    BSTNode *pLeft;
    BSTNode *pRight;
    ~BSTNode() { /*cout << "destruction of " << value << endl;*/ }
};

#endif // BINSEARCHTREE_H
