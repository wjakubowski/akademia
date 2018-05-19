#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
//#include "expression.h"

using namespace std;

class Expression;

class Visitor
{
public:
    virtual void visit(const Expression & e) const = 0;
    virtual ~Visitor() = default;
};

class Printer : public Visitor
{
    ostream& os;
    void visit(const Expression& e) const override;

   public:
    Printer(ostream & os):os(os){}
};

class Evaluator : public Visitor
{
    void visit(const Expression& e) const override;
};

/*

class AltEvaluator : public Visitor
{
    double value;
public:
    void visit(const Literal& e)
    {
        value = e.eval();
    }
};*/

#endif // VISITOR_H
