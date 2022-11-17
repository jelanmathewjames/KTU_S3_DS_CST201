#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;
int size = 0;

struct Node* create_node(int data,struct Node* next){
	struct Node* new_node = malloc(sizeof (struct Node));
	new_node->data = data; new_node->next = next;
	return new_node;
}

void addnode_front(int data){
	struct Node* new_node = create_node(data,head);
	head = new_node;
	size++;
}

void addnode_middle(int data,int position){
	if(position < 1 || position>size+1)
		printf("invalid position\n");
	else{
		struct Node** temp = &head;
		for(int i=1;i<position;i++)
			temp = &(*temp)->next;
		struct Node* new_node = create_node(data,*temp);
		*temp = new_node;
		size++;
	}
}

void addnode_end(int data){
	struct Node* new_node = create_node(data,NULL);
   	struct Node** temp = &head;
    while(*temp!=NULL)
    	temp = &(*temp)->next;
    *temp = new_node;
    size++;
}

void delete_front(void){
	if(head){
		struct Node* remove = head;
		head = head->next; free(remove); size--;
	}else
		printf("list is empty\n");
}

void delete_middle(int position){
	if(position < 1 ||position > size)
		printf("invalid position\n");
	else{
		struct Node** temp = &head;
		for(int i= 1;i<position;i++)
			temp = &(*temp)->next;
		struct Node* remove = *temp;
		*temp = (*temp)->next; free(remove);
		size--;
	}
}

void delete_end(void){
	if(head){
		struct Node **temp =  &head;
		while((*temp)->next)
			temp = &(*temp)->next;
		free(*temp); *temp = NULL;
		size--;
	}
}

void display(void){
    if(head == NULL)
        printf("No values in Linkedlist\n");
    else{
    struct Node* temp = head;
    printf("data in linkedlist = ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;    
    }
    printf("\n");
    }
}

int main(){
    
    int choice,data,position;
    int flag=1;
    while(flag){
    	printf("Enter the choice\n 1 for display\n");
    	printf(" 2 for insert at beginning\n 3 for insert at end\n");
    	printf(" 4 for insert at a specific position\n 5 delete from beginning\n");
    	printf(" 6 delete from end\n 7 delete from specific position\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:display();printf("%d\n",size);break;
        	case 2:printf("Enter data");scanf("%d",&data);
            	   addnode_front(data);break;
        	case 3:printf("Enter data");scanf("%d",&data);
            	   addnode_end(data);break;
        	case 4:printf("Enter data and position to insert");
				   scanf("%d%d",&data,&position);addnode_middle(data,position);
	    		   break;
        	case 5:delete_front();break;
        	case 6:delete_end();break;
        	case 7:printf("Enter position to delete");scanf("%d",&position);
				   delete_middle(position);break;
            default:flag=0;break;
        }
    }
    return 0;
}

