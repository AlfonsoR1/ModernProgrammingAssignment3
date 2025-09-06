/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on
*           definition file, print_functions.cpp
************************************************* */

#include "functions.h"


void resetCounter(TestCounters& myCounters) {
    /* **************************
     * Resets all counters to zero.
     *
     * @param myCounters : myCounters is
     * reference to TestCounters struct
     * @exception none
     * @return none
     ****************************/

    myCounters.is_empty = 0;
    myCounters.peeked = 0;
    myCounters.popped = 0;
    myCounters.pushed = 0;
}

TestResult underFlowTests(Stack& stack,TestCounters& myCounters, int& value) {
    /* **************************
     * Runs underflow test on the stack.
     *
     * @param stack : stack is reference
     * to Stack
     * @param myCounters : myCounters is
     * reference to TestCounters struct
     * @param value : value is reference
     * to integer used for testing.
     *
     * @exception none
     * @return TestResult of the test pass or fail.
     ****************************/

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
    TestResult result = FAIL;
    if(myCounters.popped == 0 &&
       myCounters.peeked == 0 &&
       myCounters.pushed == round(STACKSIZE*MULTIPLIER) &&
       myCounters.is_empty == round(STACKSIZE*MULTIPLIER)) {
        result = PASS;
       }
    return result;
}

TestResult overFlowTests(Stack& stack,TestCounters& myCounters, int& value) {
    /* **************************
     * Runs overflow test on the stack.
     *
     * @param stack : stack is reference
     * to Stack
     * @param myCounters : myCounters is
     * reference to TestCounters struct
     * @param value : value is reference
     * to integer used for testing.
     *
     * @exception none
     * @return TestResult of the test pass or fail.
     ****************************/

    // reset counters for tests
    resetCounter(myCounters);
    // fill stack
    for (int i = 0; i <= STACKSIZE; i++) { // go one too far past STACKSIZE
    value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
    stack.push(value);
    }

    for (int i = 0; i < STACKSIZE*MULTIPLIER; i++) {

        if (stack.isEmpty()) {
        myCounters.is_empty++;
        } else {
        // should always decrement
        myCounters.is_empty--;
        }

        if(stack.peek(&value)){
        // should always increment
        myCounters.peeked++;
        } else {
        myCounters.peeked--;
        }

        try{
        // should always increment
        // stack is now not full
        value = stack.pop();
        myCounters.popped++;
        } catch(...){
        myCounters.popped--;
        }

        if (stack.push(i)){
        // should always increment
        // stack is now full again
        myCounters.pushed++;
        } else{
        myCounters.pushed--;
        }

        if (stack.push(i)){
        myCounters.pushed++;
        } else{
        // should always decrement
        myCounters.pushed--;
        }
    }

    // notice these numbers are logical
    // in overflow, we should expect these numbers
    TestResult result = FAIL;
    if(myCounters.popped == round(STACKSIZE*MULTIPLIER) &&
        myCounters.peeked == round(STACKSIZE*MULTIPLIER) &&
        myCounters.pushed == 0 &&
        myCounters.is_empty == round(STACKSIZE*MULTIPLIER)) {
        result = PASS;
    }
    return result;
}

void simpleUnderFlowTests(Stack& stack,TestCounters& myCounters, int& value) {
    /* **************************
     * Runs simple underflow test on the stack.
     *
     * @param stack : stack is reference
     * to Stack
     * @param myCounters : myCounters is
     * reference to TestCounters struct
     * @param value : value is reference
     * to integer used for testing.
     *
     * @exception none
     * @return none
     ****************************/

    printheader("simple underflow tests");
    // reset counters for tests
    resetCounter(myCounters);

    // emptying stack
    for (int i = 0; i < STACKSIZE+1; i++) {
    if(stack.isEmpty()){
    myCounters.is_empty++;
    } else {
    myCounters.is_empty--;
    }
    if(stack.peek(&value)){
    myCounters.peeked++;
    } else {
    myCounters.peeked--;
    }
    try {
    value = stack.pop();
    myCounters.popped++;
    } catch (...) {
    myCounters.popped--;
    }
    }

    if(myCounters.popped == STACKSIZE-1 &&
    myCounters.peeked == STACKSIZE-1 &&
    myCounters.pushed == 0 &&
    -myCounters.is_empty == STACKSIZE-1) {
    printpass();
    } else {
    printfailed();
    }
}

