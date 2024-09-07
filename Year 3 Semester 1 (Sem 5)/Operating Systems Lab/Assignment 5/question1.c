#include <stdio.h>
#include <stdlib.h>

void fifoPageReplacement(int pages[], int numPages, int numFrames)
{
    int frame[numFrames];
    int i, j;
    int pageFaults = 0;
    int currentIndex = 0;
    int exists = 0;

    for (i = 0; i < numFrames; i++)
    {
        frame[i] = -1;
    }

    for (i = 0; i < numPages; i++)
    {
        exists = 0;
        for (j = 0; j < numFrames; j++)
        {
            if (frame[j] == pages[i])
            {
                exists = 1;
                break;
            }
        }

        if (exists == 0)
        {
            frame[currentIndex] = pages[i];
            currentIndex = (currentIndex + 1) % numFrames;
            pageFaults++;
        }

        printf("\nPage %d: ", pages[i]);
        for (j = 0; j < numFrames; j++)
        {
            printf("%d ", frame[j]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
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

    printf("\nFIFO Page Replacement Algorithm:\n");
    fifoPageReplacement(pages, numPages, numFrames);

    return 0;
}