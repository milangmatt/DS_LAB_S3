/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 3
Experiment Name : Stack
Date : 12-10-2023
*/

#include <stdio.h>
int a[15],top,size;
void push();
void display();
int pop();
int pop(){
        if (top==-1){
                printf("\nStack empty\n");
                return 0;
        }
        else{
                int item=a[top];
                top-=1;
                printf("Stack-> ");
                display();
                return item;
        }
}

void push(){
        if (top==size-1){
                printf("\nStack full\n");
        }
        else{
                int item;
                printf("Enter element to push: ");
                scanf("%d",&item);
                top+=1;
                a[top]=item;
                printf("\nStack-> ");
                display();
        }
}
void display(){
        if (top==-1){
                printf("\nStack empty\n");
        }
        else{
                for (int i=0;i<=top;i++){
                        printf("%d   ",a[i]);
                }
                printf("<-(top)\n\n");
        }
}

void main(){
        int ch;
        printf("Enter size of array: ");
        scanf("%d",&size);
        printf("MENU:\n----------------------------------\n\n\t1.Pop\n\t2.Push\n\t3.Show stack\n0.Exit");
        do{
        printf("\n\nChoice: ");
        scanf("%d",&ch);
        switch (ch){
                case 1:
                        pop();continue;
                case 2:
                        push();continue;
                case 3:
                        display();continue;
                case 0:
                        continue;
                default:
                        printf("Invalid choice\n");continue;
        };
        }while(ch!=0);
        printf("Program Exiting......\n");
  
}
