//
// Created by Glavak on Sep 12, 17.
//

#ifndef EXPRESSIONS_EXPRESSION_H
#define EXPRESSIONS_EXPRESSION_H

class expression
{
public:
    // NOTE: virtual - значит что это виртуальная функция, т.е. её можно переопределить в классе наследнике.
    //       =0 - значит что у класса expression нет реализации этой функции. Классы с хотя бы одной такой функцией
    //       называются абстрактные и экземпляр их типа нельзя создать
    virtual expression * diff() = 0;

    // NOTE: не самый типичный паттерн для C++, но эта функция понадобится нам в mulExpression, и не только, чтобы
    //       корректно освобождать потом память и не порождать лищних ссылок
    virtual expression * copy() = 0;

    virtual void print() = 0;

    // NOTE: ОЧЕНЬ ВАЖНО: деструктор должен обязательно быть виртуальным. Это самый популярный вопрос на собеседованиях
    //       по C++. Если непонятно почему - лучше загуглите
    virtual ~expression() = default;
};

#endif //EXPRESSIONS_EXPRESSION_H
