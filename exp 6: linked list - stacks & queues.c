#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

struct snode{
    int data;
    struct snode *next;
}*top=NULL;

struct qnode{
    int data;
    struct qnode *next;
}*front=NULL, *rear=NULL;

void push(int data){
    struct snode*newnode, *temp;
    newnode=(struct snode*)malloc(sizeof(struct snode));
    newnode->data=data;
    if(top==NULL){
        top=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
    printf("pushing %d ",newnode->data);
}


void pop(){
    struct snode *temp=top;
    if(top==NULL){
        printf("underflow");
    }
    
        printf("popping %d", top->data);
        top=top->next;
        free(temp);
    
}

void sdisplay (){
    struct snode*temp;
    temp=top;
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        printf("\nthe stack is: ");
        while(temp!=NULL){
            printf("%d  ", temp->data);
            temp=temp->next;
        }
    }
    
}
void enqueue(int data){
    struct qnode*temp, * newnode=(struct qnode*)malloc(sizeof(struct qnode));
    newnode->data=data;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void qdisplay(){
    struct qnode *temp;
    if(front==NULL && rear==NULL){
        printf("list is empty");
    }
    else{
        temp=front;
        printf("the queue is : \n");
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue(){
    struct qnode*temp=front;
    if(front==0 && rear==0){
        printf("list is empty");
    }
    else{
        front=front->next;
        free(temp);
    }
}


int main() {
    int choice, ch,data,a,m;
    printf("chose what you want to make: 1. stack   2. queue\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
        printf("making a stack, select function: \n1. push\n2.pop\n");
        scanf("%d",&ch);
        while(ch!=1 || ch!=2){
            if(ch==1){
                printf("enter data to push : ");
                scanf("%d",&data);
            push(data);}
            else if(ch==2){
            pop();
            }
            sdisplay();
            printf("\nchose a function: ");
            scanf("%d",&ch);
        }
        
        break;
        case 2:
         printf("making a queue, select function: \n1. enqueue\n2.dequeue\n");
        scanf("%d",&ch);
        while(ch!=1 || ch!=2){
            if(ch==1){
                printf("enter data to enqueue : ");
                scanf("%d",&data);
            enqueue(data);}
            else if(ch==2){
            dequeue();
            }
            qdisplay();
            printf("\nchose a function: ");
            scanf("%d",&ch);
        }
        
    }
    return 0;
}
