#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top];
}

int main()
{
    char post[] = "231*+9-", op;
    int a, b, res;
    for (int i = 0; i < strlen(post); i++)
    {
        if (isalnum(post[i]))
        {
            push(post[i] - '0');
        }
        else
        {
            op = post[i];
            b = pop();
            a = pop();
            switch (op)
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            case '*':
                push(a * b);
                break;
            case '/':
                if (b != 0)
                    push(a / b);
                else
                {
                    printf("Can't divide by zero\n");
                    return 1;
                }
                break;
            case '%':
                push(a % b);
                break;
            default:
                printf("Invalid operator\n");
                return 1;
            }
        }
    }
    printf("Result: %d\n", pop());
}