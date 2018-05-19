#include "binsearchtree.h"

void BinSearchTree::insert(int value)
{
    if(!m_pRoot)
        m_pRoot = new BSTNode{value, nullptr, nullptr};
    else
    {
        //if(m_isIncr && (value < m_pRoot->pLeft->value)  )
    }
}
