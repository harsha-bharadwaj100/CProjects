#include <stdio.h>
#include <string.h>
struct hash2
{
    int key;
    char name[50];
} ht[10];

int lprobe(int key)
{
    int loc = key % 10;
    while (ht[loc].key != 0)
    {
        loc = (loc + 1) % 10;
    }
    return loc;
}

int qprobe(int key)
{
    int loc = key % 10;
    int i = 1;
    while (ht[loc].key != 0)
    {
        loc = (loc + i * i) % 10;
        i++;
    }
    return loc;
}

void main()
{
    int i, loc, key, choice;
    char name[50];
    FILE *fp;
    // innitialize ht
    for (i = 0; i < 10; i++)
    {
        ht[i].key = 0;
        strcpy(ht[i].name, "");
    }
    // open file
    fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter the probing method:\n1. Linear Probing\n2. Quadratic Probing\n");
    scanf("%d", &choice);
    // iterate through file and add to ht
    while (fscanf(fp, "%s %d", name, &key) == 2)
    {
        if (choice == 1)
        {
            loc = lprobe(key);
        }
        else if (choice == 2)
        {
            loc = qprobe(key);
            printf("%d\n", loc);
        }
        ht[loc].key = key;
        strcpy(ht[loc].name, name);
    }
    fclose(fp);
    // print the contents of hash table
    printf("Name\tkey\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t%d\n", ht[i].name, ht[i].key);
    }
}
