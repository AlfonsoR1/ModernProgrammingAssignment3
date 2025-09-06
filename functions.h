/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on
*           declaration file, functions.h
**************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MULTIPLIER 1.5 // used to test overflow and underflow
#define NARROW .30 // percent of the stack for a narrow band
#define RANDOM_MULTIPLIER 10
#define CHOICES 6 // used to pick random operations
#define MAX_INT 100000 // random ints to push, 1 - 100000

#include <cmath>    // round

#include "stack.h"


enum TestResults{PASS, FAIL, SKIPPED};

struct  TestCounters {
    int is_empty;
    int peeked;
    int popped;
    int pushed;
};

void resetCounter(TestCounters& );

void underFlowTests(Stack& ,TestCounters& , int& );

void overFlowTests(Stack& ,TestCounters& , int& );

void simpleUnderFlowTests(Stack& ,TestCounters& , int& );

void midStackTests(Stack& ,TestCounters& , int& );

void randomTests(Stack& ,TestCounters& , int& );

#endif //FUNCTIONS_H