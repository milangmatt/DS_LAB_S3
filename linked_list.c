/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 8
Experiment Name : Linked List
Date : 16-11-2023
*/
#include <stdio.h>
#include <stdlib.h>

//linked list
struct node{
    int data;
    struct node *link;
};

//declare top front and rear
struct node *top,*f,*r;

//Stack Functions
void stack();
void spush(int item);
int spop();
void sdisp();
//Queue Functions
void queue();
void enq(int item);
int deq();
void qdisp();


//Push Function for stack
void spush(int item){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=item;
    newNode->link=NULL;
    if (top==NULL){
        top=newNode;
    }
    else{
        newNode->link=top;
        top=newNode;
    }
    sdisp();
}

//Pop Function for stack
int spop(){
        int dat;
    if (top==NULL){
        printf("\nStack is empty\n");
        return 0;
    }
    else{
        struct node *ptr;
        ptr=top;
        printf("\nPopped Element is : %d\n",top->data);
        dat=top->data;
        top=top->link;
        free(ptr);
        sdisp();
        return dat;
    }
}

//Display Function for stack
void sdisp(){
    struct node *ptr;
    if (top==NULL){
        printf("\nStack is empty\n");
    }
    else{
        ptr=top;
        printf("\nStack elements are : ");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
    }
}

//Enqueue Function in Queue
void enq(int item){
    struct node *newNode=(struct node *)malloc(sizeof (struct node));
    newNode->data=item;
    newNode->link=NULL;
    if(f==NULL){
        f=newNode;
        r=newNode;
    }
    else{
        r->link=newNode;
        r=r->link;
    }
    qdisp();
}

//Dequeue Function in Queue
int deq(){
    int item;
    struct node *ptr;
    if (f==NULL){
        printf("Queue Empty\n");
        return 0;
    }
    else if (f->link==NULL){
        ptr=f;
        printf("Deleted Element : %d",f->data);
        item=f->data;
        f=NULL;
        r=NULL;
        free(ptr);
        return item;
    }
    else{
        ptr=f;
        printf("Deleted Element : %d",f->data);
        item=f->data;
        f=ptr->link;
        free(ptr);
        return item;
    }
    
}

//Display Function in Queue
void qdisp(){
    struct node *ptr;
    if (f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        ptr=f;
        printf("Queue Elements are : ");
        while (ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}

//Queue Menu
void queue(){
    int x,c=-1,item;
    while(c!=0){
        printf("\n1.Enqueue\n2.Delete Queue\n3.Display Queue\n0.Main Menu\n");
        printf("Enter Choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter Element to be Inserted : ");
                scanf("%d",&x);
                enq(x);
                break;
            case 2:
                item=deq();
                break;
            case 3:
                qdisp();
                break;
            case 4:
                item=deq();
                while (item!=0){
                        item=deq();
                }
                printf("Queue deleted\n");
                printf("Exiting ...\n");
                break;
            default :
                printf("Invalid choice\n");    
        }
    }   
}

//Stack Menu
void stack(){
    int x,c=-1,item;
    while(c!=0){
        printf("\n1.Push\n2.Pop\n3.Display\n0.Main Menu\n");
        printf("Enter Choice : ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter Element to be Pushed : ");
                scanf("%d",&x);
                spush(x);
                break;
            case 2:
                item=spop();
                break;
            case 3:
                sdisp();
                break;
            case 0:
                item=spop();
                while (item!=0){
                        item=spop();
                }
                printf("Stack deleted\n");
                printf("Exiting ...\n");
                break;
            default :
                printf("Invalid choice\n");   
        }
    }   
}


void main(){
    int x,ch=-1;
    while(ch!=0){
        printf("\n1.Stack\n2.Queue\n0.Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                stack();
                break;
            case 2:
                queue();
                break;
            case 0:
                printf("Exiting Program ...\n");
                break;
            default :
                printf("Invalid choice\n");
        }
    }
}
