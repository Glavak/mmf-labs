//
// Created by Glavak on Sep 11, 17.
//

#ifndef LIST_MYLIST_H
#define LIST_MYLIST_H

template<class TElement>
class mylist
{
public:
    mylist();

    ~mylist();

    void push(TElement value);

    TElement pop();

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
void mylist<TElement>::push(TElement value)
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

#endif //LIST_MYLIST_H
