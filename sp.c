/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 2
Experiment Name : Sparse Matrix
Date : 12-10-2023
*/



#include <stdio.h>




// function declaration
void matin(int *x[30][30],int *r,int *c);
void matout(int *x[50][30],int r,int c);
void cnvsp_to_tup(int *x[30][30],int *xs[50][3],int *r,int *c);
void cnv_tup_to_sp(int *x[30][30],int *xs[50][3],int *r,int *c);
void transp(int *xs[50][3],int *tsp[50][3]);
void sum(int *sp1[50][3],int *sp2[50][3],int *sumsp[50][3]);
//funtion definitions
// matrix in


void matin(int *x[30][30],int *r,int *c){
        printf("enter number of rows");
        scanf("%d",r);
        printf("enter number of columns");
        scanf("%d",c);
        for(int i=0;i<*r;i++){
                for(int j=0;j<*c;j++){
                        printf("( %d , %d )",i+1,j+1);
                        scanf("%d", x[i][j]);
                }
        }
        matout(x,*r,*c);
}


//matrix out
void matout(int *x[50][30],int r,int c){
        printf("Matrix (%d,%d): \n",r,c);
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        printf("%d\t",*x[i][j]);
                }
                printf("\n");
        }
}


// sparse to tuple
void cnv_sp_to_tup(int *x[30][30],int *xs[50][3],int *r,int *c){
        *xs[0][0]=*r;
        *xs[0][1]=*c;
        int k=1;
        for(int i=0; i<*r; i++){
                for(int j=0;j<*c;j++){
                        if (*x[i][j]==0) {
                                continue;
                        }
                        else {
                                *xs[k][0]=i;
                                *xs[k][1]=j;
                                *xs[k][2]=*x[i][j];
                                k++;
                        }
                }
        }
        *xs[0][2]=k-1;
}



// tuple to sparse
void cnv_tup_to_sp(int *x[30][30],int *xs[50][3],int *r,int *c){
        *r=*xs[0][0];
        *c=*xs[0][1];
        int k=1;
        for(int i=0;i<*r;i++){
                for(int j=0;j<*c;j++){
                        if ((*xs[k][0]==i)&&(*xs[k][1]==j)) {
                                *x[i][j]=*xs[k][2];
                                k++;
                        }
                        else {
                                *x[i][j]=0;
                        }
                }
        }
}



//transpose
void transp(int *xs[50][3],int *tsp[50][3]){
        *tsp[0][0]=*xs[0][1];
        *tsp[0][1]=*xs[0][0];
        *tsp[0][2]=*xs[0][2];
        int k=1;
        for (int i=1;i<=*xs[0][2];i++){
                for ( int j=1;j<*xs[0][2]-i;j++){
                        if (*xs[j][1]==*xs[j+1][1]){
                                if (*xs[j][0]==*xs[j+1][0]){
                                        *tsp[k][0]=*xs[j][1];
                                        *tsp[k][1]=*xs[j][0];
                                        *tsp[k][2]=*xs[j][2];
                                       
                                }
                                else if (*xs[j][0]<*xs[j+1][0]){
                                        *tsp[k][0]=*xs[j][1];
                                        *tsp[k][1]=*xs[j][0];
                                        *tsp[k][2]=*xs[j][2];
                                       
                                }
                                else {
                                        *tsp[k][0]=*xs[j+1][1];
                                        *tsp[k][1]=*xs[j+1][0];
                                        *tsp[k][2]=*xs[j+1][2];
                                        
                                }
                        }
                        else if (*xs[j][1]<*xs[j+1][1]){
                                        *tsp[k][0]=*xs[j][1];
                                        *tsp[k][1]=*xs[j][0];
                                        *tsp[k][2]=*xs[j][2];
                                        
                                }
                        else {
                                *tsp[k][0]=*xs[j+1][1];
                                *tsp[k][1]=*xs[j+1][0];
                                *tsp[k][2]=*xs[j+1][2];
                                
                        }
                }
                k++;
        }
}



