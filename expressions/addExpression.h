//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_ADDEXPRESSION_H
#define EXPRESSIONS_ADDEXPRESSION_H

#include "expression.h"

class addExpression : public expression
{
public:
    addExpression(expression * rhs, expression * lhs);

    expression * diff() override;

    void print() override;

    ~addExpression() override;

private:
    expression * rhs;

    expression * lhs;
};

#endif //EXPRESSIONS_ADDEXPRESSION_H
