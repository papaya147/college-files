#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int top;
int *stack;
int size;

void init(int n)
{
    size = n;
    stack = malloc(size * sizeof(int));
    top = -1;
}

void del()
{
    free(stack);
}

bool isEmpty()
{
    return top == -1 ? true : false;
}

bool isFull()
{
    return top == size - 1 ? true : false;
}

bool push(int n)
{
    if (isFull())
        return false;
    *(stack + ++top) = n;
    return true;
}

int pop()
{
    if (isEmpty())
        return -1;
    return *(stack + top--);
}

int peek()
{
    if (isEmpty())
        return -1;
    return *(stack + top);
}

int display()
{
    if (isEmpty())
        printf("Stack is empty.");
    else
        for (int x = 0; x < top + 1; x++)
            printf("%d ", *(stack + x));
}

int main()
{
    int inp;
    printf("Enter size: ");
    scanf("%d", &inp);
    init(inp);
    bool flag = true;
    while (flag)
    {
        printf("Enter 1 to push\n      2 to pop\n      3 to peek\n      4 to display\n      5 to exit\n");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            scanf("%d", &inp);
            if (push(inp))
                printf("Pushed %d successfully.", inp);
            else
                printf("Stack Overflow.");
            break;

        case 2:
            inp = pop();
            if (inp == -1)
                printf("Stack Underflow.");
            else
                printf("Popped %d successfully.", inp);
            break;

        case 3:
            inp = peek();
            if (inp == -1)
                printf("Stack Underflow.");
            else
                printf("Peek is %d.", inp);
            break;

        case 4:
            display();
            break;

        case 5:
            del();
            flag = false;
        }
        printf("\n");
    }
}