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

#ifndef __STDLIB_H
#define __STDLIB_H
#endif

#define PI 3.14159265359

#define MAX(x, y) ((x) <= (y) ? (y) : (x))

int main()
{
    clrscr();
    HELLO();

    int choice = 0;
    int choice2 = 0;
    int howmany = 0;
    int howmany2 = 0;
    int max = 0;
    srand((unsigned)time(NULL));

    printf("Wie viele Zufallszahlen? ");
    scanf("%d", &howmany);

    int *ptr = malloc(howmany * sizeof(int)); // Allocate Memory the size of howmany * datatype

    if (ptr == NULL)
    {
        printf("Sorry! Unable to allocate memory\n");
        exit(0);
    }

    for (int i = 0; i < howmany; i++)
    {
        *(ptr + i) = (rand() % 1000) + 1;
        printf("%d\n", *(ptr + i));
    }
    printf("Do you want more numbers?\t");
    printf("[Anything else] = Yes\t\t [0] = NO \n");
    scanf("%d", &choice);
    clrscr();
    HELLO();

    if (choice)
    {
        printf("How many?");
        scanf("%d", &howmany2);
        clrscr();
        HELLO();
        ptr = realloc(ptr, howmany2);
        if (ptr == NULL)
        {
            printf("Sorry! Unable to allocate memory\n");
            exit(0);
        }
        for (int i = 0; i < howmany2; i++)
        {
            *(ptr + howmany + i) = (rand() % 1000) + 1;
        }

        for (int i = 0; i < howmany2 + howmany; i++)
        {
            printf("%d\n", *(ptr + i));
            for (int i = 1; i < howmany2 + howmany; i++)
            {
                max = MAX(*(ptr + i), max);
            }
        }
        printf("The biggest number is: %d\n", max);
    }
    printf("Do you want number * PI?\t");
    printf("[Anything else] = Yes\t\t [0] = NO \n");
    scanf("%d", &choice2);
    clrscr();
    HELLO();

    if (choice2)
    {
        float *ptrf = malloc((howmany + howmany2) * sizeof(float));
        float max = 0;
        if (ptrf == NULL)
        {
            printf("Sorry! Unable to allocate memory\n");
            exit(0);
        }
        for (int i = 0; i < howmany2 + howmany; i++)
        {
            *(ptrf + i) = (float)*(ptr + i) * PI;
            printf("%f\n", *(ptrf + i));
            for (int i = 1; i < howmany2 + howmany; i++)
            {
                max = MAX(*(ptrf + i), max);
            }
        }
        printf("The biggest number is: %f\n", max);
        free(ptrf);
    }

    free(ptr);

    return EXIT_SUCCESS;
}