//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_POWEXPRESSION_H
#define EXPRESSIONS_POWEXPRESSION_H

#include "expression.h"
#include "numberExpression.h"

class powExpression : public expression
{
public:
    powExpression(expression * base, numberExpression * power);

    expression * diff() override;

    expression * copy() override;

    void print() override;

    ~powExpression() override;

private:
    expression * base;

    numberExpression * power;
};

#endif //EXPRESSIONS_POWEXPRESSION_H
