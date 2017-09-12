//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_SUBEXPRESSION_H
#define EXPRESSIONS_SUBEXPRESSION_H

#include "expression.h"

class subExpression : public expression
{
public:
    subExpression(expression * lhs, expression * rhs);

    expression * diff() override;

    expression * copy() override;

    void print() override;

    ~subExpression() override;

private:
    expression * lhs;

    expression * rhs;
};

#endif //EXPRESSIONS_SUBEXPRESSION_H
