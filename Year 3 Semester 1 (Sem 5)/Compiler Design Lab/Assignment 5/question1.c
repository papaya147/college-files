#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *buildDAG(char postfix[])
{
    Node *stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isalnum(ch))
        {
            Node *newNode = createNode(ch);
            stack[++top] = newNode;
        }
        else
        {
            Node *newNode = createNode(ch);
            newNode->right = stack[top--];
            newNode->left = stack[top--];

            stack[++top] = newNode;
        }
    }

    return stack[top];
}

void printPostfix(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c ", root->data);
}

int main()
{
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    Node *root = buildDAG(postfix);

    printf("Postfix expression: ");
    printPostfix(root);
    printf("\n");
}
