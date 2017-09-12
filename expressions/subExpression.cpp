//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "subExpression.h"

subExpression::subExpression(expression * lhs, expression * rhs) : lhs(lhs), rhs(rhs)
{}

expression * subExpression::diff()
{
    // Производная разности равна разности производных
    return new subExpression(lhs->diff(), rhs->diff());
}

expression * subExpression::copy()
{
    return new subExpression(lhs->copy(), rhs->copy());
}

void subExpression::print()
{
    std::cout << "(";
    lhs->print();
    std::cout << " - ";
    rhs->print();
    std::cout << ")";
}

subExpression::~subExpression()
{
    delete lhs;
    delete rhs;
}
