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
