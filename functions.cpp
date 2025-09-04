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
