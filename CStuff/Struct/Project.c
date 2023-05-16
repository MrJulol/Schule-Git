#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Functions.h>

#define TRUE 1

struct BOOK
{
    char author[20];
    char title[20];
    char publisher[20];
    int pages;
    char ISBN[14];
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
void printObject_BOOK(struct BOOK *book, int bookCounter);

int addObject_PAPER(struct PAPER *paper, int paperCounter);
void trimPaper(struct PAPER *paper);
void printObject_PAPER(struct PAPER *paper, int paperCounter);

int addObject_DVD(struct DVD *dvd, int dvdCounter);
void trimDvd(struct DVD *dvd);
void printObject_DVD(struct DVD *dvd, int dvdCounter);

void end();

void clrscr();

int main()
{
    clrscr();
    int printOrAdd = 0;
    int bookPaperDvd = 0;

    int bookCounter = 0;
    int paperCounter = 0;
    int dvdCounter = 0;

    struct BOOK book[100];
    struct PAPER paper[100];
    struct DVD dvd[100];

    while (TRUE)
    {
        printf("|0| = Add Object\t\t|1| = Print Objects\t\t|else| = EXIT\n");
        fflush(stdin);
        scanf("%d", &printOrAdd);
        switch (printOrAdd)
        {
        case 0:
            clrscr();
            printf("|0| = Add a new book\t\t|1| = Add a new News Paper\t\t|2| = Add a new DVD\t\t|else| = RETURN\n");
            fflush(stdin);
            scanf("%d", &bookPaperDvd);
            clrscr();
            switch (bookPaperDvd)
            {
            case 0:
                bookCounter = addObject_BOOK(&book[bookCounter], bookCounter);
                break;
            case 1:
                paperCounter = addObject_PAPER(&paper[paperCounter], paperCounter);
                break;
            case 2:
                dvdCounter = addObject_DVD(&dvd[dvdCounter], dvdCounter);
                break;

            default:
                continue;
                break;
            }
            break;
        case 1:
            clrscr();
            printf("|0| = Print Books\t\t|1| = Print News Papers\t\t|2| = Print DVDs\t\t|3| = Print All\t\t|else| = RETURN\n");
            fflush(stdin);
            scanf("%d", &bookPaperDvd);
            clrscr();
            switch (bookPaperDvd)
            {
            case 0:
                if (bookCounter)
                {
                    printObject_BOOK(book, bookCounter);
                }
                else
                {
                    end();
                }
                break;
            case 1:
                if (paperCounter)
                {
                    printObject_PAPER(paper, paperCounter);
                }
                else
                {
                    end();
                }
                break;
            case 2:
                if (dvdCounter)
                {
                    printObject_DVD(dvd, dvdCounter);
                }
                else
                {
                    end();
                }
                break;
            case 3:
                if (bookCounter && paperCounter && dvdCounter)
                {
                    printf("BOOKS: \n");
                    printObject_BOOK(book, bookCounter);
                    printf("NEWS PAPERS: \n");
                    printObject_PAPER(paper, paperCounter);
                    printf("DVD`S: \n");
                    printObject_DVD(dvd, dvdCounter);
                }
                else
                {
                    end();
                }
                break;

            default:
                continue;
                break;
            }
            break;

        default:
            end();
            break;
        }
    }

    return EXIT_SUCCESS;
}

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
        printf("Enter the ISBN of the book: ");
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

    strcpy(book->ISBN, arr);
    trimBook(book);
    return bookCounter + 1;
}
void trimBook(struct BOOK *book)
{
    book->author[strlen(book->author) - 1] = '\0';
    book->title[strlen(book->title) - 1] = '\0';
    book->publisher[strlen(book->publisher) - 1] = '\0';
}
void printObject_BOOK(struct BOOK *book, int bookCounter)
{
    for (int i = 0; i < bookCounter; i++)
    {
        printf("Author: %s\n", book[i].author);
        printf("Title: %s\n", book[i].title);
        printf("Publisher: %s\n", book[i].publisher);
        printf("Pages: %d\n", book[i].pages);
        printf("ISBN: %s", book[i].ISBN);
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
