#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main()
{
    char *stpmssg = "STOP";

    int fd[2];
    if (pipe(fd) < 0) // Error during Pipe creation
    {
        perror("Pipe: ");
    }

    int pid = fork();
    if (pid < 0)
    {
        perror("Child creation");
        return 1;
    }
    if (!pid)
    {
        char buffer[100];
        while (1)
        {
            close(fd[1]);
            read(fd[0], &buffer, sizeof(char *));
            if (!strcmp(buffer, stpmssg))
            {
                printf("END\n");
                break;
            }
            else
            {
                printf("%s\n", buffer);
            }
        }
    }
    if (pid)
    {
        char test[100];
        while (1)
        {
            close(fd[0]);
            fgets(test, 100, stdin);
            test[strlen(test) - 1] = '\0';
            write(fd[1], &test, sizeof(char *));
            if (!strcmp(test, stpmssg))
            {
                break;
            }
        }
        wait(NULL);
        printf("ALL END\n");
    }

    return EXIT_SUCCESS;
}