/*binary search T O(log n)*/

#include <stdio.h>

void binarysearch(int arr[], int key, int n)
{
	int left = 0, right = n - 1, mid;
    while(left <= right) {
    	mid = (left + right) / 2;
        if(arr[mid] == key) {
        	printf("%d found at %d\n", key, mid);
            return;
        }
		else if(key > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;	
	}
	printf("not found\n");
	return;
}

void read(int arr[], int n)
{
	for(int i = 0; i < n; i++)
     	scanf("%d", &arr[i]);
}

int main(void)
{
	int n;
	printf("Enter the limit\n");
	scanf("%d", &n);
	
	int arr[n], key;
	printf("Enter the sorted elements\n"); 
	read(arr,n);

	printf("Enter the key for searching\n");
	scanf("%d", &key);
    binarysearch(arr, key, n);
}



