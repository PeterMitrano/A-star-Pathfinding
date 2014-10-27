#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int p3(int argc, char** argv) {

    unsigned long long N = 600851475143UL;
    printf("%llu\n", N);
    for (int i = 2; i < sqrt(N); i++) {
        while (N % i == 0) {
            N /= i;
            printf("%llu\n", N);
        }
    }
    printf("%llu\n", N);
}