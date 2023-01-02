#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=0, *temp, *newnode;
void insertbegin(int x){
	newnode=(struct node*) malloc (sizeof(struct node)) ;
	newnode->data=x;
	newnode->next=0;
	if(head==0)
		head=newnode;
	else{
		newnode->next=head;
		head=newnode;
	}
}
void insertend(int x) {
	newnode=(struct node*) malloc (sizeof(struct node)) ;
	newnode->data=x;
	newnode->next=0;
	if(head==0)
		head=temp=newnode;
	else{
		temp=head;
		while(temp->next!=0)
			temp=temp->next;
		temp->next=newnode;
	}
}
void specificpos(int pos){
	int count=0, i=1,x;
	printf("enter element");
	scanf("%d",&x);
	temp=head;
	while(temp!=0){
		temp=temp->next;
		count++;
	}
	temp = head;
	if(pos>count+1||pos<1)
		printf("invaid");
	else if(pos==1)
		insertbegin(x) ;
	else if(pos==(count+1))
		insertend(x);
	else{
		while(i<pos-1){
			temp=temp->next;
		i++;
	}
	newnode=(struct node*) malloc (sizeof(struct node)) ;
	newnode->data=x;
	newnode->next=temp->next;
	temp->next=newnode;
	}
}

void deletebegin() {
	if(head==0)
		printf("empty....");
	else{
		temp=head;
		head=head->next;
		free(temp);
	}
}

void deleteend(){
	struct node *prev;
	temp=prev=head;
	while(temp->next!=0){
		prev=temp;
		temp=temp->next;
	}
	prev->next=0;
	free(temp);
}

void deletespecificpos () {
	int pos, i=1;
	struct node *prev;
	printf("enter position to be deleted");
	scanf("%d",&pos);
	temp=head;
	while(i<pos){
		prev =temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
}

void display(){
	temp=head;
	while(temp!=0){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

void main(){
	int x, choice,pos, flag=1;
	while(flag){
		printf("1 for insert begin\n 2 for end node\n 3for specific pos \n 4 for exit");
		printf("5 for delete begin\n 6 for delete end\n 7 for delete specific pos\n 8 for display");
		printf(" enter your choice");
		scanf("%d",&choice);
		switch (choice) {
			case 1: printf("enter element");
				    scanf("%d",&x);
				   	insertbegin(x) ;
					break;
			case 2:	printf("enter element");
				   	scanf("%d",&x);
					insertend(x) ;
					break;
			case 3: printf("enter position");
					scanf("%d",&pos);
					specificpos(pos);
					break;
			case 4:	flag=0;
					break;
			case 5:	deletebegin();
					break;
			case 6:	deleteend();
					break;
			case 7:	deletespecificpos();
					break;
			case 8:	display();
					break;
			default:printf("invalid");
					break;
		}
	}
}
