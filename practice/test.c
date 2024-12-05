#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Initialize the head of the list as NULL
struct node *head = NULL;

// Function to insert a node at the end
void insertEnd(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    if (head == NULL)
    { // If the list is empty
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {                                   // If the list has at least one node
        struct node *last = head->prev; // Get the last node
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// Function to delete a node at the end
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty. No element to delete.\n");
        return;
    }

    struct node *temp = head;

    // If there's only one node in the list
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *last = head->prev; // Find the last node
        struct node *secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;
        free(last); // Free the last node
    }
    printf("Deleted node from the end.\n");
}

// Function to display the list
void display()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Circular Doubly Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function with menu
int main()
{
    int choice, value;

    while (1)
    {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Delete at End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}