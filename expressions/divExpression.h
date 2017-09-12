//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_DIVEXPRESSION_H
#define EXPRESSIONS_DIVEXPRESSION_H

#include "expression.h"

class divExpression : public expression
{
public:
    divExpression(expression * numerator, expression * denominator);

    expression * diff() override;

    expression * copy() override;

    void print() override;

    ~divExpression() override;

private:
    expression * numerator;

    expression * denominator;

};

#endif //EXPRESSIONS_DIVEXPRESSION_H
