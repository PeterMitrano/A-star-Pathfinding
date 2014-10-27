
#include <stdio.h>
#include <stdlib.h>


int main(int argv, char** argc){
	int i;
	int x[4]={1,2,3,4};
	int y[4];
	for (i=0;i<4;i++){
		y[i]=x[i];
	}

	for (i=0;i<4;i++){
		printf("x[%d]=%d\n",i,x[i]);
		printf("y[%d]=%d\n",i,y[i]);
	}
	x[2]=5;
	for (i=0;i<4;i++){
		printf("x[%d]=%d\n",i,x[i]);
		printf("y[%d]=%d\n",i,y[i]);
	}
	return 0;
}