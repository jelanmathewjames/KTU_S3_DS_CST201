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


int addtuplehelper(int arr[][3],int *a,int res[][3],int *r){
	res[++(*r)][2] = arr[*a][2];
    res[*r][0] = arr[*a][0];
    res[*r][1] = arr[(*a)++][1];
}

int addtuple(int tuple1[][3],int tuple2[][3],int tuple3[][3]){
    if(tuple1[0][0]!=tuple2[0][0]||tuple1[0][1]!=tuple2[0][1]){
    	printf("Matrix cannot be added\n");
        return 0;
    }
    int i=1,j=1,k=0;
    tuple3[0][0]=tuple1[0][0];
    tuple3[0][1]=tuple1[0][1];
    while(i<= tuple1[0][2] && j<= tuple2[0][2]){
		if(tuple1[i][0]==tuple2[j][0]){
		
        	if(tuple1[i][1]==tuple2[j][1]){
            	tuple3[++k][2] = tuple1[i][2]+tuple2[j][2];
            	tuple3[k][0] = tuple1[i++][0];
            	tuple3[k][1] = tuple2[j++][1];
            }else if(tuple1[i][1]>tuple2[j][1])
                addtuplehelper(tuple1,&i,tuple3,&k);
            else
            	addtuplehelper(tuple2,&j,tuple3,&k);
            	
		}else if(tuple1[i][0]>tuple2[j][0])
        	addtuplehelper(tuple1,&i,tuple3,&k);
        else
        	addtuplehelper(tuple2,&j,tuple3,&k);
    }
    while(i<= tuple1[0][2])
    	addtuplehelper(tuple1,&i,tuple3,&k);
    
    while(j<= tuple2[0][2])
    	addtuplehelper(tuple1,&i,tuple3,&k);
    tuple3[0][2]=k;
    return 1;
}

int main(void){

	int row1,col1,row2,col2;
	
	printf("\nEnter no. of rows and columns for first matrix\n");
	scanf("%d%d",&row1,&col1);
	printf("Enter no. of rows and columns for second matrix\n");
	scanf("%d%d",&row2,&col2);
	int arr1[row1][col1], arr2[row2][col2];
	int tuple1[(row1*col1)+1][3], tuple2[(row2*col2)+1][3];
	int tuple3[(row1*col1)+1][3];
	
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

	if(addtuple(tuple1,tuple2,tuple3)){
		printf("sum of matrix in tuple form\n");
		printf("r  c  v\n");
		display(tuple3[0][2]+1,3,tuple3);
	}
	return 0;
		
	
}
