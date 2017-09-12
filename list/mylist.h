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

    // Запрет использования конструктора копирования
    mylist(const mylist & other) = delete;

    // Запрет использования оператора присваивания
    mylist & operator=(const mylist & other) = delete;

    void push(const TElement & value);

    TElement pop();

    void push_back(const TElement & value);

    TElement pop_back();

    // Нам понадобится ещё одна структура/класс, чтобы хранить цепочку элементов списка
    struct listItem
    {
        TElement value;
        listItem * next;
    };

    class iterator
    {
    public:
        typedef std::forward_iterator_tag iterator_category; // не обязательно, но показывает что может наш итератор

        iterator(listItem * item);

        iterator(const iterator & other);

        iterator & operator=(const iterator & other) = delete;

        bool operator==(const iterator & other) const;

        bool operator!=(const iterator & other) const;

        iterator & operator++();

        TElement & operator*() const;

        TElement & operator->() const;

    private:

        listItem * current;
    };

    iterator begin();

    iterator end();

private:
    mylist<TElement>::listItem * head;
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
    listItem * item = new listItem();
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

    listItem * newHead = head->next;
    delete head;
    head = newHead;

    return value;
}

// Метод вставки элемента в конец
template<class TElement>
void mylist<TElement>::push_back(const TElement & value)
{
    listItem * newItem = new listItem();
    newItem->value = value;
    newItem->next = nullptr;

    if (head == nullptr)
    {
        head = newItem;
    }
    else
    {
        listItem * current = head;
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

    listItem * current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    TElement value = current->next->value;
    delete current->next;
    current->next = nullptr;

    return value;
}

// NOTE: ключевое слово typename здесь для того, чтобы показать компилятору, что mylist<TElement>::iterator это именно
//       вложенный класс, а не член/поле класса
template<class TElement>
typename mylist<TElement>::iterator mylist<TElement>::begin()
{
    // Вызываем конструктор mylist<TElement>::iterator(listItem<TElement> * item)
    return mylist<TElement>::iterator(head);
}

template<class TElement>
typename mylist<TElement>::iterator mylist<TElement>::end()
{
    return mylist<TElement>::iterator(nullptr);
}

template<class TElement>
mylist<TElement>::iterator::iterator(listItem * item)
{
    current = item;
}

template<class TElement>
mylist<TElement>::iterator::iterator(const mylist<TElement>::iterator & other)
{
    current = other.current;
}

template<class TElement>
bool mylist<TElement>::iterator::operator==(const mylist<TElement>::iterator & other) const
{
    return current == other.current;
}

template<class TElement>
bool mylist<TElement>::iterator::operator!=(const mylist<TElement>::iterator & other) const
{
    return current != other.current;
}

// Оператор перехода к следующему элементу списка
template<class TElement>
typename mylist<TElement>::iterator & mylist<TElement>::iterator::operator++()
{
    current = current->next;

    return *this;
}

// Операторы получения элемента, на который сейчас указывает итератор
template<class TElement>
TElement & mylist<TElement>::iterator::operator*() const
{
    return current->value;
}

template<class TElement>
TElement & mylist<TElement>::iterator::operator->() const
{
    return current->value;
}

#endif //LIST_MYLIST_H
