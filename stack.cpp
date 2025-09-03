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

bool Stack::push(int value) {
    /* **************************
     * Pushes a value onto the stack
     *
     * @param int value. value to push
     * @exception none
     * @return bool : true if push is successful
     *  false if stack is full
     ****************************/
    if (top < STACKSIZE - 1) {
        stack[++top] = value;
        return true;
    } else {
        return false;
    }
}

int Stack::pop() {
    /* **************************
     * Removes and returns the top
     * value from the stack.
     *
     * @param none
     * @exception throws -1 if stack is empty
     * @return int value popped from
     *  the stack
     ****************************/
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



