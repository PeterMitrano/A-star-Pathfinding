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
int p1(int argc, char** argv) {

    int count = 0;
    int i = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            count+=i;
        }
    }
    printf("%i",count);
}


