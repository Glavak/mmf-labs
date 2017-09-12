//
// Created by Glavak on Sep 12, 17.
//

#include <iostream>
#include "divExpression.h"
#include "mulExpression.h"
#include "addExpression.h"
#include "powExpression.h"

divExpression::divExpression(expression * numerator, expression * denominator) : numerator(numerator), denominator(denominator)
{}

expression * divExpression::diff()
{
    // Тут тоже всё просто расписанно по формуле производной частного
    expression * udashv = new mulExpression(numerator->diff(), denominator->copy());
    expression * uvdash = new mulExpression(numerator->copy(), denominator->diff());
    expression * diffNum = new addExpression(udashv, uvdash);
    expression * diffDenom = new powExpression(denominator->copy(), new numberExpression(2));
    return new divExpression(diffNum, diffDenom);
}

expression * divExpression::copy()
{
    return new divExpression(numerator->copy(), denominator->copy());
}

void divExpression::print()
{
    std::cout << "(";
    numerator->print();
    std::cout << " / ";
    denominator->print();
    std::cout << ")";
}

divExpression::~divExpression()
{
    delete numerator;
    delete denominator;
}
