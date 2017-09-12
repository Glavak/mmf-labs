//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "subExpression.h"

subExpression::subExpression(expression * rhs, expression * lhs) : rhs(rhs), lhs(lhs)
{}

expression * subExpression::diff()
{
    // Производная разности равна разности производных
    return new subExpression(rhs->diff(), lhs->diff());
}

void subExpression::print()
{
    rhs->print();
    std::cout << " - ";
    lhs->print();
}

subExpression::~subExpression()
{
    delete rhs;
    delete lhs;
}
