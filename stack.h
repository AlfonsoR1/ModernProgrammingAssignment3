/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices.
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

    bool isEmpty() { return top < 0; };
    bool peek(int*);
    int pop();
    bool push(int i);

    int top=0;

private:
    int stack[10];
};

#endif //STACK_INTSTACK_H

