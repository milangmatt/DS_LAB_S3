#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    char val;
};

void insert(struct node **head, char val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%c ", ptr->val);
        ptr = ptr->next;
    }
}
struct node *reverselist(struct node *head)
{
    struct node *prev = NULL;
    struct node *ptr2 = head;
    struct node *left = NULL;

    while (ptr2 != NULL)
    {
        left = ptr2->next;
        ptr2->next = prev;
        prev = ptr2;
        ptr2 = left;
    }

    return prev;
}
void ispalindrome(struct node *head, struct node *reverse)
{
    struct node *w1 = head;
    struct node *w2 = reverse;
    int flag = 0;
    while (w1 && w2)
    {
        if (w1->val != w2->val)
        {
            flag = 1;
            break;
        }
        w1 = w1->next;
        w2 = w2->next;
    }
    if (flag == 1)
    {
        printf("it is not a palindrome");
    }
    else
    {
        printf("it is a palindrome");
    }
}
void main()
{
    struct node *head = NULL;
    insert(&head, 'c');
    insert(&head, 'a');
    insert(&head, 'c');
    display(head);
    struct node *reverse = reverselist(head);
    display(reverse);
    ispalindrome(head, reverse);
}