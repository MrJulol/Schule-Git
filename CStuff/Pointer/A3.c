#include <stdio.h>
#include <stdlib.h>

#define MAX_READ 200

void readstring(char *ptr)
{
    fflush(stdin);
    fgets(ptr, MAX_READ, stdin);
}

void printstring(char *ptr)
{
    printf("%s", ptr);
}

int main()
{

    char *ptr = (char *)malloc(MAX_READ * sizeof(char));
    readstring(ptr);
    printstring(ptr);

    free(ptr);

    return EXIT_SUCCESS;
}
