//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "numberExpression.h"

numberExpression::numberExpression(double value) : value(value)
{}

expression * numberExpression::diff()
{
    // Производная константы равна нулю
    return new numberExpression(0);
}

expression * numberExpression::copy()
{
    return new numberExpression(value);
}

void numberExpression::print()
{
    std::cout << value;
}
