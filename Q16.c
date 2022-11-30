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

void add_duplicate(struct Node **startC){

	struct Node **fix=startC,**mover = &(*fix)->next;

	while(*fix && (*fix)->next){
		
		while(*mover){
			if((*fix)->expo == (*mover)->expo){
				
				(*fix)->coef = (*fix)->coef+(*mover)->coef;
				struct Node* remove = *mover;
				*mover = (*mover)->next; free(remove); 
			}else
				mover = &(*mover)->next;
		}
		fix = &(*fix)->next;
		mover = &(*fix)->next;
	}
	

}

void multiplypoly(struct Node *startA,struct Node *startB,struct Node **startC){
	struct Node *temp = startB;
	
	while(startA){
		while(startB){
			startC = enterpoly(startC,startA->coef*startB->coef,startA->expo+startB->expo);
			startB = startB->next;
		}
		startB = temp;
		startA = startA->next;
	}
	add_duplicate(startC);
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
	add_duplicate(&startC);
	printf("result: ");
	displaypoly(startC);
	return 0;
}

