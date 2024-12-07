#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure for binary search tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

// Function prototypes
NODE getNode(int data);
NODE binarySearchInsert(NODE root, int data);
int getTreeHeight(NODE root);
void generateSVG(NODE root, const char *filename);
void writeNodeToSVG(FILE *file, NODE node, double x, double y, double hSpacing, int depth);

// Create a new node
NODE getNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into binary search tree
NODE binarySearchInsert(NODE root, int data)
{
    if (root == NULL)
        return getNode(data);

    if (data < root->data)
        root->left = binarySearchInsert(root->left, data);
    else if (data > root->data)
        root->right = binarySearchInsert(root->right, data);

    return root;
}

// Calculate tree height
int getTreeHeight(NODE root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Generate SVG visualization
void generateSVG(NODE root, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    int height = getTreeHeight(root);
    double svgWidth = 800;
    double svgHeight = 400;

    // SVG header
    fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(file, "<svg width=\"%f\" height=\"%f\" xmlns=\"http://www.w3.org/2000/svg\">\n",
            svgWidth, svgHeight);

    // Background
    fprintf(file, "<rect width=\"100%%\" height=\"100%%\" fill=\"white\"/>\n");

    // Draw the tree
    writeNodeToSVG(file, root, svgWidth / 2, 50, svgWidth / 2, 0);

    // SVG footer
    fprintf(file, "</svg>");

    fclose(file);
}

// Recursive function to write nodes and connections
void writeNodeToSVG(FILE *file, NODE node, double x, double y, double hSpacing, int depth)
{
    if (node == NULL)
        return;

    double nodeRadius = 20;
    double verticalSpacing = 60;

    // Draw node circle
    fprintf(file, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"lightblue\" stroke=\"black\"/>\n",
            x, y, nodeRadius);

    // Draw node text
    fprintf(file, "<text x=\"%f\" y=\"%f\" text-anchor=\"middle\" font-size=\"12\" font-weight=\"bold\">%d</text>\n",
            x, y + 5, node->data);

    // Recursive drawing of left and right children
    if (node->left)
    {
        double leftX = x - hSpacing / (depth + 1);
        double leftY = y + verticalSpacing;

        // Line to left child
        fprintf(file, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"black\"/>\n",
                x, y + nodeRadius, leftX, leftY - nodeRadius);

        // Recursively draw left subtree
        writeNodeToSVG(file, node->left, leftX, leftY, hSpacing, depth + 1);
    }

    if (node->right)
    {
        double rightX = x + hSpacing / (depth + 1);
        double rightY = y + verticalSpacing;

        // Line to right child
        fprintf(file, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"black\"/>\n",
                x, y + nodeRadius, rightX, rightY - nodeRadius);

        // Recursively draw right subtree
        writeNodeToSVG(file, node->right, rightX, rightY, hSpacing, depth + 1);
    }
}

int main()
{
    NODE root = NULL;
    int btree[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 5, 2};
    int n = sizeof(btree) / sizeof(btree[0]);

    // Insert elements into the tree
    for (int i = 0; i < n; i++)
    {
        root = binarySearchInsert(root, btree[i]);
    }

    // Generate SVG visualization
    generateSVG(root, "binary_tree.svg");

    printf("Binary Search Tree SVG generated as 'binary_tree.svg'\n");

    return 0;
}