#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

// Function prototypes
void insertFront(Node **tail, int value);
void insertEnd(Node **tail, int value);
void deleteFront(Node **tail);
void deleteEnd(Node **tail);
void display(Node *tail);
void search(Node *tail, int value);

// Main function
int main()
{
    Node *tail = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Delete Front\n");
        printf("4. Delete End\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&tail, value);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertEnd(&tail, value);
            break;
        case 3:
            deleteFront(&tail);
            break;
        case 4:
            deleteEnd(&tail);
            break;
        case 5:
            display(tail);
            break;
        case 6:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(tail, value);
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Insert at front
void insertFront(Node **tail, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    if (*tail == NULL)
    {
        newNode->next = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
    }
    printf("Inserted %d at front.\n", value);
}

// Insert at end
void insertEnd(Node **tail, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;

    if (*tail == NULL)
    {
        newNode->next = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode;
    }
    printf("Inserted %d at end.\n", value);
}

// Delete from front
void deleteFront(Node **tail)
{
    if (*tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    Node *temp = (*tail)->next;

    if (*tail == temp)
    { // Only one node
        *tail = NULL;
    }
    else
    {
        (*tail)->next = temp->next;
    }
    printf("Deleted %d from front.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd(Node **tail)
{
    if (*tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *current = (*tail)->next, *prev = NULL;

    if (current == *tail)
    { // Only one node
        *tail = NULL;
    }
    else
    {
        while (current->next != (*tail)->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        *tail = prev;
    }
    printf("Deleted %d from end.\n", current->data);
    free(current);
}

// Display the list
void display(Node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *current = tail->next;
    printf("Circular Singly Linked List: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("\n");
}

// Search for a value
void search(Node *tail, int value)
{
    if (tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *current = tail->next;
    int position = 1, found = 0;

    do
    {
        if (current->data == value)
        {
            printf("Value %d found at position %d.\n", value, position);
            found = 1;
            break;
        }
        current = current->next;
        position++;
    } while (current != tail->next);

    if (!found)
    {
        printf("Value %d not found in the list.\n", value);
    }
}
