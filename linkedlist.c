#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

void addnode_front(int data){
	struct Node* new_node = malloc(sizeof (struct Node));
	new_node->data = data ; new_node->next = head;
	head = new_node;
}
void addnode_middle(int data,int add_after){
    struct Node* new_node = malloc(sizeof (struct Node));
    struct Node* temp = head;
        while(temp&&temp->data!=add_after)
			temp = temp->next;
	    if(temp){
			new_node->next = temp->next;
			temp->next = new_node; new_node->data=data;
		}else
			printf("data not found in list\n");
}
void addnode_end(int data){
	struct Node* new_node = malloc(sizeof (struct Node));
   
    if(!head){
    	new_node->data = data ; new_node->next = head;
		head = new_node;                                                                          
    }else{
    	struct Node* temp = head;
    	while(temp->next!=NULL)
    		temp = temp->next;
    	temp->next = new_node;
    	new_node->data = data; new_node->next = NULL;
    }
}
int delete(int* delete_node){
	
	if(head == NULL)
		printf("no data to delete\n");
	else{
		struct Node* temp = head;
		struct Node* prev = NULL;
		while(temp->next){
			if(delete_node != NULL && (temp->data == *delete_node && temp->next!=NULL)){
				struct Node* remove = temp->next;
				*temp = *temp->next;
				free(remove);
				return 1;
			}
			prev = temp;
			temp = temp->next;
		}
		if(delete_node != NULL && temp->data != *delete_node)
			printf("data not found in list\n");
		else if(!prev){
			free(temp);
			head=NULL;
		}else{
			prev->next = NULL;
			free(temp);
		}
		
	}
	return 1;
}
void display(){
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
    
    int choice,data,add_after,delete_node;
    int flag=1;
    while(flag){
    	printf("Enter the choice\n 1 for display\n");
    	printf(" 2 for insert at beginning\n 3 for insert at end\n");
    	printf(" 4 for insert at a specific position\n 5 delete from beginning\n");
    	printf(" 6 delete from end\n 7 delete from specific position\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:
        		display();
	    		break;
        	case 2:
        		printf("Enter data");
				scanf("%d",&data);
            	addnode_front(data);
	    		break;
        	case 3:
        		printf("Enter data");
				scanf("%d",&data);
            	addnode_end(data);
	    		break;
        	case 4:
        		printf("Enter data and after which data you want to insert");
				scanf("%d%d",&data,&add_after);
				addnode_middle(data,add_after);
	    		break;
        	case 5:
        		delete(&head->data);
	    		break;
        	case 6:
				delete(NULL);
	    		break;
        	case 7:
        		printf("Enter data to delete");
				scanf("%d",&delete_node);
				delete(&delete_node);
	    		break;
            	
        	default:flag=0;break;
            
    	}
    }
    return 0;
}

