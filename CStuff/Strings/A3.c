//! NOT FINFISHED DO NOT COMPILE + RUN

#include <stdio.h>
#include <stdlib.h>

void stringlen(char word[100], int *len)
{
    int counter = 0;
    while (word[counter] != '\0')
    {
        counter++;
    }
    *len = counter - 1;
    return;
}

int check(char sentence[500], char word[100], int *lensentence, int *lenword)
{
    int positionword = 0;
    for (int i = 0; i < *lensentence; i++)
    {
        if (sentence[i] == word[positionword])
        {
        }
    }
}
int main()
{

    char word[100];
    char sentence[500];
    int lensentence;
    int lenword;

    printf("Enter your sentence: ");
    fgets(sentence, 500, stdin);
    printf("Enter the word you want to search: ");
    fgets(word, 100, stdin);

    stringlen(sentence, &lensentence);
    stringlen(sentence, &lenword);

    check(sentence, word, &lensentence, &lenword);

    printf("\n");
    return 0;
}