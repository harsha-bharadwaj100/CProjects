#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
int S[MAX]; // Change the stack to hold integers
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    S[++top] = value;
}

// Function to pop an element from the stack
int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return S[top--];
}

// Function to get the top element of the stack (not really needed here)
int peek()
{
    if (top == -1)
    {
        return -1;
    }
    return S[top];
}

int main()
{
    char post[MAX] = "231*+4-"; // Example postfix expression
    int a, b;

    for (int i = 0; post[i] != '\0'; i++)
    {
        if (isdigit(post[i]))
        {
            // Convert character to integer and push it
            push(post[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();
            switch (post[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push((int)pow(b, a)); // For exponentiation
                break;
            }
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}
