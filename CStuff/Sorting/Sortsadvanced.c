#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Bubble = n^2
// Selection = n^2
// Insertion = n^2
// Shell = n^2
// merge = nlogn
// Quick = nlogn

unsigned long long counter_merge = 0;
unsigned long long counter_quick = 0;

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

#define MAX 1000       // Arr Size
#define SAMPLESIZE 10 // Test Sample average SAMPLESIZE

void swap(int *a, int *b)
// Swap for Selectionsort
{
    int t = *a;
    *a = *b;
    *b = t;
}
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
        counter_merge++;
        mergesort2(arr, l, m);
        counter_merge++;
        mergesort2(arr, m + 1, r);

        merge2(arr, l, m, r);
    }
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
            counter_quick++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    counter_quick++;
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

int bubble(int arr[])
{
    // BUBBLE-SORT
    int temp = 0;
    int counter = 0;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                counter++;
            }
        }
    }
    return counter;
}

int selection(int arr[])
// SELECTION-SORT
{
    int min = 0;
    int counter = 0;
    int i, j;

    for (i = 0; i < MAX - 1; i++)
    {
        min = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[min], &arr[i]);

            counter++;
        }
    }
    return counter;
}
int insert(int arr[])
// INSERTION-SORT
{
    int j, i, counter;
    for (i = 1; i < MAX; i++)
    {
        int key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            counter++;
        }
        arr[j + 1] = key;
    }

    return counter;
}

