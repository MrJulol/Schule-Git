#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 20

void swap(int *a, int *b);

int main()
{
    srand((unsigned)time(NULL));
    int min = 0;
    int j, i, temp;
    // int counter = 0;
    int a[MAX];
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (rand() % 100) + 1;
    }

    // clock_t t;
    // t = clock();
    for (i = 0; i < (MAX - 1); i++)
    {
        min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            // counter++;
        }
    }
    // t = clock() - t;
    // double time_taken = ((double)t) / CLOCKS_PER_SEC;

    for (int i = 0; i < MAX; i++)
    {
        printf("%d, ", a[i]);
    }
    // printf("\n%.15f seconds = Time taken\n", time_taken);
    // printf("%d = Number of Changes\n", counter);

    return EXIT_SUCCESS;
}