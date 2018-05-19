#include <iostream>
#include "example.hpp"
#include "rational.hpp"
#include <memory>

using namespace std;


class Literal;
class Add;
class Mult;

class Visitor {
public:
    virtual void visit(const Literal& e) = 0;
    virtual void visit(const Add& e) = 0;
    virtual void visit(const Mult& e) = 0;
    virtual ~Visitor() = default;
};


class Expression {
public:
    virtual ~Expression() = 0;
    virtual double eval() const = 0;
    virtual void accept(Visitor& v) const = 0;
};

inline Expression::~Expression() = default;

inline double Expression::eval() const {
    return 0;
}

class Literal : public Expression {
    double val;
public:
    explicit Literal(double val): val{val} { }

    double eval() const override {
        return val;
    }
    void accept(Visitor& v) const {
        v.visit(*this);
    }
};

class BinaryOp : public Expression {
protected:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
public:
    BinaryOp(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left{std::move(left)}, right{std::move(right)} { }
    Expression& getLeft() const { return *left; }
    Expression& getRight() const { return *right; }
};

class Add : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double eval() const override {
        return left->eval() + right->eval();
    }
    void accept(Visitor& v) const {
        v.visit(*this);
    }
};

class Mult : public BinaryOp {
public:
    using BinaryOp::BinaryOp;

    double eval() const override {
        return left->eval() * right->eval();
    }
    void accept(Visitor& v) const {
        v.visit(*this);
    }
};

class Printer : public Visitor {
public:
    void visit(const Literal& e) override {
        std::cout << e.eval();
    }
    void visit(const Add& e) override {
        e.getLeft().accept(*this);
        std::cout << " + ";
        e.getRight().accept(*this);
    }
    void visit(const Mult& e) override {

    }


};




int main()
{
    std::unique_ptr<Expression> l1{ new Literal{5} };
    std::unique_ptr<Expression> l2{ new Literal{3} };
    std::unique_ptr<Expression> add{ new Add{std::move(l1), std::move(l2)} };
    Printer p{};
    add->accept(p);

}

