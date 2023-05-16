#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int multip(int a, int b)
{
    a *= b;
    return a;
}

int main()
{
    int pid = fork();
    if (pid < 0){
        perror("Child creation");
    }

    if (!pid)
    {
        int a, b, res;
        a = 4;
        b = 3;
        res = multip(a, b);
        printf("Child says: %d\n", res);
    }
    else
    {
        waitpid(pid, NULL, 1);
        int a, b, res;
        scanf("%d", &a);
        scanf("%d", &b);
        res = multip(a, b);
        printf("Parent says: %d\n", res);
    }

    return EXIT_SUCCESS;
}
