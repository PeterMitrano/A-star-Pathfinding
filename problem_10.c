#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//sum of all the primes below two million.

int main (int argc, char** argv) {
    int len = 400000;
    int primes[len];
//    for (int i = 0; i < len; i++) {
//        primes[i] = i;
//    }
//    for (int i = 2; i < sqrt(len); i++) {
//        for (int j = 0; j < len; j++) {
//            if (primes[j] % i == 0 && primes[j] > i) {
//                primes[j] = -1;
//            }
//        }
//    }
    int sum=0;
//    for (int i = 0; i < len; i++) {
//        if (primes[i] > 0) {
//            sum+=primes[i];
//        }
//    }
    printf("%i",sum);
}

