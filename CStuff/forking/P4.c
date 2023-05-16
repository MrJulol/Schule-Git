#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>

void response()
{
    printf("Parent: Recieved Signal\n");
}

int main()
{
    char *stpmssg = "STOP";
    int status;

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
            kill(getppid(), SIGUSR1);
            if (!strcmp(buffer, stpmssg))
            {
                printf("END\n");
                break;
            }
            else
            {
                printf("Child Recived: %s\n", buffer);
            }
        }
    }
    if (pid)
    {
        signal(SIGUSR1, response);
        char test[100];
        char *arrow = "> ";
        while (1)
        {
            close(fd[0]);
            printf("%s", arrow);
            fflush(stdin);
            fgets(test, 100, stdin);
            test[strlen(test) - 1] = '\0';
            write(fd[1], &test, sizeof(char *));
            if (!strcmp(test, stpmssg))
            {
                break;
            }
            pause();
        }
        waitpid(-1, &status, 0);
        printf("ALL END\n");
    }

    return EXIT_SUCCESS;
}