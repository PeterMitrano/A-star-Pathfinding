#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int power(int a, int n, int mod)
{
    int power = a;
    int result = 1;
 
    while (n)
    {
        if (n & 1)
            result = (result * power) % mod;
        power = (power * power) % mod;
        n >>= 1;
    }
    return result;
}

int isWitness(int s, int d, int n, int a){
	int x = power(a,d,n);
	int y;
	while (s){
		y = (x * x) % n;
        if (y == 1 && x != 1 && x != n-1)
            return 0;
        x = y;
        s--;
	}
	 if (y != 1)
        return 0;
    return 1;
}

int isPrime(int n){
		int s,d;

		s=1;
		d=n/2;

		while (d%2==0) {
	        d/=2;
	        s++;
	    }

		return isWitness(s,d,n,2)&
			isWitness(s,d,n,7)&
			isWitness(s,d,n,61);
}