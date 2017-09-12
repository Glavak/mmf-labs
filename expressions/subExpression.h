//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_SUBEXPRESSION_H
#define EXPRESSIONS_SUBEXPRESSION_H

#include "expression.h"

class subExpression : public expression
{
public:
    subExpression(expression * rhs, expression * lhs);

    expression * diff() override;

    void print() override;

    ~subExpression() override;

private:
    expression * rhs;

    expression * lhs;
};

#endif //EXPRESSIONS_SUBEXPRESSION_H
