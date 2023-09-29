#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int end=-1;
int *arr = NULL;

void initarray(){
	if(arr == NULL)
		arr = malloc(MAX*sizeof (int));
 	else
		printf("array already intialised");
}
void insertarray(int data){
	if(end<MAX)
		printf("array is full");
	else if(arr == NULL){
		initarray();
		arr[++end] = data;
	}else
		arr[++end] = data;
}
void setarray(int data){
	
}

int main(){
}
