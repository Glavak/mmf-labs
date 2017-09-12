//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_MULEXPRESSION_H
#define EXPRESSIONS_MULEXPRESSION_H

#include "expression.h"

class mulExpression: public expression
{
public:
    mulExpression(expression * lhs, expression * rhs);

    expression * diff() override;

    expression * copy() override;

    void print() override;

    ~mulExpression() override;

private:
    expression * lhs;

    expression * rhs;
};

#endif //EXPRESSIONS_MULEXPRESSION_H
