//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_VARIABLE_H
#define EXPRESSIONS_VARIABLE_H

#include "expression.h"

class variableExpression : public expression
{
public:
    explicit variableExpression(char name);

    expression * diff() override;

    expression * copy() override;

    void print() override;

private:
    // Да, char, математики ведь всегда обозначают переменные одной буквой
    char name;
};

#endif //EXPRESSIONS_VARIABLE_H
