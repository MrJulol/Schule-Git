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
    printf("\nRecieved a singnal from parent");
    sleep(1);
    kill(getppid(), SIGUSR2);
}

void recieve()
{
    printf("\nParent: Recieved a Signal from Child\n");
}

int main()
{
    int pid = fork();
    if (pid < 0)
    {
        perror("Child creation");
        return 1;
    }

    if (!pid)
    {
        signal(SIGUSR1, response);
        printf("\nChild: Waiting for Signal");
        pause();
    }
    else
    {
        signal(SIGUSR2, recieve);
        sleep(1);
        printf("\nParent: Sending signal to child");
        kill(pid, SIGUSR1);
        printf("\nParent: Waiting for Signal\n");
        pause();
    }
    return EXIT_SUCCESS;
}
