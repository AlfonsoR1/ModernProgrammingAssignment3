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

void underFlowTests(Stack& stack) {
    /************************************************
    ******* UNDERFLOW TESTS *************************
    ************************************************/

    printheader("underflow tests");

    for (int i = 0; i < STACKSIZE*MULTIPLIER; i++) {

        if (stack.isEmpty()) is_empty++;
        else is_empty--;

        if(stack.peek(&value)) peeked++;
        else peeked--;

        try{
            value = stack.pop();
            popped++;
        } catch(...){
            // should always decrement
            popped--;
        }

        if (stack.push(i)){
            // should always increment
            pushed++;
            if(stack.peek(&value)){
                // should always increment
                peeked++;
            } else {
                peeked--;
            }
            try{ // returns to empty
                // should always increment
                value = stack.pop();
                popped++;
            } catch(...){
                popped--;
            }
        } else{
            pushed--;
        }
    }

    // notice these numbers are logical
    // in underflow, we should expect these numbers
    if(popped == 0 &&
       peeked == 0 &&
       pushed == round(STACKSIZE*MULTIPLIER) &&
       is_empty == round(STACKSIZE*MULTIPLIER)) {
        printpass();
       } else {
           printfailed();
       }
}
