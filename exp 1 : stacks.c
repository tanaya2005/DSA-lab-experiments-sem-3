#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 7
int st[MAX];
int Top=-1;

bool isFull();
bool isEmpty();
void push(int a);
void pop();
int gettop();

int main()
{   int choice, num,i;
    
    printf("enter the function to be performed on the stack:\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. check if stack is empty?\n");
    printf("4. check if stack is full\n");
    printf("5. get top most element of stack\n");
    printf("6. exit");
    do{
        printf("\nchoose an operation: ");
        scanf("%d",&choice);
    
    switch(choice){
        case 1: 
        printf("enter the number to be pushed: ");
        scanf("%d",&num);
        push(num);
        break;
        case 2:
        pop();
        break;
        case 3:
        if (isEmpty()){
            printf("the stack is empty.");
        }
        else{
            printf("stack is not empty.");
        }
        break;
        case 4:
        if(isFull()){
            printf("stack is full");
        }
        else{
            printf("stack is not full");
        }
        break;
        case 5:
        gettop();
        break;
        case 6:
        printf("\nexiting the program");
        exit(0);
        default:
        printf("please enter a valid option.");
    }
    
    printf("\nstack is : ");
    int j=0;
     while(j<=Top){
      printf("%d    ", st[j]);
      j++;
     }
     
  } while(choice!=6);
  
  
    return 0;
}

bool isEmpty(){
    return (Top==-1);
}

bool isFull(){
    return(Top==(MAX-1));
}

void push(int a){
    if(isFull()){
        printf("Overflow: the stack is full.");
    }
    else{
        Top=Top+1;
        st[Top]=a;
    }
}

void pop(){
    if(isEmpty()){
        printf("Underflow: stack is empty no element to pop.");
    }
    
    else{
        printf("popped element: %d", st[Top]);
        Top=Top-1;
    }
}

int gettop(){
    if(isEmpty()){
        printf("underflow!");
    }
    else{
        printf("top most element = %d", st[Top]);
    }
}
