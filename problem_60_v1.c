#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** seive(int n){
	int** numbers = (int**)malloc(sizeof(int*)*n);
	int i,j;

	for (i=0;i<n;i++){
		numbers[i] = (int*)malloc(sizeof(int)*n);
		numbers[i][0]=i;
	}

	//get rid of 1 and 5
	numbers[1][0]=-1;


	for (i=2;i<n;i++){
		if (numbers[i][0]!=-1){
			//split into 2 nums
			for (j=10;j<pow(10,(int)log10(numbers[i][0])+1);j*=10){
				int a = numbers[i][0]/j; //first half as num
				int b = numbers[i][0]%j; //second half as num
				if (numbers[a][0]==a && numbers[b][0]==b){
					numbers[a][b]=1;
				}
			}

			//cross of multiples of numbers[i]
			for (j=2;j*numbers[i][0]<n;j++){
				numbers[j*numbers[i][0]][0]=-1;
			}
			
		}
	}

	numbers[5][0]=-1;

	return numbers;
}

int omniprime(int** numbers, int a, int b){
	if (numbers[a][b]==1&&numbers[b][a]==1){
		return 1;
	}
	return 0;
}

int main(int argc, char** argv){
	int i,j,N=70000;//DO NOT RAISE ABOVE 700000

	if (N>500000){
		printf("you're a fucking idiot\n");
		return 1;
	}

	int** numbers=seive(N);

	int k,l;
	for (i=3;i<N;i+=2){
		if (numbers[i][0]!=-1){
			//go through all numbers omiprime with i
			for (j=i+2;j<N;j+=2){
				if (numbers[j][0]!=-1 && omniprime(numbers,i,j)){
					//go through all numbers omniprime with i & j
					for (k=j+2;k<N;k+=2){
						if (numbers[k][0]!=-1 &&
								omniprime(numbers,i,k) &&
								omniprime(numbers,j,k)){
							printf("%d,%d,%d\n",i,j,k);
						}
					}
				
				}
			}
		}
	}

/*	
	for (i=3;i<20;i++){
		if (numbers[i][0]!=-1){
			printf("%d |",numbers[i][0]);
			for (j=3;j<20;j++){
				if (numbers[j][0]!=-1){
					if (omniprime(numbers,i,j)){
						printf("X ");
					}else {
						printf("  ");
					}
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	printf("\n");
*/


	
	return 0;
}
