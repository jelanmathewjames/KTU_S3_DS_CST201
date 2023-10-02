 /*binary search tree with the following operations:
	Insert a new node .
	Inorder traversal.
	Preorder traversal.
	Postorder traversal.
	Delete a node.*/
	
#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *left, *right;
	int data;
} *root=NULL;

struct Node** search(int key)
{
	struct Node** search = &root;
	while(*search) {
		if((*search)->data == key)
			return search;
		else if(key > (*search)->data)
			search = &(*search)->right;
		else
			search = &(*search)->left;
	}
	printf("Date not found");
	return NULL;
}

void insert(int data)
{
	struct Node **new_node = &root;
	while(*new_node) {
		if(data > (*new_node)->data)
			new_node = &(*new_node)->right;
		else if(data < (*new_node)->data)
			new_node = &(*new_node)->left;
		else {
			printf("duplicate value not allowed");
			return;
		}
	}
	*new_node = malloc(sizeof (struct Node));
	(*new_node)->data=data;
	(*new_node)->left=NULL;
	(*new_node)->right=NULL;
}

void delete_helper(struct Node** delete_node)
{
	if(*delete_node) {
		if(!(*delete_node)->left && !(*delete_node)->right) {
			free(*delete_node);
			*delete_node = NULL;
		}
		else if(!(*delete_node)->left) {
			(*delete_node)->data = (*delete_node)->right->data;
			free((*delete_node)->right);
			(*delete_node)->right = NULL;
		}
		else if(!(*delete_node)->right) {
			(*delete_node)->data = (*delete_node)->left->data;
			free((*delete_node)->left);
			(*delete_node)->left = NULL;
		}
		else {
			struct Node** successor = &(*delete_node)->right;
			while((*successor)->left)
				successor = &(*successor)->left;
			(*delete_node)->data = (*successor)->data;
			free(*successor);
			*successor = NULL;
		}
	}		 
}

void delete(int key)
{
	delete_helper(search(key));
}

void preorder(struct Node* node)
{
	if(node) {
		printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct Node* node)
{
	if(node) {
		preorder(node->left);
		preorder(node->right);
		printf("%d ",node->data);
	}
}

void inorder(struct Node* node)
{
	if(node) {
		preorder(node->left);
		printf("%d ",node->data);
		preorder(node->right);
	}
}

int main(void)
{
	int choice, data, position, flag = 1;
	
    while(flag) {
    	printf("Enter the choice\n 1 for Insert element to tree\n");
    	printf(" 2 Delete element from tree\n 3 preorder traversal\n");
    	printf(" 4 inorder traversal\n 5 postorder traversal\n");
    	printf("6 for exit\n");
    	scanf("%d", &choice);

    	switch(choice) {
        	case 1:printf("Enter data to insert");
				   scanf("%d",&data);
        		   insert(data);
				   break;
        	case 2:printf("Enter data to delete");
			       scanf("%d",&data);
            	   delete(data);
				   break;
        	case 3:preorder(root);
			       break;
        	case 4:inorder(root);
			       break;
        	case 5:postorder(root);
			       break;
        	case 6:flag=0;
			       break;
        	default:printf("invalid input");
			        break;
        }
    }
    return 0;
}
