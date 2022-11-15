/*Implement a stack using linked list with the operations:
	Push elements to the stack.
	Pop elements from the stack.
	Display the stack after each operation.*/
	
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* top = NULL;

void push(int data){
	struct Node* new_node = malloc(sizeof (struct Node));
	new_node->data = data; new_node->next = top;
	top = new_node;
}

void pop(void){
	if(top){
		struct Node* remove = top;
		top = top->next;
		free(remove);
	}else
		printf("Stack is empty\n");
}

void display(void){
	struct Node* temp = top;
	while(temp){
		printf("%d, ",temp->data);
		temp = temp->next;
	}printf("\n");
}

int main(void){
	int flag=1,choice,data;
	while(flag){
		printf("Enter\n 1 for push\n 2 for pop\n 3 for exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter data\n");
					scanf("%d",&data);
					push(data);display();
					break;
			case 2: pop();display();
					break;
			case 3: flag = 0;break;
			default:printf("Invalid input\n");
		}
	}
}












