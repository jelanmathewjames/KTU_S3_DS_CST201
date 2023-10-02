/*program to enter two matrices in normal form . Write a function to
convert two matrices to tuple form and display it. Also find the transpose of
the two matrices represented in tuple form and display it.*/

/*A sparse matrix is a matrix in which most of the elements are zero. 
 By contrast, if most of the elements are nonzero, then the matrix is 
 considered dense. The number of zero-valued elements divided by the total 
 number of elements is called the sparsity of the matrix 
 (which is equal to 1 minus the density of the matrix).
 Now to keep track of non-zero elements in a sparse matrix we have 3-tuple 
 method using an array. Elements of the first row represent the number of rows, 
 columns and non-zero values in the sparse matrix. Elements of the other rows 
 give information about the location and value of non-zero elements
*/


#include <stdio.h>

void display(int row, int col, int arr[][col]) 
{
	for(int i = 0;i < row;i++) {
		for(int j = 0; j < col; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void readmatrix(int row, int col, int arr[][col]) 
{
	for(int i = 0;i < row; i++)
		for(int j = 0; j < col; j++)
			scanf("%d", &arr[i][j]);
}

void matrixtotuple(int row, int col, int arr[][col], int tuple[][3])  
{
    int current = 0;
	tuple[0][0] = row; 
	tuple[0][1] = col; 
	tuple[0][2] = 0;
	
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++) {
			if(arr[i][j] != 0) {
				current++;
				tuple[current][0] = i;
				tuple[current][1] = j;
			    tuple[current][2] = arr[i][j];
			}
		}

	tuple[0][2] = current;
}

void transposetuple(int tuple[][3], int trans[][3])
{
	/* transposetuple() calculates the number of elements corresponds 
	to each column and store it in a rowterms[], index of array and 
	column is related. Then caluclates the starting point of each column and
	store it in startingpos[]. swap row and column and place it in 
	corresponding position of that column from startingpos[] 
	and increment value in startingpos[]*/
	
	int rowterms[tuple[0][1]], startingpos[tuple[0][1]];
	int i, j, numcols = tuple[0][1], numterms = tuple[0][2];
	trans[0][0] = tuple[0][1];
	trans[0][1] = tuple[0][0];
	trans[0][2] = tuple[0][2];
	if(numterms > 0) {
		for(i = 0; i < numcols; i++)
			rowterms[i] = 0;
		for(i = 1; i <= numterms; i++)
			rowterms[tuple[i][1]]++;
		startingpos[0] = 1;
		for(i = 1; i <= numcols; i++)
			startingpos[i] = startingpos[i-1] + rowterms[i-1];
		for(i = 1; i <= numterms; i++){
			j = startingpos[tuple[i][1]]++;
			trans[j][0] = tuple[i][1];
			trans[j][1] = tuple[i][0];
			trans[j][2] = tuple[i][2];
		}
	}
}

int main(void)
{
	int row1,col1,row2,col2;
	
	printf("\nEnter no. of rows and columns for first matrix\n");
	scanf("%d%d", &row1, &col1);
	printf("Enter no. of rows and columns for second matrix\n");
	scanf("%d%d", &row2, &col2);
	int arr1[row1][col1], arr2[row2][col2];
	int tuple1[(row1 * col1) + 1][3], tuple2[(row2 * col2) + 1][3];
	int transtuple1[(row1 * col1) + 1][3], transtuple2[(row2 * col2) + 1][3];
	
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
	
	transposetuple(tuple1,transtuple1);
	transposetuple(tuple2,transtuple2);
	printf("r-row, c-column, v-value\n");
	printf("first matrix transpose in tuple form\n");
	printf("r  c  v\n");
	display(transtuple1[0][2]+1,3,transtuple1);
	printf("second matrix transpose in tuple form\n");
	printf("r  c  v\n");
	display(transtuple2[0][2]+1,3,transtuple2);
	
	return 0;

}
























































