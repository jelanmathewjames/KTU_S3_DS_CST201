#include <stdio.h>
#define SWAP(a,b,t) ((t) = (a), (a)= (b), (b)=(t))

void selectionsort(int arr[],int n)
{
	for(int i = 0; i <= n - 1; i++){
		int min = i, t;
		for(int j = i + 1; j <= n; j++)
			if(arr[min] > arr[j])
				min = j;
		if(i != min)
			SWAP(arr[i], arr[min], t);
	}
}

int main(void) 
{
    int n;
    printf("Enter the limit");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array of numbers");
    for(int i = 0; i < n; i++)
        scanf("%d", arr+i);

    selectionsort(arr,n - 1);
    printf("Sorted array\n");
    for(int i = 0; i < n; i++)
        printf("%d,", arr[i]);
}