#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top=-1;

void push(char c);
int pop();
int preceedance(char c);
char peek();
int isempty();
void infixtopostfix(char *infix, char *postfix);

void push (char c){
    stack[++top]=c;
}

int pop(){
    return stack[top--];
}

char peek (){
    return stack[top];
}

int isempty(){
    return top==-1;
}

int preceedance(char op){
    switch (op){
        case '+':
        case '-':
        return 1;
        
        case '*':
        case '/':
        return 2;
        
        case '^':
        return 3;
        
        default:
        return 0;
    }
}
void infixtopostfix(char *infix, char* postfix){
    int i=0,j=0;
    while (infix[i]){
        if (infix[i]=='('){
            push (infix[i]);
        }
        
        else if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        
        else if(infix[i]==')'){
            while (!isempty() && peek()!='('){
                postfix[j++]=pop();
            }
            pop(); //pop the '('
        }
        
        else {
            while(!isempty() && preceedance(infix[i])<=preceedance(peek())){
                postfix[j++]=pop();
            }
            push (infix[i]);
        }
        i++;
    }
    
    while(!isempty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0'; //terminate the postfix string
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    int a , choice;
    printf("enter the expression: ");
    gets(infix);
    infixtopostfix(infix,postfix);
    printf("\nthe postfix expression is: %s", postfix);
    return 0;
}
