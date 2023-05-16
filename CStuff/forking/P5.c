#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>

int main()
{

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
        char *buff;
        close(fd[1]);
        read(fd[0], &buff, sizeof(char *));
        printf("%s\n", buff);
        int len = (int)strlen(buff);
        printf("%d\n", len);
    }
    else
    {
        char *mssg = "5*5";
        int buff = 0;
        close(fd[0]);
        write(fd[1], &mssg, sizeof(char *));
        wait(NULL);
        close(fd[1]);
        read(fd[0], &buff, sizeof(int));
    }

    return EXIT_SUCCESS;
}