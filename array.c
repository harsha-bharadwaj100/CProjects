#include <stdio.h>

#define MAX 100

int array[MAX]; // Global array to store elements
int size = 0;   // Variable to store the size of the array

// Function to create an array
void createArray()
{
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    if (size > MAX)
    {
        printf("Exceeded maximum array size.\n");
        size = 0; // Reset size to 0
        return;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

// Function to display array elements
void displayArray()
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to insert an element at a given position
void insertElement()
{
    int pos, element;

    if (size == MAX)
    {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    printf("Enter the position to insert (1 to %d): ", size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    // Shift elements to the right
    for (int i = size; i >= pos; i--)
    {
        array[i] = array[i - 1];
    }

    array[pos - 1] = element; // Insert the element
    size++;                   // Increase size of the array
    printf("Element inserted successfully.\n");
}

// Function to delete an element at a given position
void deleteElement()
{
    int pos;

    if (size == 0)
    {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the position to delete (1 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size)
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }

    size--; // Decrease size of the array
    printf("Element deleted successfully.\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createArray();
            break;
        case 2:
            displayArray();
            break;
        case 3:
            insertElement();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}