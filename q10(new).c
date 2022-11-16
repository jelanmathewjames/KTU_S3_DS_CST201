// singly linked list operations
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;

struct node *createNode(int data){
    struct node *newnode = malloc(sizeof(struct node));
    if(newNode!=NULL){
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
    }
    else{
      printf("Error.(memmory allocation failed)");
      eixit(0);
    }
}

void printList(){
    struct node *ptr = head;
    printf("List : ");
    if(head==NULL){
        printf("List Empty\n");
    }
    else{
        while (ptr != NULL) {
            printf("%d ", ptr->data);
             ptr = ptr->link; 
        }
        printf("\n");
    }
}

void insertAtFront(int x) {
    struct node *newNode=createNode(x);
    newNode->link=head;
    head=newNode;
}

void insertAtEnd(int x){
    struct node *newNode=createNode(x);
    if(head==NULL)
        head=newNode;
    else{
        struct node *ptr=head;
        while(ptr->link!= NULL)
            ptr=ptr->link;
        ptr->link=newNode;
    }
}

void insertAtPos(int x,int pos){
    if(pos<1)
        printf("Invalid! positon should start from 1\n");
    else if(pos==1){
        struct node *newNode=createNode(x);
        newNode->link=head;
        head = newNode;
    }
    else if (head==NULL)
        printf("sorry,List empty can't insert at position %d\n",pos);
    else{
        int elemNum=1;
        struct node *temp=head;
        while(temp!=NULL&&elemNum<pos-1){
            temp=temp->link;
            elemNum++;
        }
        if(temp==NULL)
            printf("Sorry there are only %d nodes in the list\n",elemNum-1);
        else{
            struct node *newNode =createNode(x);
            newNode->link=temp->link;
            temp->link=newNode;
        }
    }
}

void deleteFront(){
    if(head==NULL)
        printf("List Empty\n");
    else{
        struct node *temp= head;
        head=head->link;
        free(temp);
    }
}

void deleteEnd(){
    if(head==NULL)
        printf("List Empty\n");
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        while(temp->link->link!=NULL)
            temp=temp->link;
        free(temp->link);
        temp->link=NULL;
    }
}

void deletePos(int pos){
    if(pos<1)
        printf("Invalid ! position should start from 1\n");
    else if(pos==1){
        struct node *temp=head;
        head=head->link;
        free(temp);
    }
    else if (head==NULL)
        printf("list Empty\n");
    else{
        int elemNum=1;
        struct node *prev=head;
        while(prev->link!=NULL && elemNum <pos-1){
            prev=prev->link;
            elemNum++;
        }
        if(prev->link==NULL)
            printf("Sorry ,there are only %d elements in the list \n",elemNum);
        else{
            struct node *curr=prev->link;
            prev->link=curr->link;
            free(curr);
        }
    }
}

int main(){
    int choice,data,pos;
    do{
       printf("Enter");
       printf("\n1. Display");
       printf("\n2. Insert at Beginning");
       printf("\n3. Insert at End");
       printf("\n4. Insert at a specified position");
       printf("\n5. Delete from beginnig");
       printf("\n6. Delete from End");
       printf("\n7. Delete from a specified position");
       printf("\n8. Exit\n");
       scanf("%d",&choice);
       switch(choice){
            case 1: printList();
                    break;
            case 2: printf("Enter the data :");
                    scanf("%d",&data);
                    insertAtFront(data);
                    break;
            case 3: printf("Enter the data :");
                    scanf("%d",&data);
                    insertAtEnd(data);
                    break;
            case 4: printf("Enter the data :");
                    scanf("%d",&data);
                    printf("Enter the position:");
                    scanf("%d",&pos);
                    insertAtPos(data,pos);                   
                    break;            
            case 5: deleteFront();
                    break;
            case 6: deleteEnd();
                    break;
            case 7: printf("Enter the position: ");
                    scanf("%d",&pos);
                    deletePos(pos);
                    break;           
       }
    }while(choice<8);
}

