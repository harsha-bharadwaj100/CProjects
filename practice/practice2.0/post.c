#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int top = -1, j = -1;
char stack[MAX], post[MAX];

void push(char ele)
{
    if (top == MAX - 1)
    {
        printf("Overflow!\n");
        return;
    }
    stack[++top] = ele;
}

void append(char ele)
{
    if (j == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    post[++j] = ele;
}

char pop()
{
    if (top == -1)
    {
        printf("Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        printf("Underflow!\n");
        return '\0';
    }
    return stack[top];
}

int precedence(char var)
{
    switch (var)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    char inf[MAX] = "(A+(B-C)*D)^E+F";
    for (int i = 0; i < strlen(inf); i++)
    {
        if (isalpha(inf[i]))
        {
            append(inf[i]);
        }
        else if (inf[i] == '(')
        {
            push(inf[i]);
        }
        else if (inf[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                append(pop());
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(inf[i]))
            {
                append(pop());
            }
            push(inf[i]);
        }
    }
    while (top != -1)
    {
        append(pop());
    }
    printf("Postfix: %s\n", post);
    return 0;
}