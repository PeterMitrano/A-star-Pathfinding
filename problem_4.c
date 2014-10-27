#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int dgt (int i)
{
    return (int) log10 ((double) i) + 1;
}

int isPalendrome(int n){
    int len = dgt(n);
    for (int i=len;i>0;i--){
        int digit1 = (n%(int)pow(10,i))/pow(10,i-1);
        int digit2 = (n%(int)pow(10,len-i+1))/pow(10,len-i);
        //printf(" %i %i \n",digit1,digit2);
        if (digit1!=digit2){
        return 0;
        }
    }
    return 1;
}


int p4(int argc, char** argv) {
    int max=0;
    for (int a=100;a<=1000;a++){
        for (int b=100;b<=1000;b++){
            int c=a*b;
            //printf("%i\n",c);
            if (isPalendrome(c)==1){
                printf("%i\n",c);
                if (c>max){
                    max=c;
                }
            }
        }
    }
    printf("%i\n",max);
}
