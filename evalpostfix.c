#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

double S[MAX];
int top = -1;

// Function to push an element onto the stack
void push(double value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    S[++top] = value;
}

// Function to pop an element from the stack
double pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return S[top--];
}

// Function to get the top element of the stack
double peek()
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
    double op1, op2, result;
    char post[MAX] = "2.3 31.1 .1*+9-1+2/2/";
    for (int i = 0; post[i] != '\0'; i++)
    {
        if (isdigit(post[i]) || post[i] == '.')
        {
            // convert character to double and push it
            // iterate untill a space is encountered
            char *startptr = &post[i];
            char *endptr;
            double num = strtod(startptr, &endptr);
            push(num);

            // update the iterator to the end of the number
            i = endptr - post - 1;
        }
        else if (post[i] == ' ')
        {
            continue;
        }
        else
        {
            op1 = pop();
            op2 = pop();
            switch (post[i])
            {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
                // case '^':
                //     result = pow(op1, op2);
                //     break;
            }
            push(result);
        }
    }

    // Print the result
    printf("Result: %lf\n", pop());
    return 0;
}