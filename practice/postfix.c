#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50
int top = -1, j = -1;
char S[MAX], post[MAX];

void push(char ele)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    S[++top] = ele;
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return '\0';
    }
    return S[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return '\0';
    }
    return S[top];
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
    // printf("Enter Infix Expression:\n");
    // scanf("%s", inf);
    char inf[MAX] = "(A+(B-C)*D)^E+F";
    for (int i = 0; inf[i] != '\0'; i++)
    {
        if (isalnum(inf[i]))
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
            while (precedence(peek()) >= precedence(inf[i]) && top != -1)
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

    printf("Postfix Expression: ");
    for (int i = 0; post[i] != '\0'; i++)
    {
        printf("%c", post[i]);
    }
    printf("\n");
}