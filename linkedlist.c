#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* tail=NULL;
void addnode(int data);
int display();

int main(){
    
    int choice,data;
    int flag=1;
    while(flag){
    	printf("Enter the choice\n 1 for addnode\n 2 for display\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:
			printf("Enter data");
			scanf("%d",&data);
            		addnode(data);
	    		break;
        	case 2:
            		display(head);
	    		break;
        	default:flag=0;break;
            
    	}
    }
    return 0;
}
void addnode(int data){
    struct Node* node = malloc(sizeof (struct Node));
  
    if(head == NULL){
        head = node;
	head->data = data;
    }else{
        tail->next = node;}
    tail = node;
    tail->data = data;
    tail->next = NULL;
}
int display(){
    if(head == NULL){
        printf("No values in Linkedlist\n");
        return 0;    
    }
    struct Node* temp = head;
    printf("data in linkedlist = ");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;    
    }
    printf("\n");
    return 1;
}
