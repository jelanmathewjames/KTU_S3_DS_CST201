#include <stdio.h>
#define SWAP(a,b,t) ((t) = (a), (a)= (b), (b)=(t))
void selectionsort(int arr[],int n){
	for(int i=0;i<=n-1;i++){
		int min = i,t;
		for(int j=i+1;j<=n;j++)
			if(arr[min]>arr[j])
				min = j;
		if(i!=min)
			SWAP(arr[i],arr[min],t);
	}
}
void bubblesort(int arr[],int n){
	int t;
	for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (arr[j] > arr[j + 1])
                SWAP(arr[j],arr[j+1],t);
}
void quicksort(int a[],int left,int right){
	int pivot,i,j,t;
	if(left<right){
		i = left; j = right+1;
		pivot = a[left];
		do{
			do i++; while(a[i]<pivot);
			do j--; while(a[j]>pivot);
			if(i<j) SWAP(a[i],a[j],t);
		} while(i<j);
		SWAP(a[left],a[j],t);
		quicksort(a,left,j-1);
		quicksort(a,j+1,right);
	}
}
void merge(int arr[], int left, int mid, int right){
    int i = left,j = mid + 1,k=0;
    int temp[right - left + 1];
    while (i <= mid && j <= right)
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}
void mergesort(int arr[], int left, int right){
    if ( left < right ){
        int mid = (left + right) / 2;
    	mergesort(arr,left,mid);
    	mergesort(arr,mid + 1,right);
    	merge( arr, left, mid, right);
    }
}
void insertionsort(int a[],int n){
	for(int j=1;j<n;j++){
		int e  = a[j],i=j-1;
		while(e<a[i] && i!=-1){
			a[i+1] = a[i];
			i--;
		}a[i+1] = e;
	}
}
void printarray(int arr[],int n){
	printf("Sorted array\n");
	for(int i=0;i<n;i++)
		printf("%d",arr[i]);
	printf("\n");
}
int main(void){
	int n,flag=1;
	while(flag){
		printf("Enter the limit\n");
		scanf("%d",&n);
		int arr[n],choice;
		printf("Enter the values\n");
		for(int i=0;i<n;i++)
			scanf("%d",arr+i);
		printf("Enter choice\n1 for selection sort\n2 for bubble sort\n");
		printf("3 for insertion sort\n4 for quick sort\n");
		printf("5 for merge sort\n6 for exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:selectionsort(arr,n-1);printarray(arr,n);break;
			case 2:bubblesort(arr,n-1);printarray(arr,n);break;
			case 3:insertionsort(arr,n);printarray(arr,n);break;
			case 4:quicksort(arr,0,n-1);printarray(arr,n);break;
			case 5:mergesort(arr,0,n-1);printarray(arr,n);break;
			case 6:flag=0;break;
			default:printf("Enter valid number\n");
		}
	}
}
