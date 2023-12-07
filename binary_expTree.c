/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 
Experiment Name : 
Date : 30-11-2023
*/

#include<stdio.h>
#include<stdlib.h>

struct tree{
    char data;
    struct tree* left;
    struct tree* right;
};

struct tree * newNode(char data){
    struct tree* node = (struct tree*)malloc(sizeof(newNode));
    node->left =NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

struct tree* nullNode(){
    struct tree* nullNode = (struct tree*)malloc(sizeof(struct tree));
    nullNode->left=NULL;
    nullNode->right=NULL;
    nullNode->data='\0';
    return nullNode;
}

struct tree* ptr = NULL;

void inorder(struct tree*ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%c",ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct tree* ptr){
    if(ptr!=NULL){
        printf("%c",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct tree* ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%c",ptr->data);
    }
}

void insertTree(struct tree* ptr){
    char dat[2];
    int choice;
    printf("Enter data: ");
    scanf("%s",dat);
    ptr->data = (char)dat[0];
    printf("Does %c have a left child?(1/0): ",ptr->data);
    scanf("%d", &choice);
    if(choice == 1){
        ptr->left = nullNode();
        insertTree(ptr->left);
    }

    printf("Does %c have a right child?(1/0): ",ptr->data);
    scanf("%d",&choice);
    if(choice == 1){
        ptr->right = nullNode();
        insertTree(ptr->right);
    }
}

int main(){
    int g;
    struct tree* root = nullNode();
    printf("Enter the Expression:\n");
    insertTree(root);
    while(1){
        printf("\n1.InOrder   \n2.PreOrder   \n3.PostOrder   \n4.Exit\n");
        printf("Enter your choice:"); 
        scanf("%d", &g);
        switch(g){
            case 1:inorder(root);break;
            case 2: preorder(root);break;
            case 3: postorder(root);break;
            case 4: exit(0);break;
        }
    }
    return 0;
}
