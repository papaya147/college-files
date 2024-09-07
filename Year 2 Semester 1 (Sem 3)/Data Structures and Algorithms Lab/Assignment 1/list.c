#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *root;
struct Node *curr;
struct Node *last;
int length;

void init()
{
    length = 0;
    root = malloc(sizeof(struct Node));
    last = root;
}

void del()
{
    struct Node *temp;
    curr = root;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

void append(int n)
{
    last->val = n;
    last->next = malloc(sizeof(struct Node));
    last = last->next;
    last->next = NULL;
    length++;
}

bool insert(int n, int i)
{
    if (i > length + 1 || i < 0)
        return false;
    else if (i == 0)
    {
        curr = malloc(sizeof(struct Node));
        curr->val = n;
        curr->next = root;
        root = curr;
        length++;
    }
    else if (i == length + 1)
        append(n);
    else
    {
        curr = root;
        for (int x = 0; x < i - 1; x++)
            curr = curr->next;
        struct Node *temp = curr->next;
        curr->next = malloc(sizeof(struct Node));
        curr->next->val = n;
        curr->next->next = temp;
        length++;
    }
}

bool delete (int i)
{
    if (i > length - 1 || i < 0)
        return false;
    if (i == 0)
    {
        curr = root;
        root = root->next;
        free(curr);
        length--;
        return true;
    }
    curr = root;
    for (int x = 0; x < i - 1; x++)
        curr = curr->next;
    struct Node *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    length--;
    return true;
}

void display()
{
    curr = root;
    while (curr->next != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

int main()
{
    init();
    int choice, temp;
    bool flag = true;
    while (flag)
    {
        printf("Enter 1 to append\n      2 to insert\n      3 to delete\n      4 to Display\n      5 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &choice);
            append(choice);
            printf("Appended %d successfully.", choice);
            break;

        case 2:
            scanf("%d%d", &choice, &temp);
            if (insert(choice, temp))
                printf("Inserted %d at position %d successfully.", choice, temp);
            else
                printf("Index not valid.");
            break;

        case 3:
            scanf("%d", &choice);
            if (delete (choice))
                printf("Item at index %d deleted successfully.", choice);
            else
                printf("Index not valid.");
            break;

        case 4:
            display();
            break;

        case 5:
            flag = false;
        }
        printf("\n\n");
    }
    del();
}