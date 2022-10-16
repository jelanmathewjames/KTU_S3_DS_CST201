#include <stdio.h>

#define MAX 10

int queue[MAX];
int rear = 0,front= 0;



void enqueue(){
    
    if((rear+1)%MAX==front){
        printf("full at%d",rear);
        printf("Queue is full");
    }
    else{
        
        rear = (rear+1)%MAX;
        queue[rear] = rear;
        printf("%d",rear);
     }   
	
}

int dequeue(){
    if(rear == front)
		printf("Queue is empty");
	else{
        front = (front+1)%MAX;
        return queue[front];
    }
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
