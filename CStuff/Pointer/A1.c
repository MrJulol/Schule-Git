#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{

    int a = 1;
    int b = 0;

    printf("%d, %d\n", a, b);

    swap(&a, &b);

    printf("%d, %d\n", a, b);

    return EXIT_SUCCESS;
}
