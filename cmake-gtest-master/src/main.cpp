#include <iostream>
#include <memory>
#include <random>
#include <ctime>
#include "rational.h"

using namespace std;

class Visitor;
class Literal;
class Add;
class Multiply;

class Visitor
{
public:
    virtual void visit(const Literal& e) const = 0;
    virtual void visit(const Add& e) const = 0;
    virtual void visit(const Multiply& e) const = 0;

    virtual ~Visitor() = default;
};

class Printer : public Visitor
{
    void visit(const Literal& e) const override
    {
        cout << e.toString();
    }
};

class Expression
{

public:
    virtual double eval() const = 0;
    virtual ~Expression() = 0;
    virtual string toString() const = 0;
    virtual void accept(Visitor& v) = 0;
};

inline Expression::~Expression() = default;

inline double Expression::eval() const{
    return 0;
}




class Literal : public Expression
{
public:
    double value;
    explicit Literal(double value): value(value){}
    double eval() const override;
    string toString() const
    {
        return to_string(value);
    }

    void accept(Visitor& v) const
    {
        v.visit(*this);
    }


};



double Literal::eval() const
{
    return value;
}

class BinaryOperator : public Expression
{
public:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;
    BinaryOperator(unique_ptr<Expression> left, unique_ptr<Expression> right): left(move(left)), right(move(right)), Expression()
    {

    }

};

class UnaryOperator : public Expression
{
    Expression * expt;
};

class Add : public BinaryOperator
{
public:
    Add(unique_ptr<Expression> left, unique_ptr<Expression> right): BinaryOperator(move(left),move(right)){}
    double eval() const override
    {
        return left->eval()+right->eval();
    }

    string toString() const
    {
        return "("+left->toString()+"+"+right->toString()+")";
    }

    void accept(Visitor& v) const
    {
        v.visit(*this);
    }
};

class Multiply : public BinaryOperator
{
public:
    Multiply(unique_ptr<Expression> left, unique_ptr<Expression> right): BinaryOperator(move(left),move(right)){}
    double eval() const override
    {
        return left->eval()*right->eval();
    }

    string toString() const
    {
        return "("+left->toString()+"*"+right->toString()+")";
    }

    void accept(Visitor& v) const
    {
        v.visit(*this);
    }
};



unique_ptr<Expression> randomExpression()
{
    switch(rand()%3)
    {
        case 0:
            return unique_ptr<Expression>{new Literal(rand()%10)};
        case 1:
        {
            unique_ptr<Expression> e1 {move(randomExpression())};
            unique_ptr<Expression> e2 {move(randomExpression())};
            return unique_ptr<Expression>{new Add(move(e1), move(e2))};
        }
        case 2:
        {
            unique_ptr<Expression> e3 {move(randomExpression())};
            unique_ptr<Expression> e4 {move(randomExpression())};
            return unique_ptr<Expression>{new Multiply(move(e3), move(e4))};
        }
    };
}


void f(Rational r)
{

}

int main()
{
    srand(time(NULL));
    //cout << "Hello World!" << endl;

    //std::cout << "RELEASE MAIN FINISHED!" << std::endl;

    //Rational rat(1,2);
    //std::cout << rat << std::endl;

    unique_ptr<Expression> ul1 {new Literal(1)};
    unique_ptr<Expression> ul2 {new Literal(2)};

    Expression * l1 = new Literal(1);
    Expression * l2 = new Literal(2);






    //Expression * mmmm = new Multiply(move(ul1),move(ul2));


    unique_ptr<Expression> mult {new Multiply(move(ul1),move(ul2))};
    //unique_ptr<Expression> add {new Add(move(ul1),move(ul2))};


   // Printer p{};
    //mult->accept(p);

    //cout << ul1->eval() << endl;
    //cout << add->eval() << endl;
    cout << mult->eval() << endl;
    cout << mult->toString() << endl;

    unique_ptr<Expression> p {new Literal(1)};
    Expression * raw_ptr = p.release();
    unique_ptr<Expression> p2 {raw_ptr};

    unique_ptr<Expression> p3 {move(p2)};

    int x = 9;
    int * y = move(&x);
    cout << "x: " << x << "y: " << *y << endl;
    cout << "&x: " << &x << "&y: " << y << endl;

    cout << "random expresion: " << randomExpression()->eval() << endl;
    cout << "random expresion: " << randomExpression()->toString() << endl;




    return 0;
}

