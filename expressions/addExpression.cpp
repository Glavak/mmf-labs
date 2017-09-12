//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "addExpression.h"

addExpression::addExpression(expression * rhs, expression * lhs) : rhs(rhs), lhs(lhs)
{}

expression * addExpression::diff()
{
    // Производная суммы равна сумме производных
    return new addExpression(rhs->diff(), lhs->diff());
}

void addExpression::print()
{
    std::cout << "(";
    rhs->print();
    std::cout << " + ";
    lhs->print();
    std::cout << ")";
}

addExpression::~addExpression()
{
    delete rhs;
    delete lhs;
}
