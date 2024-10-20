#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node* next;
};

struct node* createcll(int data){
    struct node*  newnode=(struct node*)malloc(sizeof(struct node));
    struct node* head;
    newnode->data=data;
    newnode->next=newnode;
    head=newnode;
    return head;
}

struct node* insertatbeg(struct node*head,int data){
    struct node* tail=head, *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        head=newnode=tail;
        newnode->next=newnode;
    }
    else{
        newnode->next=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=newnode;
        head=newnode;
    }
    return head;
}

struct node* insertatend(struct node*head, int data){
    struct node*newnode, *temp, *tail=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        newnode->next=newnode;
        head=tail=newnode;
    }
    else{
        while(tail->next!=head){
            tail=tail->next;
        }
        newnode->next=tail->next;
        tail->next=newnode;
    }
    return head;
}

struct node* insertinmid(struct node* head, int data, int loc){
    int i=1, pos;
    struct node*newnode, *temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        while(i<loc){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}

struct node* deletefrombeg(struct node* head){
    struct node* temp=head;
    struct node* tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    head=head->next;
    tail->next=temp->next;
    free(temp);
    return head;
}

struct node* deletefromend(struct node* head){
    struct node* temp=head, *tail=head;
    struct node* prenode;
    while(tail->next!=head){
        prenode=tail;
        tail=tail->next;
    }
    prenode->next=tail->next;
    free(tail);
    return head;
}

struct node* deleteinmid(struct node* head, int loc){
    int i=1,pos;
    if(loc==1){
        head=deletefrombeg(head);
    }
    struct node* prenode, *temp=head;
    while (i<loc){
        prenode=temp;
        temp=temp->next;
        i++;
    }
    prenode->next=temp->next;
    free(temp);
    return head;
} 

void display(struct node* head){
    struct node *temp=head;
    printf("the list is: \n");
    do{
        printf("%d  ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}


int main(){
    int a, choice,loc,data,n,m,l;
    printf("enter the first element of the list: ");
    scanf("%d", &a);
    struct node *head=createcll(a);
    
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
