#include <stdio.h>
#include <stdlib.h>
int main()
{
    char Area[4][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Area[i][j] = '*';
            printf("%c\t", Area[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\nPointer:\n\n");

    char *ptr = (char *)malloc(12 * sizeof(char));

    for (int i = 0; i < 12; i++)
    {
        *(ptr + i) = '*';
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c\t", *(ptr + (i * j)));
        }
        printf("\n");
    }

    free(ptr);

    return 0;
}