//sum
void sum(int *sp1[50][3],int *sp2[50][3],int *sumsp[50][3]){
        int l1=sp1[0][2];
        int l2=sp2[0][2];
        if ((sp1[0][0]==sp2[0][0]) && (sp1[0][1]==sp2[0][1])){
                sumsp[0][0]=sp1[0][0];              
                sumsp[0][1]=sp1[0][1];
                int k=1,i=1,j=1;
                while((i<=l1)&&(j<=l2)){
                        if(sp1[i][0]==sp2[j][0]){ 
                                if(sp1[i][1]==sp2[j][1]){ 
                                        sumsp[k][0]=sp1[i][0];
                                        sumsp[k][1]=sp1[i][1];
                                        *sumsp[k][2]=*sp1[i][2]+*sp2[j][2];
                                        i++;
                                        j++;
                                        k++;
                                }
                                else if(sp1[i][1]<sp2[j][1]){
                                        sumsp[k][0]=sp1[i][0];
                                        sumsp[k][1]=sp1[i][1];
                                        sumsp[k][2]=sp1[i][2];
                                        i++;
                                        k++;
                                }
                                else 
                                {
                                        sumsp[k][0]=sp2[j][0];
                                        sumsp[k][1]=sp2[j][1];
                                        sumsp[k][2]=sp2[j][2];
                                        j++;
                                        k++;
                                }
                        }
                        else if(sp1[i][0]<sp2[j][0]){
                                sumsp[k][0]=sp1[i][0];
                                sumsp[k][1]=sp1[i][1];
                                sumsp[k][2]=sp1[i][2];
                                i++;
                                k++;
                        } 
                        else{
                                sumsp[k][0]=sp2[j][0];
                                sumsp[k][1]=sp2[j][1];
                                sumsp[k][2]=sp2[j][2];
                                j++;
                                k++;
                        }
                }
                while(i<=l1){
                        sumsp[k][0]=sp1[i][0];
                        sumsp[k][1]=sp1[i][1];
                        sumsp[k][2]=sp1[i][2];
                        i++;
                        k++;
                }
                while(j<=l2){
                        sumsp[k][0]=sp2[j][0];
                        sumsp[k][1]=sp2[j][1];
                        sumsp[k][2]=sp2[j][2];
                        j++;
                        k++;
                 }
                 printf("Sum of matrices (Tuple) :\n");
                 matout(sumsp,sumsp[0][2],3);
                 int sum[50][30];
                 int r,c;
                 cnv_tup_to_sp(sum,sumsp,&r,&c);
                 printf("Sum of matrices (Sparse) :\n");
                 matout(sum,r,c);
                 
                
                
        }
        else{
                printf("addition not possisble");
        }
}






void main(){
        int ch=0;
        int a[30][30],r1,c1,b[30][30],r2,c2,sp1[50][3],sp2[50][3],tsp1[50][3],tsp2[50][3],t1[30][30],t2[30][30],sumsp[50][3];
        do{
        printf("Menu:\n\n\t\t1.Read Sparse Matrix 1\n\t\t2.Sparse Matrix  2\n\t\t3. Display Tuple form of matrix 1\n\t\t4. Display Tuple form of matrix 2\n\t\t5. Display transpose of matrix 1\n\t\t6. Display transpose of matrix 2\n\t\t7.Find Sum\n\t\t 0.Exit\n\n\t Choice:");
        scanf("%d",&ch);        
        switch (ch){
                case 1:
                        printf("Sparse Matrix 1 ");
                        matin(a,&r1,&c1);
                        cnv_sp_to_tup(a,sp1,&r1,&c1);
                        continue;
                case 2:
                        printf("Sparse Matrix 2 ");
                        matin(b,&r2,&c2);
                        cnv_sp_to_tup(b,sp2,&r2,&c2);
                        continue;
                case 3: 
                        matout(sp1,sp1[0][2],3);
                        continue;
                case 4: 
                        matout(sp2,sp2[0][2],3);
                        continue;
                case 5:
                        transp(sp1,tsp1);
                        cnv_tup_to_sp(t1,tsp1,&c1,&r1);
                        printf("Transpose of matrix 1 (Tuple) :\n");
                        matout(tsp1,tsp1[0][2],3);
                        printf("Transpose of matrix 1 (Sparse) :\n");
                        matout(t1,c1,r1);
                        continue;
                case 6:
                        transp(sp2,tsp2);
                        cnv_tup_to_sp(t2,tsp2,&c2,&r2);
                        printf("Transpose of matrix 2 (Tuple) :\n");
                        matout(tsp2,tsp2[0][2],3);
                        printf("Transpose of matrix 2 (Sparse) :\n");
                        matout(t2,c2,r2);
                        continue; 
                case 7:
                        sum(sp1,sp2,sumsp);
                        continue;
                case 0:
                        printf("Exiting program....");
                        continue;       
                default:
                        printf("Invalid choice");
                             
        };
        }while (ch!=0);
}
