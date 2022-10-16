#include <stdio.h>
#include <malloc.h>

#define MALLOC(p,s) \
	if(!((p) = malloc(s))) {\
		fprintf(stderr,"Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define CALLOC(p,n,s) \
	if(!((p) = calloc(n,s))) {\
		fprintf(stderr,"Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define REALLOC(p,s) \
	if(!((p) = realloc(p,s))) {\
		fprintf(stderr,"Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

int main(){
	printf("hello");
}
