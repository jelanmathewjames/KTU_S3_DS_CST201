#include <stdio.h>

#define MAX 10

int queue[MAX];
int rear = -1,front= -1;



void enqueue(){
    if((rear+1)%MAX==front){
        printf("full at%d",rear);
        printf("Queue is full");
    }
    else{
        if(front == -1)
            front = 0;
        rear = (rear+1)%MAX;
        queue[rear] = rear;
        printf("%d",rear);
     }   
	
}

int dequeue(){
    int temp;
    if(rear == -1)
		printf("Queue is empty");
    else if(front == rear){
        temp =queue[front];
        front = -1;
        rear = -1;  
        return temp;  
    }
	else{
        temp = queue[front];
        front = (front+1)%MAX;
        return temp;}
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
