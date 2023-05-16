#include <stdio.h>
#include <stdlib.h>

int equals(char word1[], char word2[], int len);
void merge(char word1[], char word2[], int len, int len2);
void switchstring(char word[], int len);
void stringlen(char word[], int *len);

#define SIZE 100

int main()
{
    char word1[SIZE];
    char word2[SIZE];
    int len = 0;
    int len2 = 0;
    int equal = 0;

    printf("Enter Word 1: ");
    fgets(word1, SIZE, stdin);
    printf("Enter Word 2: ");
    fgets(word2, SIZE, stdin);

    stringlen(word1, &len);
    stringlen(word2, &len2);

    if (len == len2)
    {
        equal = equals(word1, word2, len);
    }
    if (equal)
    {
        printf("Both words are the same.\n");
    }
    else
    {
        merge(word1, word2, len, len2);
    }
    return EXIT_SUCCESS;
}

void stringlen(char word[], int *len)
{
    int counter = 0;
    while (word[counter] != '\n')
    {
        counter++;
    }
    *len = counter;
}

int equals(char word1[], char word2[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (word1[i] != word2[i])
        {
            return 0;
        }
    }
    return 1;
}

void merge(char word1[], char word2[], int len, int len2)
{
    char wordmerged[len + len2];

    for (int i = 0; i < len + len2; i++)
    {
        wordmerged[i] = ' ';
    }
    for (int i = 0; i < len; i++)
    {
        wordmerged[i] = word1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        wordmerged[len + i] = word2[i];
    }

    printf("The merged word: ");
    for (int i = 0; i < len + len2; i++)
    {
        printf("%c", wordmerged[i]);
    }
    printf("\n");

    switchstring(wordmerged, len + len2);
}

void switchstring(char word[], int len)
// Switches the inside of the string
{
    int temp = 0;
    char wordswitched[len];
    for (int i = 0; i < len; i++)
    {
        temp = word[len - i - 1];
        wordswitched[i] = temp;
        word[len - i - 1] = wordswitched[i];
    }

    printf("The switched up word: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", wordswitched[i]);
    }

    printf("\n"); // WHY? MAC OS Terminal
}
