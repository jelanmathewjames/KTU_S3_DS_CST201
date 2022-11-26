/*Create a Doubly Linked List from a string taking each character from the
string. Check if the given string is palindrome in an efficient method.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node* prev;
	struct Node* next; 
};

struct Node *head=NULL,*tail=NULL;

void todoubly(char str[]){
	for(int i=0;str[i]!='\0';i++){
		struct Node* new_node = malloc(sizeof (struct Node)); 
		new_node->data = str[i];
		new_node->prev = tail;new_node->next = NULL;
		if(!head)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
	}
}

void check_palindrome(){
	int flag=1;
	struct Node *h_temp=head,*t_temp=tail;
	if(head){
		while(h_temp!=t_temp){
			if(h_temp->data != t_temp->data){
				flag=0;
			}
			h_temp = h_temp->next;
			t_temp = t_temp->prev;
		}
	}if(flag)
		printf("String is palindrome\n");
	else
		printf("String is not palindrome\n");
}

int main(void){
	char str[50];
	printf("Enter a string\n");
	scanf("%s",str);
	todoubly(str);
	check_palindrome();
	
}
