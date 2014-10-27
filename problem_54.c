//problem_54.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
A hand is a 5x3 matrix of chars
each cards is a char[3]
it looks like [ value, suite, \0]
there are 5 in each had
*/

int valofchar(char c){
	switch(c){
    	case '2':return 2;
    	case '3':return 3;
    	case '4':return 4;
    	case '5':return 5;
    	case '6':return 6;
    	case '7':return 7;
    	case '8':return 8;
    	case '9':return 9;
    	case 'T':return 10;
    	case 'J':return 11;
    	case 'Q':return 12;
    	case 'K':return 13;
    	case 'A':return 14;
    	default: return -1;
    }
}

int valof(char card[3]){
	valofchar(card[0]);
}


int has(char hand[5][3],char c){
	int i,count=0;
	for (i=0;i<5;i++){
		if (hand[i][0]==c){
			count++;
		}
	}
	return count;
}

int flush(char hand[5][3]){
	int i;
	char suite = hand[0][1];
	for (i=0;i<5;i++){
		if (hand[i][1]!=suite){
			return 0;
		}
	}
	return 1;
}

int straight(char hand[5][3]){
	/*sort the hand*/
	 int i;
	 for (i=1;i<5;i++){
	 	if (valof(hand[i]) != valof(hand[i-1]) - 1){
	 		return 0;
	 	}
	 }
	 return 1;
}

/*
MULTIPLICITY: char[5][3] int -> char[3]
consumes a hand and a size of multiple to look for 
	-kind=(2 of a kind, 3 of a kind, 4 of a kind)

*/
void multiplicity(char hand[5][3],int kind,char result[3]){
	int i,j=0;
	for (i=1;i<5;i++){
		if (hand[i][0]!=hand[i-1][0]){
			if (i-j==kind){
				sprintf(result,"%s%c",result,hand[i-1][0]);
			}
			j=i;
		}
	}
	if (i-j==kind){
		sprintf(result,"%s%c",result,hand[i-1][0]);
	}
}

/*
SCORE: char* -> int*
*/
void score(char hand[5][3], int result[6]){
	int i;
	for (i=1;i<6;i++){
		result[i]=0;
	}

	char quads[3]={'\0','\0','\0'};
	char trios[3]={'\0','\0','\0'};
	char pairs[3]={'\0','\0','\0'};

	multiplicity(hand,4,quads);
	multiplicity(hand,3,trios);
	multiplicity(hand,2,pairs);

	/*ROYAL FLUSH: 10*/
	if (has(hand,'T') && has(hand,'J') &&
		has(hand,'Q') && has(hand,'K') &&
		has(hand,'A') && flush(hand)){
		result[0]=10;
	}
	/*STRAIGHT FLUSH: 9*/
	else if (straight(hand) && flush(hand)){
		result[0]=9;
		result[1]=valof(hand[0]);
	}	
	/*FOUR OF A KIND: 8*/
	else if (quads[0] != '\0'){
		result[0]=8;
		result[1]=valofchar(quads[0]);
	}
	/*FULL HOUSE: 7*/
	else if (trios[0] != '\0' &&
			pairs[0] != '\0'){
		result[0]=7;
		result[1]=valofchar(trios[0]);
		result[2]=valofchar(pairs[0]);
	}
	/*FLUSH: 6*/
	else if (flush(hand)){
		result[0]=6;
		for (i=1;i<6;i++){
			result[i]=valof(hand[i-1]);
		}
	}
	/*STRAIGHT: 5*/
	else if (straight(hand)){
		result[0]=5;
		result[1]=valof(hand[0]);
	}
	/*THREE OF A KIND: 4*/
	else if (trios[0] != '\0'){
		result[0]=4;
		result[1]=valofchar(trios[0]);
	}
	/*TWO PAIRS: 3*/
	else if (strlen(pairs)>1){
		result[0]=3;
		result[1]=valofchar(pairs[0]);
		result[2]=valofchar(pairs[1]);
	}
	/*PAIR: 2*/
	else if (pairs[0] != '\0'){
		result[0]=2;
		result[1]=valof(pairs);
		for (i=2;i<5;i++){
			result[i]=valof(hand[i-2]);
		}
	}
	/*HIGH CARD: 1*/
	else {
		result[0]=1;
		for (i=1;i<6;i++){
			result[i]=valof(hand[i-1]);
		}
	}
}

int compare_scores(int score1[6], int score2[6]){
	int i;
	for (i=0;i<6;i++){
		if (score1[i]>score2[i]){
			return 1;
		}
		else if (score2[i]>score1[i]){
			return 2;
		}
	}
	return 0;
}

/*
fill_hand: FILE* char[5][3] -> void
consumes a file stream and a 5 by 3 char matrix (list of 5 cards)
returns that 5 by 3 char matrix filled in order of card value
*/
void fill_hand(FILE *file,char hand[5][3]){
	int j,k,l;
	for (j=0;j<5;j++){
		char c[3];
		fscanf(file,"%s",c);
		for (k=0;valof(c)<valof(hand[k]);k++);
		for (l=3;l>=k;l--){
			strcpy(hand[l+1],hand[l]);
		}
		strcpy(hand[k],c);
	}
}

int main(int argc, char **argv){

	FILE *file=fopen("p054_poker.txt","r");

	if (file!=NULL){
		//printf("no errors opening the file!\n");
		int i,count=0;
		for (i=0;i<1000;i++){
			
			/*each hand is a char matrix*/
			char hand1[5][3];
			char hand2[5][3];
			char null_card[3]="0X";

			/*initialize the hands*/
			int j;
			for (j=0;j<5;j++){
				strcpy(hand1[j],null_card);
				strcpy(hand2[j],null_card);
			}
	
			/*fill hands with cards in order*/
			fill_hand(file,hand1);
			fill_hand(file,hand2);


			/*score the arrays and compare the hands*/
			int result1[5];
			score(hand1,result1);
			int result2[5];
			score(hand2,result2);
			int winner = compare_scores(result1,result2);

			if (winner == 1){
				count++;
			}
		}

		printf("PLAYER 1 WINS: %d\n", count);
	}
	else {
		printf("file could not be read!\n");
		return 1;
	}

	fclose(file);	
	return 0;
}