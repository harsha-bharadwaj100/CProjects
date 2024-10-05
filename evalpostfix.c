#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char S[MAX];
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

// void append(char value)
// {
//     if (end == MAX - 1)
//     {
//         printf("postfix overflow\n");
//         return;
//     }
//     post[end++] = value;
//     // post[end + 1] = '\0';
// }

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

// Evaluate the postfix expression
int main()
{
    char post[MAX] = "ABC-D*+E^F+";
    for (int i = 0; post[i] != '\0'; i++)
    {
        if (isdigit(post[i]) || isalpha(post[i]))
        {
            push(post[i]);
        }
        else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
        {
            char op1 = pop();
            char op2 = pop();
            char result;
            switch (post[i])
            {
            case '+':
                result = (int)op1 + (int)op2;
                break;
            case '-':
                result = (int)op1 - (int)op2;
                break;
            case '*':
                result = (int)op1 * (int)op2;
                break;
            case '/':
                result = (int)op1 / (int)op2;
                break;
            case '^':
                result = pow((int)op1, (int)op2);
                break;
            }
            push(result);
        }
    }

    // Print the result
    printf("Result: %d\n", pop());
    return 0;
}