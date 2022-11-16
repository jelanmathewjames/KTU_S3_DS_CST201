/*Implement a Queue using linked list with the operations:
	Insert an elements to the queue.
	Delete an elements from the queue.
	Display the queue after each operation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data){
	if(!front&&!rear){
		rear = malloc(sizeof (struct Node));
		front = rear;
		rear->data = data; rear->next = NULL;
	}else{
		rear->next = malloc(sizeof (struct Node));
		rear->next->data = data; rear->next->next = NULL;
		rear = rear->next;
	}
}

void dequeue(void){
	if(front){
		if(front->next){
			struct Node* remove = front;
			front = front->next;
			free(remove);remove = NULL;
		}else{
			free(front);
			front = NULL; rear = NULL;
		}
	}else
		printf("Queue is empty\n");
}

void display(void){
	struct Node* temp = front;
	while(temp){
		printf("%d, ",temp->data);
		temp = temp->next;
	}printf("\n");
}

int main(void){
	int flag=1,choice,data;
	while(flag){
		printf("Enter\n 1 for enqueue\n 2 for dequeue\n 3 for exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter data\n");
					scanf("%d",&data);
					enqueue(data);display();
					break;
			case 2: dequeue();display();
					break;
			case 3: flag = 0;break;
			default:printf("Invalid input\n");
		}
	}
}
