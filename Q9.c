/*Using stack convert an infix expression to a postfix expression and evaluate
the postfix expression.*/

#include <stdio.h>
#include <math.h>
#define MAX 30

int top = -1;
int stack[MAX];
char expr[MAX],res[MAX];

void push(int data){
    if(top<MAX-1)
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

int precedence(char token,int type){
	int prec;
	switch(token){
		case '(': prec = type?0:20;break;
		case ')': prec = 19;break;
		case '+':
		case '-': prec = 12;break;
		case '*': 
		case '/':
		case '%': prec = 13;break;
		case '^': prec = 14;break;
		default: prec = -1;
	}return prec;
}

void infixtopostfix(void){
	int k=0,n=0;
	while(expr[n] != '\0'){
		if(precedence(expr[n],1)==-1)
			res[k++] = expr[n];
		else if(expr[n] == ')'){
			while(stack[top] != '(')
				res[k++] = pop();
			pop();
		}else{
			while((top>-1)&&(precedence(stack[top],1)>=precedence(expr[n],0)))
				res[k++] = pop();
			push(expr[n]);
		}
		n++;
	}
	while(top>-1)
		res[k++] = pop();
}

void evalpostfix(void){
	int n=0,op1,op2;
	while(res[n] != '\0'){
		if(precedence(res[n],1) == -1)
			push(res[n]-'0');
		else{
			op1=pop();op2=pop();
			switch(res[n]){
				case '+': push(op2+op1);break;
				case '-': push(op2-op1);break;
				case '*': push(op2*op1);break;
				case '/': push(op2/op1);break;
				case '%': push(op2%op1);break;
				case '^': push(pow(op2,op1));break;
			}
		}
		n++;
	}
}

int main(void){
	printf("Enter the infix expression");
	scanf("%s",expr);
	infixtopostfix();
	printf("postfix expression : %s\n",res);
	evalpostfix();
	printf("result: %d\n",pop());
}