int shell(int arr[])
// SHELL-SORT
{
    int counter = 0;

    for (int gap = MAX / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < MAX; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                counter++;
            }
            arr[j] = temp;
        }
    }
    return counter;
}
int main()
{
    HELLO();
    srand((unsigned)time(NULL));
    int arr_bubble[MAX];
    int arr_select[MAX];
    int arr_insert[MAX];
    int arr_shell[MAX];
    int arr_quick[MAX];
    int arr_merge[MAX];
    double time_taken_bubble = 0.0f;
    double time_taken_select = 0.0f;
    double time_taken_instert = 0.0f;
    double time_taken_shell = 0.0f;
    double time_taken_quick = 0.0f;
    double time_taken_merge = 0.0f;
    unsigned long long counter_bubble = 0;
    unsigned long long counter_select = 0;
    unsigned long long counter_insert = 0;
    unsigned long long counter_shell = 0;
    clock_t tbubble;
    clock_t tselect;
    clock_t tinsert;
    clock_t tshell;
    clock_t tquick;
    clock_t tmerge;
    unsigned long long memcounter_bubble[100] = {0};
    unsigned long long memcounter_select[100] = {0};
    unsigned long long memcounter_insert[100] = {0};
    unsigned long long memcounter_shell[100] = {0};
    unsigned long long memcounter_merge[100] = {0};
    unsigned long long memcounter_quick[100] = {0};
    unsigned long long avg_bubble = 0;
    unsigned long long avg_select = 0;
    unsigned long long avg_insert = 0;
    unsigned long long avg_shell = 0;
    unsigned long long avg_quick = 0;
    unsigned long long avg_merge = 0;
    double memtime_bubble[100] = {0.0f};
    double memtime_select[100] = {0.0f};
    double memtime_insert[100] = {0.0f};
    double memtime_shell[100] = {0.0f};
    double memtime_quick[100] = {0.0f};
    double memtime_merge[100] = {0.0f};
    double avgt_bubble = 0.0f;
    double avgt_select = 0.0f;
    double avgt_insert = 0.0f;
    double avgt_shell = 0.0f;
    double avgt_quick = 0.0f;
    double avgt_merge = 0.0f;

    for (int samplesize = 0; samplesize < SAMPLESIZE; samplesize++)
    {
        counter_merge = 0;
        counter_quick = 0;

        for (int i = 0; i < MAX; i++)
        {
            arr_bubble[i] = (rand() % 100) + 1;
            arr_select[i] = arr_bubble[i];
            arr_insert[i] = arr_bubble[i];
            arr_shell[i] = arr_bubble[i];
            arr_quick[i] = arr_bubble[i];
        }

        tbubble = clock();
        counter_bubble = bubble(arr_bubble);
        tbubble = clock() - tbubble;
        time_taken_bubble = ((double)tbubble) / CLOCKS_PER_SEC;

        tselect = clock();
        counter_select = selection(arr_select);
        tselect = clock() - tselect;
        time_taken_select = ((double)tselect) / CLOCKS_PER_SEC;

        tinsert = clock();
        counter_insert = insert(arr_insert);
        tinsert = clock() - tinsert;
        time_taken_instert = ((double)tinsert) / CLOCKS_PER_SEC;

        tshell = clock();
        counter_shell = shell(arr_shell);
        tshell = clock() - tshell;
        time_taken_shell = ((double)tshell) / CLOCKS_PER_SEC;

        tquick = clock();
        quicksort2(arr_quick, 0, MAX - 1);
        tquick = clock() - tquick;
        time_taken_quick = ((double)tquick) / CLOCKS_PER_SEC;

        tmerge = clock();
        mergesort2(arr_merge, 0, MAX - 1);
        tmerge = clock() - tmerge;
        time_taken_merge = ((double)tmerge) / CLOCKS_PER_SEC;

        memcounter_bubble[samplesize] = counter_bubble;
        memcounter_select[samplesize] = counter_select;
        memcounter_insert[samplesize] = counter_insert;
        memcounter_shell[samplesize] = counter_shell;
        memcounter_quick[samplesize] = counter_quick;
        memcounter_merge[samplesize] = counter_merge;

        memtime_bubble[samplesize] = time_taken_bubble;
        memtime_select[samplesize] = time_taken_select;
        memtime_insert[samplesize] = time_taken_instert;
        memtime_shell[samplesize] = time_taken_shell;
        memtime_quick[samplesize] = time_taken_quick;
        memtime_merge[samplesize] = time_taken_merge;
    }

    for (int i = 0; i < SAMPLESIZE; i++)
    {
        avg_bubble = avg_bubble + memcounter_bubble[i];
        avg_insert = avg_insert + memcounter_insert[i];
        avg_select = avg_select + memcounter_select[i];
        avg_shell = avg_shell + memcounter_shell[i];
        avg_quick = avg_quick + memcounter_quick[i];
        avg_merge = avg_merge + memcounter_merge[i];

        avgt_bubble = avgt_bubble + memtime_bubble[i];
        avgt_select = avgt_select + memtime_select[i];
        avgt_insert = avgt_insert + memtime_insert[i];
        avgt_shell = avgt_shell + memtime_shell[i];
        avgt_quick = avgt_quick + memtime_quick[i];
        avgt_merge = avgt_merge + memtime_merge[i];
    }
    avg_bubble = avg_bubble / SAMPLESIZE;
    avg_insert = avg_insert / SAMPLESIZE;
    avg_select = avg_select / SAMPLESIZE;
    avg_shell = avg_shell / SAMPLESIZE;
    avg_quick = avg_quick / SAMPLESIZE;
    avg_merge = avg_merge / SAMPLESIZE;

    avgt_bubble = avgt_bubble / SAMPLESIZE;
    avgt_insert = avgt_insert / SAMPLESIZE;
    avgt_select = avgt_select / SAMPLESIZE;
    avgt_shell = avgt_shell / SAMPLESIZE;
    avgt_quick = avgt_quick / SAMPLESIZE;
    avgt_merge = avgt_merge / SAMPLESIZE;

    printf("_____________________________________________________________________");
    printf("\nAverage Times: \nBubble: %.10lf\nSelection: %.10lf\nInsertion: %.10lf\nShell: %.10lf\nQuick: %.10lf\nMerge: %.10lf\n", avgt_bubble, avgt_select, avgt_insert, avgt_shell, avgt_quick, avgt_merge);
    printf("Average Moves: \nBubble: %llu\nSelection: %llu\nInsertion: %llu\nShell: %llu\nQuick: %llu\nMerge: %llu\n", avg_bubble, avg_select, avg_insert, avg_shell, avg_quick, avg_merge);

    return EXIT_SUCCESS;
}