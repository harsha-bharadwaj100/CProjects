#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct employee
{
    char name[50];
    int key;
} ht[10];

int lprobe(int key)
{
    int index = key % 10;
    while (ht[index].key != 0)
    {
        index = (index + 1) % 10;
    }
    return index;
}

int qprobe(int key)
{
    int index = key % 10;
    int i = 1;
    while (ht[index].key != 0)
    {
        index = (index + i * i) % 10;
        i++;
    }
    return index;
}

int main()
{
    int i, loc, k, choice;
    char name[50];
    FILE *fp;

    for (i = 0; i < 10; i++)
    {
        ht[i].key = 0;
        strcpy(ht[i].name, "");
    }

    fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("File not found"); // Check if the file exists
        return 0;                 // Exit if the file cannot be opened
    }

    printf("Enter the probing method:\n1. Linear Probing\n2. Quadratic Probing\n");
    scanf("%d", &choice);
    while (fscanf(fp, "%s %d", name, &k) == 2)
    {
        if (choice == 1)
        {
            loc = lprobe(k);
        }
        else if (choice == 2)
        {
            loc = qprobe(k);
        }
        ht[loc].key = k;
        strcpy(ht[loc].name, name);
    }

    fclose(fp);
    printf("Name\tKey\n"); // Header for the table
    for (i = 0; i < 10; i++)
    {
        printf("%s\t%d\n", ht[i].name, ht[i].key); // Print each slot
    }
}