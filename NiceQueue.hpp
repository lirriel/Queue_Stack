////////////////////////////////////////////////////////////////////////////////
// Module Name:  NiceQueue.h/cpp
// Author:       Iskhakova Lyaysan
// Version:      0.1.0
// Date:         14.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////


#include "NiceQueue.h"
#include <limits>

template <class T>
NiceQueue<T>::NiceQueue(size_t capacity):inStack(capacity), outStack(capacity)
{
    m_capacity = capacity;
}


template <class T>
size_t NiceQueue<T>::size() const
{
    return inStack.size() + outStack.size();
}


template <class T>
void NiceQueue<T>::enq(T newelement) throw (out_of_range)
{
    if (size() == m_capacity)
        throw out_of_range("Queue is full!");

    inStack.push(newelement);
}


template <class T>
T NiceQueue<T>::deq() throw (out_of_range)
{
    if (outStack.size() == 0)
        while (inStack.size() > 0)
            outStack.push(inStack.pop());

    return outStack.pop();
}


template <class T>
T NiceQueue<T>::getMinimum() throw (out_of_range)
{
    if (size() == 0)
        throw out_of_range("Queue is empty!");

    T min;

    if (inStack.size() == 0)
        min = outStack.getMinimum();

    if (inStack.size() != 0 && inStack.getMinimum() < min)
        min = inStack.getMinimum();

    return min;
}


