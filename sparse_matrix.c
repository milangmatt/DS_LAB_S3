/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 2
Experiment Name : Sparse Matrix
Date : 12-10-2023
*/

#include <stdio.h>
int create(int a[10][10], int r1, int c1)
{
    int count = 0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                count++;
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return count;
}

int tuple(int a[10][10], int sp[50][3], int r, int c, int n)
{
    sp[0][0] = r;
    sp[0][1] = c;
    sp[0][2] = n;
    int k = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = a[i][j];
                k++;
            }
        }
    }
    return k;
}

void transpose(int sp[50][3], int t[50][3])
{
    t[0][0] = sp[0][1];
    t[0][1] = sp[0][0];
    t[0][2] = sp[0][2];
    int k = 1;
    for (int i = 0; i < sp[0][1]; i++)
    {
        for (int j = 1; j <= sp[0][2]; j++)
        {
            if (i == sp[j][1])
            {
                t[k][0] = sp[j][1];
                t[k][1] = sp[j][0];
                t[k][2] = sp[j][2];
                k++;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
}

void addn(int a[50][3], int b[50][3], int c[100][3])
{
    int i = 1, j = 1, k = 1;
    int r1, r2;
    r1 = a[0][2];
    r2 = b[0][2];
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    while (i <= r1 && j <= r2)
    {
        if (a[i][0] == b[j][0])
        { // row no same
            if (a[i][1] == b[j][1])
            { // column same
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                int temp = a[i][2] + b[j][2];
                if (temp != 0)
                {
                    c[k][2] = temp;
                    k++;
                }
                i++;
                j++;
            }
            else if (a[i][1] < b[j][1])
            {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                i++;
                k++;
            }    // col of a less than col of b
            else // col of b less
            {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                j++;
                k++;
            }
        }
        else if (a[i][0] < b[j][0])
        {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
            k++;
        } // row no diff a less
        else
        {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
            k++;
        }
    }

    while (i <= r1)
    { // remaining elements
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= r2)
    {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }
    c[0][2] = k - 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int a[10][10], b[10][10], r1, r2, c1, c2, n1, n2, sp1[50][3], sp2[50][3], nr1, nr2;
    printf("enter the no of rows of matrix 1:");
    scanf("%d", &r1);
    printf("enter the no of columns of matrix 1:");
    scanf("%d", &c1);
    printf("Enter the elements\n");
    n1 = create(a, r1, c1);
    printf("enter the no of rows of matrix 2:");
    scanf("%d", &r2);
    printf("enter the no of columns of matrix 2:");
    scanf("%d", &c2);
    printf("Enter the elements:\n");
    n2 = create(b, r2, c2);
    printf("tuple representation of matrix 1:\n");
    nr1 = tuple(a, sp1, r1, c1, n1);
    for (int i = 0; i < nr1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", sp1[i][j]);
        }
        printf("\n");
    }
    printf("tuple representation of matrix 2:\n");
    nr2 = tuple(b, sp2, r2, c2, n2);
    for (int i = 0; i < nr2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", sp2[i][j]);
        }
        printf("\n");
    }
    int t1[50][3], t2[50][3], g = 1, q;
    while (g == 1)
    {
        printf("MENU\n1 - transpose\n 2 - addition ");
        scanf("%d", &q);
        switch (q)
        {
        case 1:
        {
            printf("transpose of matrix 1:\n");
            transpose(sp1, t1);
            printf("transpose of matrix 2:\n");
            transpose(sp2, t2);
            break;
        }
        case 2:
        {
            int add[100][3];
            printf("sum of matrices:\n");
            addn(sp1, sp2, add);
            break;
        }
        }
        printf("Do u want to continue yes(1) or no(0): ");

        scanf("%d", &g);
    }
}
