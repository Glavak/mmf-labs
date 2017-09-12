//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "mulExpression.h"
#include "addExpression.h"

mulExpression::mulExpression(expression * lhs, expression * rhs) : lhs(lhs), rhs(rhs)
{}

expression * mulExpression::diff()
{
    // Производная произведения.. а, вы и сами знаете
    expression * udashv = new mulExpression(lhs->diff(), rhs->copy());
    expression * uvdash = new mulExpression(lhs->copy(), rhs->diff());
    return new addExpression(udashv, uvdash);
}

expression * mulExpression::copy()
{
    return new mulExpression(lhs->copy(), rhs->copy());
}

void mulExpression::print()
{
    std::cout << "(";
    lhs->print();
    std::cout << " * ";
    rhs->print();
    std::cout << ")";
}

mulExpression::~mulExpression()
{
    delete lhs;
    delete rhs;
}
