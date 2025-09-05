/* *************************************************
*  Name: Alfonso Rocha
*  Assignment: Assignment 3: Best Practices
*  Purpose: A demonstration of a simple stack ADT and finding
*           all violations of best practices on
*           definition file, print_functions.cpp
************************************************* */

#include "print_functions.h"

void printopening() {
    /* *************************************************
    * Prints the opening message to indicate the start
    * of the testing process.
    *
    * @param none
    * @return none
    * @exception none
    * ************************************************* */

    std::cout << "Beginning tests..." << std::endl;
}

void printclosing() {
    /* *************************************************
    * Prints the closing message to indicate the end
    * of the testing process.
    *
    * @param none
    * @return none
    * @exception none
    * ************************************************* */

    std::cout << "Testing complete." << std::endl;
}

void printpass() {
    /* *************************************************
    * Prints pass message to indicate the passing
    * of the testing process.
    *
    * @param none
    * @return none
    * @exception none
    * ************************************************* */

    std::cout << "pass" << std::endl;
}

void printfailed() {
    /* *************************************************
    * Prints failed message to indicate the failure
    * of the testing process.
    *
    * @param none
    * @return none
    * @exception none
    * ************************************************* */

    std::cout << "failed" << std::endl;
}

void printskipped() {
    /* *************************************************
    * Prints failed message to indicate the failure
    * of the testing process.
    *
    * @param none
    * @return none
    * @exception none
    * ************************************************* */

    std::cout << "skipped, stack too small" << std::endl;
}

void printheader(const std::string& testName) {
    /* *************************************************
    * Prints a header for the test section.
    *
    * @param testName. the name of the test section to display
    * @return none
    * @exception none
    * ************************************************* */
    std::cout << "  " << testName<< " ==> ";
}