void midStackTests(Stack& stack,TestCounters& myCounters, int& value) {
    /* **************************
     * Runs mid-stack test on the stack.
     *
     * @param stack : stack is reference
     * to Stack
     * @param myCounters : myCounters is
     * reference to TestCounters struct
     * @param value : value is reference
     * to integer used for testing.
     *
     * @exception none
     * @return none
     ****************************/

    printheader("mid-stack tests");

    // reset counters for tests
    resetCounter(myCounters);

    // need a stack of reasonable size
    // to perform tests
    #if(STACKSIZE < 4)
        printskipped();
    return;
    #endif

    // fill stack half-way
    for (int i = 0; i < int(STACKSIZE / 2); i++) {
        // using positive and negative "big" numbers
        value = rand() % 2 ? rand() % MAX_INT / 2 + 1 : -(rand() % MAX_INT / 2 + 1);
        stack.push(value);
    }

    for (int i = 0; i < STACKSIZE * MULTIPLIER; i++) {
        if (stack.isEmpty()) {
            myCounters.is_empty++;
        } else {
            myCounters.is_empty--;
        }
        if (stack.peek(&value)) {
            myCounters.peeked++;
        } else {
            myCounters.peeked--;
        }
        try {
            value = stack.pop();
            myCounters.popped++;
        } catch (...) {
            myCounters.popped--;
        }
        // using positive and negative "big" numbers
        value = rand() % 2 ? rand() % MAX_INT / 2 + 1 : -(rand() % MAX_INT / 2 + 1);
        if (stack.push(value)) {
            myCounters.pushed++;
        } else {
            myCounters.pushed--;
        }
    }

    // notice these numbers are logical
    // in mid-stack, we should expect these numbers
    if (myCounters.popped == round(STACKSIZE * MULTIPLIER) &&
        myCounters.peeked == round(STACKSIZE * MULTIPLIER) &&
        myCounters.pushed == round(STACKSIZE * MULTIPLIER) &&
        -myCounters.is_empty == round(STACKSIZE * MULTIPLIER)) {
        printpass();
    } else {
        printfailed();
    }
    }

void randomTests(Stack& stack,TestCounters& myCounters, int& value) {
    /* **************************
     * Runs random crash test on the stack.
     * Checks push,pop,peek when stack is nearly empty.
     *
     * @param stack : stack is reference
     * to Stack
     * @param myCounters : myCounters is
     * reference to TestCounters struct
     * @param value : value is reference
     * to integer used for testing.
     *
     * @exception none
     * @return none
     ****************************/

    printheader("random testing");
    // clearing stack to start
    bool notEmpty = stack.isEmpty();
    while(notEmpty){
        stack.pop();
    }

    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< int(STACKSIZE / 2); i++) {
        value = rand() % MAX_INT + 1;
        stack.push(value);
    }

    // the following will test random operations. push() and pop()
    // are called twice as often as peek and isempty because they
    // change the stack and should be tested more rigorously.
    // the point of these tests are a "crash test." if it runs
    // and the code does not crash, we just assume success.
    // we don't check operations, we don't care now, we just want
    // to observe the code does not crash.
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < STACKSIZE*RANDOM_MULTIPLIER; i++) {
            if (choice == 1 || choice == 2) {
                value = (rand() % MAX_INT) + 1;
                stack.push(value);
            }
            if (choice == 3 || choice == 4) {
                // pop
                try{
                    value = stack.pop();
                } catch(...){
                    // do nothing because we don't
                    // care about this case now and we
                    // expect it to happen sometimes
                }
            }
            if (choice == 5) {
                // peek
                stack.peek(&value);
            }
            if (choice == 6) {
                // isempty
                stack.isEmpty();
            }
        }
    // if we made it here, no crash
    printpass();
    }