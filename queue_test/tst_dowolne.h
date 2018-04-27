#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdexcept>

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

/*
TEST(dowolne, nie_przechodzi)
{
    EXPECT_FALSE(true);
}

TEST(dowolne, przechodzi)
{
    EXPECT_EQ(1, 1);
}

TEST(dowolne, DISABLED_przechodzi)
{
    EXPECT_EQ(2, 1);
}*/

class VQueue {
public:
    virtual void putElement()=0;
    virtual unsigned getMaxSize()=0;
    virtual unsigned getElementNumber()=0;
};

class MockQueue : public VQueue {
public:
    void putElement(){}
    unsigned getMaxSize(){return 0;}
    unsigned getElementNumber(){return 0;}
};

class Queue : public VQueue {
protected:
    unsigned maxSize;
    unsigned elementNumber;

public:
    Queue(unsigned maxSize):maxSize(maxSize), elementNumber(0){}

    unsigned getMaxSize(){return maxSize;}
    unsigned getElementNumber(){return elementNumber;}

    void putElement(){
        //cout << "maxSize: " << maxSize << "\t elementNumber: " << elementNumber << endl;
        if(maxSize < elementNumber+1 )
            throw out_of_range("Przeplnienie kolejki!");
        ++elementNumber;
    }

};

class CommonResources : public testing::Test{
    protected:
    CommonResources(){
        cout << "Create fixture\n";
    }

    ~CommonResources(){
        cout << "Deleting fixture\n";
    }
    //przygotowani
    void SetUp(){ cout << "SetUp\n";}
    //sprzatanie
    void TearDown(){cout << "TearDown\n";}

    /*int queueTest(){
        unsigned sizeQ = 9;
        Queue q = Queue(sizeQ);
        cout << sizeQ << endl;
    }*/

    //int resource;
};

TEST_F(CommonResources,maxSizeTest){
    const bool implemented = implementationDone(true);
    unsigned sizeQ = 9;
    VQueue * ptr_q;
    if(implemented)
        ptr_q = new Queue(sizeQ);
    else
        ptr_q = new MockQueue;
    EXPECT_EQ(sizeQ,ptr_q->getMaxSize());
    delete ptr_q;
}

TEST_F(CommonResources,putMethodTest){
    const bool implemented = implementationDone(false);
    unsigned sizeQ = 10;
    VQueue * ptr_q;
    if(implemented)
        ptr_q = new Queue(sizeQ);
    else
        ptr_q = new MockQueue;
    EXPECT_EQ(0,ptr_q->getElementNumber());
    ptr_q->putElement();
    EXPECT_EQ(1,ptr_q->getElementNumber());
}

TEST_F(CommonResources,putSizeOverflowTest){
    const bool implemented = implementationDone(false);
    unsigned sizeQ = 10;
    VQueue * ptr_q;
    if(implemented)
        ptr_q = new Queue(sizeQ);
    else
        ptr_q = new MockQueue;
    for(int i=0;i<sizeQ;++i){
        EXPECT_NO_THROW(ptr_q->putElement());
    }
    EXPECT_ANY_THROW(ptr_q->putElement());
}






