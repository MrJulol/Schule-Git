#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    char surname[20];
    int age;
    char adress[50];
    int abt;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

void addend();
void addbeg();
void prrand();
void prall();
void addrand();
void sort();

void swapStruct(struct node *ptr, struct node *ptr2, struct node *ptr3)
{
    void *temp1;
    void *temp2;
    if (ptr2 == head)
    {
        head = ptr3;
    }
    temp1 = ptr3->next;
    ptr->next = ptr3;
    ptr3->next = ptr2;
    ptr2->next = temp1;
    ptr3->prev = ptr;
    ptr2->prev = ptr3;
}
void searchob();
void clrscr();
void cutstr(char name[]);

int main()
{
    int choice = 1;
    while (choice)
    {
        printf("\n______Main Menu______\n\n");
        printf("1 = Add at the End\t2 = Print a certain Element\t3 = Print All\t4 "
               "= Add at a certain Position\t5 = Delete a certain element\t6 = Add "
               "at the beginning\t7 = Sort(does not work)\t8 = Search\t0 = EXIT\n");
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
            break;
        case 6:
            addbeg();
            break;
        case 7:
            sort();
        case 8:
            searchob();
        default:
            continue;
        }
    }
    return EXIT_SUCCESS;
}

void addbeg()
{
    struct node *ptr = malloc(sizeof(struct node));
    char name[20];
    char surname[20];
    char address[50];
    int abt = 0;

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
        printf("Enter the surname of the employee: ");
        fflush(stdin);
        fgets(surname, 20, stdin);
        cutstr(surname);
        strcpy(ptr->surname, surname);
        printf("Enter the age of the employee: ");
        scanf("%d", &ptr->age);
        printf("Enter the address of the employee: ");
        fflush(stdin);
        fgets(address, 50, stdin);
        cutstr(address);
        strcpy(ptr->adress, address);
        do
        {
            printf("Enter the abt of the employee: ");
            scanf("%d", &abt);
        } while (abt < 1 || abt > 12);
        ptr->abt = abt;
        clrscr();
        ptr->next = head;
        head = ptr;
        ptr->prev = NULL;
        printf("Employee succesfully added to system");
    }
}
void addend()
{
    char name[20];
    char surname[20];
    char address[50];
    int abt;
    struct node *ptr, *temp;
    ptr = malloc(sizeof(struct node));

    clrscr();
    printf("Add a Person to the end of the list\n");
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
        printf("Enter the surname of the employee: ");
        fflush(stdin);
        fgets(surname, 20, stdin);
        cutstr(surname);
        strcpy(ptr->surname, surname);
        printf("Enter the age of the employee: ");
        scanf("%d", &ptr->age);
        printf("Enter the address of the employee: ");
        fflush(stdin);
        fgets(address, 50, stdin);
        cutstr(address);
        strcpy(ptr->adress, address);
        do
        {
            printf("Enter the abt of the employee: ");
            scanf("%d", &abt);
        } while (abt < 1 || abt > 12);
        ptr->abt = abt;
        clrscr();
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
            printf("Employee succesfully added to system");
        }
        else
        {
            temp = head;
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
void addrand()
{
    char name[20];
    char surname[20];
    char address[50];
    int abt;
    printf("Add Data to certain Position");
    int loca, input;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));

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
        printf("Enter the surname of the employee: ");
        fflush(stdin);
        fgets(surname, 20, stdin);
        cutstr(surname);
        strcpy(ptr->surname, surname);
        printf("Enter the age of the employee: ");
        scanf("%d", &ptr->age);
        printf("Enter the address of the employee: ");
        fflush(stdin);
        fgets(address, 50, stdin);
        cutstr(address);
        strcpy(ptr->adress, address);
        do
        {
            printf("Enter the abt of the employee: ");
            scanf("%d", &abt);
        } while (abt < 1 || abt > 12);
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
void prall()
{
    printf("Print all employees!\n");
    struct node *ptr = head;
    int i = 1;
    if (ptr == NULL)
    {
        printf("Data not found!");
    }
    else
    {
        while (ptr != NULL)
        {

            printf("\nEmploye Nr.%d: \nName: %s\nSurname: %s\nAddress: %s\nAge: %d\nAbt: %d\n", i, ptr->name, ptr->surname, ptr->adress, ptr->age, ptr->abt);
            i++;
            ptr = ptr->next;
        }
    }
}
void prrand()
{
    int loca;
    printf("Print a certain Employee\n");
    printf("Which Employee do you want to print? ");
    scanf("%d", &loca);
    struct node *ptr;
    ptr = head;
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
        printf("Data found: \nName: %s\nSurname: %s\nAddress: %s\nAge: %d\nAbt: %d\n", ptr->name, ptr->surname, ptr->adress, ptr->age, ptr->abt);
    }
}

