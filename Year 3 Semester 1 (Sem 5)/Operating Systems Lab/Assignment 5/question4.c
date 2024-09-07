#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void lockFile(const char *filename)
{
    int fileDescriptor = open(filename, O_WRONLY);

    if (fileDescriptor == -1)
    {
        perror("Error opening file");
        return;
    }

    struct flock fl;
    memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK; // Write lock
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0; // Lock entire file

    if (fcntl(fileDescriptor, F_SETLK, &fl) == -1)
    {
        perror("Error locking file");
        close(fileDescriptor);
        return;
    }

    printf("File locked successfully.\n");

    // Simulating a locked file by pausing execution for a few seconds
    sleep(5);

    fl.l_type = F_UNLCK; // Unlock
    if (fcntl(fileDescriptor, F_SETLK, &fl) == -1)
    {
        perror("Error unlocking file");
    }
    else
    {
        printf("File unlocked successfully.\n");
    }

    close(fileDescriptor);
}

int main()
{
    const char *filename = "test.txt";

    lockFile(filename);

    return 0;
}