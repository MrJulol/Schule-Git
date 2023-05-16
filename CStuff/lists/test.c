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

void swapStruct(struct node *ptr, struct node *ptr2, struct node *ptr3)
{
    if (ptr3 == NULL)
    {
        ptr2->next = NULL;
        return;
    }
    if (ptr == NULL)
    {
        if (head == ptr2)
        {
            head = ptr3;
        }
        ptr2->next = ptr3->next;
        ptr3->next = ptr2;
        ptr2->prev = ptr3;
        ptr3->prev = NULL;
        return;
    }
    struct node *temp1;
    struct node *temp2;
    if (ptr2 == head)
    {
        head = ptr3;
    }
    temp1 = ptr3;
    ptr->next = ptr3;
    ptr3->next = ptr2;
    ptr2->next = temp1->next;
    ptr3->prev = ptr;
    ptr2->prev = ptr3;
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

int main()
{
    int len = 0;
    struct node *ptr1 = malloc(sizeof(struct node));
    struct node *ptr2 = malloc(sizeof(struct node));
    struct node *ptr3 = malloc(sizeof(struct node));
    struct node *ptr4 = malloc(sizeof(struct node));

    head = ptr1;

    char *test = "asd";
    strcpy(ptr1->name, test);
    strcpy(ptr2->name, test);
    strcpy(ptr3->name, test);
    strcpy(ptr4->name, test);

    strcpy(ptr1->name, test);
    strcpy(ptr2->name, test);
    strcpy(ptr3->name, test);
    strcpy(ptr4->name, test);

    strcpy(ptr1->name, test);
    strcpy(ptr2->name, test);
    strcpy(ptr3->name, test);
    strcpy(ptr4->name, test);

    ptr1->age = 5;
    ptr2->age = 4;
    ptr3->age = 3;
    ptr4->age = 2;

    ptr1->abt = 5;
    ptr2->abt = 4;
    ptr3->abt = 3;
    ptr4->abt = 2;

    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = NULL;

    ptr1->prev = NULL;
    ptr2->prev = ptr1;
    ptr3->prev = ptr2;
    ptr4->prev = ptr3;

    prall();

    struct node *currHead = head;
    int swapped = 1;
    while (swapped != 0)
    {
        swapped = 0;
    }

    prall();
    printf("\n");
    return EXIT_SUCCESS;
}