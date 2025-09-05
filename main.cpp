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

    printopening();
    underFlowTests(stack,myCounters,value);
    overFlowTests(stack,myCounters,value);
    simpleUnderFlowTests(stack,myCounters,value);

    /************************************************
    ******** MID-STACK TESTS ************************
    ************************************************
    // reset counters for tests
    is_empty = 0;
    peeked = 0;
    popped = 0;
    pushed = 0;

    // need a stack of reasonable size
    // to perform tests
    std::cout << "  mid-stack tests ==> ";
    if(STACKSIZE >= 4){
        
        // fill stack half-way
        for (int i = 0; i< int(STACKSIZE / 2); i++) {
            // using positive and negative "big" numbers
            value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
            stack.push(value);
        }
    
        for (int i = 0; i < STACKSIZE*MULTIPLIER; i++) {
            if(stack.isEmpty()){
                is_empty++;
            } else {
                is_empty--;
            }
            if(stack.peek(&value)){
                peeked++;
            } else {
                peeked--;
            }
            try {
                value = stack.pop();
                popped++;
            } catch (...) {
                popped--;
            }
            // using positive and negative "big" numbers
            value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
            if(stack.push(value)){
                pushed++;
            } else {
                pushed--;
            }
        }

        // notice these numbers are logical
        // in mid-stack, we should expect these numbers
        if(popped == round(STACKSIZE*MULTIPLIER) &&
           peeked == round(STACKSIZE*MULTIPLIER) &&
           pushed == round(STACKSIZE*MULTIPLIER) && 
           -is_empty == round(STACKSIZE*MULTIPLIER)) {
           std::cout << "pass" << std::endl;
        } else {
            std::cout << "failed" << std::endl;
        }

    } else{
        std::cout << "skipped, stack too small" << std::endl;
    }

    /************************************************
    ******** RANDOM TESTS ***************************
    ** essentially this is only a crash test ********
    *************************************************/
    
    std::cout << "  random testing ==> ";
    // clearing stack to start
    while(1){
        stack.pop();
        if(stack.isEmpty()) break;
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
        switch (choice) {
            case 1:
            case 2:
                // push
                value = (rand() % MAX_INT) + 1;
                stack.push(value);
                break;
            case 3:
            case 4:
                // pop
                try{
                    value = stack.pop();
                } catch(...){
                    // do nothing because we don't
                    // care about this case now and we
                    // expect it to happen sometimes
                }
                break;
            case 5:
                // peek
                stack.peek(&value);
                break;
            case 6:
                // isempty
                stack.isEmpty();
                break;
        }
        choice = rand() % CHOICES + 1;

    }
    // if we made it here, no crash
    std::cout << "pass" << std::endl;

   printclosing();
   return 0;
}

