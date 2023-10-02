/*program to read two polynomials and store them in an array.
Calculate the sum of the two polynomials and display the first polynomial,
second polynomial and the resultant polynomial.*/

/*polynomial is stored in the form of an array of structures, where each structure
 contains the coefficient and exponent of the term.
 avail is the index of the next available space in the array.
 start and end are the indices of the first and last terms of the polynomial
 in the array.
 
 *limitation: the program can only handle 3 polynomial, for all there is only 
 100 space and polynomial must be in descending order and exponents may not be 
 repeated for getting proper sum*/


#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct {
	int coef;
	int expo;
} polynomial;

polynomial poly[MAX];
int avail = 0;

void enterpoly(int *coef, int *expo, int terms) 
{
	for(int i = 0; i < terms; i++) {
		if(avail < MAX) {
			poly[avail].coef = *(coef + i) ; 
			poly[avail].expo = *(expo + i);
			avail++;
		}
		else {
			printf("No more space left\n");
			exit(0);
		}
	}
}

void readpoly(int *start,int *end)
{
	int terms;
	printf("Enter number of terms\n");
	scanf("%d",&terms);

	int coef[terms], expo[terms];
	*start = avail;
	*end = *start + terms - 1;
	
	printf("Enter the coefficients");
	for(int i =0; i < terms; i++) 
		scanf("%d",coef +i);

	printf("Enter the exponents");
	for (int i = 0; i < terms; i++) 
		scanf("%d",expo + i);

	enterpoly(coef, expo, terms);
}

void displaypoly(int start, int end) 
{
	printf("%dx^%d", poly[start].coef, poly[start].expo);

	for(int i = start + 1; i <= end; i++)
		printf(" +%dx^%d", poly[i].coef, poly[i].expo);

	printf("\n");
}

void addpoly(int startA, int endA, int startB, int endB, int *startC, int *endC)
{
	*startC = avail;

	while(startA <= endA && startB <= endB) {
		if(poly[startA].expo == poly[startB].expo) {
			int temp = poly[startA].coef + poly[startB].coef;
			enterpoly(&temp, &poly[startA].expo, 1);
			startA++, 
			startB++;
		}
		else if(poly[startA].expo > poly[startB].expo) {
			enterpoly(&(poly[startA].coef), &(poly[startA].expo), 1);
			startA++;
		}
		else {
			enterpoly(&(poly[startB].coef), &poly[startB].expo, 1);
			startB++;
		}
	}

	while(startA <= endA) {
		enterpoly(&poly[startA].coef, &poly[startA].expo, 1);
		startA++;
	}

	while(startB<=endB) {
		enterpoly(&poly[startB].coef, &poly[startB].expo, 1);
		startB++;
	}

	*endC = avail-1;
}

int main() 
{
	int startA, endA, startB, endB, startC, endC, flag = 1;
	while(flag) {
		startA = 0, endA = 0, startB = 0, endB = 0, startC = 0, endC = 0;
		printf("Enter first polynomial\n");
		readpoly(&startA, &endA);

		printf("Enter second polynomial\n");
		readpoly(&startB, &endB);

		printf("first: ");
		displaypoly(startA,endA);

		printf("second: ");
		displaypoly(startB,endB);

		addpoly(startA, endA, startB, endB, &startC, &endC);
		printf("result: ");
		displaypoly(startC,endC);

		printf("\n");	
		printf("Enter 1 to continue, 0 to exit\n");
		scanf("%d", &flag);
	}
}
