////////////////////////////////////////////////////////////////////////////////
// Module Name:  NiceStack.h/cpp
// Author:       Iskhakova Lyaysan
// Version:      0.1.0
// Date:         14.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "NiceStack.h"

template <class T>
NiceStack<T>::NiceStack(size_t capacity)
{
    m_capacity = capacity;
    iHead = 0;
    storage.reserve(capacity);
}


template <class T>
size_t NiceStack<T>::size() const
{
    return iHead;
}


template <class T>
NiceStack<T>::~NiceStack()
{
    vector<TypeElementStack>().swap(storage);
}


template <class T>
void NiceStack<T>::push(T newelement) throw (out_of_range)
{
    if (iHead == m_capacity)
        throw  std::out_of_range("Stack is full!");

    if (iHead == 0)
    {
        TypeElementStack typeElementStack(newelement, newelement);
        storage.push_back(typeElementStack);
        iHead++;
        return;
    }

    TypeElementStack temp = storage.at(iHead - 1);
    T min = newelement;

    if (min > temp.second)
        min = temp.second;

    TypeElementStack current(newelement, min);

    storage.push_back(current);

    iHead++;
}


template <class T>
T NiceStack<T>::pop() throw (out_of_range)
{
    if (iHead == 0)
        throw std::out_of_range("Stack is empty!");

    TypeElementStack value = storage.at(iHead - 1);

    iHead--;

    storage.erase(storage.begin() + iHead);

    return value.first;
}


template <class T>
T NiceStack<T>::getMinimum() throw (out_of_range)
{
    if (iHead == 0)
        throw std::out_of_range("Stack is empty!");

    TypeElementStack lastPair = storage.at(iHead - 1);

    return lastPair.second;
}