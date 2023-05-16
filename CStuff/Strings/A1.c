#include <stdio.h>
#include <stdlib.h>

int stringlen(char word[100])
{
    int counter = 0;
    while (word[counter] != '\0')
    {
        counter++;
    }
    return counter - 1;
}

int main()
{
    char word[100];
    int counter = 0;
    printf("Enter your Sentence: ");
    fgets(word, 100, stdin);

    counter = stringlen(word);

    printf("Lenght: %d\n", counter);
    return EXIT_SUCCESS;
}