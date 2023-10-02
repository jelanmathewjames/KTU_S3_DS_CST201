#include <stdio.h>
#define SWAP(a,b,t) ((t) = (a), (a)= (b), (b)=(t))
	
void quicksort(int a[], int left, int right)
{
	int pivot, i, j, t;
	if(left < right) {
		i = left; 
		j = right + 1;
		pivot = a[left];
		do{
			do i++; while(a[i] < pivot);
			do j--; while(a[j] > pivot);
			if(i < j) SWAP(a[i], a[j], t);
		} while(i < j);
		SWAP(a[left], a[j], t);
		quicksort(a, left, j - 1);
		quicksort(a, j + 1, right);
	}
}

int main(void)
{
	int n;
	printf("Enter the limit");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array of numbers");
	for(int i = 0; i < n; i++)
		scanf("%d",arr+i);

	quicksort(arr,0,n-1);
	printf("Sorted array\n");
	for(int i = 0; i < n; i++)
		printf("%d,",arr[i]);
}
