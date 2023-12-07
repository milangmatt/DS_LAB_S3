#include <stdio.h>
struct polynomial {
                        int coeff;
                        int exp;
                }p1[10],p2[10],p3[20];
void polyout(struct polynomial *p,int c); 
void polysum(struct polynomial *p1,int c1,struct polynomial *p2,int c2);               
void polyin(struct polynomial *p,int c){
                for (int i=0;i<c;i++){
                        printf("enter the order of element: ");
                        scanf("%d",&p[i].exp);
                        printf("enter the coefficent of element: ");
                        scanf("%d",&p[i].coeff);
                }
                for (int i=0;i<c;i++){
                        for (int j=0;j<c-i;j++){
                                if ( p[j].exp<p[j+1].exp ){
                                        int temp_c=p[j].coeff;
                                        int temp_e=p[j].exp;
                                        p[j].coeff=p[j+1].coeff;
                                        p[j].exp=p[j+1].exp;
                                        p[j+1].coeff=temp_c;
                                        p[j+1].exp=temp_e;
                                }
                                
                        }
                }
                 polyout(p,c);
                }
void polyout(struct polynomial *p,int c){
                for (int i=0;i<c-1;i++){
                        printf(" %dx^%d +",p[i].coeff,p[i].exp);
                        
                        
                }
                printf(" %dx^%d\n",p[c-1].coeff,p[c-1].exp); 
}
void polysum(struct polynomial *p1,int c1,struct polynomial *p2,int c2){
        int i=0,j=0,k=0;
        while ( i<c1 || j<c2){
                if (p1[i].exp==p2[i].exp){
                        p3[k].coeff=p1[i].coeff+p2[j].coeff;
                        p3[k].exp=p1[i].exp;
                        i++;
                        j++;
                        k++;
                }
                else if (p1[i].exp>p2[j].exp){
                        p3[k]=p1[i];
                        i++;
                        k++;
                }
                else {
                        p3[k]=p2[j];
                        j++;
                        k++;
                }
        }
        while (i<c1){
                p3[k]=p1[i];
                i++;
                k++;
        }
        while (i<c2){
                p3[k]=p2[j];
                i++;
                k++;
        }
        polyout(p3,k);
}
void main(){
        int ch=0;
        do{
        printf("Menu:\n\n\t\t1.Read Polynomial 1\n\t\t2.Read Polynomial 2\n\t\t3. Display Polynomial 1\n\t\t4. Display Polynomial 2\n\t\t5.Find Sum\n\n\t 0.Exit\n\n\t Choice:");
        scanf("%d",&ch);        
        switch (ch){
                case 1:
                        printf("enter the number of elements in polynomial: ");
                        int c1;
                        scanf("%d", &c1);
                        polyin(p1,c1);
                        continue;
                case 2:
                        printf("enter the number of elements in polynomial: ");
                        int c2;
                        scanf("%d", &c2);
                        polyin(p2,c2);
                        continue;
                case 3: 
                        printf("polynomial 1: ");
                        polyout(p1,c1);
                        continue;
                case 4: 
                        printf("polynomial 2: ");
                        polyout(p2,c2);
                        continue;
                case 5:
                        printf("polynomial sum: ");
                        polysum(p1,c1,p2,c2);
                default:
                        printf("invalid choice");
                             
        };
        }while (ch!=0);
}