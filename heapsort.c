#include <stdio.h>
#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

void adjust(int a[],int root,int n){
	int temp = a[root], child = root*2;
	while(child<=n){
		if((child<n)&&(a[child]<a[child+1]))
			child++;
		if(temp > a[child])
			break;
		else{
			a[child/2] = a[child];
			child *= 2;
		}
	}a[child/2] = temp;
}

void heapsort(int a[], int n){
	int i,j,temp;
	for(i = n/2;i>0;i--)
		adjust(a,i,n);
	for(i = n-1;i>0;i--){
		SWAP(a[1],a[i+1],temp);
		adjust(a,1,i);
	}
}

int main(void){
	int n;
	printf("Enter the limit");
	scanf("%d",&n);
	int arr[n+1];
	printf("Enter the array of numbers");
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	heapsort(arr,n);
	for(int i=1;i<=n;i++){
		printf("%d",arr[i]);
	}
}
