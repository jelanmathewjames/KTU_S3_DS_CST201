#include <stdio.h>

void display(int row, int col, int arr[][col]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

void readmatrix(int row,int col,int arr[][col]){
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			scanf("%d",&arr[i][j]);
}

void matrixtotuple(int row,int col,int arr[][col],int tuple[][3]){
    int current = 0;
	tuple[0][0] = row, tuple[0][1] = col, tuple[0][2] = 0;
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++){
			if(arr[i][j]!=0){
				current++;
				tuple[current][0] = i, tuple[current][1] = j, tuple[current][2] = arr[i][j];
			}
		}
	tuple[0][2] = current;
}

void transposetuple(int tuple[][3]){
	for(int i =0; i<=tuple[0][2]; i++){
		int temp = tuple[i][0];
		tuple[i][0] = tuple[i][1];
		tuple[i][1] = temp;
	}
}

int addtuple(tuple1[][3],tuple2[][3]){
    if(
    int i=1, j=1,k=0;
	while(i<= tuple1[0][2] && j<= tuple2[0][2]){
		if(tuple1[i][2]==tuple2[j][2]
	}
}

int main(){

	int row1,col1,row2,col2;
	
	printf("\nEnter no. of rows and columns for first matrix\n");
	scanf("%d%d",&row1,&col1);
	printf("Enter no. of rows and columns for second matrix\n");
	scanf("%d%d",&row2,&col2);
	int arr1[row1][col1], arr2[row2][col2];
	int tuple1[(row1*col1)+1][3], tuple2[(row2*col2)+1][3];
	
	printf("Enter first matrix elements");
	readmatrix(row1,col1,arr1);
	printf("Enter second matrix elements");
	readmatrix(row2,col2,arr2);
	
	matrixtotuple(row1,col1,arr1,tuple1);
	matrixtotuple(row2,col2,arr2,tuple2);
	printf("r-row, c-column, v-value\n");
	printf("first matrix in tuple form\n");
	printf("r  c  v\n");
	display(tuple1[0][2]+1,3,tuple1);
	printf("second matrix in tuple form\n");
	printf("r  c  v\n");
	display(tuple2[0][2]+1,3,tuple2);
	
	transposetuple(tuple1);
	transposetuple(tuple2);
	printf("r-row, c-column, v-value\n");
	printf("first matrix transpose in tuple form\n");
	printf("r  c  v\n");
	display(tuple1[0][2]+1,3,tuple1);
	printf("second matrix transpose in tuple form\n");
	printf("r  c  v\n");
	display(tuple2[0][2]+1,3,tuple2);
}
























































