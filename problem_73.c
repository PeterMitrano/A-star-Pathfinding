//problem_73.c
#include <stdio.h>

int gcd(int a, int b){
	if (b == 0){
		return a;
	}
	return gcd(b, a%b);
}

int main(int argv, char* argc){
	int n=0,d=0;
	long count=0;

	for (d=5;d<=12000;d++){
		for (n = d/3+1; n<=d/2; n++) {
			if (gcd(n,d)==1){
				count++;
			}
		}
	}

	printf("count:%lu\n",count);
	return 0;
}