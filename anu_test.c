#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char stack[30];
int top = -1;
char push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        char ch = stack[top--];
        return ch;
    }
}
int isoperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    else
        return 0;
}
int priority(char pr)
{
    if (pr == '^')
        return 3;
    if (pr == '/' || pr == '*')
        return 2;
    else if (pr == '+' || pr == '-')
        return 1;
}

void infixtopostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char e, x, m;
    while ((e = infix[i++]) != '\0')
    {
        if (isalnum(e))
            postfix[j++] = e;
        else if (e == '(')
            push(e);
        else if (e == ')')
        {
            while (x = pop() != '('){
                j++;
                postfix[j] = x;
                
            }
    }
        else if (isoperator(e))
        {
            while (top != -1 && priority(stack[top]) >= priority(e))
            {
                postfix[j++] = pop();
            }
            push(e);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression:%s", postfix);
}
void main()
{
    char infix[100], postfix[100];
    int choice;
    while (1)
    {
        printf("\n");
        printf("Menu:\n1.Convert infix to postfix\n2.Evaluate postfix expression\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the infix expression:");
            scanf("%s", infix);
            infixtopostfix(infix, postfix);
            printf("\n");
            break;
        case 2:
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}