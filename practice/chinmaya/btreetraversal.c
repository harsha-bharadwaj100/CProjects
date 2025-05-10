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
{                                               // return type shiuld be NODE, parmas should int v - value
    NODE n = (NODE)malloc(sizeof(struct node)); //
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

// Insert value into BST
NODE insert(NODE root, int v)
{
    if (root == NULL)
        return makeNode(v); // Empty tree or leaf position
    if (v < root->val)
        root->left = insert(root->left, v); // Go left
    else if (v > root->val)
        root->right = insert(root->right, v); // Go right
    return root;
}

// Inorder traversal: Left → Node → Right
void InOrder(NODE root)
{
    if (root)
    {
        InOrder(root->left);
        printf("%d ", root->val);
        InOrder(root->right);
    }
}

// Preorder traversal: Node → Left → Right
void PreOrder(NODE root)
{
    if (root)
    {
        printf("%d ", root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// Postorder traversal: Left → Right → Node
void PostOrder(NODE root)
{
    if (root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->val);
    }
}

int main()
{
    NODE root = NULL; // Start with empty BST
    int choice, num, count;

    while (1)
    {
        // Menu options
        printf("1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Exit\nEnter choice: \n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("How many values to insert? \n");
            scanf("%d", &count);
            printf("Enter values: \n");
            for (int i = 0; i < count; i++)
            {
                scanf("%d", &num);
                root = insert(root, num);
            }
        }
        else if (choice == 2)
            InOrder(root);
        else if (choice == 3)
            PreOrder(root);
        else if (choice == 4)
            PostOrder(root);
        else if (choice == 5)
            break;
        else
            printf("Invalid choice!\n");
    }
    return 0;
}