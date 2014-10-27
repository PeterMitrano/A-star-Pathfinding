#include <stdio.h>

#define LIMIT 999999 /*size of integers array*/

int main(){
    int i,j,numbers[LIMIT],flags[LIMIT];

    /*fill the array with natural numbers*/
    for (i=0;i<LIMIT;i++){
        numbers[i]=i+2;
        flags[i]=1;
    }

    /*sieve the non-primes*/
    for (i=0;i<LIMIT;i++){
        if (flags[i]==1){
            for (j=2*numbers[i]-2;j<LIMIT;j+=numbers[i]){
                numbers[j]=(int) (numbers[j]*(1-1.0/((float) numbers[i])));
                flags[j]=0;
            }
            numbers[i]--;
        }
    }

    long sum=0;
    for (i=0;i<LIMIT;i++){
        sum+=numbers[i];
    }
    printf("sum:%lu\n",sum);

    return 0;
}