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
    // printf("{");
    preOrder(root->left);
    // printf(",");
    preOrder(root->right);
    // printf("}");
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

void search(NODE root, int data)
{
    if (root == NULL)
        return;
    search(root->left, data);
    if (root->data == data)
    {
        printf("found! %d\n", root->data);
        return;
    }
    search(root->right, data);
}

void min(NODE root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    printf("min: %d\n", root->data);
}

void max(NODE root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    printf("max: %d\n", root->data);
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
    printf("\n");

    search(root, 2);
    printf("\n");
    min(root);
    max(root);
    return 0;
}
// 6
// {
//     5 {
//         2 {
//             ,
//         },
//     },
//         9
//     {
//         8 {
//             7 {
//                 ,
//             },
//         },
//             15
//         {
//             14 {
//                 ,
//             },
//                 24
//             {
//                 ,
//             }
//         }
//     }
// }