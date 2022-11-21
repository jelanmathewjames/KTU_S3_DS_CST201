/*Write a program to read two polynomials and store them using linked list.
Calculate the sum of the two polynomials and display the first polynomial,
second polynomial and the resultant polynomial.*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
	int coef;
	int expo;
	struct Node* next;
};

struct Node** enterpoly(struct Node **temp,int coef,int expo){
	*temp = malloc(sizeof (struct Node));
	(*temp)->coef = coef;
	(*temp)->expo = expo;
	(*temp)->next = NULL;
	temp = &(*temp)->next;
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

void displaypoly(struct Node **start){
	
	struct Node* temp = *start;
	printf("%dx^%d",temp->coef,temp->expo);
	temp = temp->next;
	while(temp){
		printf("+%dx^%d",temp->coef,temp->expo);
		temp = temp->next;
	}
}

void polyaddition(struct Node* startA,struct Node* startB,struct Node** startC){
	*startC = malloc(sizeof (struct Node));
	struct Node* temp = *startC;
	
	/*while(startA && startB){
		if(startA->expo > startB->expo)
	}*/
}

int main(void){
	struct Node *startA=NULL, *startB=NULL, *startC=NULL;
	readpoly(&startA);
	displaypoly(&startA);
}













