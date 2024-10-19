#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 7
int queque[MAX];
int rear=-1;
int front=-1;

bool isfull(){
    return (rear==(MAX-1));
}

bool isempty(){
    return (front==-1 && rear==-1);
}

void enqueue(int a){
    if (isfull()){
        printf("overflow");
    }
    else if (front==rear==-1){
        front=0;
        rear=0;
        queque[rear]=a;
    }
    else{
        rear++;
        queque[rear]=a;
    }
}

void dequeue(){
    if(isempty()){
        printf("underflow");
    }
    else if(front==rear){
         printf("dequeueing element: %d at index %d \n",queque[front], front);
        front=rear=-1;
    }
    else{
        printf("dequeueing element: %d at index %d \n",queque[front], front);
        front++;
    }
}

void getfront(){
    printf("the element at the front position is %d at %d",queque[front], front);
}

void getrear(){
    printf("the element at the rear position is %d at %d",queque[rear], rear);
}


int main() {
    int a,n,choice;
    printf("enter the no.of elements in the array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("element %d: ",i+1);
    scanf("%d",&queque[i]);
    printf("\n");
    rear++;
    front=0;
    }
    
    printf("\nchose an operation you want to do on the queue:\n1.enqueue\n2.dequeue\n3.check if full\n4.check if empty\n5.get rear element\n6.get front element\n7.exit\n ");
    do{
        scanf("%d",&choice);
        switch(choice){
        case 1:
        printf("enter the element you eant to enqueue: ");
        scanf("%d",&a);
        enqueue(a);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        if(isfull()){
            printf("queue is full");
        }
        else{
            printf("queue is not full");
        }
        break;
        case 4:
        if(isempty()){
            printf("queue is empty");
        }
        else{
            printf("queue is not empty");
        }
        break;
        case 5: 
        getrear();
        break;
        case 6:
        getfront();
        break;
        case 7:
        exit(1);
        break;
        }
    printf("\nthe queue is: \n");
    for(int i=front;i<=rear;i++){
        printf("%d  ",queque[i]);
    }
     
    printf("\nchoose another operation or press 7 to exit: \n");
    }while (choice!=7);
    return 0;
}
