#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

int** primes;

int seive(int n){
	
	primes = malloc(sizeof(int*)*n);
	
	int i,j;

	for (i=0;i<n;i++){
		primes[i]=malloc(sizeof(int)*n);
		primes[i][0]=1;
	}

	primes[0][0]=-1;
	primes[1][0]=-1;
	for (i=2;i<n;i++){
		if (primes[i][0]!=-1){
			//check if omniprime
			for (j=3;j<i;j+=2){
				int dI=(int)(log10(i))+1;
				int dJ=(int)(log10(j))+1;
				int ij = pow(10,dJ)*i+j;
				int ji = pow(10,dI)*j+i;
				primes[i][j]=isPrime(ij);
				primes[j][i]=isPrime(ji);
			}

			//cross off multiples
			for (j=2;j*i<n;j++){
				primes[j*i][0]=-1;
			}
		}		
	}
	return 0;
}

int omniprime(int a, int b){
	return primes[a][b] * primes[b][a];
}

int main(int argc, char** argv){
	int pcount,i,j,k,l,m,N=30000;

	seive(N);

	for (i=3;i<N;i+=2){
		if (primes[i][0]!=-1){
			for (j=i+2;j<N;j+=2){
				if (omniprime(i,j)){
					for (k=j+2;k<N;k+=2){
						if (omniprime(i,k) &&
							omniprime(j,k)){
							for (l=k+2;l<N;l+=2){
								if (omniprime(i,l) &&
									omniprime(j,l) &&
									omniprime(k,l)){
									for (m=l+2;m<N;m+=2){
										if (omniprime(i,m) &&
											omniprime(j,m) &&
											omniprime(k,m) &&
											omniprime(l,m)){
											printf("%d . %d . %d . %d . %d\n",
													i, j, k, l, m);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}