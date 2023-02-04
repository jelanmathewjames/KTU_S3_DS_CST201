/*Represent any given graph and
	Perform a depth first search .
	Perform a breadth first search*/
	
#include <stdio.h>
#include <stdlib.h>

struct Vertex{
	int data;
	struct Vertex* link;
};
int main(void){
	int n,c,choice,flag = 1;
	printf("Enter the number of vertex. starts from 0");
	scanf("%d",&n);
	struct Vertex *graph = malloc(sizeof (struct Vertex) * n);
	for(int i=0;i<n;i++){
		graph[i].data = i;
		graph[i].link = NULL;
		struct Vertex *current = &graph[i];
		printf("Enter the vertex linked to %d\n-1 to move next vertex\n",i);
		scanf("%d",&c);
		while(c!=-1){
			if(0<=c && c<=n-1){
				current->link = malloc(sizeof (struct Vertex));
				current = current->link; current->data = c;
				current->link = NULL;
			}else
				printf("Enter valid vertex\n");
			scanf("%d",&c);
		}
	}
	while(flag){
		printf("Enter the choice\n 1 for dfs\n 2 for bfs\n 3 to exit");
		scanf("%d",&choice);
		switch(choice){
			case 1:break;
			case 2:break;
			case 3:flag=0;break;
		}
	}
}
