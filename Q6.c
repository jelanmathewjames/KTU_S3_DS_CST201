/*Implement a Stack using arrays with the operations:
	Pushing elements to the Stack.
	Popping elements from the Stack
	Display the contents of the Stack after each operation.*/

#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE], top = -1;

int isEmpty(){
    return (top<=-1);
}

int isFull(){
    return (top>=MAX_SIZE-1);
}

void push(int data){
    if(!isFull())
        stack[++top] = data;
    else
        printf("stack overflow\n");
}

int pop(){
   if(!isEmpty())
        return stack[top--];
   printf("stack is empty\n");
   return 0;
   
}

void display(){
	for(int i = top;i>=0;i--)
		printf("%d ",stack[i]);
	printf("\n");
}

int main(){
    int choice,data,flag = 1;
    while(flag){
    	printf("Enter\n 1 for push\n 2 for pop\n 3 for exit");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:
				printf("Enter the data");
    			scanf("%d",&data);
    			push(data);
    			display();
    			break;
        	case 2:
				pop();
				display();
				break;
			case 3: 
				flag =0;
				break;
        	default:printf("Invalid Input");
        }
	}
}
