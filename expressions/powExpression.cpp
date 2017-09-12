//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "powExpression.h"

powExpression::powExpression(expression * base, numberExpression * power) : base(base), power(power)
{}

expression * powExpression::diff()
{
    return nullptr;
}

expression * powExpression::copy()
{
    return new powExpression(base, power);
}

void powExpression::print()
{
    base->print();
    std::cout << "^";
    power->print();
}

powExpression::~powExpression()
{
    delete base;
    delete power;
}
