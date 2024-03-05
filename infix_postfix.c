/*Name : Milan George Mathew
Class : S3DS
Roll No : 39
Experiment No: 4
Experiment Name : Infix to Postfix
Date : 16-11-2023
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void main()
{

	char exp[100];
	printf("enter expression:");
	scanf("%s", exp);

	int len = strlen(exp);
	char output[100];
	int index = 0;

	char stack[100];
	int top = -1;
	int prioritystack[100];

	for (int i = 0; i < len; i++)
	{
		if (isalpha(exp[i]))
		{
			output[index] = exp[i];
			index++;
		}
		else
		{
			int priority;
			switch (exp[i])
			{
			case '+':
				priority = 1;
				break;
			case '-':
				priority = 1;
				break;
			case '*':
				priority = 2;
				break;
			case '/':
				priority = 2;
				break;
			case '^':
				priority = 3;
				break;
			case '(':
				priority = 4;
				break;
			case ')':
				priority = 4;
				break;
			}
			if (top == -1)
			{
				top++;
				stack[top] = exp[i];
				prioritystack[top] = priority;
			}
			else
			{
				if (exp[i] == '(')
				{
					top++;
					stack[top] = exp[i];
					prioritystack[top] = priority;
				}
				else if (exp[i] == ')')
				{
					while (stack[top] != '(')
					{
						output[index] = stack[top];
						top--;
						index++;
					}
					top--;
				}
				else if (exp[i] == '^')
				{
					top++;
					stack[top] = exp[i];
				}
				else
				{
					while (priority <= prioritystack[top] && stack[top] != '(' && top != -1)
					{
						output[index] = stack[top];
						top--;
						index++;
					}
					top++;
					stack[top] = exp[i];
					prioritystack[top] = priority;
				}
			}
		}

		if (i != len - 1)
		{
			printf("Scanned:%c \tstack:%s \toutput:%s\n", exp[i], stack, output);
		}
		else
		{
			printf("Scanned:%c \tstack:%s \t", exp[i], stack);
			while (top != -1)
			{
				output[index] = stack[top];
				top--;
				index++;
			}
			printf("output:%s", output);
		}
	}

	printf("\n");
	int alphacount = 0;
	for (int i = 0; i < len; i++)
	{
		if (isalpha(exp[i]))
		{
			alphacount++;
		}
	}
	int operands[alphacount];
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		if (isalpha(exp[i]))
		{
			printf("enter %c:", exp[i]);
			scanf("%d", &operands[j]);
			j++;
		}
	}
	j = -1;

	top = -1;
	int newstack[alphacount];
	for (int i = 0; i < strlen(output); i++)
	{
		if (isalpha(output[i]))
		{
			top++;
			j++;
			newstack[top] = operands[j];
		}
		else
		{
			int a, b, result;
			a = newstack[top];
			b = newstack[top - 1];

			switch (output[i])
			{
			case '+':
				result = b + a;
				break;
			case '-':
				result = b - a;
				break;
			case '*':
				result = b * a;
				break;
			case '/':
				result = b / a;
				break;
			case '^':
				result = pow(b, a);
				break;
			}
			top -= 1;
			newstack[top] = result;
		}
	}
	printf("\n");
	printf("Result of the expression is %d\n", newstack[0]);
}
