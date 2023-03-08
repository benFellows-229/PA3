/*
Ben Fellows
002369768
bfellows@chapman.edu
CPSC-350-02
CPSC350 PA3
MonoStack.h
A cpp file containing a the implementation of a Templated Monotonic stack, which has all of the normal functions of a  templated stack
accept the push function allows only for it to be increasing or decreasing, there is an additional constructor 
which takes in i or d corresponding to the orientation of the stack.
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <cstdlib>
#include <iostream>
#include <array>
using namespace std;
template <typename T>
class MonoStack
{
public:
    MonoStack();
    MonoStack(int size);
    MonoStack(int size, char o);
    ~MonoStack();
    int size();
    bool isEmpty();
    void push(T c);
    T pop();
    T peek();

private:
    T *stackArr;
    int count;
    int max;
    int top;
    char direction;
    bool isFull();
};
template <typename T>
MonoStack<T>::MonoStack()
{
    top = -1;
    count = 0;
    max = 0;
    direction = 'd';
    stackArr = NULL;
}
template <typename T>
MonoStack<T>::MonoStack(int iSize)
{
    top = -1;
    count = 0;
    max = iSize;
    direction = 'd';
    stackArr = new T[max];
}
template <typename T>
MonoStack<T>::MonoStack(int iSize, char o)
{
    top = -1;
    count = 0;
    max = iSize;
    direction = o;
    stackArr = new T[max];
}
template <typename T>
MonoStack<T>::~MonoStack()
{
    delete[] stackArr;
}
template <typename T>
int MonoStack<T>::size()
{
    return count;
}
template <typename T>
bool MonoStack<T>::isEmpty()
{
    return (count == 0);
}
template <typename T>
bool MonoStack<T>::isFull()
{
    return (count == max);
}
template <typename T>
void MonoStack<T>::push(T c)
{
    if (direction == 'd')
    {
        if (isFull())
        {
            T *temp = new T[2 * max];
            for (int i = 0; i < max; ++i)
            {
                temp[i] = stackArr[i];
            }
        }
        //Checks if the element being pushed is greater than the top and pops items until it is not.
        while (!isEmpty() && stackArr[top] < c)
        {
            MonoStack::pop();
        }
        max *= 2;
        stackArr[++top] = c;
        ++count;
    }
    else
    {
        if (isFull())
        {
            T *temp = new T[2 * max];
            for (int i = 0; i < max; ++i)
            {
                temp[i] = stackArr[i];
            }
        }
        //Checks if the element being pushed is less than the top and pops items until it is not.
        while (!isEmpty() && stackArr[top] > c)
        {
            MonoStack::pop();
        }
        max *= 2;
        stackArr[++top] = c;
        ++count;
    }
}
template <typename T>
T MonoStack<T>::pop()
{
    --count;
    return stackArr[top--];
}
template <typename T>
T MonoStack<T>::peek()
{
    return stackArr[top];
}
#endif