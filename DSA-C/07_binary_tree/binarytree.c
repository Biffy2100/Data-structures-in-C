#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *right;
    Node *left;
} Node;

Node *createNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = x;

    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

void insert(Node *root, int x)
{
    Node *newNode = createNode(x);

    
}

void delete()
{
}

int main()
{
    Node *root = NULL;

    printf("Enter the root of the tree\n");
    int x;
    scanf("%d", &x);
    root->data = x;

    return 0;
}
