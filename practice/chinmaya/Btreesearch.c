#include <stdio.h>
#include <stdlib.h>

// Node structure with value, left and right links
typedef struct node
{
    int val;
    struct node *left, *right;
} *NODE;

// Create a new node with given value
NODE makeNode(int v)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

// Insert value into BST
NODE insert(NODE root, int v)
{
    if (root == NULL)
        return makeNode(v);

    if (v < root->val)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);

    return root;
}

// Search for a value in BST
void search(NODE root, int key)
{
    if (root == NULL)
        printf("Key not found\n");
    else if (key == root->val)
        printf("Key found!\n");
    else if (key < root->val)
        search(root->left, key);
    else
        search(root->right, key);
}

// Find minimum value in BST
void findMin(NODE root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    while (root->left != NULL)
        root = root->left;

    printf("Min = %d\n", root->val);
}

// Find maximum value in BST
void findMax(NODE root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    while (root->right != NULL)
        root = root->right;

    printf("Max = %d\n", root->val);
}

// Main function with menu
int main()
{
    NODE root = NULL;
    int choice, val;

    // Insert sample values
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Menu loop
    while (1)
    {
        printf("\n1.Search 2.Min 3.Max 4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter key to search: ");
            scanf("%d", &val);
            search(root, val);
        }
        else if (choice == 2)
        {
            findMin(root);
        }
        else if (choice == 3)
        {
            findMax(root);
        }
        else if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid option\n");
        }
    }

    return 0;
}
