#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
	int bestNum = 0, bestDenom = 1, currDenom = atoi(argv[1]);
	int currNum =0,minDenom = 1;
	int a = 3, b = 7;
	while (currDenom >= minDenom){
		currNum = (a*currDenom -1)/b;
		if (bestNum * currDenom < currNum * bestDenom){
			bestNum=currNum;
			bestDenom=currDenom;
			int delta = a*currDenom-b*currNum;
			minDenom = currDenom/(delta+1);
		}
		currDenom=currDenom-1;
	}
	printf("answers: %d,%d\n",bestNum,bestDenom);
}
