#include <stdio.h>
#define MAX 10
int queue[MAX],rear = -1,front= -1;
void empty_stdin (void)
{
    int c = getchar();
	while (c != '\n' && c != EOF)
        c = getchar();
}
void f_enqueue(int data){
	if((rear+1)%MAX==front)
		printf("Queue is full\n");
	else{
		if(rear == -1){
			rear++;
			queue[++front]=data;
		}else{
			front = front==0?MAX-1:--front;
			queue[front]=data;
		}
	}
}

int f_dequeue(){
	int temp;
    if(rear == -1)
		printf("Queue is empty\n");
    else if(front == rear){
        temp =queue[front];
        front = -1;
        rear = -1;  
        return temp;  
    }else{
        temp = queue[front];
        front = (front+1)%MAX;
        return temp;}
	return 0;
}

void r_enqueue(int data){
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
int r_dequeue(){
	int temp;
	if(front == -1)
		printf("Queue is empty\n");
	else if(front == rear){
		temp = queue[rear];
		front = -1;
		rear = -1;
		return temp;
	}else{
		temp = queue[rear];
		rear = rear==0?MAX-1:--rear;
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
		printf("Enter\n 1 for enqueue at front\n 2 for dequeue at front\n"
				" 3 for enqueue at rear\n 4 for dequeue at rear\n 5 for exit\n");
    	int check = scanf("%d",&choice);
    	if(check == 0){
    		printf("not a integer");
    		empty_stdin();
    	}else{
    		switch(choice){
        		case 1:
        			printf("Enter data");scanf("%d",&data);
					f_enqueue(data);display();
					break;
        		case 2:
					printf("Data removed %d\n",f_dequeue());display();
					break;
				case 3:
        			printf("Enter data");scanf("%d",&data);
					r_enqueue(data);display();
					break;
        		case 4:
					printf("Data removed %d\n",r_dequeue());display();
					break;
				case 5:
					flag=0;break;
        		default:printf("Invalid Input");
        	}
        }
    }
}
