//
// Created by Glavak on Sep 11, 17.
//

#ifndef LIST_MYLIST_H
#define LIST_MYLIST_H

#include <usp10.h>

template<class TElement>
class mylist
{
public:
    mylist();

    ~mylist();

    // Запрет использования конструктора копирования
    mylist(const mylist & other) = delete;

    // Запрет использования оператора присваивания
    mylist & operator=(const mylist & other) = delete;

    void push(const TElement & value);

    TElement pop();

    void push_back(const TElement & value);

    TElement pop_back();

private:
    // Нам понадобится ещё одна структура/класс, чтобы хранить цепочку элементов списка
    template<class TValue>
    struct listItem
    {
        TValue value;
        listItem * next;
    };

    listItem<TElement> * head;
};

// NOTE: так уж вышло, что если класс - шаблонный, то все его потроха должны находиться в .h файле, и никак иначе. На
//       это конечно есть очень важные архитектурные причины, но мораль одна - дизайн самого C++ не то чтобы прекрасен,
//       и не надо так делать языки программирования

// Конструктор по умолчанию
template<class TElement>
mylist<TElement>::mylist()
{
    head = nullptr;
}

// Деструктор
template<class TElement>
mylist<TElement>::~mylist()
{
    while (head != nullptr)
    {
        pop();
    }
}

// Метод вставки элемента в начало
template<class TElement>
void mylist<TElement>::push(const TElement & value)
{
    listItem<TElement> * item = new listItem<TElement>();
    item->value = value;
    item->next = head;
    head = item;
}

// Метод удаления (и получения) элемента из начала
template<class TElement>
TElement mylist<TElement>::pop()
{
    if (head == nullptr)
    {
        // Бросаем ошибку при пустом списке
        throw;
    }

    TElement value = head->value;

    listItem<TElement> * newHead = head->next;
    delete head;
    head = newHead;

    return value;
}

// Метод вставки элемента в конец
template<class TElement>
void mylist<TElement>::push_back(const TElement & value)
{
    listItem<TElement> * newItem = new listItem<TElement>();
    newItem->value = value;
    newItem->next = nullptr;

    if (head == nullptr)
    {
        head = newItem;
    }
    else
    {
        listItem<TElement> * current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newItem;
    }
}

// Метод удаления (и получения) элемента с конца
template<class TElement>
TElement mylist<TElement>::pop_back()
{
    if (head == nullptr)
    {
        // Бросаем ошибку при пустом списке
        throw;
    }

    if (head->next == nullptr)
    {
        // Если один элемент - то тоже самое что и удалить из начала
        return pop();
    }

    listItem<TElement> * current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    TElement value = current->next->value;
    delete current->next;
    current->next = nullptr;

    return value;
}

#endif //LIST_MYLIST_H
