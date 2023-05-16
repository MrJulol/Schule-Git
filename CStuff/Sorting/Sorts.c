#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 20

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int bubble(int a[])
{
    int temp = 0;
    int counter = 0;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (a[j] >= a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                counter++;
            }
        }
    }
    return counter;
}

int select(int a[])
{
    int min = 0;
    int counter = 0;
    int i, j;

    for (i = 0; i < MAX - 1; i++)
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
            swap(&a[min], &a[i]);
            counter++;
        }
    }
    return counter;
}
int insert(int a[])
{
    int j, i, counter;
    for (i = 1; i < MAX; i++)
    {
        int key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
            counter++;
        }
        a[j + 1] = key;
    }

    return counter;
}

int shell(int a[])
{
    int counter = 0;

    for (int gap = MAX / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < MAX; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
                counter++;
            }
            a[j] = temp;
        }
    }
    return counter;
}
int main()
{

    srand((unsigned)time(NULL));
    int a[MAX];
    int b[MAX];
    int c[MAX];
    int d[MAX];
    double time_taken_bubble = 0.0f;
    double time_taken_select = 0.0f;
    double time_taken_instert = 0.0f;
    double time_taken_shell = 0.0f;
    int counter_bubble = 0;
    int counter_select = 0;
    int counter_insert = 0;
    int counter_shell = 0;
    clock_t tbubble;
    clock_t tselect;
    clock_t tinsert;
    clock_t tshell;

    for (int i = 0; i < MAX; i++)
    {
        a[i] = (rand() % 100) + 1;
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    tbubble = clock();
    counter_bubble = bubble(a);
    tbubble = clock() - tbubble;
    time_taken_bubble = ((double)tbubble) / CLOCKS_PER_SEC;

    tselect = clock();
    counter_select = select(b);
    tselect = clock() - tselect;
    time_taken_select = ((double)tselect) / CLOCKS_PER_SEC;

    tinsert = clock();
    counter_insert = insert(c);
    tinsert = clock() - tinsert;
    time_taken_instert = ((double)tinsert) / CLOCKS_PER_SEC;

    tshell = clock();
    counter_shell = shell(d);
    tshell = clock() - tshell;
    time_taken_shell = ((double)tshell) / CLOCKS_PER_SEC;

    printf("____Bubble-Sort____\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nSorting Time: %.10lf\n", time_taken_bubble);
    printf("Moves: %d\n", counter_bubble);
    printf("____Selection-Sort____\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\nSorting Time: %.10lf\n", time_taken_select);
    printf("Moves: %d\n", counter_select);
    printf("____Insertion-Sort____\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\nSorting Time: %.10lf\n", time_taken_instert);
    printf("Moves: %d\n", counter_insert);
    printf("____Shell-Sort____\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\nSorting Time: %.10lf\n", time_taken_shell);
    printf("Moves: %d\n", counter_shell);

    return EXIT_SUCCESS;
}