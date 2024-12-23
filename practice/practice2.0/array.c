#include <stdio.h>

#define MAX 100

int array[MAX], size; // Global array to store elements

void createArray()
{
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Array Created!\n");
}

void insert()
{
    int pos, data;
    printf("Enter a valid position (1 - %d): ", size);
    scanf("%d", &pos);
    pos--;
    printf("Enter data: ");
    scanf("%d", &data);
    if (pos < 0 || pos > size)
    {
        printf("Invalid position!\n");
        return;
    }
    for (int i = size; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    size++;
    array[pos] = data;
}

void display()
{
    if (size == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void delete()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    pos--;
    if (pos < 0 || pos > size)
    {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
}

int main()
{
    int choice;
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createArray();
            break;
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            delete ();
            break;
        default:
            return 0;
        }
    }
}