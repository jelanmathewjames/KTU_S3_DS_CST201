#include <stdio.h>

void binarysearch(int arr[],int key,int n){
	int left=0,right=n-1,mid;
    while(left<=right){
    	mid = (left+right)/2;
        if(arr[mid]==key){
        	printf("%d found at %d\n",key,mid);
            return;
        }else if(key>arr[mid])
            left = mid+1;
        else
            right = mid-1;	
	}printf("not found\n");
	return;
}

void linearsearch(int arr[],int key,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			printf("%d found at %d\n",key,i); 
			return;
		}
	}printf("not found\n");
	return;
}

void read(int arr[],int n){
	for(int i=0;i<n;i++)
     	scanf("%d", &arr[i]);
}

int main(void){
	int n, key, choice,flag=1;
	while(flag){
		printf("Enter\n 1 for linear search\n 2 for binarysearch\n 3 for exit\n");
		scanf("%d",&choice);
		printf("Enter the limit\n");
		scanf("%d",&n);
		int arr[n];
		switch(choice){
			case 1:printf("Enter the elements\n"); read(arr,n);
    			   printf("Enter the key for searching\n"); scanf("%d", &key);
    			   linearsearch(arr,key,n);break;
    		case 2:printf("Enter the sorted elements\n"); read(arr,n);
    			   printf("Enter the key for searching\n"); scanf("%d", &key);
    			   binarysearch(arr,key,n);break;
    		case 3:flag=0;break;
    		default:printf("Invalid input\n");
    	}
    }
}



