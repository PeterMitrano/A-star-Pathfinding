#include <stdio.h>

#define LIMIT 1000000 /*size of integers array*/
#define PRIMES 500000 /*size of primes array*/

int * seive(){
    int i,j,numbers[LIMIT];
    int static primes[PRIMES];

    /*fill the array with natural numbers*/
    for (i=0;i<LIMIT;i++){
        numbers[i]=i+2;
    }

    /*sieve the non-primes*/
    for (i=0;i<LIMIT;i++){
        if (numbers[i]!=-1){
            for (j=2*numbers[i]-2;j<LIMIT;j+=numbers[i])
                numbers[j]=-1;
        }
    }

    /*transfer the primes to their own array*/
    j = 0;
    for (i=0;i<LIMIT&&j<primes;i++)
        if (numbers[i]!=-1)
            primes[j++] = numbers[i];
    
    return primes;
}
