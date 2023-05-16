#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    int pid = fork();
    if (pid < 0)
    {
        perror("Child creation");
    }
    if (!pid)
    {
        printf("First 3 numbers: %d\n", arr[0] + arr[1] + arr[2]);
        pid = fork();
        if (pid < 0)
        {
            perror("Child creation");
        }
        if (!pid)
        {
            printf("Next 3 numbers: %d\n", arr[3] + arr[4] + arr[5]);
        }
        else
        {
            wait(NULL);
            printf("Last 4 numbers: %d\n", arr[6] + arr[7] + arr[8] + arr[9]);
        }
        wait(NULL);
    }
    else
    {
        wait(NULL);
        int sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += arr[i];
        }
        printf("Total Sum: %d\n", sum);
    }
    return EXIT_SUCCESS;
}
