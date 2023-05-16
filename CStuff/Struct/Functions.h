#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct BOOK
{
    char author[20];
    char title[20];
    char publisher[20];
    int pages;
    char isbn[14];
};

struct PAPER
{
    char title[20];
    char publisher[20];
    int pages;
    int price;
};

struct DVD
{
    char title[20];
    int date;
    int lenght;
    int price;
};

int addObject_BOOK(struct BOOK *book, int bookCounter);
void trimBook(struct BOOK *book);
void sortBook(struct BOOK *book, int counterBook);
void swap_Book(struct BOOK *book, struct BOOK *book2);
void printObject_BOOK(struct BOOK *book, int bookCounter);

int addObject_PAPER(struct PAPER *paper, int paperCounter);
void trimPaper(struct PAPER *paper);
void sortPaper(struct PAPER *paper, int counterPaper);
void swap_Paper(struct PAPER *paper1, struct PAPER *paper2);
void printObject_PAPER(struct PAPER *paper, int paperCounter);

int addObject_DVD(struct DVD *dvd, int dvdCounter);
void trimDvd(struct DVD *dvd);
void sortDvd(struct DVD *dvd, int counterDvd);
void swap_Dvd(struct DVD *dvd1, struct DVD *dvd2);
void printObject_DVD(struct DVD *dvd, int dvdCounter);

