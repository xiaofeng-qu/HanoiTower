#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//Xiaofeng Qu xq6@zips.uakron.edu        //
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   // Constructor
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   MyStack(const MyStack &);

   //operator= overloading
   MyStack& operator=(const MyStack &);

   // Destructor
   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the statck is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};

// Constructor
template <class T>
MyStack<T>::MyStack(int theSize)
{
    stackSize = theSize;
    stackArray = new T[stackSize];
    numElem = -1;
}

// Copy constructor
template <class T>
MyStack<T>::MyStack(const MyStack &ms)
{
    stackSize = ms.stackSize; // copy the stack size
    stackArray = new T[stackSize]; // create the stack array
    numElem = ms.numElem; // copy the number of elements
    // copy all the elements from ms to this
    for (int i = 0; i <= numElem; i++)
    {
        stackArray[i] = ms.stackArray[i];
    }
}

// Overloading the = operator
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack &ms)
{
    // if assigned itself return this
    if (this == &ms) return *this;
    // if this has the the same size with the assigned stack
    if (stackSize == ms.stackSize)
    {
        numElem = ms.numElem; // copy the number of elements
        // copy the elements
        for (int i = 0; i <= numElem; i++)
        {
            stackArray[i] = ms.stackArray[i];
        }
    }
    // if this has different size with the assigned stack
    else
    {
        delete[] stackArray; // delete the array
        stackArray = nullptr; // assign nullptr to the array
        stackSize = ms.stackSize; // copy the stack size
        stackArray = new T[stackSize]; // create the stack array
        numElem = ms.numElem; // copy the number of elements
        // copy the elements
        for (int i = 0; i <= numElem; i++)
        {
            stackArray[i] = ms.stackArray[i];
        }
    }
    return *this;
}

// destructor
template <class T>
MyStack<T>::~MyStack()
{
    delete[] stackArray;
    stackArray = nullptr;
}

// push data into the stack
template <class T>
void MyStack<T>::push(T data)
{
    if (isFull())
    {
        throw "The stack is full.";
    }
    numElem++;
    stackArray[numElem] = data;
}

// pop the top number and return it
template <class T>
T MyStack<T>::pop()
{
    if (isEmpty())
    {
        throw "The stack is empty.";
    }
    else
    {
        T temp = stackArray[numElem];
        numElem--;
        return temp;
    }
}

// return the top of the stack
template <class T>
T MyStack<T>::top()
{
    return stackArray[numElem];
}

// return how many elements in the stack
template <class T>
int MyStack<T>::size() const
{
    return numElem + 1;
}

// check if the stack is empty
template <class T>
bool MyStack<T>::isEmpty() const
{
    return (numElem == -1);
}

// check if the stack is full
template <class T>
bool MyStack<T>::isFull() const
{
    return (numElem == stackSize - 1);
}
#endif
