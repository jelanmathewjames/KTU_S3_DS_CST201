#include <stdio.h>
#include <malloc.h>

typedef struct{
	int coef;
	float expo;
} polynomial;
int main(){
    polynomial poly;
    printf("%d\n%f",poly.coef,poly.expo);
}
