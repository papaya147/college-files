#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *right;
    struct Node *left;
};

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

struct Node *addNode(int val)
{
    struct Node *root = malloc(sizeof(struct Node));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insert(struct Node *root, int val)
{
    if (val < root->val)
        if (root->left == NULL)
            root->left = addNode(val);
        else
            insert(root->left, val);
    else if (root->right == NULL)
        root->right = addNode(val);
    else
        insert(root->right, val);
}

int main()
{
    int n;
    printf("Enter number of values: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int x = 0; x < n; x++)
        scanf("%d", arr + x);
    struct Node *root = addNode(*arr);
    for (int x = 1; x < n; x++)
        insert(root, *(arr + x));
    inorder(root);
}