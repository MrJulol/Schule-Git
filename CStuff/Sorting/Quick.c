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

#define SIZE 2000000

void swap(int *a, int *b)
// Swaps two values
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort2(int arr[], int low, int high)
{
    // Splits

    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quicksort2(arr, low, pivot - 1);
        quicksort2(arr, pivot + 1, high);
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
    quicksort2(arr, 0, SIZE - 1);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("\n_____Quick-Sort____\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorting Time: %.10lf\n", time_taken);

    return EXIT_SUCCESS;
}