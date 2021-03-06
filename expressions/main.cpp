#include <iostream>
#include "expression.h"
#include "numberExpression.h"
#include "variableExpression.h"
#include "addExpression.h"
#include "subExpression.h"
#include "divExpression.h"

int main()
{
    // NOTE: Тут сложно разделить задания по оценкам, так что смотрите историю на GitHub, для разных версий.
    //       Это задания на четвёрку
    expression * c42 = new numberExpression(42);
    expression * x = new variableExpression('x');
    expression * c100 = new numberExpression(100);
    expression * sum = new addExpression(c42, x);
    expression * totalSum = new subExpression(sum, c100);
    expression * fraction = new divExpression(totalSum, x->copy());

    expression * diff = fraction->diff();
    std::cout << "Derivative of ((42 + x) - 100)/x is ";
    diff->print();
    std::cout << std::endl;

    // NOTE: нам нужно освободить только корневые элементы, они рекурсивно удалят все остальные, через деструкторы
    delete sum;
    delete diff;

    return 0;
}