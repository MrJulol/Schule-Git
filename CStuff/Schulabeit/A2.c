#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 30
#define TRUE 1

int newUser(char names[][2][20], int numberOfUsers);
void printAllUsers(char names[][2][20], int numberOfUsers);
void end();

int main()
{
    char names[30][2][20];
    int numberOfUsers = 0;
    int choice = 0;

    while (TRUE)
    {
        system("clear");
        printf("|0| = New_User  |1| = Print_User    |else| = END\n");
        scanf("%d", &choice);

        if (!choice)
        {
            numberOfUsers = newUser(names, numberOfUsers);
        }
        else if (choice == 1 && numberOfUsers != 0 && numberOfUsers != -1)
        {
            printAllUsers(names, numberOfUsers);
        }
        else
        {
            end();
        }
    }
    return EXIT_SUCCESS;
}

int newUser(char names[][2][20], int numberOfUsers)
{
    char *ptr = &names[numberOfUsers][0][0];
    printf("Enter your First Name: ");
    scanf("%s", ptr);
    ptr = &names[numberOfUsers][1][0];
    printf("Enter your last name: ");
    scanf("%s", ptr);
    numberOfUsers++;
    return numberOfUsers;
}

void printAllUsers(char names[][2][20], int numberOfUsers)
{
    for (int i = 0; i < numberOfUsers; i++)
    {
        char *ptr = &names[i][0][0];
        printf("%s\n", ptr);
        ptr = &names[i][1][0];
        printf("%s\n", ptr);
    }
}

void end()
{
    printf("\n");
    exit(EXIT_SUCCESS);
}