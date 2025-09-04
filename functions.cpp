/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on
*           definition file, print_functions.cpp
************************************************* */

#include "functions.h"


void resetCounter(testCounters& counters) {
    counters.is_empty = 0;
    counters.peeked = 0;
    counters.popped = 0;
    counters.pushed = 0;
}

void underFlowTests(Stack& stack,testCounters& counters, int& value) {
    /************************************************
    ******* UNDERFLOW TESTS *************************
    ************************************************/

    printheader("underflow tests");

    for (int i = 0; i < STACKSIZE*MULTIPLIER; i++) {

        if (stack.isEmpty()) counters.is_empty++;
        else counters.is_empty--;

        if(stack.peek(&value)) counters.peeked++;
        else counters.peeked--;

        try{
            value = stack.pop();
            counters.popped++;
        } catch(...){
            // should always decrement
            counters.popped--;
        }

        if (stack.push(i)){
            // should always increment
            counters.pushed++;
            if(stack.peek(&value)){
                // should always increment
                counters.peeked++;
            } else {
                counters.peeked--;
            }
            try{ // returns to empty
                // should always increment
                value = stack.pop();
                counters.popped++;
            } catch(...){
                counters.popped--;
            }
        } else{
            counters.pushed--;
        }
    }

    // notice these numbers are logical
    // in underflow, we should expect these numbers
    if(counters.popped == 0 &&
       counters.peeked == 0 &&
       counters.pushed == round(STACKSIZE*MULTIPLIER) &&
       counters.is_empty == round(STACKSIZE*MULTIPLIER)) {
        printpass();
       } else {
           printfailed();
       }
}

void overFlowTests(Stack& stack,testCounters& counters, int& value) {
    /************************************************
    ******* OVERFLOW TESTS **************************
    ************************************************/

    std::cout << "  overflow tests ==> ";

    // reset counters for tests
    is_empty = 0;
    peeked = 0;
    popped = 0;
    pushed = 0;
    // fill stack
    for (int i = 0; i <= 10; i++) { // go one too far past STACKSIZE
    value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
    stack.push(value);
    }

    int i = 0;
    int stop = STACKSIZE*MULTIPLIER;
    while(i < stop) {

    if (stack.isEmpty()) {
    is_empty++;
    } else {
    // should always decrement
    is_empty--;
    }

    if(stack.peek(&value)){
    // should always increment
    peeked++;
    } else {
    peeked--;
    }

    try{
    // should always increment
    // stack is now not full
    value = stack.pop();
    popped++;
    } catch(...){
    popped--;
    }

    if (stack.push(i)){
    // should always increment
    // stack is now full again
    pushed++;
    } else{
    pushed--;
    }

    if (stack.push(i)){
    pushed++;
    } else{
    // should always decrement
    pushed--;
    }
    i++;
    if (i>stop) break;
    }

    // notice these numbers are logical
    // in overflow, we should expect these numbers
    if(popped == round(STACKSIZE*MULTIPLIER) &&
    peeked == round(STACKSIZE*MULTIPLIER) &&
    pushed == 0 &&
    -is_empty == round(STACKSIZE*MULTIPLIER)) {
    std::cout << "pass" << std::endl;
    } else {
    std::cout << "failed" << std::endl;
    }
}