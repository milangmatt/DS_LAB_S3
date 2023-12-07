/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 5
Experiment Name : Linear search and Binary Search
Date : 21-09-2023
*/
#include <stdio.h>

void linSearch(int arr[100],int n);
void binSearch(int arr[100],int n);

void main(){
        int arr[100],num,ch;
        printf("Enter array length : ");scanf("%d",&num);
        printf("Enter elements :\n ");
        for(int i=0;i<num;i++){
                printf("Element %d : ",i+1);
                scanf("%d",&arr[i]);
        }
        printf("\n\nMENU\n_______\n\n\t1.Linear Search\n\t2.Binary Search\n__________________________________\n\nEnter a Choice: ");
        scanf("%d",&ch);
        switch (ch) {
                case 1:
                        linSearch(arr,num);
                        break;
                case 2:
                        binSearch(arr,num);
                        break;
                default:
                        printf("Invalid choice\n");
                        break;
        }
}
void linSearch(int arr[100],int n){
        int flag=0,srch;
        printf("Enter number to search : ");scanf("%d",&srch);
        for(int i=0;i<n;i++){
                if (arr[i]==srch){
                        printf("%d found at index %d \n",arr[i],i);
                        flag=1;
                        break;
                }
        }
        if (flag==0){
               printf("Element not Found!\n"); 
        }
}

void binSearch(int arr[100],int n){
        //bubble sort
        for (int i=0;i<n;i++){
                for (int j=0;j<=n-i-1;j++){
                        if (arr[j]>arr[j+1]){
                                int temp=arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                        }
                }
        }
        //binary search
        int srch,flag=0,l=0,r=n,mid;
        printf("Enter number to search : ");scanf("%d",&srch);
        while (l<=r){
                mid=(l+r)/2;
                if (arr[mid]>srch){
                        r=mid-1;        
                }
                else if (arr[mid]<srch){
                        l=mid+1;
                }
                else{
                        printf("%d found at index %d \n",arr[mid],mid-1);
                        flag=1;
                        break;
                }
        }
        if (flag==0){
               printf("Element not Found!\n"); 
        }

}









