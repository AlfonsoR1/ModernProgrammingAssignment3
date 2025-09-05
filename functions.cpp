/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on
*           definition file, print_functions.cpp
************************************************* */

#include "functions.h"


void resetCounter(TestCounters& myCounters) {
    myCounters.is_empty = 0;
    myCounters.peeked = 0;
    myCounters.popped = 0;
    myCounters.pushed = 0;
}

void underFlowTests(Stack& stack,TestCounters& myCounters, int& value) {
    /************************************************
    ******* UNDERFLOW TESTS *************************
    ************************************************/

    printheader("underflow tests");

    for (int i = 0; i < STACKSIZE*MULTIPLIER; i++) {

        if (stack.isEmpty()) myCounters.is_empty++;
        else myCounters.is_empty--;

        if(stack.peek(&value)) myCounters.peeked++;
        else myCounters.peeked--;

        try{
            value = stack.pop();
            myCounters.popped++;
        } catch(...){
            // should always decrement
            myCounters.popped--;
        }

        if (stack.push(i)){
            // should always increment
            myCounters.pushed++;
            if(stack.peek(&value)){
                // should always increment
                myCounters.peeked++;
            } else {
                myCounters.peeked--;
            }
            try{ // returns to empty
                // should always increment
                value = stack.pop();
                myCounters.popped++;
            } catch(...){
                myCounters.popped--;
            }
        } else{
            myCounters.pushed--;
        }
    }

    // notice these numbers are logical
    // in underflow, we should expect these numbers
    if(myCounters.popped == 0 &&
       myCounters.peeked == 0 &&
       myCounters.pushed == round(STACKSIZE*MULTIPLIER) &&
       myCounters.is_empty == round(STACKSIZE*MULTIPLIER)) {
        printpass();
       } else {
           printfailed();
       }
}

void overFlowTests(Stack& stack,TestCounters& myCounters, int& value) {
    /************************************************
    ******* OVERFLOW TESTS **************************
    ************************************************/

    printheader("overflow tests");

    // reset counters for tests
    resetCounter(myCounters);
    // fill stack
    for (int i = 0; i <= STACKSIZE; i++) { // go one too far past STACKSIZE
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
    printpass();
    } else {
    printfailed();
    }
}