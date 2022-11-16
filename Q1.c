/*Write a program to read two polynomials and store them in an array.
Calculate the sum of the two polynomials and display the first polynomial,
second polynomial and the resultant polynomial.*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct{
	int coef;
	int expo;
} polynomial;

polynomial poly[MAX];
int avail = 0;


void enterpoly(int coef, int expo){
	if(avail<MAX){
		poly[avail].coef = coef, poly[avail].expo = expo;
		avail++;
	}else{
		printf("No more space left\n");
		exit(0);
	}
}

void readpoly(int *start,int *end){
	int terms,expo,coef;
	
	printf("Enter number of terms\n");
	scanf("%d",&terms);
	*start = avail;
	*end = *start+terms-1;
	
	for(int i =0;i<terms;i++){
	    printf("Enter the coefficient");
		scanf("%d",&coef);
		printf("Enter the exponential");
		scanf("%d",&expo);
		enterpoly(coef,expo);
	}
}

void displaypoly(int start, int end){
	printf("%dx^%d",poly[start].coef,poly[start].expo);
	for(int i=start+1;i<=end;i++)
		printf("+%dx^%d",poly[i].coef,poly[i].expo);
	printf("\n");
}

void addpoly(int startA, int endA, int startB, int endB, int *startC, int *endC){
	*startC = avail;
	while(startA<=endA && startB<=endB){
		if(poly[startA].expo == poly[startB].expo){
			enterpoly(poly[startA].coef+poly[startB].coef,poly[startA].expo);
			startA++,startB++;
		}else if(poly[startA].expo>poly[startB].expo){
			enterpoly(poly[startA].coef,poly[startA].expo);
			startA++;
		}else{
			enterpoly(poly[startB].coef,poly[startB].expo);
			startB++;
		}
	}
	while(startA<=endA){
		enterpoly(poly[startA].coef,poly[startA].expo);
		startA++;
	}
	while(startB<=endB){
		enterpoly(poly[startB].coef,poly[startB].expo);
		startB++;
	}
	*endC = avail-1;
}

int main(){
	int startA, endA, startB, endB, startC, endC;
	int choice,flag=1;
	while(flag){
		startA=0, endA=0, startB=0, endB=0, startC=0, endC=0;
		printf("Enter first polynomial\n");
		readpoly(&startA,&endA);
		printf("Enter second polynomial\n");
		readpoly(&startB,&endB);
		printf("first: ");
		displaypoly(startA,endA);
		printf("second: ");
		displaypoly(startB,endB);
		addpoly(startA, endA, startB, endB, &startC, &endC);
		printf("result: ");
		displaypoly(startC,endC);	
	}
	
}
