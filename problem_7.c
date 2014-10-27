#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//What is the 10 001st prime number

int p7 (int argc, char** argv) {
    int len = 105000;
    int primes[len];
    for (int i = 0; i < len; i++) {
        primes[i] = i;
    }
    for (int i = 2; i < sqrt(len); i++) {
        for (int j = 0; j < len; j++) {
            if (primes[j] % i == 0 && primes[j] > i) {
                primes[j] = -1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (primes[i] > 0) {
            printf("%i %i %i\n", i, count, primes[i]);
            count++;
        }
    }
}
