#include <stdio.h>
#include <pthread.h>

void *threadProcess1(void *arg)
{
    printf("Thread 1 starting...\n");
    printf("Printing values 0 - 9\n");
    for (int x = 0; x < 10; x++)
        printf("%d\n", x);
    printf("Thread 1 executed!\n");
    return NULL;
}

void *threadProcess2(void *arg)
{
    printf("Thread 2 starting...\n");
    printf("Printing letters a - j\n");
    for (int x = 97; x < 107; x++)
        printf("%c\n", x);
    printf("Thread 2 executed!\n");
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, threadProcess1, NULL);
    pthread_create(&thread2, NULL, threadProcess2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}
