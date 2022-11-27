/*Create a binary search tree with the following operations:
	18.1. Insert a new node .
	18.2.Inorder traversal.
	18.3. Preorder traversal.
	18.4. Postorder traversal.
	18.5. Delete a node.*/
	
#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node* left;
	struct Node* right;
	int data;
};
struct Node* root=NULL;

void create_node(int data){
	struct Node* new_node = malloc(sizeof (struct Node));
	new_node->data = data;new_node->left = NULL;new_node->right = NULL;
	return new_node;
}

void insert(int data){
	if(!root){
		struct Node **temp = &root;
		while(temp){
			if(data > temp->data)
				temp = temp->right;
			else if(data < temp->data)
				temp = temp->left;
		}
	}else
		root = create_node(data);
		
}

void delete(){
}

void preorder(){
}

void postorder(){
}

void inorder(){
}

int main(void){

}