int addObject_BOOK(struct BOOK *book, int bookCounter)
{
    char arr[14];
    int pages;
    int check;
    printf("Enter the author of the book: ");
    fflush(stdin);
    fgets(book->author, 20, stdin);
    printf("Enter the title of the book: ");
    fflush(stdin);
    fgets(book->title, 20, stdin);
    printf("Enter the publisher of the book: ");
    fflush(stdin);
    fgets(book->publisher, 20, stdin);
    printf("Enter the number of pages: ");
    scanf("%d", &book->pages);

    do
    {
        check = 0;
        printf("Enter the isbn of the book: ");
        fflush(stdin);
        fgets(arr, 14, stdin);
        for (int i = 0; i < 13; i++)
        {
            if (!((arr[i] != 'X' && arr[i] != 'x') && (arr[i] < 48 || arr[i] > 57)))
            {
                check++;
            }
        }
    } while (check < 13);

    strcpy(book->isbn, arr); //*(book).isbn
    trimBook(book);
    return bookCounter + 1;
}
void trimBook(struct BOOK *book)
{
    book->author[strlen(book->author) - 1] = '\0';
    book->title[strlen(book->title) - 1] = '\0';
    book->publisher[strlen(book->publisher) - 1] = '\0';
}
void sortBook(struct BOOK *book, int counterBook)
{
    int sortFor;
    char arr1[20];
    char arr2[20];
    char cmp;
    char cmp2;
    printf("|0| = Sort for Author\t\t|1| = Sort for Title\t\t|2| = Sort for Publisher\t\t|3| = Sort for Pages\t\t|else| = RETURN\n");
    fflush(stdin);
    scanf("%d", &sortFor);
    switch (sortFor)
    {
    case 0:
        for (int i = 0; i < counterBook - 1; i++)
        {
            strcpy(arr1, book[i].author);
            strcpy(arr2, book[i + 1].author);

            cmp = arr1[0];
            cmp2 = arr2[0];

            if ((int)cmp > (int)cmp2)
            {
                swap_Book(&book[i], &book[i + 1]);
            }
        }

        break;
    case 1:
        for (int i = 0; i < counterBook - 1; i++)
        {
            strcpy(arr1, book[i].title);
            strcpy(arr2, book[i + 1].title);

            cmp = arr1[0];
            cmp2 = arr2[0];

            if ((int)cmp > (int)cmp2)
            {
                swap_Book(&book[i], &book[i + 1]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < counterBook - 1; i++)
        {
            strcpy(arr1, book[i].publisher);
            strcpy(arr2, book[i + 1].publisher);

            cmp = arr1[0];
            cmp2 = arr2[0];

            if ((int)cmp > (int)cmp2)
            {
                swap_Book(&book[i], &book[i + 1]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < counterBook - 1; i++)
        {
            if (book[i].pages > book[i + 1].pages)
            {
                swap_Book(&book[i], &book[i + 1]);
            }
        }
        break;
    default:
        break;
    }
}

void swap_Book(struct BOOK *book, struct BOOK *book2)
{
    struct BOOK temp;

    strcpy(temp.author, book->author);
    strcpy(temp.title, book->title);
    strcpy(temp.publisher, book->publisher);
    strcpy(temp.isbn, book->isbn);
    temp.pages = book->pages;

    strcpy(book->author, book2->author);
    strcpy(book->title, book2->title);
    strcpy(book->publisher, book2->publisher);
    strcpy(book->isbn, book2->isbn);
    book->pages = book2->pages;

    strcpy(book2->author, temp.author);
    strcpy(book2->title, temp.title);
    strcpy(book2->publisher, temp.publisher);
    strcpy(book2->isbn, temp.isbn);
    book2->pages = temp.pages;
}

void printObject_BOOK(struct BOOK *book, int bookCounter)
{
    for (int i = 0; i < bookCounter; i++)
    {
        printf("Author: %s\n", book[i].author);
        printf("Title: %s\n", book[i].title);
        printf("Publisher: %s\n", book[i].publisher);
        printf("Pages: %d\n", book[i].pages);
        printf("isbn: %s", book[i].isbn);
        printf("\n\n");
    }
}

int addObject_PAPER(struct PAPER *paper, int paperCounter)
{
    printf("Enter the title of the News Paper: ");
    fflush(stdin);
    fgets(paper->title, 20, stdin);
    printf("Enter the publisher of the News Paper: ");
    fflush(stdin);
    fgets(paper->publisher, 20, stdin);
    printf("Enter the number of pages: ");
    scanf("%d", &paper->pages);
    printf("Enter the price of the News Paper: ");
    scanf("%d", &paper->price);
    trimPaper(paper);
    return paperCounter + 1;
}
void trimPaper(struct PAPER *paper)
{
    paper->title[strlen(paper->title) - 1] = '\0';
    paper->publisher[strlen(paper->publisher) - 1] = '\0';
}
void sortPaper(struct PAPER *paper, int counterPaper)
{
    int sortFor;
    char arr1[20];
    char arr2[20];
    char cmp;
    char cmp2;
    printf("|0| = Sort for Title\t\t|1| = Sort for Publisher\t\t|2| = Sort for Pages\t\t|3| = Sort for Price\t\t|else| = RETURN\n");
    fflush(stdin);
    scanf("%d", &sortFor);
    switch (sortFor)
    {
    case 0:
        for (int i = 0; i < counterPaper - 1; i++)
        {
            strcpy(arr1, paper[i].title);
            strcpy(arr2, paper[i + 1].title);

            cmp = arr1[0];
            cmp2 = arr2[0];

            if ((int)cmp > (int)cmp2)
            {
                swap_Paper(&paper[i], &paper[i + 1]);
            }
        }

        break;
    case 1:
        for (int i = 0; i < counterPaper - 1; i++)
        {
            strcpy(arr1, paper[i].publisher);
            strcpy(arr2, paper[i + 1].publisher);

            cmp = arr1[0];
            cmp2 = arr2[0];

            if ((int)cmp > (int)cmp2)
            {
                swap_Paper(&paper[i], &paper[i + 1]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < counterPaper - 1; i++)
        {

            if (paper[i].pages > paper[i + 1].pages)
            {
                swap_Paper(&paper[i], &paper[i + 1]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < counterPaper - 1; i++)
        {
            if (paper[i].price > paper[i + 1].price)
            {
                swap_Paper(&paper[i], &paper[i + 1]);
            }
        }
        break;
    default:
        break;
    }
}

void swap_Paper(struct PAPER *paper1, struct PAPER *paper2)
{
    struct PAPER temp;

    strcpy(temp.title, paper1->title);
    strcpy(temp.publisher, paper1->publisher);
    temp.pages = paper1->pages;
    temp.price = paper1->price;

    strcpy(paper1->title, paper2->title);
    strcpy(paper1->publisher, paper2->publisher);
    paper1->pages = paper2->pages;
    paper1->price = paper2->price;

    strcpy(paper2->title, temp.title);
    strcpy(paper2->publisher, temp.publisher);
    paper2->pages = temp.pages;
    paper2->price = temp.price;
}

void printObject_PAPER(struct PAPER *paper, int paperCounter)
{
    for (int i = 0; i < paperCounter; i++)
    {
        printf("Title: %s\n", paper[i].title);
        printf("Publisher: %s\n", paper[i].publisher);
        printf("Pages: %d\n", paper[i].pages);
        printf("Price: %d", paper[i].price);
        printf("\n\n");
    }
}

int addObject_DVD(struct DVD *dvd, int dvdCounter)
{
    printf("Enter the title of the DVD: ");
    fflush(stdin);
    fgets(dvd->title, 20, stdin);
    printf("Enter the release-date of the dvd: ");
    scanf("%d", &dvd->date);
    printf("Enter the lenght of the DVD: ");
    scanf("%d", &dvd->lenght);
    printf("Enter the price of the DVD: ");
    scanf("%d", &dvd->price);
    trimDvd(dvd);
    return dvdCounter + 1;
}
void trimDvd(struct DVD *dvd)
{
    dvd->title[strlen(dvd->title) - 1] = '\0';
}
void sortDvd(struct DVD *dvd, int counterDvd)
{
    int sortFor;
    char arr1[20];
    char arr2[20];
    char cmp;
    char cmp2;
    printf("|0| = Sort for Titel\t\t|1| = Sort for Date\t\t|2| = Sort for Lenght\t\t|3| = Sort for Price\t\t|else| = RETURN\n");
    fflush(stdin);
    scanf("%d", &sortFor);
    switch (sortFor)
    {
    case 0:
        for (int i = 0; i < counterDvd - 1; i++)
        {
            strcpy(arr1, dvd[i].title);
            strcpy(arr2, dvd[i + 1].title);

            cmp = arr1[0];
            cmp2 = arr2[0];

            if ((int)cmp > (int)cmp2)
            {
                swap_Dvd(&dvd[i], &dvd[i + 1]);
            }
        }

        break;
    case 1:
        for (int i = 0; i < counterDvd - 1; i++)
        {

            if (dvd[i].date > dvd[i + 1].date)
            {
                swap_Dvd(&dvd[i], &dvd[i + 1]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < counterDvd - 1; i++)
        {
            if (dvd[i].lenght > dvd[i + 1].lenght)
            {
                swap_Dvd(&dvd[i], &dvd[i + 1]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < counterDvd - 1; i++)
        {
            if (dvd[i].price > dvd[i + 1].price)
            {
                swap_Dvd(&dvd[i], &dvd[i + 1]);
            }
        }
        break;
    default:
        break;
    }
}

void swap_Dvd(struct DVD *dvd1, struct DVD *dvd2)
{
    struct DVD temp;

    strcpy(temp.title, dvd1->title);
    temp.date = dvd1->date;
    temp.lenght = dvd1->lenght;
    temp.price = dvd1->price;

    strcpy(dvd1->title, dvd2->title);
    dvd1->date = dvd2->date;
    dvd1->lenght = dvd2->lenght;
    dvd1->price = dvd2->price;

    strcpy(dvd1->title, temp.title);
    dvd1->date = temp.date;
    dvd1->lenght = temp.lenght;
    dvd1->price = temp.price;
}
void printObject_DVD(struct DVD *dvd, int dvdCounter)
{
    for (int i = 0; i < dvdCounter; i++)
    {
        printf("Title: %s\n", dvd[i].title);
        printf("Publishing Year: %d\n", dvd[i].date);
        printf("Lenght: %d\n", dvd[i].lenght);
        printf("Price: %d", dvd[i].price);
        printf("\n\n");
    }
}

void end()
{
    exit(EXIT_SUCCESS);
}

void clrscr()
{
    system("clear");
}
