#include <stdio.h>

void insertionsort(int a[], int n)
{
	for(int j = 1; j < n; j++) {
		int e  = a[j], i = j - 1;
		while(e < a[i] && i != -1) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = e;
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

	insertionsort(arr,n);
	printf("Sorted array\n");
	for(int i=0;i<n;i++)
		printf("%d,",arr[i]);
}
