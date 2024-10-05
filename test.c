#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char post[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    post[++top] = value;
}

// Function to pop an element from the stack
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return post[top--];
}

// Function to get the top element of the stack
char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return post[top];
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

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
            {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1)
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
