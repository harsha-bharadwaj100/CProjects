#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char S[MAX], post[MAX];
int top = -1, end = 0;

// Function to push an element onto the stack
void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    S[++top] = value;
}

void append(char value)
{
    if (end == MAX - 1)
    {
        printf("postfix overflow\n");
        return;
    }
    post[end++] = value;
    // post[end + 1] = '\0';
}

// Function to pop an element from the stack
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return S[top--];
}

// Function to get the top element of the stack
char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return S[top];
}

// Function to check the precedence of operators
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    // char infix[MAX];
    int k;
    printf("Enter an infix expression: ");
    char infix[MAX] = "(A+(B-C)*D)^E+F";

    // Convert infix to postfix
    int i;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            append(infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                append(pop());
            }
            // pop the '('
            pop();
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
            {
                append(pop());
            }
            push(infix[i]);
        }
    }

    // pop the remaining operators
    while (top != -1)
    {
        append(pop());
    }

    // print the postfix expression
    for (int k = 0; post[k] != '\0'; k++)
    {
        printf("%c", post[k]);
    }
    printf("\n");
    return 0;
}