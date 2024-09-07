#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findOptimal(int pages[], int numPages, int frame[], int numFrames, int startIndex)
{
    int index = -1;
    int farthest = startIndex;

    for (int i = 0; i < numFrames; i++)
    {
        int j;
        for (j = startIndex; j < numPages; j++)
        {
            if (frame[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        if (j == numPages)
            return i;
    }

    return (index == -1) ? 0 : index;
}

void optimalPageReplacement(int pages[], int numPages, int numFrames)
{
    int frame[numFrames];
    bool isPresent[numFrames];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; i++)
    {
        frame[i] = -1;
        isPresent[i] = false;
    }

    for (int i = 0; i < numPages; i++)
    {
        int j;
        bool isFull = true;

        for (j = 0; j < numFrames; j++)
        {
            if (frame[j] == pages[i])
            {
                isPresent[j] = true;
                break;
            }
        }

        if (j == numFrames)
        {
            int k;
            for (k = 0; k < numFrames; k++)
            {
                if (!isPresent[k])
                {
                    frame[k] = pages[i];
                    isPresent[k] = true;
                    pageFaults++;
                    isFull = false;
                    break;
                }
            }

            if (k == numFrames)
            {
                int index = findOptimal(pages, numPages, frame, numFrames, i + 1);
                frame[index] = pages[i];
                pageFaults++;
            }
        }

        printf("\nPage %d: ", pages[i]);
        for (int k = 0; k < numFrames; k++)
        {
            printf("%d ", frame[k]);
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

    printf("\nOptimal Page Replacement Algorithm:\n");
    optimalPageReplacement(pages, numPages, numFrames);

    return 0;
}