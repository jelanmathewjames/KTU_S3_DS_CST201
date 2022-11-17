#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

struct Node* create_node(int data,struct Node* next){
	struct Node* new_node = malloc(sizeof (struct Node));
	new_node->data = data; new_node->next = next;
	return new_node;
}

void addnode_front(int data){
	struct Node* new_node = create_node(data,head);
	head = new_node;
}

void addnode_middle(int data,int position){
	if(position < 1)
		printf("low position\n");
	else{
		int i;
		if(!head && position == 1){
			struct Node* new_node = create_node(data,head);
			head = new_node;
		}else if(head){
			struct Node* temp = head;
			for(i=1;i<position;i++){
				if(temp->next)
					temp = temp->next;
				else
					break;
			}if(!temp->next ){
					if(i == position-1)
						temp->next = create_node(data,NULL);
					else
						printf("position out of list\n");
					return;
			}struct Node var = *temp;
			printf("%d",temp->next);
			printf("%d",var.next);
			struct Node* new_node = create_node(data,&var);
			printf("%d\n",new_node->next->next);
			*temp = *new_node;return;
			printf("%d",temp->data);
		}printf("position out of list\n");
	}
}

void addnode_end(int data){
	struct Node* new_node = create_node(data,NULL);
   	if(!head){
		head = new_node;                                                                          
    }else{
    	struct Node* temp = head;
    	while(temp->next!=NULL)
    		temp = temp->next;
    	temp->next = new_node;
    }
}

void delete_front(void){
	if(head){
		struct Node* remove = head;
		head = head->next; free(remove);
	}else
		printf("list is empty\n");
}

void delete_middle(int position){
	if(position < 1)
		printf("low position\n");
	else{
		if(!head){
			printf("list is empty\n");
			return;
		}struct Node *temp = head, *prev = NULL;
		for(int i=1;i<position;i++){
			prev = temp;
			temp = temp->next;
			if(!temp){
				printf("position out of list\n");
				return;
			}
		}if(prev){
			prev->next = temp->next; free(temp);
		}else{
			head = head->next; free(temp);
		}
	}
}

void delete_end(void){
	if(!head){
		printf("list is empty\n");
		return;
	}struct Node *temp = head, *prev = NULL;
	while(temp->next){
		prev = temp; temp = temp->next;
	}if(prev){
			prev->next = temp->next; free(temp);
	}else{
			head = head->next; free(temp);
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
    
    int choice,data,position,delete_node;
    int flag=1;
    while(flag){
    	printf("Enter the choice\n 1 for display\n");
    	printf(" 2 for insert at beginning\n 3 for insert at end\n");
    	printf(" 4 for insert at a specific position\n 5 delete from beginning\n");
    	printf(" 6 delete from end\n 7 delete from specific position\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1:display();break;
        	case 2:printf("Enter data");scanf("%d",&data);
            	   addnode_front(data);break;
        	case 3:printf("Enter data");scanf("%d",&data);
            	   addnode_end(data);break;
        	case 4:printf("Enter data and position to insert");
				   scanf("%d%d",&data,&position);addnode_middle(data,position);
	    		   break;
        	case 5:delete_front();break;
        	case 6:delete_end();break;
        	case 7:printf("Enter position to delete");scanf("%d",&delete_node);
				   delete_middle(delete_node);break;
            default:flag=0;break;
        }
    }
    return 0;
}

