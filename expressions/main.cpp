#include <iostream>
#include <memory>
#include <random>
#include <ctime>
#include "visitor.h"
#include "expression.h"

using namespace std;






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



    Printer p{};
    Evaluator ev{};
    add->accept(ev);
    add->accept(p);






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




    return 0;
}

