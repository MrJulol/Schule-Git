#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == -1)
    {
        printf("ERROR");
    }
    if (!pid)
    {
        printf("Child : %d\n", getpid());
    }
    else
    {
        int pid2 = fork();

        if (!pid2)
        {
            printf("Child : %d\n", getpid());
        }
        else
        {
            char buffer[20];
            waitpid(-1, NULL, 0);
            fgets(buffer, 20, stdin);
            printf("INPUT: %s", buffer);
            printf("Terminate");
        }
    }
    return EXIT_SUCCESS;
}
