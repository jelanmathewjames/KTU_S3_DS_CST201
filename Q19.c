/*Represent any given graph and
	Perform a depth first search .
	Perform a breadth first search*/
	
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct Vertex{
	int data;
	struct Vertex* link;
} *graph;

int *visited, queue[MAX], rear = -1, front= -1;
void enqueue(int data){
    if((rear+1)%MAX==front){
        printf("Queue is full\n");
    }
    else{
        if(front == -1)
            front = 0;
        rear = (rear+1)%MAX;
        queue[rear] = data;
        
     }   
}

int dequeue(){
    int temp;
    if(rear == -1)
		printf("Queue is empty\n");
    else if(front == rear){
        temp =queue[front];
        front = -1;
        rear = -1;  
        return temp;  
    }
	else{
        temp = queue[front];
        front = (front+1)%MAX;
        return temp;}
	return 0;
}

void bfs(int data){
	enqueue(data);
	struct Vertex* w;
	printf("%d->",data);
	visited[data] = 1;
	while(rear != -1){
		int v = dequeue();
		for(w=&graph[v];w;w=w->link){
			if(!visited[w->data]){
				printf("%d->",w->data);
				enqueue(w->data);
				visited[w->data] = 1;
			}
		}
	}
}

void dfs(int data){
	visited[data] = 1;
	printf("%d->",graph[data].data);
	struct Vertex* w;
	for(w=&graph[data];w;w=w->link){
		if(!visited[w->data])
			dfs(w->data);
	}
}


int main(void){
	int n,c,choice,flag = 1,data;
	printf("Enter the number of vertex. starts from 0");
	scanf("%d",&n);
	graph = malloc(sizeof (struct Vertex) * n);
	visited = malloc(sizeof (int) * n);
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
		for(int i=0;i<n;i++)
			visited[i] = 0;
		printf("\nEnter the choice\n 1 for dfs\n 2 for bfs\n 3 to exit");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the data");scanf("%d",&data);dfs(data);break;
			case 2:printf("Enter the data");scanf("%d",&data);bfs(data);break;
			case 3:flag=0;break;
		}
	}
}
