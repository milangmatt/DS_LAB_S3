/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 4
Experiment Name : Infix to Postfix : Conversion and Evaluation
Date : 2-11-2023
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 30

void pushchar(char item , char stk[MAX]);
char popchar(char stk[MAX]);
void display(char stk[MAX]);
void in_to_post(char expin[MAX],char exppost[MAX]);
void exp_to_eq(char exppost[MAX],char eqpost[MAX]);
double evaluate(char exppost[MAX]);
char popint(int stk[MAX]);
int top = -1;
char expin[MAX];
char exppost[MAX];
char eqpost[MAX];


char popchar(char stk[MAX]){
        if (top==-1){
                printf("\nStack empty\n");
                return 0;
        }
        else{
                char item=stk[top];
                stk[top]='\0';
                top-=1;
                return item;
        }
}
char popint(int stk[MAX]){
        if (top==-1){
                printf("\nStack empty\n");
                return 0;
        }
        else{
                int item=stk[top];
                top-=1;
                return item;
        }
}

void pushchar(char item,char stk[MAX]){
        if (top==MAX-1){
                printf("\nStack full\n");
        }
        else{
                top+=1;
                stk[top]=item;
        }
}
void pushint(int item,int stk[MAX]){
        if (top==MAX-1){
                printf("\nStack full\n");
        }
        else{
                top+=1;
                stk[top]=item;
        }
}

void display(char stk[MAX]){
        if (top==-1){
                printf("\nStack empty\n");
        }
        else{
                for (int i=0;i<=top;i++){
                        printf("%d   ",stk[i]);
                }
                printf("<-(top)\n\n");
        }
}

void in_to_post(char expin[MAX],char exppost[MAX]){
        int i=0,j=0;
        char oprstk[MAX]=" ";
        top=-1;
        char item = expin[i];
        while (item!='\0'){
                if(isalpha(item)){
                        exppost[j]=item;
                        j++;
                }
                else if ((top==-1)||(item =='(')){
                        pushchar(item, oprstk);
                }
                else if (item == '+' || item == '-'){
                        while (oprstk[top]== '*' || oprstk[top]== '/' || oprstk[top]== '^'|| oprstk[top]== '+' || oprstk[top]== '-'){
                                exppost[j]=popchar(oprstk);
                                j++;
                        }
                        pushchar(item,oprstk);
                }
                else if (item == '*' || item == '/'){
                        while (oprstk[top]== '*' || oprstk[top]== '/' || oprstk[top]== '^'){
                                exppost[j]=popchar(oprstk);
                                j++;
                        }
                        pushchar(item,oprstk); 
                }
                else if (item == '^'){
                        pushchar(item,oprstk);
                }
                else if (item == ')'){
                        while(oprstk[top]!='('){
                                exppost[j]=popchar(oprstk);
                                j++;
                        }
                        top -=1;
                }
                printf("Scanned -> %c \tStack -> %s \tOutput -> %s\n",item,oprstk,exppost);
                i++;
                item = expin[i];
        }
        while ( top!=-1 ){
                exppost[j]=popchar(oprstk);
                j++;
        }
}

void exp_to_eq(char exppost[MAX],char eqpost[MAX]){
        int i=0;
        char val;
        eqpost=exppost;
        int len=0;
        while ( eqpost[len]!='\0'){
                len++;
        }
        while ( eqpost[i]!='\0' ){
                if (isalpha(eqpost[i])){
                        printf("Enter value of %c :",eqpost[i]);
                        scanf("%",&val);
                        int j=i;
                        while (eqpost[j]!='\0'){
                                if (eqpost[i]==eqpost[j]){
                                        eqpost[j]=val;
                                        printf("%s",eqpost);
                                }
                                j++;
                        }
                }
                else {
                        eqpost[i]=eqpost[i];
                }
                i++;
        }
        printf("%s",eqpost);
}

double evaluate(char exppost[MAX]){
        exp_to_eq(exppost,eqpost);
        top=-1;
        int i=0;
        int result=0;
        int opndstk[MAX];
        while ( eqpost[i]!='\0'){
                if (isdigit(eqpost[i])){
                        pushint((int)eqpost[i]-48,opndstk);
                }
                else{
                        int a=popint(opndstk);
                        int b=popint(opndstk);
                        switch(eqpost[i]){
                                case '+':
                                        result=b+a;
                                        pushint(result,opndstk);
                                        continue;
                                case '-':
                                        result=b-a;
                                        pushint(result,opndstk);
                                        continue;
                                case '*':
                                        result=b*a;
                                        pushint(result,opndstk);
                                        continue;
                                case '/':
                                        result=b/a;
                                        pushint(result,opndstk);
                                        continue;
                                /*case '^':
                                        result=pow(b,a);
                                        pushint(result,opndstk);
                                        continue;*/
                        }
                        
                }
        }
        return(opndstk[top]);
        
}


void main(){
        int choice=1;
        do{
                printf("MENU: \n");
                printf("\t1.Convert Infix to postfix\n\t2.Evaluate Postfix\n\t0.Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter Infix Expression: ");
                                scanf("%s",expin);
                                in_to_post(expin,exppost);
                                printf("\n\nPostfix Expression: %s\n",exppost);
                                continue;

                        case 2:
                                double result=evaluate(exppost);
                                printf("Result of evaluation: %f \n",result);
                                continue;

                        case 0:
                                printf("Exiting program.....\n");
                                continue;
                        
                        default:
                                printf("Invalid Choice");

                }
        }while(choice!=0);
}
       







