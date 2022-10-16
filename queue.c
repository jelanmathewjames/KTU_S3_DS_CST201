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

void enqueue(){
	if(!isFull())
		queue[++rear] = rear;
	else
		printf("Queue is full");
}

int dequeue(){
	if(!isEmpty())
		return queue[++front];
	printf("Queue is empty");
	return 0;
}

int main(){
    int choice,flag=1;

    while(flag){
	printf("Enter\n 1 for enqueue\n 2 for dequeue\n 3 for exit\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:
			enqueue();
			break;
        	case 2:
			printf("%d",dequeue());
			break;
		case 3:
			flag=0;
			break;
        	default:printf("Invalid Input");
	}
    }
}