void sort()
//!!!THIS SHIT IS NOT WORKING!!!! DO NOT USE AT ALL COSTS
{
    int lenght;
    int choice = 0;
    struct node *ptr;
    char arr[20];
    char arr2[20];
    char temp1;
    char temp2;
    ptr = head;

    printf("1 = Name\t2 = Surname\t3 = Address\t4 = Age\t5 = abt\t0 = EXIT\n");
    scanf("%d", &choice);

    lenght = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        lenght++;
    }

    switch (choice)
    {
    case 1:
        for (int i = 0; i < lenght; i++)
        {
            ptr = head;
            for (int j = 0; j < lenght; j++)
            {
                strcpy(arr, ptr->name);
                strcpy(arr2, ptr->next->name);

                temp1 = arr[0];
                temp2 = arr2[0];

                if ((int)temp2 > (int)temp1)
                {
                    swapStruct(ptr->prev, ptr, ptr->next);
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < lenght; i++)
        {
            ptr = head;
            for (int j = 0; j < lenght; j++)
            {
                strcpy(arr, ptr->surname);
                strcpy(arr2, ptr->next->surname);

                temp1 = arr[0];
                temp2 = arr2[0];

                if ((int)temp2 > (int)temp1)
                {
                    swapStruct(ptr->prev, ptr, ptr->next);
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < lenght; i++)
        {
            ptr = head;
            for (int j = 0; j < lenght; j++)
            {
                strcpy(arr, ptr->adress);
                strcpy(arr2, ptr->next->adress);

                temp1 = arr[0];
                temp2 = arr2[0];

                if ((int)temp2 > (int)temp1)
                {
                    swapStruct(ptr->prev, ptr, ptr->next);
                }
            }
        }
        break;
    case 4:
        for (int i = 0; i < lenght; i++)
        {
            ptr = head;
            for (int j = 0; j < lenght; j++)
            {
                if (ptr->next->age > ptr->age)
                {
                    swapStruct(ptr->prev, ptr, ptr->next);
                }
            }
        }
        break;
    case 5:
        for (int i = 0; i < lenght; i++)
        {
            ptr = head;
            for (int j = 0; j < lenght; j++)
            {
                if (ptr->next->abt > ptr->abt)
                {
                    swapStruct(ptr->prev, ptr, ptr->next);
                }
            }
        }
        break;
    default:
        break;
    }
}

void searchob()
{
    int choice = 0;
    char arr[20];
    int i = 0;
    int age = 0;
    struct node *ptr = head;
    printf("1 = Name\t2 = Surname\t3 = Address\t4 = Age\t5 = abt\t0 = EXIT\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        clrscr();
        printf("Enter Name");
        fgets(arr, 20, stdin);
        cutstr(arr);
        i = 0;
        while (ptr->next != NULL)
        {
            int a = strcmp(arr, ptr->name);
            i++;
            if (a)
            {
                continue;
            }
            else
            {
                printf("Found: Poition: %d, Name: %s", i, ptr->name);
                break;
            }
        }
        break;
    case 2:
        clrscr();
        printf("Enter Surname: ");
        fgets(arr, 20, stdin);
        cutstr(arr);
        i = 0;
        while (ptr->next != NULL)
        {
            int a = strcmp(arr, ptr->surname);
            i++;
            if (a)
            {
                continue;
            }
            else
            {
                printf("Found: Poition: %d, Name: %s", i, ptr->surname);
                break;
            }
        }
        break;
    case 3:
        clrscr();
        printf("Enter Adress: ");
        fgets(arr, 20, stdin);
        cutstr(arr);
        i = 0;
        while (ptr->next != NULL)
        {
            int a = strcmp(arr, ptr->adress);
            i++;
            if (a)
            {
                continue;
            }
            else
            {
                printf("Found: Poition: %d, Name: %s", i, ptr->adress);
                break;
            }
        }
        break;
    case 4:
        clrscr();
        printf("Enter age: ");
        scanf("%d,", &age);
        i = 0;
        while (ptr->next != NULL)
        {
            if (age != ptr->age)
            {
                continue;
            }
            else
            {
                printf("Found at Position: %d, Age: %d", i, ptr->age);
                break;
            }
        }
        break;
    case 5:
        clrscr();
        printf("Enter abt: ");
        scanf("%d,", &age);
        i = 0;
        while (ptr->next != NULL)
        {
            if (age != ptr->abt)
            {
                continue;
            }
            else
            {
                printf("Found at Position: %d, Age: %d", i, ptr->abt);
                break;
            }
        }
        break;
    case 0:
        return;
    }
    return;
}

void clrscr()
{
    system("clear");
}

void cutstr(char name[])
{
    name[strlen(name) - 1] = '\0';
}
