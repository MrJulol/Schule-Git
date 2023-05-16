#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int add_em_up(int count, ...)
{
    va_list lst;
    int i, sum;

    va_start(lst, count); /* Initialize the argument list. */

    sum = 0;
    for (i = 0; i < count; i++)
        sum += va_arg(lst, int); /* Get the next argument value. */

    va_end(lst); /* Clean up. */
    return sum;
}

int main()
{
    printf("%d\n", add_em_up(3, 5, 5, 6));
    printf("%d\n", add_em_up(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

    return 0;
}