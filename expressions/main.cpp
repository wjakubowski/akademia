#include <iostream>
#include <memory>
#include <random>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include "visitor.h"
#include "expression.h"

using namespace std;

vector<string> split(string str)
{
    string buf;
    stringstream ss(str);
    vector<string> tokens;
    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}

unique_ptr<Expression> polishNotationExpression(string str_expr)
{
    vector<string> parts = split(str_expr);
    int pos = 0;
    unique_ptr<Expression> tmp1, tmp2;

    while(pos < parts.size())
    {
        cout << parts[pos] << endl;
        if(parts[pos] == "*")
        {
            tmp1 = move(unique_ptr<Expression>{new Multiply(move(tmp1), move(tmp2))});
        }
        else if(parts[pos] == "+")
        {
            tmp1 = move(unique_ptr<Expression>{new Add(move(tmp1), move(tmp2))});
        }
        else
        {
            if(tmp1)
                tmp2 = move(unique_ptr<Expression>{new Literal(stod(parts[pos]))});
            else
                tmp1 = move(unique_ptr<Expression>{new Literal(stod(parts[pos]))});
        }
        ++pos;
    }
    return tmp1;
}


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

/*
double eval_expression(const Expression e)
{
    if(const Literal* lit = dynamic_cast<const Literal*>(e))
    {
        return lit->getValue();
    } else if(const Add add = dynamic_cast<const Add*>(e))
    {
        return eval_expression( add.left ) + eval_expression( add.right);
    } else if(const Multiply multiply = dynamic_cast<const Multiply*>(e))
    {
        return eval_expression( multiply.left ) * eval_expression( multiply.right);
    }
}/*

/*
void f(Rational r)
{

}*/

int main()
{
    srand(time(NULL));
    //cout << "Hello World!" << endl;

    //std::cout << "RELEASE MAIN FINISHED!" << std::endl;

    //Rational rat(1,2);
    //std::cout << rat << std::endl;

    unique_ptr<Expression> ul1 {new Literal(1)};
    unique_ptr<Expression> ul2 {new Literal(2)};
    unique_ptr<Expression> ul3 {new Literal(3)};

    //Expression * l1 = new Literal(1);
    //Expression * l2 = new Literal(2);






    //Expression * mmmm = new Multiply(move(ul1),move(ul2));


    unique_ptr<Expression> mult {new Multiply(move(ul1),move(ul2))};
    unique_ptr<Expression> add {new Add(move(mult),move(ul3))};

    cout << add->eval() << endl;
    cout << add->toString() << endl;



    Printer p{cout};
    Evaluator ev{};
    cout << endl;
    add->accept(ev);
    add->accept(p);
    cout << endl;






//    unique_ptr<Expression> p {new Literal(1)};
//    Expression * raw_ptr = p.release();
//    unique_ptr<Expression> p2 {raw_ptr};

//    unique_ptr<Expression> p3 {move(p2)};

//    int x = 9;
//    int * y = move(&x);
//    cout << "x: " << x << "y: " << *y << endl;
//    cout << "&x: " << &x << "&y: " << y << endl;

//    unique_ptr<Expression> rand_expr(move(randomExpression()));
//    cout << "random expresion: " << rand_expr->eval() << endl;
//    cout << "random expresion: " << rand_expr->toString() << endl;


    string reversePolishNotation = "2 3 + 7 *";

    unique_ptr<Expression> rpn{move(polishNotationExpression(reversePolishNotation))};

    cout << rpn->eval() << endl;
    cout << rpn->toString() << endl;


    return 0;
}

