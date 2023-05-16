#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if (!pid)
    {
        printf("%d\n", getpid());
        pid = fork();
        if (!pid)
        {
            printf("%d\n", getpid());
            pid = fork();
            if (!pid)
            {
                printf("%d\n", getpid());
                pid = fork();
                if (!pid)
                {
                    printf("%d\n", getpid());
                    pid = fork();
                    if (!pid)
                    {
                        printf("%d\n", getpid());
                        pid = fork();
                    }
                }
            }
        }
        wait(NULL);
    }
    else
    {
        wait(NULL);
        printf("END\n");
    }
    return EXIT_SUCCESS;
}
