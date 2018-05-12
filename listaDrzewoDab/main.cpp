#include <iostream>
#include <memory>
#include <vector>

using namespace std;

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

void runBinSearchTreeMethods()
{
    constexpr int arr1[] = {4,2,6,1,3,5,7};
    constexpr int arr1Size = sizeof(arr1) / sizeof(arr1[0]);

    std::unique_ptr<BinSearchTree> pBST1(BinSearchTree::fromArray(arr1, arr1Size));

    cout << "*** Testing BST1 built from [4,2,6,1,3,5,7] ***" << endl;
    cout << "pBST1 = " << pBST1->toString() << endl;
    cout << "pBST1->depth() = " << pBST1->depth() << endl;
    cout << endl;

    cout << "*** Testing contains method on BST1 ***" << endl;
    for (int i = 0; i < arr1Size; ++i) {
       cout << "BST1.contains(" << arr1[i] << ") = "
            << pBST1->contains(arr1[i]) << endl;
    }

    for (int i = 8; i < 10; ++i) {
       cout << "BST1.contains(" << i << ") = " << pBST1->contains(i) << endl;
    }

    cout << "*** Testing mirroring of BST1 ***" << endl;
    pBST1->mirror();
    cout << "BST1 = " << pBST1->toString() << endl;
    cout << "pBST1->depth() = " << pBST1->depth() << endl;

    // Checking if "contains" still works
    for (int i = 0; i < arr1Size; ++i) {
       cout << "BST1.contains(" << arr1[i] << ") = "
            << pBST1->contains(arr1[i]) << endl;
    }

    constexpr int arr2[] = {4,2,6};
    constexpr int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    std::unique_ptr<BinSearchTree> pBST2(BinSearchTree::fromArray(arr2, arr2Size));

    cout << "*** Testing BST2 built from [4,2,6] ***" << endl;
    cout << "BST2 = " << pBST2->toString() << endl;
    cout << "BST2->depth() = " << pBST2->depth() << endl;
    cout << endl;

    constexpr int arr3[] = {1,2,3,4,5,6,7,8,9};
    constexpr int arr3Size = sizeof(arr3) / sizeof(arr3[0]);
    std::unique_ptr<BinSearchTree> pBST3(BinSearchTree::fromArray(arr3, arr3Size));

    cout << "*** Testing BST3 built from [1,2,3,4,5,6,7,8,9] ***" << endl;
    cout << "BST3 = " << pBST3->toString() << endl;
    cout << "BST3->depth() = " << pBST3->depth() << endl;
    cout << "*** Testing mirroring of BST1 ***" << endl;
    pBST3->mirror();
    cout << "BST3 = " << pBST3->toString() << endl;
    cout << "BST3->depth() = " << pBST3->depth() << endl;
    cout << endl;
}

BinSearchTree* BinSearchTree::fromArray(int const arr[], int size)
{
    BinSearchTree* pBST = new BinSearchTree;

    for (int i = 0; i < size; ++i) {
        pBST->insert(arr[i]);
    }

    return pBST;
}

BinSearchTree::~BinSearchTree()
{
    deleteElems(this->m_pRoot);
    this->m_elemCount = 0; // ?
}

void BinSearchTree::insert(int value)
{
    this->m_pRoot = insertRecur(value, this->m_pRoot);
}

std::string BinSearchTree::toString()
{
    return toStringRecur(m_pRoot);
}

bool BinSearchTree::contains(int elem) const
{
    return containsRecur(elem, this->m_pRoot);
}

void BinSearchTree::mirror()
{
    mirrorRecur(this->m_pRoot);
    m_isIncr = !m_isIncr;
}

int BinSearchTree::depth() const
{
    return depthRecur(this->m_pRoot);
}

BSTNode* BinSearchTree::insertRecur(int elem, BSTNode *pCurrRoot)
{
    if (pCurrRoot == nullptr) {
        BSTNode *pNode = newBSTNode(elem);
        m_elemCount++;
        return pNode;
    } else {
        int val = pCurrRoot->value;
        if ((m_isIncr && elem < val) || (!m_isIncr && elem > val)) {
            pCurrRoot->pLeft = insertRecur(elem, pCurrRoot->pLeft);
        } else if ((m_isIncr && elem > val) || (!m_isIncr && elem < val)) {
            pCurrRoot->pRight = insertRecur(elem, pCurrRoot->pRight);
        } else { /* do nothing; assuming unique elems */ }

        return pCurrRoot;
    }
}

std::string BinSearchTree::toStringRecur(BSTNode *pCurrRoot) const
{
    if (pCurrRoot == nullptr) {
        return "";
    } else {
        return toStringRecur(pCurrRoot->pLeft) +
                to_string(pCurrRoot->value) +
                toStringRecur(pCurrRoot->pRight);
    }
}

BSTNode* BinSearchTree::mirrorRecur(BSTNode *pCurrRoot) const
{
    if (pCurrRoot != nullptr) {
        BSTNode *pLeftMird = mirrorRecur(pCurrRoot->pRight);
        BSTNode *pRightMird = mirrorRecur(pCurrRoot->pLeft);
        pCurrRoot->pLeft = pLeftMird;
        pCurrRoot->pRight = pRightMird;
    }

    return pCurrRoot;
}

int BinSearchTree::depthRecur(BSTNode *pCurrRoot) const
{
    int depth = 0;

    if (pCurrRoot != nullptr) {
        depth = 1 + std::max(depthRecur(pCurrRoot->pLeft),
                             depthRecur(pCurrRoot->pRight));
    }

    return depth;
}

bool BinSearchTree::containsRecur(int elem, BSTNode *pCurrRoot) const
{
    bool result = false;

    if (pCurrRoot != nullptr) {
        int val = pCurrRoot->value;
        if (val == elem) {
            result = true;
        } else if ((m_isIncr && elem < val) || (!m_isIncr && elem > val)) {
            result = containsRecur(elem, pCurrRoot->pLeft);
        } else {
            result = containsRecur(elem, pCurrRoot->pRight);
        }
    }

    return result;
}

BSTNode* BinSearchTree::newBSTNode(int elem) const
{
    BSTNode *pNode = new BSTNode;
    pNode->value = elem;
    pNode->pLeft = nullptr;
    pNode->pRight = nullptr;
    return pNode;
}

void BinSearchTree::deleteElems(BSTNode *pCurrRoot)
{
    if (pCurrRoot != nullptr) {
        deleteElems(pCurrRoot->pLeft);
        deleteElems(pCurrRoot->pRight);
        delete pCurrRoot;
    }
}

double fun()
{
    return 1.0;
}

int fun(int i)
{
    return i+1;
}


int main(int argc, char *argv[])
{

    std::cout << "Hello World!" << std::endl;
    runBinSearchTreeMethods();
    //vector <int> vec;
    cout << fun() << '\t' << fun(1) << endl;
    return 0;
}
