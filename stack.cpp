/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on stack.cpp
************************************************* */

#include "stack.h"

Stack::Stack() {
    /* **************************
     * Constructor initializes the stack
     * and sets top to -1 to show the
     * stack is empty.
     *
     * @param none
     * @exception none
     * @return void
     * ****************************/
    this->top = -1;
}

Stack::~Stack() {
    /* **************************
     * Destructor (empty)
     * @param none
     * @exception none
     * @return void
     ****************************/
}

bool Stack::isEmpty() {
    /* **************************
     * Checks to see if the stack
     * is empty.
     *
     * @param none
     * @exception none
     * @return bool : true if the stack
     * is empty, false if not empty
     ****************************/
    return top < 0;
}

bool Stack::push(int i) {
    if (top < STACKSIZE - 1) {
        stack[++top] = i;
        return true;
    } else {
        return false;
    }
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



