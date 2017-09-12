//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "variableExpression.h"
#include "numberExpression.h"

variableExpression::variableExpression(char name) : name(name)
{}

expression * variableExpression::diff()
{
    // Производная переменной равна единице (будем считать что это та самая переменная, а остальные - константы)
    return new numberExpression(1);
}

void variableExpression::print()
{
    std::cout << name;
}
