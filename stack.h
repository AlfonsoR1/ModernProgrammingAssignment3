/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on stack.h
************************************************* */

#ifndef STACK_H
#define STACK_H

#define STACKSIZE 10

class Stack {

public:
    /**********************
     * Constructors/Destructor
     **********************/
    Stack();  // constructor
    ~Stack();  // destructor

    /**********************
    Getters/Accessors
    ***********************/
    bool isEmpty();
    bool peek(int*);

    /**********************
    Setters/Mutators
    ***********************/
    int pop();
    bool push(int );

    /**********************
    Printing Methods
    ***********************/



private:
    /**********************
    Methods
    ***********************/



    /**********************
    Attributes
    ***********************/
    int stack;
    int top;
};

#endif //STACK_H

