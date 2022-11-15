/*Implement a circular queue using arrays with the operations:
	Insert an element to the queue.
	Delete an elements from the queue.
	Display the contents of the queue after each operation.*/

#include <stdio.h>
#define MAX 10
int queue[MAX];
int rear = -1,front= -1;
void empty_stdin (void)
{
    int c = getchar();
	while (c != '\n' && c != EOF)
        c = getchar();
}
void enqueue(int data){
    if((rear+1)%MAX==front){
        printf("Queue is full\n");
    }
    else{
        if(front == -1)
            front = 0;
        rear = (rear+1)%MAX;
        queue[rear] = data;
        
     }   
}

int dequeue(){
    int temp;
    if(rear == -1)
		printf("Queue is empty\n");
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

void display(){	
	if(rear == -1)
		printf("Queue is empty\n");
	else{
		int current = front;
		printf("content :");
		while(rear!=current){
			printf("%d, ",queue[current]);
			current = (current+1)%MAX;}
		printf("%d\n",queue[current]);
	}
}

int main(){
    int choice,flag=1,data;
	while(flag){
		printf("Enter\n 1 for enqueue\n 2 for dequeue\n 3 for exit\n");
    	int check = scanf("%d",&choice);
    	if(check == 0){
    		printf("not an integer");
  			empty_stdin();
    	}else{
    		switch(choice){
        		case 1:
        			printf("Enter data");
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
        		default:printf("Invalid Input");
        	}
		}
    }
}
