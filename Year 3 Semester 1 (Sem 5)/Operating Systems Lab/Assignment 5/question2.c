#include <stdio.h>
#include <stdlib.h>

void lruPageReplacement(int pages[], int numPages, int numFrames)
{
    int frame[numFrames];
    int i, j, k;
    int pageFaults = 0;
    int currentIndex = 0;
    int exists = 0;
    int *counters = (int *)malloc(numFrames * sizeof(int));

    for (i = 0; i < numFrames; i++)
    {
        frame[i] = -1;
        counters[i] = 0;
    }

    for (i = 0; i < numPages; i++)
    {
        exists = 0;
        for (j = 0; j < numFrames; j++)
        {
            if (frame[j] == pages[i])
            {
                exists = 1;
                counters[j] = i + 1;
                break;
            }
        }

        if (exists == 0)
        {
            int minIndex = 0;
            for (k = 1; k < numFrames; k++)
            {
                if (counters[k] < counters[minIndex])
                {
                    minIndex = k;
                }
            }

            frame[minIndex] = pages[i];
            counters[minIndex] = i + 1;
            pageFaults++;
        }

        printf("\nPage %d: ", pages[i]);
        for (j = 0; j < numFrames; j++)
        {
            printf("%d ", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
    free(counters);
}

int main()
{
    int numPages, numFrames, i;

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int pages[numPages];

    printf("Enter the page sequence:\n");
    for (i = 0; i < numPages; i++)
    {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("\nLRU Page Replacement Algorithm:\n");
    lruPageReplacement(pages, numPages, numFrames);

    return 0;
}