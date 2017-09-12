//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_NUMBER_H
#define EXPRESSIONS_NUMBER_H


#include "expression.h"

class numberExpression : public expression
{
public:
    explicit numberExpression(double value);

    expression * diff() override;

    expression * copy() override;

    void print() override;

private:
    double value;
};


#endif //EXPRESSIONS_NUMBER_H
