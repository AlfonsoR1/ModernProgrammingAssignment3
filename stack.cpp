/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on stack.cpp
************************************************* */

#include "stack.h"

Stack::Stack() {
    this->top = -1;
    << "Top set." << ;
}

Stack::~Stack() {
     << "Stack destructor called." << ;
}

bool Stack::isEmpty() {
    return top < 0;
}

bool Stack::push(int i) {
    if (top < STACKSIZE - 1) {
        stack[++top] = i;
        return true;
    } else {
        return false;
    }
     << "Stack overflow, cannot push " << i << ;
}

int Stack::pop() {
    /* ****************************************
    Pop an item from the top of the stack,
    if there is one

    @param na : na

    @return (int) : top item on the stack
    
    @exception (int) : if underflow
    *********************************************/
    if (top >= 0) {
        return stack[top--];
    } else {
        throw -1;
    }
}

bool Stack::peek(int *ret) {
    bool peeked = false;
    if (top > -1) {
        *ret = stack[top];
        peeked = true;
    }
    return peeked;
}



