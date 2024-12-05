#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} *NODE;

NODE root = NULL;

NODE getNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inOrder(NODE root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(NODE root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

NODE binarySearchInsert(NODE root, int data)
{
    if (root == NULL)
        root = getNode(data);
    if (root->data > data)
        root->left = binarySearchInsert(root->left, data);
    if (root->data < data)
        root->right = binarySearchInsert(root->right, data);
    return root;
}

int main()
{
    int btree[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2};
    int n = sizeof(btree) / sizeof(btree[0]);
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
    return 0;
}