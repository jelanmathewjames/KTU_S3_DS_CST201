#include <stdio.h>
#include <math.h>
#define MAX 30

int top = -1;
char stack[MAX],expr[MAX];

void push(int data){
    if(top<MAX_SIZE-1)
        stack[++top] = data;
    else
        printf("stack overflow\n");
}

int pop(){
   if(top>-1)
        return stack[top--];
   else
        printf("stack is empty\n");
}

//lparen, rparen, plus, minus, times, divide, mod,eos,operand
//isp 0,19,12,12,13,13,13,0
//icp 20,19,12,12,13,13,13,0
int precedence(char token,int type){
	switch(token){
		case '(': type?return 0: return 20;
		case ')': return 19;
	}
}
