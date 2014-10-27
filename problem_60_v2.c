#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** numbers;
int** primes;

int seive(int n){
	numbers = (int**)malloc(sizeof(int*)*n);
	
	if (numbers==NULL){
		return -1; // error
	}
	
	int i,j,k,pcount=0;

	for (i=0;i<n;i++){
	
		numbers[i]=(int*)malloc(sizeof(int)*2);
	
		if (numbers[i]==NULL){
			return -2; // error
		}
	
		numbers[i][0]=0;
		numbers[i][1]=0;
	}

	//get rid of 0 and 1
	numbers[0][0]=-1;
	numbers[1][0]=-1;

	for (i=2;i<n;i++){
		if (numbers[i][0]!=-1){
			numbers[i][1]=pcount++;
			//cross off multiples
			for (j=2;j*i<n;j++){
				numbers[j*i][0]=-1;
				numbers[j*i][1]=-1;
			}
		}
	}

	primes = (int**)malloc(sizeof(int*)*pcount);

	if (primes==NULL){
		return -3; // error
	}

	j=0;
	for (i=0;i<n;i++){
		if (numbers[i][0]!=-1){

			primes[j]=(int*)malloc(sizeof(int)*pcount);

			if (primes[j]==NULL){
				return -4; // error
			}

			primes[j++][0]=i;
			//fill in matrix
			for (k=10;k<pow(10,(int)log10(i)+1);k*=10){
				int a = i/k; //first half as num
				int b = i%k; //second half as num
				if (b*10>k){ //stops 03 from being 3
					if (numbers[a][0]!=-1 && numbers[b][0]!=-1){
						primes[numbers[a][1]][numbers[b][1]]=1;
					}
				}
			}
		}
	}
	return pcount;
}

/*A and B are NOT prime numbers. they are meaningless indeces*/
int omniprime(int a, int b){
	if (primes[a][b]==1&&primes[b][a]==1){
		return 1;
	}
	return 0;
}

int main(int argc, char** argv){
	int pcount,i,j,k,l,N=1000000;

	pcount=seive(N);

	
	for (i=0;i<pcount;i++){
		for (j=i+1;j<pcount;j++){
			//i and j are not primes, they are the location of primes
			if (omniprime(i,j)){
				for (k=j+1;k<pcount;k++){
					if (omniprime(i,k) &&
						omniprime(j,k)){
						for (l=k+1;l<pcount;l++){
							if (omniprime(i,l) &&
								omniprime(j,l) &&
								omniprime(k,l)){
								printf("%d . %d . %d . %d\n",
									primes[i][0],
									primes[j][0],
									primes[k][0],
									primes[l][0]);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}