//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "addExpression.h"

addExpression::addExpression(expression * lhs, expression * rhs) : lhs(lhs), rhs(rhs)
{}

expression * addExpression::diff()
{
    // Производная суммы равна сумме производных
    return new addExpression(lhs->diff(), rhs->diff());
}

expression * addExpression::copy()
{
    return new addExpression(lhs->copy(), rhs->copy());
}

void addExpression::print()
{
    std::cout << "(";
    lhs->print();
    std::cout << " + ";
    rhs->print();
    std::cout << ")";
}

addExpression::~addExpression()
{
    delete lhs;
    delete rhs;
}
