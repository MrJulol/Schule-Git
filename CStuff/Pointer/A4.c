#include <stdio.h>
#include <stdlib.h>

int add(const long count, const long *numbers)
{
    long sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += *(numbers + i);
    }
    return (int)sum;
}

int main()
{
    char input[100];
    long numCounter;

    printf("How many numbers? ");
    fflush(stdin);
    fgets(input, 100, stdin);
    numCounter = strtol(input, NULL, 10);

    long *numbers = malloc(numCounter * sizeof(int));

    for (long i = 0; i < numCounter; i++)
    {
        fflush(stdin);
        fgets(input, 100, stdin);
        *(numbers+i) = strtol(input, NULL, 10);
    }

    printf("Total: %d\n", add(numCounter, numbers));

    return EXIT_SUCCESS;
}
