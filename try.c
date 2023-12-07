#include <stdio.h>

#define MAX 30
int c_queue [MAX];
int front_c = -1, rear_c = -1;
int len_c;
void inCircular(int item);
int delCircular();
void dispCircular();

void inCircular(int item){
        rear_c=(rear_c+1)%len_c;
        if ( front_c == rear_c ){
                printf("queue : FULL\n");
                rear_c=(rear_c-1)%len_c;
        }
        else{
                c_queue[rear_c]=item;
        }
        dispCircular();
}
int delCircular(){
        if ( front_c == rear_c ){
                printf("queue : EMPTY\n");
        }
        else{
                front_c=(front_c+1)%len_c;
                int item = c_queue[front_c];
                printf("Popped - > %d\n",item);
                dispCircular();
                return item;
        }
        
}
void dispCircular(){
        if ( front_c == rear_c ){
                printf("queue : EMPTY\n");
        }
        else{
                printf("Circular Queue : \nfront -> ");
                int ptr=front_c+1;
                while (ptr!=rear_c){
                        printf("%d ",c_queue[ptr]);
                        ptr=(ptr+1)%len_c;
                }
                printf("%d <- rear\n",c_queue[ptr]);
        }
}


void main(){
       printf("Enter size of Queue: ");
       scanf("%d",&len_c);
       int choice=1;
       do{
                printf("\n\nMENU: \n");
                printf("\t1.Pop an element\n\t2.Push new element\n\t3.Display Queue\n\t0.Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                delCircular();
                                continue;

                        case 2:
                                printf("Enter Item to Push: ");
                                int item;
                                scanf("%d",&item);
                                inCircular(item);
                                continue;
                        case 3:
                                dispCircular();
                                continue;
                        case 0:
                                printf("Exiting program.....\n");
                                continue;
                        
                        default:
                                printf("Invalid Choice");

                }
        }while(choice!=0); 
}
