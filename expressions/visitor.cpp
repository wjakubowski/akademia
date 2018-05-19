#include "visitor.h"
#include "expression.h"

void Printer::visit(const Expression& e) const
{
    cout << e.toString();
}

void Evaluator::visit(const Expression& e) const
{
    cout << e.eval();
}
