#include <stdio.h>
#include <string.h>
#define MAX 50

// Global variables
int stack[MAX];
int top = -1;

// Function prototypes
void push(int value);
int pop();
void display();
int isPalindrome(char *str);

// Push operation
void push(int value)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

// Pop operation
int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return -1;
    }
    return stack[top--];
}

// Display stack contents
void display()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

// Check if string is palindrome using stack
int isPalindrome(char *str)
{
    int length = strlen(str);
    int i, temp_top = top;

    // Push first half of characters onto stack
    for (i = 0; i < length / 2; i++)
    {
        push(str[i]);
    }

    // Skip middle character for odd length strings
    if (length % 2 != 0)
    {
        i++;
    }

    // Compare remaining characters with popped values
    while (i < length)
    {
        if (str[i] != pop())
        {
            top = temp_top; // Restore original stack
            return 0;       // Not a palindrome
        }
        i++;
    }

    top = temp_top; // Restore original stack
    return 1;       // Is a palindrome
}

int main()
{
    int choice, value;
    // char str[MAX];

    // do
    // {
    //     printf("\nStack Operations Menu:\n");
    //     printf("1. Push\n");
    //     printf("2. Pop\n");
    //     printf("3. Display\n");
    //     printf("4. Check Palindrome\n");
    //     printf("5. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice)
    //     {
    //     case 1:
    //         printf("Enter value to push: ");
    //         scanf("%d", &value);
    //         push(value);
    //         break;

    //     case 2:
    //         value = pop();
    //         if (value != -1)
    //         {
    //             printf("Popped value: %d\n", value);
    //         }
    //         break;

    //     case 3:
    //         display();
    //         break;

    //     case 4:
    //         printf("Enter a string to check for palindrome: ");
    //         scanf(" %s", str);
    //         if (isPalindrome(str))
    //         {
    //             printf("%s is a palindrome\n", str);
    //         }
    //         else
    //         {
    //             printf("%s is not a palindrome\n", str);
    //         }
    //         break;

    //     case 5:
    //         printf("Exiting program\n");
    //         break;

    //     default:
    //         printf("Invalid choice! Please try again\n");
    //     }
    // } while (choice != 5);

    // printf("Enter a string to check for palindrome: ");
    // scanf(" %s", str);
    char str[MAX] = "aibohphobia";
    if (isPalindrome(&str))
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}