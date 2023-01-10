#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEAT 3
#define WAIT 3

typedef struct{
	char name[30];
	int age;
	int status;
} passenger;

struct Node{
	int data;
	struct Node* next;
}*head = NULL,*tail = NULL;

passenger seats[SEAT];
passenger waiting[WAIT];
int current_seat = -1,front=-1,rear=-1,waiting_position = 0;

void empty_stdin (void)
{
    int c = getchar();
	while (c != '\n' && c != EOF)
        c = getchar();
}

passenger enterdata(){
	passenger temp;
	printf("Enter name\n");
	scanf("%s",temp.name);
	printf("Enter age\n");
	scanf("%d",&(temp.age));
	temp.status = 1;
	return temp;
}

void book_ticket(){
	if(current_seat < SEAT-1){
		seats[++current_seat] = enterdata();
	}else if(head != NULL){
		seats[head->data] = enterdata();
		struct Node* temp = head;
		head = head->next;
		free(temp);
	}else if((rear+1)%WAIT != front){
		printf("Reservation list is full adding to waiting list\n");
		if(front == -1)
    		front = 0;
    	rear = (rear+1)%WAIT;
    	waiting[rear] = enterdata();
    	printf("your waiting list number is %d\n",(++waiting_position));
	}else
		printf("Reservation and waiting list is full\n");
}

void cancel_ticket(){
	int seat_no;
	printf("Enter seat number\n");
	scanf("%d",&seat_no);
	if(seat_no<0 || seat_no>SEAT-1)
		printf("Invalid seat number\n");
	else{
		if(seats[seat_no].status == 1){
			if(rear == -1){
				struct Node* new_node = malloc(sizeof(struct Node));
				new_node->data = seat_no;
				new_node->next = NULL;
				if(head == NULL)
					head = new_node;
				else
					tail->next = new_node;
				tail = new_node;
				seats[seat_no].status = 0;
			}else{
				if(front == rear){
					strcpy(seats[seat_no].name,waiting[front].name);
        			seats[seat_no].age = waiting[front].age;
        			front = -1;
        			rear = -1;  
    			}
				else{
        			strcpy(seats[seat_no].name,waiting[front].name);
        			seats[seat_no].age = waiting[front].age;
        			front = (front+1)%WAIT;
				}
				waiting_position--;
			}
		}else
			printf("Seat is already empty\n");
	}
}
void display(){
	printf("Reservation list\n");
	for(int i=0;i<=current_seat;i++){
		if(seats[i].status == 1){
			printf("Name: %s ",seats[i].name);
			printf("Age: %d ",seats[i].age);
			printf("seat no: %d \n",i);
		}
	}
	printf("Waiting list\n");
	if(rear == -1)
		printf("\n");
	else{
		int current = front;
		while(rear!=current){
			printf("Name: %s ",waiting[current].name);
			printf("Age: %d \n",waiting[current].age);
			current = (current+1)%WAIT;
		}
		printf("Name: %s ",waiting[current].name);
		printf("Age: %d \n",waiting[current].age);
	}
}
int main(void){
	int data,position,flag=1,choice;
    while(flag){
    	printf("Enter the choice\n 1 Book ticket\n");
    	printf(" 2 Cancel ticket\n 3 Display\n 4 exit\n");
    	int check = scanf("%d",&choice);
    	if(check == 0)
    		empty_stdin();
    	else{
    		switch(choice){
        		case 1:book_ticket();break;
        		case 2:cancel_ticket();break;
        		case 3:display();break;
        		case 4:flag=0;break;
        		default:printf("invalid input");break;
        }
        }
    }
    return 0;
}

