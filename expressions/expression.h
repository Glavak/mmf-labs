//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_EXPRESSION_H
#define EXPRESSIONS_EXPRESSION_H

class expression
{
public:
    virtual expression * diff() = 0;

    virtual void print() = 0;

    // NOTE: ОЧЕНЬ ВАЖНО: деструктор должен обязательно быть виртуальным. Это самый популярный вопрос на собеседованиях
    //       по C++. Если непонятно почему - лучше загуглите
    virtual ~expression() = default;
};

#endif //EXPRESSIONS_EXPRESSION_H
