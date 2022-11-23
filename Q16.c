/*Write a program to read two polynomials and store them using linked list.
Find the product of two polynomials and store the result using linked list.
Display the resultant polynomial.*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
	int coef;
	int expo;
	struct Node* next;
};

struct Node** enterpoly(struct Node **temp,int coef,int expo){
	*temp = malloc(sizeof (struct Node));
	(*temp)->coef = coef;(*temp)->expo = expo;
	(*temp)->next = NULL;temp = &(*temp)->next;
	return temp;
}

void readpoly(struct Node **start){

    int coef,expo,terms;
	printf("Enter no of terms");
	scanf("%d",&terms);
	
	for(int i=0;i<terms;i++){
		printf("Enter coefficient and exponent");
		scanf("%d%d",&coef,&expo);
		start = enterpoly(start,coef,expo);
	}

}
void multiplypoly(struct Node *startA,struct Node *startB,struct Node **startC){
	struct Node* temp = startB;
	while(startA){
		while(startB){
			if(*startC && ((*startC)->expo == startA->expo+startB->expo))
				startC = enterpoly(startC,(startA->coef*startB->coef)+(*startC)->coef,(*startC)->coef);
			else
				startC = enterpoly(startC,startA->coef*startB->coef,startA->expo+startB->expo);
			startB = startB->next;
		}
		startB = temp;
		startA = startA->next;
	}
}

void displaypoly(struct Node *start){
	
	struct Node* temp = start;
	printf("%dx^%d",temp->coef,temp->expo);
	temp = temp->next;
	while(temp){
		printf("+%dx^%d",temp->coef,temp->expo);
		temp = temp->next;
	}printf("\n");
}

int main(void){
	struct Node *startA=NULL, *startB=NULL, *startC=NULL;
	printf("Enter first polynomial\n");
	readpoly(&startA);
	printf("Enter second polynomial\n");
	readpoly(&startB);
	printf("first: ");
	displaypoly(startA);
	printf("second: ");
	displaypoly(startB);
	multiplypoly(startA,startB,&startC);
	printf("result: ");
	displaypoly(startC);
	return 0;
}

