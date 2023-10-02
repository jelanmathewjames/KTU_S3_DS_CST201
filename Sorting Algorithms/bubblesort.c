#include <stdio.h>
#define SWAP(a,b,t) ((t) = (a), (a)= (b), (b)=(t))

void bubblesort(int arr[], int n)
{
	int t;
	for(int i = 0; i < n; i++)
        for(int j = 0; j < n - i; j++)
            if(arr[j] > arr[j + 1])
                SWAP(arr[j], arr[j+1], t);
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

    bubblesort(arr,n - 1);
    printf("Sorted array\n");
    for(int i = 0; i < n; i++)
        printf("%d,", arr[i]);
}