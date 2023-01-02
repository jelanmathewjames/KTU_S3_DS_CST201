/*Create a binary search tree with the following operations:
	18.1. Insert a new node .
	18.2. Inorder traversal.
	18.3. Preorder traversal.
	18.4. Postorder traversal.
	18.5. Delete a node.*/
	
#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *left,*right;
	int data;
}*root=NULL;

struct Node** search(int key){
	struct Node** search = &root;
	while(*search){
		if((*search)->data == key)
			return search;
		else if(key > (*search)->data)
			search = &(*search)->right;
		else
			search = &(*search)->left;
	}printf("Date not found");
	return NULL;
}
void insert(int data){
	struct Node **new_node = &root;
	while(*new_node){
		if(data > (*new_node)->data)
			new_node = &(*new_node)->right;
		else if(data < (*new_node)->data)
			new_node = &(*new_node)->left;
	}*new_node = malloc(sizeof (struct Node));
	(*new_node)->data=data;
	(*new_node)->left=NULL;(*new_node)->right=NULL;
}

void delete_helper(struct Node** delete_node){
	if(*delete_node){
		if(!(*delete_node)->left && !(*delete_node)->right){
			free(*delete_node);
			*delete_node = NULL;
		}else if(!(*delete_node)->left){
			(*delete_node)->data = (*delete_node)->right->data;
			free((*delete_node)->right);
			(*delete_node)->right = NULL;
		}else if(!(*delete_node)->right){
			(*delete_node)->data = (*delete_node)->left->data;
			free((*delete_node)->left);
			(*delete_node)->left = NULL;
		}else{
			
		}
	}
		 
}

void delete(int key){
	delete_helper(search(key));
}


void preorder(){
}

void postorder(){
}

void inorder(){
}

int main(void){

}
