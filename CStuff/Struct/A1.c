#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

struct Person
{
    char firstname[20];
    char lastname[20];
    int age;
};

void trim(struct Person *personen)
{
    personen->firstname[strlen(personen->firstname) - 1] = '\0';
    personen->lastname[strlen(personen->lastname) - 1] = '\0';
}

int adduser(struct Person *personen, int numberOfUsers)
{
    printf("Enter your firstname: ");
    fflush(stdin);
    fgets(personen->firstname, 20, stdin);
    printf("Enter your lastname: ");
    fflush(stdin);
    fgets(personen->lastname, 20, stdin);
    printf("Enter your age: ");
    scanf("%d", &personen->age);
    trim(personen);
    numberOfUsers++;
    return numberOfUsers;
}

void printAllUser(struct Person *personen, int numberOfUsers)
{
    for (int i = 0; i < numberOfUsers; i++)
    {
        printf("Vorname: %s\n", personen[i].firstname);
        printf("Nachname: %s\n", personen[i].lastname);
        printf("Alter: %d\n", personen[i].age);
        printf("\n");
    }
}

void end()
{
    exit(0);
}

int main()
{
    int choice = 0;
    int numberOfUsers = 0;
    struct Person personen[100];

    while (TRUE)
    {
        printf("|0| = New_User  |1| = Print_User    |else| = END\n");
        scanf("%d", &choice);

        if (!choice)
        {
            numberOfUsers = adduser(&personen[numberOfUsers], numberOfUsers);
        }
        else if (choice == 1 && numberOfUsers != 0 && numberOfUsers != -1)
        {
            printAllUser(personen, numberOfUsers);
        }
        else
        {
            end();
        }
    }

    return EXIT_SUCCESS;
}