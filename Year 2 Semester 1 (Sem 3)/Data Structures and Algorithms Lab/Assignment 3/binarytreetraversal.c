#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *right;
    struct Node *left;
};

struct Node *addNode(int val)
{
    struct Node *root = malloc(sizeof(struct Node));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct Node *insert(int *arr, int i, int n)
{
    struct Node *root = NULL;
    if (i < n)
    {
        root = addNode(*(arr + i));
        root->left = insert(arr, 2 * i + 1, n);
        root->right = insert(arr, 2 * i + 2, n);
    }
    return root;
}

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

int main()
{
    int n;
    printf("Enter number of values: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int x = 0; x < n; x++)
        scanf("%d", arr + x);
    struct Node *root = insert(arr, 0, n); // creates complete binary tree
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    free(arr);
}