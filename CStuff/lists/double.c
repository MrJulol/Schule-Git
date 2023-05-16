#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

struct PERSON
{
    char name[20];
    int age;
    struct PERSON *next;
    struct PERSON *prev;
};
struct PERSON *head;

void addend();
void addbeg();
void prrand();
void prall();
void addrand();
void delrand();
void clrscr();
void cutstr(char name[]);

int main()
{
    clrscr();
    int choice = 1;
    while (choice != 0)
    {
        printf("\n\n______Main Menu______\n\n");
        printf("1 = Add at the End\t2 = Print a certain Element\t3 = Print All\t4 = Add at a certain Position\t5 = Delete a certain element\t6 = Add at the beginning\t0 = EXIT\n");
        printf("Your Input: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addend();
            break;
        case 2:
            prrand();
            break;
        case 3:
            prall();
            break;
        case 4:
            addrand();
            break;
        case 5:
            delrand();
            break;
        case 6:
            addbeg();
            break;
        default:
            continue;
        }
    }
    struct PERSON *ptr, *end, *temp;
    ptr = head;
    while (ptr != NULL)
    {
        end = ptr;
        ptr = ptr->next;
    }
    temp = ptr;
    while (temp != NULL)
    {
        temp = end->prev;
        free(end);
        end = temp;
    }
    return EXIT_SUCCESS;
}

void addend()
{
    char name[20];
    int age;
    printf("Add a Person to the end of the list\n");
    struct PERSON *ptr = (struct PERSON *)malloc(sizeof(struct PERSON));
    if (ptr == NULL)
    {
        printf("Error during Memory-Allocation\n");
    }
    else
    {
        printf("Enter the name of the employee: ");
        fflush(stdin);
        fgets(name, 20, stdin);
        cutstr(name);
        strcpy(ptr->name, name);
        printf("\nEnter the age of the employee: ");
        scanf("%d", &ptr->age);
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            printf("Employee succesfully added to system");
        }
        else
        {
            struct PERSON *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
            printf("Employee succesfully added to system");
        }
    }
}

void addbeg()
{
    struct PERSON *ptr, *temp;
    int age;
    char name[20];

    printf("Add a Person to the beginning of the list\n");

    ptr = malloc(sizeof(struct PERSON));
    if (ptr == NULL)
    {
        printf("Error during Memory-Allocation\n");
    }
    else
    {
        printf("Enter the name of the employee: ");
        fflush(stdin);
        fgets(name, 20, stdin);
        cutstr(name);
        strcpy(ptr->name, name);
        printf("\nEnter the age of the employee: ");
        scanf("%d", &ptr->age);

        ptr->next = head;
        ptr->prev = NULL;

        if (head != NULL)
        {
            head->prev = ptr;
        }
        head = ptr;
    }
}

void prrand()
{
    int loca;
    struct PERSON *ptr = head;

    printf("Print a certain Employee\n");
    printf("Which Employee do you want to print? ");
    scanf("%d", &loca);

    if (ptr == NULL)
    {
        printf("Data not foud!");
    }
    else
    {
        for (int i = 0; i < loca - 1; i++)
        {
            if (ptr->next == NULL)
            {
                printf("Data not found");
                return;
            }
            ptr = ptr->next;
        }
        printf("Data found: \nName: %s\nAge: %d\n", ptr->name, ptr->age);
    }
}

void prall()
{
    printf("Print all employees!\n");
    struct PERSON *ptr;
    struct PERSON *end;
    int i = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Data not found!");
    }
    else
    {
        printf("\nForeward:  ");
        while (ptr != NULL)
        {

            printf("\nEmploye Nr.%d: \nName: %s\nAge: %d\n", i, ptr->name, ptr->age);
            i++;
            end = ptr;
            ptr = ptr->next;
        }
        printf("\n\nBackwards");
        while (end != NULL)
        {
            printf("\nEmploye Nr.%d: \nName: %s\nAge: %d\n", i - 1, end->name, end->age);
            i--;
            end = end->prev;
        }
    }
}

void addrand()
{
    char name[20];
    printf("Add Data to certain Position");
    int loca, input;
    struct PERSON *ptr, *temp;
    ptr = (struct PERSON *)malloc(sizeof(struct PERSON));

    if (ptr == NULL)
    {
        printf("Error during Memory-Allocation");
    }
    else
    {
        printf("Enter the name of the employee: ");
        fflush(stdin);
        fgets(name, 20, stdin);
        cutstr(name);
        strcpy(ptr->name, name);
        printf("\nEnter the age of the employee: ");
        scanf("%d", &ptr->age);
        printf("Where do you want to insert? ");
        scanf("%d", &loca);
        temp = head;
        for (int i = 0; i < loca; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Data not found\n");
                return;
            }
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        printf("Employee succesfully added to the system");
    }
}

void delrand()
{

    printf("Delete Employee at a certain location\n");
    struct PERSON *ptr, *ptr2;
    int loca;
    printf("Which Employee do you want to delete? ");
    scanf("%d", &loca);

    for (int i = 0; i < loca; i++)
    {
        ptr2 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("Data not found\n");
            return;
        }
    }
    ptr2->next = ptr->next;
    free(ptr);
    printf("Succesfully deleted Data!");
}

void clrscr()
{
    // system("clear");
}

void cutstr(char name[])
{
    name[strlen(name) - 1] = '\0';
}
