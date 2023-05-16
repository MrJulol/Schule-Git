#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZEMAX 100

void stringlen(char word[], int *len);
void switchstring(char word[], int len);

int main()
{
    char word[SIZEMAX];
    int len = 0;
    printf("Enter a word: ");
    fgets(word, SIZEMAX, stdin);

    stringlen(word, &len);

    char pali[len];
    pali[len] = '\0';

    for (int i = 0; i < len; i++)
    {
        pali[i] = toupper(word[i]);
    }

    switchstring(pali, len);

    printf("\n");
    return 0;
}

void stringlen(char word[], int *len)
{
    int lencounter = 0;
    while (word[lencounter] != '\n')
    {
        lencounter++;
    }
    *len = lencounter;
}

void switchstring(char word[], int len)
// Switches the inside of the string
{
    int temp = 0;
    char wordswitched[len];
    wordswitched[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        temp = word[len - i - 1];
        wordswitched[i] = temp;
        word[len - i - 1] = wordswitched[i];
    }

    for (int i = 0; i < len; i++)
    {
        if (wordswitched[i] != word[i])
        {
            printf("The word %s is not a Palindrom\n", word);
            exit(0);
        }
    }
    printf("%s = %s\n", word, wordswitched);
    printf("The word you enterd is a Palindrom\n");
}
