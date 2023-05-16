#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main()
{

    int temp = 0;
    int counter = 0;
    srand((unsigned)time(NULL));
    int a[MAX];
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (rand() % 100) + 1;
    }
    clock_t t;
    t = clock();
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (a[j] >= a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                counter++;
            }
        }
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n%.15f seconds = Time taken\n", time_taken);
    printf("%d = Number of Changes\n", counter);

    return EXIT_SUCCESS;
}