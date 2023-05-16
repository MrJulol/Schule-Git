#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    char *temp = NULL;
    printf("Enter width");
    scanf("%d", &width);
    printf("Enter height");
    scanf("%d", &height);

    char **ptr = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        *(ptr + i) = (char *)malloc(width * sizeof(char));
    }

    for (int i = 0; i < height; i++)
    {
        temp = *(ptr + i);
        for (int j = 0; j < width; j++)
        {
            *(temp + j) = '*';
        }
    }

    for (int i = 0; i < height; i++)
    {
        temp = *(ptr + i);
        for (int j = 0; j < width; j++)
        {
            printf("%c", *(temp + j));
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++)
    {
        free(*(ptr + i));
    }
    free(ptr);
    return EXIT_SUCCESS;
}