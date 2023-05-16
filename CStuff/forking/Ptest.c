#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
    printf("\n Inside handler function \n");
}

int main()
{
    signal(SIGINT, SIG_IGN);
    for (int i = 1;; i++)
    {
        printf("%d : Inside Main function", i);
        sleep(1);
    }
    return 0;
}
