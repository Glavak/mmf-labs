//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_ADDEXPRESSION_H
#define EXPRESSIONS_ADDEXPRESSION_H

#include "expression.h"

class addExpression : public expression
{
public:
    addExpression(expression * lhs, expression * rhs);

    expression * diff() override;

    expression * copy() override;

    void print() override;

    ~addExpression() override;

private:
    expression * lhs;

    expression * rhs;
};

#endif //EXPRESSIONS_ADDEXPRESSION_H
