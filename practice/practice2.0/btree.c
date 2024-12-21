#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE getNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

NODE binarySearchInsert(NODE root, int data)
{
    if (root == NULL)
    {
        root = getNode(data);
    }
    if (data > root->data)
    {
        root->right = binarySearchInsert(root->right, data);
    }
    if (data < root->data)
    {
        root->left = binarySearchInsert(root->left, data);
    }
    return root;
}

void inOrder(NODE root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(NODE root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(NODE root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void search(NODE root, int data)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == data)
    {
        printf("Found");
        return;
    }
    if (data < root->data)
    {
        search(root->left, data);
    }
    if (data > root->data)
    {
        search(root->right, data);
    }
}

void max(NODE root)
{
    if (root->right == NULL)
    {
        printf("Max: %d\n", root->data);
        return;
    }
    max(root->right);
}

void min(NODE root)
{
    if (root->left == NULL)
    {
        printf("Max: %d\n", root->data);
        return;
    }
    min(root->left);
}

int main()
{
    int btree[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2};
    int n = sizeof(btree) / sizeof(btree[0]);
    NODE root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = binarySearchInsert(root, btree[i]);
    }

    printf("Inorder: ");
    inOrder(root);
    printf("\nPreorder: ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);
    printf("\n");

    search(root, 2);
    printf("\n");
    min(root);
    max(root);
    return 0;
}