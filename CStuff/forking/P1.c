#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define NSIZE 16

int main()
{
    int fd[2];
    if (pipe(fd) < 0)
    {
        exit(1);
    }
    int pid = fork();
    if (pid < 0)
    {
        perror("Child creation");
    }
    if (!pid)
    {
        char buffer[NSIZE];
        read(fd[0], buffer, NSIZE);
        printf("%s", buffer);
    }
    else
    {
        char buffer[NSIZE];
        fgets(buffer, NSIZE, stdin);
        write(fd[1], buffer, NSIZE);
    }
    return EXIT_SUCCESS;
}
