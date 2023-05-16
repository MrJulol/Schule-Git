#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __APPLE__
#define clrscr() system("clear")
#define HELLO() printf("Hey Apple User!\n")
#elif _Windows
#define clrscr() system("cls")
#define HELLO() printf("Hey you poor Windows user\n")
#elif __linux__
#define clrscr() system("clear")
#define HELLO() printf("You Gigachad Linux User\n")
#else
#define clrscr() printf("GET A GOOD PC\n")
#define HELLO() printf("What dafuq are you running as OS\n")
#endif

#define SIZE 1000000

void merge2(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort2(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort2(arr, l, m);
        mergesort2(arr, m + 1, r);

        merge2(arr, l, m, r);
    }
}

int main()
{
    clrscr();
    HELLO();

    clock_t time;

    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = (rand() % 10000) + 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    time = clock();
    mergesort2(arr, 0, SIZE - 1);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("\n_____Merge-Sort____\n");
    for (int ij = 0; ij < SIZE; ij++)
    {
        printf("%d ", arr[ij]);
    }
    printf("\nSorting Time: %.10lf\n", time_taken);

    return EXIT_SUCCESS;
}