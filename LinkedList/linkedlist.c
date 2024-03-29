/*  Linked List:
	Display
	Insert at Beginning
	Insert at End
	Insert at a specified Position
	Delete from Beginning
	Delete from End
	Delete from a specified Position*/
	
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
int size = 0;

void addnode(int data, int position)
{
	if(position < 1 || position > size + 1)
		printf("invalid position\n");
	else {
		struct Node** temp = &head;
		for(int i = 1; i < position; i++)
			temp = &(*temp)->next;
		struct Node* new_node = malloc(sizeof (struct Node));
		new_node->data = data; 
		new_node->next = *temp;
		*temp = new_node;
		size++;
	}
}

void delete(int position)
{
	if(position < 1 || position > size)
		printf("invalid position\n");
	else {
		struct Node** temp = &head;
		for(int i = 1; i < position; i++)
			temp = &(*temp)->next;
		struct Node* remove = *temp;
		*temp = (*temp)->next; 
		free(remove);
		size--;
	}
}

void display(void)
{
    if(head == NULL)
        printf("No values in Linkedlist\n");
    else {
    	struct Node* temp = head;
    	printf("data in linkedlist = ");
    	while(temp != NULL){
        	printf("%d ", temp->data);
        	temp = temp->next;    
    	}
		printf("\n");
    }
}

int main(void)
{
    int choice, data, position, flag = 1;
    while(flag) {
    	printf("Enter the choice\n 1 for display\n");
    	printf(" 2 for insert at beginning\n 3 for insert at end\n");
    	printf(" 4 for insert at a specific position\n 5 delete from beginning\n");
    	printf(" 6 delete from end\n 7 delete from specific position\n");
    	scanf("%d",&choice);
    	switch(choice) {
        	case 1:display(); 
			       break;

        	case 2:printf("Enter data");
				   scanf("%d",&data);
            	   addnode(data,1);
				   break;

        	case 3:printf("Enter data");
			       scanf("%d",&data);
            	   addnode(data,size + 1);
				   break;

        	case 4:printf("Enter data and position to insert");
				   scanf("%d%d",&data,&position);
				   addnode(data, position);
				   break;

        	case 5:delete(1);
			       break;

        	case 6:delete(size);
			       break;

        	case 7:printf("Enter position to delete");
			       scanf("%d",&position);
				   delete(position);
				   break;

            default:flag=0;
			        break;
        }
    }
    return 0;
}


