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

int main(int argc, char** argv){
	int n;

	if (argc>1){
		n=atoi(argv[1]);
		
		int s,d;
		s=1;
		d=n/2;
		while (d%2==0) {
	        d/=2;
	        s++;
	    }
		
		//printf("%d-1 is 2^%d*%d\n",n,s,d);

		//if any are zero, it will return 0
		int isprime = isWitness(s,d,n,147);

		if (isprime){
			printf("%d is prime\n",n);	
		}
		else {
			printf("%d is sadly not prime\n",n);		
		}
	}

	return 0;
}