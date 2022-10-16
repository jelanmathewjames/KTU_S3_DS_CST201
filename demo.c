#include <stdio.h>
#include <malloc.h>
#define MALLOC(o,s)\
    if(!((o) = malloc(s*10))){\
        printf("ff");\
    }
int main(){
    /*int* o=NULL;
    int i;
    MALLOC(o,sizeof(int));
    for(i =0;i<10;i++)
        *(o+i) = i;
    for(i =0;i<10;i++)
        printf("%d",*(o+i));*/
    char a[] = "hel";
    printf("%c",a[3]);
}
