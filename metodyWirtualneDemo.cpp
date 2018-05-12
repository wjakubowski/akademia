#include <iostream>
#include <memory>

using namespace std;

struct A
{
    virtual void fA() { cout << "A::fA()" << endl; }
    void fB() { cout << "A::fB()" << endl; } // not virtual
    void fC() { cout << "A::fC()" << endl; } // not virtual

    A() { cout << "A::A()" << endl; }
    A(const A&) { cout << "A::A(const A&)" << endl; }
    virtual ~A() { cout << "~A::A()" << endl; }
};

struct BfromA : A
{
    void fA() { cout << "BfromA::fA()" << endl; }
    virtual void fB() { cout << "BfromA::fB()" << endl; }

    BfromA() { cout << "BfromA::BfromA()" << endl; }
    BfromA(const BfromA&) { cout << "BfromA::BfromA(const BfromA&)" << endl; }
    virtual ~BfromA() { cout << "~BfromA::BfromA()" << endl; }
};

struct CfromB : BfromA
{
    void fA() { cout << "CfromB::fA()" << endl; }
    void fB() /*final */{ cout << "CfromB::fB()" << endl; }
    void fC() { cout << "CfromB::fC()" << endl; }

    CfromB() { cout << "CfromB::CfromB()" << endl; }
    CfromB(const CfromB&) { cout << "CfromB::CfromB(const CfromB&)" << endl; }
    ~CfromB() { cout << "~CfromB::CfromB()" << endl; }
};

struct DFromNothing {
    void fA() { cout << "DFromNothing::fA()" << endl; }
    void fB() { cout << "DFromNothing::fB()" << endl; }
    void fC() { cout << "DFromNothing::fC()" << endl; }

    DFromNothing() { cout << "DFromNothing::DFromNothing()" << endl; }
    ~DFromNothing() { cout << "~DFromNothing::DFromNothing()" << endl; }
};

void polyMorphDemo1()
{
    cout << "polyMorphDemo1()..." << endl;

    A a;
    cout << endl;

    BfromA b;
    cout << endl;

    CfromB c;
    cout << endl;

    cout << "calling fA(), fB(), fC() for object A a ..." << endl;
    a.fA(); a.fB(); a.fC();
    cout << endl;

    cout << "calling fA(), fB(), fC() for object BfromA b ..." << endl;
    b.fA(); b.fB(); b.fC();
    cout << endl;

    cout << "calling fA(), fB(), fC() for object CfromB c ..." << endl;
    c.fA(); c.fB(); c.fC();
    cout << endl;
}

void polyMorphDemo2()
{
    cout << "polyMorphDemo2()..." << endl;

    cout << "constructing A..." << endl;
    A * pAA = new A; cout << endl;
    cout << "calling methods with the use of 'A * pAA = new A'" << endl;
    pAA->fA(); pAA->fB(); pAA->fC();
    cout << endl;

    cout << "constructing BfromA..." << endl;
    A * pAB = new BfromA; cout << endl;
    cout << "calling methods with the use of 'A * pAB = new BfromA'" << endl;
    pAB->fA(); pAB->fB(); pAB->fC();
    cout << endl;

    cout << "constructing CfromB..." << endl;
    A * pAC = new CfromB; cout << endl;
    cout << "calling methods with the use of 'A * pAC = new CfromB'" << endl;
    pAC->fA(); pAC->fB(); pAC->fC();
    cout << endl;

    cout << "constructing BfromA..." << endl;
    BfromA * pBB = new BfromA; cout << endl;
    cout << "calling methods with the use of 'BfromA * pBB = new BfromA'" << endl;
    pBB->fA(); pBB->fB(); pBB->fC();
    cout << endl;

    cout << "constructing CfromB..." << endl;
    BfromA * pBC = new CfromB; cout << endl;
    cout << "calling methods with the use of 'BfromA * pBC = new CfromB'" << endl;
    pBC->fA(); pBC->fB(); pBC->fC();
    cout << endl;

    cout << "deleting objects..." << endl;
    delete pAA; cout << endl;
    delete pAB; cout << endl;
    delete pAC; cout << endl;
    delete pBB; cout << endl;
    delete pBC; cout << endl;
}

template <typename T>
void paramPolymDemoFun(T polyValue)
{
    polyValue.fA();
    polyValue.fB();
    polyValue.fC();
}

