#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));

    int fd[2];
    if (pipe(fd) < 0) // Error during Pipe creation
    {
        perror("Pipe: ");
    }

    int pid = fork();

    if (pid < 0) // Error while forking
    {
        perror("Fork(): ");
    }

    if (!pid) // Child #1
    {
        int pid2 = fork();

        if (!pid2) // Child #2
        {
            int random = abs((rand() * getpid()) % 10 + 1);
            printf("Random 2: %d\n", random);
            int get = 0;
            read(fd[0], &get, sizeof(int));               // Read random number of other process from pipe
            write(fd[1], &random, sizeof(int));           // Write own random number to pipe
            printf("Multiplied Number 1: %d\n", get * 2); // Print the number recived * 2
        }

        else // Child #1
        {
            int random = abs((rand() * getpid()) % 10 + 1);
            printf("Random 1: %d\n", random);
            int get = 0;
            write(fd[1], &random, sizeof(int));           // Write own random number to pipe
            wait(NULL);                                   // Wait for child to finish
            read(fd[0], &get, sizeof(int));               // read the other number from pipe
            printf("Multiplied Number 2: %d\n", get * 2); // Print the number recived * 2
        }
    }

    else // Parent Just waits for children and prints message to signal end
    {
        wait(NULL);
        printf("\nEnd of Code\n");
    }
    return EXIT_SUCCESS;
}
