#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node* next;
};

struct node* createll(int a){
    struct node* head, *temp, *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    head=newnode;
    newnode->data=a;
    newnode->next=NULL;
    return head;
}

struct node *insertatbeg(struct node * head, int data){
    struct node * temp, *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=head;
    newnode->data=data;
    newnode->next=head;
    head=temp=newnode;
    return head;
}

struct node* insertatend(struct node* head, int data){
    struct node *temp, *newnode;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

struct node* insertinmid(struct node* head, int data, int pos)
{ 
    struct node* temp=head;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int i=1,loc;
    newnode->data=data;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;    
}


void display(struct node * head){
    struct node* temp=head;
    if(head==NULL){
        printf("the list is empty.");
    }
    else{
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

struct node* deletefrombeg(struct node*head){
    struct node*temp=head;
    if(head==NULL){
        printf("list is already empty");
    }
    else{
        head=head->next;
        free(temp);
    }
    return head;
}

struct node* deletefromend(struct node* head){
    struct node* prenode,*temp=head;
    while(temp->next!=NULL){
        prenode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=NULL;
        free(temp);
    }
    else{
        prenode->next=NULL;
        free(temp);
    }
    return head;
}

struct node* deleteinmid(struct node* head, int loc){
    struct node *temp=head, *dnode;
    int i=1;
    while(i<loc-1){
        temp=temp->next;
        i++;
    }
    dnode=temp->next;
    temp->next=dnode->next;
    free(dnode);
    return head;
}
int main(){
    int a, choice,loc,data,n,m,l;
    printf("enter the first element of the list: ");
    scanf("%d", &a);
    struct node *head=createll(a);
    
    printf("chose an operation: \n 1.insert a node at start\n2.insert a node at end\n3. insert a node at a particular place\n4.delete a node from start\n5.delete a node from end\n6.delete a node at a particular place.\n7.exit\n");
    do{
        scanf("%d",&choice);
        switch(choice){
        case 1:
        printf("enter the number to be inserted: ");
        scanf("%d",&data);
        head=insertatbeg(head,data);
        break;
        
        case 2:
        printf("enter the number to be inserted: ");
        scanf("%d",&data);
        head=insertatend(head,data);
        break;
        
        case 3:
        printf("enter the number to be inserted: ");
        scanf("%d",&data);
        printf("enter the position after which the node is to be inserted: ");
        scanf("%d",&loc);
        head=insertinmid(head,data,loc);
        break;
        
        case 4:
        head=deletefrombeg(head);
        break;
        
        case 5:
        head=deletefromend(head);
        break;
        
        case 6:
        printf("enter thhe position of the node to be deleted: ");
        scanf("%d",&loc);
        head=deleteinmid(head,loc);
        break;
        
        case 7:
        exit(1);
        break;
        }
        display(head);
        printf("\n");
    }while(choice!=7);
    
}
