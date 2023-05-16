#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char arr[200];
    char arr2[200];
    char arrrev[200];
    int status = 0;
    int index = 0;
    printf("Enter Sentence: ");
    fgets(arr, 200, stdin);
    arr[strlen(arr) - 1] = '\0';

    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] > 64 && arr[i] < 91)
        {
            arr[i] += 32;
        }
    }

    for (int i = 0; i < strlen(arr); i++)
    {
        if (!(arr[i] == ' ' || arr[i] == ';'))
        {
            arr2[index] = arr[i];
            index++;
        }
    }

    for (int i = 0; i < strlen(arr2); i++)
    {
        arrrev[(strlen(arr2) - 1) - i] = arr2[i];
    }

    for (int i = 0; i < strlen(arr2); i++)
    {
        if (arr2[i] != arrrev[i])
        {
            status = 1;
            break;
        }
    }

    if (status)
    {
        printf("NOT\n");
    }
    else
    {
        printf("IS\n");
    }

    return EXIT_SUCCESS;
}