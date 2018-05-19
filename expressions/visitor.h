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
    void visit(const Expression& e) const override;
};

class Evaluator : public Visitor
{
    void visit(const Expression& e) const override;
};

#endif // VISITOR_H
