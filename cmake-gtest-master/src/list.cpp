#include "list.h"
#include <exception>

List::List():pHead(NULL), size(0)
{

}

List::List(const int arr[], unsigned size):List()
{
    for(unsigned i=0; i<size; ++i)
    {
        this->insert(arr[i]);
    }
}

List::~List()
{
    Node * ptr_iterator = pHead, * ptr_tmp;
    while(ptr_iterator)
    {
        ptr_tmp = ptr_iterator;
        ptr_iterator = ptr_iterator->pNext;
        delete ptr_tmp;
    }
}

unsigned List::getSize()
{
    return size;
}

List::Node * List::getNodeIndex(unsigned index)
{
    Node * ptr_node = pHead;
    for(unsigned i=0; i<index && ptr_node!=nullptr ;++i)
    {
        ptr_node = ptr_node->pNext;
        //cout << "i: " << i << endl;
    }
    if(ptr_node)
        return ptr_node;
    else
        throw out_of_range("Index is out of range of the list. Pointer is null");
}

int List::getIndex(unsigned index)
{
    return getNodeIndex(index)->value;
}

void List::insert(int value)
{
    insert(value,size);
}

bool List::contains(int element)
{
    Node * ptr_iterator = pHead;
    while(ptr_iterator)
    {
        if(ptr_iterator->value == element)
            return true;
        ptr_iterator = ptr_iterator->pNext;
    }
    return false;
}

void List::reverse()
{
    if(!getSize())
        return;

    Node * pNewHead = reverseNodes(pHead, pHead->pNext);
    /*if(pNewHead == pTail)
        cout << "Rekursja zwrocila tail jako nowy head" << endl;
    else
        cout << "Rekursja nie dziala poprawnie" << endl;*/
    pTail = pHead;
    pHead = pNewHead;
}

List::Node * List::reverseNodes(Node * pPreviousFirst, Node * pNextFirst)
{
    Node * pTmp = pNextFirst->pNext;
    pNextFirst->pNext = pPreviousFirst;
    if(pPreviousFirst == pHead)
        pPreviousFirst->pNext = nullptr;
    if(pTmp)
        return reverseNodes(pNextFirst, pTmp);
    else
        return pNextFirst;
}

string List::toString()
{
    Node * ptr_iterator = pHead;
    string output{""};
    output += "[";
    while(ptr_iterator)
    {
        output += to_string(ptr_iterator->value);
        output += " -> ";
        ptr_iterator = ptr_iterator->pNext;
    }
    //output.pop_back();
    //output.pop_back();
    output += "]";
    return output;
}

void List::insert(int value, unsigned position)
{
    Node * newNode{new Node};
    newNode->value = value;
    if(!size)
    {
        pHead = newNode;
        pTail = newNode;
        newNode->pNext = nullptr;
    }
    else if(position == size)
    {
        pTail->pNext = newNode;
        pTail = newNode;
        newNode->pNext = nullptr;
    }
    else if(position == 0)
    {
        newNode->pNext = pHead;
        pHead = newNode;
    }
    else
    {
        newNode->pNext = getNodeIndex(position);
        getNodeIndex(position-1)->pNext = newNode;
    }
    ++size;
}

void List::remove()
{
    if(!size)
        remove(0);
    remove(size-1);
}

void List::remove(unsigned position)
{
    //Node * rmvNode{new Node};
    //rmvNode->value = value;
    if(!size)
    {
        throw out_of_range("Can't remove item. List is empty.");
    }
    else if(size == 1)
    {
        delete pHead;
        pHead = nullptr;
        pTail = nullptr;
    }
    else if(position == size-1)
    {
        Node * newTail = getNodeIndex(size-2);
        delete pTail;
        pTail = newTail;
        pTail->pNext = nullptr;
    }
    else if(position == 0)
    {
        Node * newHead = pHead->pNext;
        delete pHead;
        pHead = newHead;
    }
    else
    {
        Node * pPrevious = getNodeIndex(position-1);
        Node * pToDelete = pPrevious->pNext;
        pPrevious->pNext = pPrevious->pNext->pNext;
        delete (pToDelete);
    }
    --size;
}

bool List::equal(List& l1, List& l2)
{
    if(l1.getSize()!=l2.getSize())
        return false;
    //malo efektywne O(N^2)
    for(int i=0; i<l1.getSize(); ++i)
        if(l1.getIndex(i)!=l2.getIndex(i))
            return false;
    return true;
}

bool List::equal(List& list, const int tab [], unsigned tabSize)
{
    if(list.getSize()!=tabSize)
        return false;
    //malo efektywne O(N^2)
    for(int i=0; i<list.getSize(); ++i)
        if(list.getIndex(i)!=tab[i])
            return false;
    return true;
}
