/*Linear search T O(n)*/
#include <stdio.h>

void linearsearch(int arr[], int key, int n)
{
	for(int i = 0; i < n; i++) {
		if(arr[i] == key) {
			printf("%d found at %d\n", key, i); 
			return;
		}
	}
	printf("not found\n");
	return;
}

void read(int arr[],int n){
	for(int i=0;i<n;i++)
     	scanf("%d", &arr[i]);
}

int main(void)
{
	int n;
	printf("Enter the limit\n");
	scanf("%d", &n);

	int arr[n], key;
	printf("Enter the elements\n"); 
	read(arr,n);

	printf("Enter the key for searching\n"); 
	scanf("%d", &key);
    linearsearch(arr,key,n);
}



