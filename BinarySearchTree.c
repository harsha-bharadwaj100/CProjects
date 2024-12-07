#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE root = NULL;

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
        root = getNode(data);
    if (root->data > data)
        root->left = binarySearchInsert(root->left, data);
    if (root->data < data)
        root->right = binarySearchInsert(root->right, data);
    return root;
}

// Modified preOrder function to write to both stdout and file
void preOrder(NODE root, FILE *fp)
{
    if (root == NULL)
    {
        return;
    }
    printf("\"%d\" : ", root->data);
    fprintf(fp, "\"%d\" : ", root->data);

    printf("{");
    fprintf(fp, "{");

    preOrder(root->left, fp);

    if (root->right != NULL)
    {
        printf(",");
        fprintf(fp, ",");
        preOrder(root->right, fp);
    }

    printf("}");
    fprintf(fp, "}");
}

int main()
{
    // Open file for writing
    FILE *fp = fopen("binary_tree.json", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    int btree[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2};
    int n = sizeof(btree) / sizeof(btree[0]);

    for (int i = 0; i < n; i++)
    {
        root = binarySearchInsert(root, btree[i]);
    }

    // Print to console and file
    printf("Preorder: ");
    fprintf(fp, "{\"Preorder\": ");

    printf("{");
    fprintf(fp, "{");

    preOrder(root, fp);

    printf("}\n");
    fprintf(fp, "}}\n");

    // Close the file
    fclose(fp);

    return 0;
}