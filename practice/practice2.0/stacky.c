#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int top = -1;
int stack[MAX];

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

int display()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void checkPalindrome()
{
    char str[MAX];
    printf("Enter string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (pop() != str[i])
        {
            printf("Not a palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}
int main()
{
    int choice, data;
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            if (data != '\0')
                printf("Popped element %d\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            checkPalindrome();
            break;
        default:
            printf("Invalid choice\n");
            return 0;
        }
    }
}