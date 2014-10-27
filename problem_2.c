/* 
 * File:   main.c
 * Author: Peter
 *
 * Created on December 13, 2013, 1:56 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int p2(int argc, char** argv) {

    int fib0 = 0;
    int fib1 = 1;
    int fib2 = 0;
    int sum = 0;

    while (fib1 < 4000000) {
        fib2 = fib0 + fib1;
        fib0 = fib1;
        fib1 = fib2;
        if (fib2 % 2==0) {
            sum += fib2;
        }
        printf("%i %i\n", fib2,sum);
    }
}


