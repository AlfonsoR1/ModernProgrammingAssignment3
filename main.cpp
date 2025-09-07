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

    std::cout << "  underflow tests ==> ";
    TestResult result = underFlowTests(stack,myCounters,value);
        if (result == PASS) {
            std::cout << "passed" << std::endl;
        }else {
            std::cout << "failed" << std::endl;
        }

    std::cout << "  overflow tests ==> ";
    TestResult result2 = overFlowTests(stack,myCounters,value);
    if (result2 == PASS) {
        std::cout << "passed" << std::endl;
    }else {
        std::cout << "failed" << std::endl;
    }

    std::cout << "  simple underflow tests ==> ";
    TestResult result3 = simpleUnderFlowTests(stack,myCounters,value);
    if (result3 == PASS) {
        std::cout << "passed" << std::endl;
    }else {
        std::cout << "failed" << std::endl;
    }

    std::cout << "  mid-stack testing ==> ";
    TestResult result4 = midStackTests(stack,myCounters,value);
    if (result4 == PASS) {
        std::cout << "passed" << std::endl;
    }else if (result4 == FAIL) {
        std::cout << "failed" << std::endl;
    }else {
        std::cout << "skipped, stack too small" << std::endl;
    }

    std::cout << "  random testing ==> ";
    TestResult result5 = randomTests(stack,myCounters,value);
    if (result5 == PASS) {
        std::cout << "passed" << std::endl;
    }else {
        std::cout << "failed" << std::endl;
    }

    std::cout << "Testing complete." << std::endl;
   return 0;
}

