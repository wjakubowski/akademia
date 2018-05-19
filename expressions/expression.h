#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <memory>
#include <string>
#include "visitor.h"

using namespace std;

class Expression
{
public:
    virtual double eval() const = 0;
    virtual ~Expression() = 0;
    virtual string toString() const = 0;
    void accept(Visitor& v) const;
};

inline Expression::~Expression() = default;

class Literal : public Expression
{
public:
    double value;
    explicit Literal(double value): value(value){}
    double eval() const override;
    string toString() const;
    double getValue() const
    {
        return value;
    }
};

class BinaryOperator : public Expression
{
public:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;
    BinaryOperator(unique_ptr<Expression> left, unique_ptr<Expression> right)
        :left(move(left)), right(move(right)), Expression(){}

};

class UnaryOperator : public Expression
{
    Expression * expt;
};

class Add : public BinaryOperator
{
public:
    Add(unique_ptr<Expression> left, unique_ptr<Expression> right)
        :BinaryOperator(move(left),move(right)){}
    double eval() const override;
    string toString() const override;
};

class Multiply : public BinaryOperator
{
public:
    Multiply(unique_ptr<Expression> left, unique_ptr<Expression> right)
        :BinaryOperator(move(left),move(right)){}
    double eval() const override;
    string toString() const override;
};

/*ostream& operator << (ostream& os, const Expression & e)
{

}*/


#endif // EXPRESSION_H