void polyMorphDemo3()
{
    cout << "polyMorphDemo3()..." << endl;

    A a; cout << endl;
    BfromA b; cout << endl;
    CfromB c; cout << endl;
    DFromNothing d; cout << endl;

    cout << "calling fA(), fB(), fC() for object A a ..." << endl;
    paramPolymDemoFun(a);
    cout << endl;

    cout << "calling fA(), fB(), fC() for object B b ..." << endl;
    paramPolymDemoFun(b);
    cout << endl;

    cout << "calling fA(), fB(), fC() for object C c ..." << endl;
    paramPolymDemoFun(c);
    cout << endl;

    cout << "calling fA(), fB(), fC() for object D d ..." << endl;
    paramPolymDemoFun(d);
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////

typedef void (*FPT)(void *);

///////////////////////////////////////////////////////////////////////////////
typedef struct CStructBase
{
    void **vt;
    int a;
} CStructBaseT;

// "a method" :)
void cStructM1B(void *pObj) // void cStructM1B(CStructBaseT *pSelf)
{
    CStructBase *pBase = static_cast<CStructBase*>(pObj);
    cout << "CStructBase::cStructM1(), a = "
         << pBase->a << endl;
}

// "constructor" :)
CStructBaseT* createCStructBaseT(int a)
{
    CStructBaseT *pCStructBase = new CStructBaseT;
    pCStructBase->vt = new void *[1];
    // pCStructBase->vt[0] = (void*) &cStructM1B
    pCStructBase->vt[0] = reinterpret_cast<void*> (cStructM1B);
    pCStructBase->a = a;

    return pCStructBase;
}

// "destructor" :)
void deleteCStructBaseT(void *pObj)
{
    cout << "deleteCStructBaseT()..." << endl;
    CStructBaseT *pCStructBaseObj = static_cast<CStructBaseT *>(pObj);
    delete [] pCStructBaseObj->vt;
    delete pCStructBaseObj;
}

///////////////////////////////////////////////////////////////////////////////
typedef struct CStructDerived
{
    void **vt;
    CStructBase *pParent;
    int b;
} CStructDerivedT;

void cStructM1D(void *pObj)
{
    CStructDerived *pDerived = static_cast<CStructDerivedT*>(pObj);
    cout << "CStructDerived::cStructM1D(), a = "
         << pDerived->pParent->a << ", b = " << pDerived->b << endl;
}

CStructDerivedT* createCStructDerivedT(CStructBaseT* pParent, int b)
{
    CStructDerivedT *pCStructDerived = new CStructDerivedT;
    pCStructDerived->vt = new void *[1];
    pCStructDerived->vt[0] = reinterpret_cast<void*> (cStructM1D);
    pCStructDerived->pParent = pParent;
    pCStructDerived->b = b;

    return pCStructDerived;
}

void deleteCStructDerivedT(void *pObj, bool deleteParent = false)
{
    cout << "deleteCStructDerivedT()..." << endl;
    CStructDerivedT* pCStructDerivedObj = static_cast<CStructDerivedT*>(pObj);
    if (deleteParent) {
        deleteCStructBaseT(pCStructDerivedObj->pParent);
    }

    delete [] pCStructDerivedObj->vt;
    delete pCStructDerivedObj;
}
///////////////////////////////////////////////////////////////////////////////

void runPolyImplDemo()
{
    CStructBaseT *pBase = createCStructBaseT(1);
    ((FPT) pBase->vt[0])(pBase);

    CStructDerivedT *pDeriv = createCStructDerivedT(pBase, 2);
    reinterpret_cast<FPT>(pDeriv->vt[0])(pDeriv);

    CStructBaseT *pBase2 = createCStructBaseT(11);
    CStructBaseT *pBase3 =
            reinterpret_cast<CStructBaseT *>(createCStructDerivedT(pBase2, 22));
    reinterpret_cast<FPT>(pBase3->vt[0])(pBase3);

    deleteCStructDerivedT(pDeriv, true);
    deleteCStructDerivedT(pBase3, true);

    cout << endl;
}

void runPolymorphismFuncs()
{
    polyMorphDemo1();
    cout << endl;

    polyMorphDemo2();
    cout << endl;

    polyMorphDemo3();
    cout << endl;

    runPolyImplDemo();
}

///////////////////////////////////////////////////////////////////////////////
struct S1
{
    int m_a;
    int getA() const { return m_a; }
    S1(int a) : m_a(a) { cout << "Constr: S1(" << m_a << ")" << endl; }
    ~S1() { cout << "Destr: ~S1()" << endl; }
};

void rawPtrs1()
{
    cout << "rawPtrs1(): before local block (1)" << endl;
    { // (1)
        S1 s1{1};
    }
    cout << "rawPtrs1(): after local block (1)" << endl;
    cout << endl;

    cout << "rawPtrs1(): before local block (2)" << endl;
    { // (2)
        S1 *pS1 = new S1(1);
        cout << "pS1->getA():" << pS1->getA()
             << ", (*pS1).getA():" << (*pS1).getA() << endl;
        delete pS1; // !
    }
    cout << "rawPtrs1(): after local block (2)" << endl;
    cout << endl;

    S1 *pS11{nullptr}; // S1 *pS11 = nullptr;
    cout << "rawPtrs1(): before local block (3)" << endl;
    { // (3)
        S1 *pS1 = new S1(1);
        pS11 = pS1; // !
    }
    cout << "rawPtrs1(): after local block (3)" << endl;
    cout << "pS11->getA():" << pS11->getA()
         << ", (*pS11).getA():" << (*pS11).getA() << endl;
    delete pS11;
}

void smartPtrs1()
{
    cout << "smartPtrs1(): before local block (1)" << endl;
    { // (1)
        unique_ptr<S1> uSP1{new S1(11)};
        cout << "smartPtrs1(): before local block (12)" << endl;
        {
//            unique_ptr<S1> uSP11(uSP1); // !!!
//            unique_ptr<S1> uSP12 = uSP1; // !!!
            unique_ptr<S1> uSP13(move(uSP1));
            cout << "uSP13->getA() = " << uSP13->getA() << endl;
            cout << "(*uSP13).getA() = " << (*uSP13).getA() << endl;
            cout << "uSP13.get()->getA() = " << uSP13.get()->getA() << endl;
            //cout << "uSP1.get()->getA() = " << uSP1.get()->getA() << endl;
        }
        cout << "smartPtrs1(): after local block (12)" << endl;
    }
    cout << "smartPtrs1(): after local block (1)" << endl;
}

void runSmartPointersFuncs()
{
    cout << "runSmartPointersFuncs()..." << endl;
    rawPtrs1();
    cout << endl;
    smartPtrs1();
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    runPolymorphismFuncs();
    runSmartPointersFuncs();
    return 0;
}

