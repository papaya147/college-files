#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int top;
int *queue;
int size;

void init(int n){
    size = n;
    queue = malloc(size * sizeof(int));
    top = -1;
}

void del(){
    free(queue);
}

bool isEmpty(){
    return top == -1 ? true : false;
}

bool isFull(){
    return top == size - 1 ? true : false;
}

bool enqueue(int n){
    if(isFull())
        return false;
    *(queue + ++top) = n;
    return true;
}

int dequeue(){
    if(isEmpty())
        return -1;
    int temp = *queue;
    for(int x = 0; x < top; x++)
        *(queue + x) = *(queue + x + 1);
    top--;
    return temp;
}

int peek(){
    if(isEmpty())
        return -1;
    return *queue;
}

void display(){
    if(top == -1)
        printf("Queue is empty.");
    for(int x = 0; x < top + 1; x++)
        printf("%d ", *(queue + x));
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
        printf("Enter 1 to enqueue\n      2 to dequeue\n      3 to peek\n      4 to display\n      5 to exit\n");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            scanf("%d", &inp);
            if (enqueue(inp))
                printf("Queued %d successfully.", inp);
            else
                printf("Queue Overflow.");
            break;

        case 2:
            inp = dequeue();
            if (inp == -1)
                printf("Queue Underflow.");
            else
                printf("Dequeued %d successfully.", inp);
            break;

        case 3:
            inp = peek();
            if (inp == -1)
                printf("Queue Underflow.");
            else
                printf("Dequeued is %d.", inp);
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