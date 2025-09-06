/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on main.cpp
************************************************* */

#include "main.h"

int main() {


    //Test program for testing the stack.

    // seeds the rand() function
    // call only ONCE
    srand(time(NULL));

    // create stack
    // make only one stack for testing
    Stack stack;

    // generic int used for testing
    int value;

    // counters for tests
    TestCounters myCounters{};

    std::cout << "Beginning tests..." << std::endl;

    underFlowTests(stack,myCounters,value);
    overFlowTests(stack,myCounters,value);
    simpleUnderFlowTests(stack,myCounters,value);
    midStackTests(stack,myCounters,value);
    randomTests(stack,myCounters,value);

    std::cout << "Testing complete." << std::endl;
   return 0;
}

