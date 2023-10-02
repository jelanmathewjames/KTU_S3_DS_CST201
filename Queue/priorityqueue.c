/*Priority Queue using arrays with the operations:
	Insert elements to the Priority Queue.
	Delete elements from the Priority Queue.
	Display the contents of the Priority Queue after each operation.*/

#include <stdio.h>
#define MAX 3

int queue[MAX][2];
int rear = -1;

void enqueue(int data, int priority)
{
	if(rear < MAX - 1) {
		queue[++rear][0] = data;
		queue[rear][1] = priority;
	}
	else
		printf("Queue is full\n");
}

int peek()
{
	int max_priority = queue[0][1];
	int max_index = 0;
	for(int i = 1; i <= rear; i++) {
		if(max_priority > queue[i][1]) {
			max_priority = queue[i][1];
			max_index = i;
		}
	}
	return max_index;
}

int dequeue()
{
	if(rear > -1) {
		int max_index = peek();
		int max_value = queue[max_index][0];
		for(int i = max_index + 1; i <= MAX - 1; i++) {
			queue[i - 1][0] = queue[i][0];
			queue[i - 1][1] = queue[i][1];
		}
		rear--;
		return max_value;
	}
	printf("Queue is empty\n");
	return 0;
}

void display()
{	
	if(rear <= -1) {
		printf("Queue is empty\n");
		return;
	}
	printf("content :");
	for(int i=0;i<=rear;i++) {
		printf("%d, ", queue[i][0]);
		printf("%d| ", queue[i][1]);
	}
	printf("\n");
}

int main()
{
    int choice,flag=1,data,priority;

    while(flag) {
	printf("Enter\n 1 for enqueue\n 2 for dequeue\n 3 for exit\n");
    	scanf("%d",&choice);
    	switch(choice) {
        	case 1:printf("Enter data and priority\n");
        		   scanf("%d%d", &data, &priority);
				   enqueue(data, priority);
				   display();
				   break;

        	case 2:printf("Data removed %d\n", dequeue());
				   display();
				   break;

			case 3:flag=0;
				   break;
				   
        	default:printf("Invalid Input\n");
		}
    }
}
