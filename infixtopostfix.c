#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30
typedef enum {lparen, rparen, plus, minus, times, divide, 
                mod,eos,operand} precedence;

/* isp in-stack precedence | icp incoming precedence */
int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};

int stack[MAX_SIZE], top = -1;
char expr[20],res[20];

int isEmpty(){
    return (top<=-1);
}

int isFull(){
    return (top>=MAX_SIZE-1);
}

void push(int data){
    if(!isFull())
        stack[++top] = data;
    else
        printf("stack overflow\n");
}

int pop(){
   if(!isEmpty())
        return stack[top--];
   else
        printf("stack is empty\n");
}

int peek(){
    if(!isEmpty())
        return stack[top];
}

precedence getToken(char *symbol,int *n){
    *symbol = expr[(*n)++];
    switch(*symbol){
        case '(':return lparen;
        case ')':return rparen;
        case '+':return plus;
        case '-':return minus;
        case '/':return divide;
        case '*':return times;
        case '%':return mod;
        case '\0':return eos;
        default:return operand;   
    }
}

char getSymbol(precedence token){
    switch(token){
        
        case plus:return '+';
        case minus:return '-';
        case divide:return '/';
        case times:return '*';
        case mod:return '%';
        default:return ' ';   
    }
}

void evalPostfix(void){
	precedence token;
    char symbol;
    int op1,op2,n=0;
    token = getToken(&symbol,&n);
    while(token!=eos){
        if(token == operand)
            push(symbol-'0');
        else{
            op1 = pop();
            op2 = pop();
            switch(token){
                case plus:push(op1+op2);
                          break; 
                case minus:push(op1-op2);
                          break;
                case times:push(op1*op2);
                          break;
                case divide:push(op1/op2);
                          break;
                case mod:push(op1%op2);
                          break;           
            }
        }
        token = getToken(&symbol,&n);
    }
    printf("%d",stack[0]);
    
}

void infixtoPostfix(void){
    int n = 0,k = -1;
    top = 0;
    char symbol;
    precedence token;
    stack[0]= eos;
    token = getToken(&symbol,&n);
    while(token != eos){
        
        if(token == operand)
            res[++k] = symbol;
        else if(token == rparen){
            while(stack[top] != lparen)
                res[++k] = getSymbol(pop());
            pop();         
        }else{
            while(isp[stack[top]]>=icp[token])
                res[++k] = getSymbol(pop());
               
            push(token);
        }
        token = getToken(&symbol,&n);
        
    }
    
    
    while((token = pop())!=eos)
        res[++k] = getSymbol(token);
}

int main(){
    int choice;
    printf("Enter\n 1 for postfix evaluation\n 2 for infix to postfix");
    scanf("%d",&choice);
    printf("Enter the expression");
    scanf(" %s",expr);
    switch(choice){
        case 1:
		evalPostfix();
		break;
        case 2:
		infixtoPostfix();
		break;
        default:printf("Invalid Input");
	}
    printf("%s",res);
 
}



