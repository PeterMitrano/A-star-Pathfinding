//Find the difference between the sum of 
//the squares of the first one hundred natural numbers 
//and the square of the sum.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int p6 (int agrc, char** argv) {
    int sumOfSquares = 0, squareOfSums = 0;
    for (int i = 1; i <= 100; i++) {
        sumOfSquares += i*i;
        squareOfSums += i;
    }
    squareOfSums *= squareOfSums;
    printf("%i %i\n", sumOfSquares, squareOfSums);
    printf("%i",sumOfSquares-squareOfSums); 

}

