#include <stdio.h>

#define MAX 10

int queue[10];
int rear = -1,front= -1;

int isEmpty(){
	return (front==rear);
}

int isFull(){
	return (rear == MAX-1);
}

void enqueue(int data){
	if(!isFull())
		queue[++rear] = data;
	else
		printf("Queue is full\n");
}

int dequeue(){
	if(!isEmpty())
		return queue[++front];
	printf("Queue is empty\n");
	return 0;
}

void display(){	
	if(isEmpty())
		printf("Queue is empty\n");
	else{
		int current = front+1;
		printf("content :");
		while(current<=rear){
			printf("%d, ",queue[current]);
			current++;
		}printf("\n");
	}
}

int main(){
    int choice,flag=1,data;

    while(flag){
	printf("Enter\n 1 for enqueue\n 2 for dequeue\n 3 for exit\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:
        		printf("Enter data\n");
        		scanf("%d",&data);
				enqueue(data);
				display();
				break;
        	case 2:
				printf("Data removed %d\n",dequeue());
				display();
				break;
			case 3:
				flag=0;
				break;
        	default:printf("Invalid Input\n");
	}
    }
}
