#include <stdio.h>

int main(void){	
	int n;
	printf("Enter the limit");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array of numbers");
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
}
