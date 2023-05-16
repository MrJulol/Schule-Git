#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

int main()
{

    int printAddSort = 0;
    int bookPaperDvd = 0;
    int sortWhat2;

    int bookCounter = 0;
    int paperCounter = 0;
    int dvdCounter = 0;

    struct BOOK book[100];
    struct PAPER paper[100];
    struct DVD dvd[100];

    while (TRUE)
    {
        printf("|0| = Add Object\t\t|1| = Print Objects\t\t|2| = Sort then Print Object\t\t|else| = EXIT\n");
        fflush(stdin);
        scanf("%d", &printAddSort);
        switch (printAddSort)
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
        case 2:
            printf("|0| = Sort Books\t\t|1| = Sort News Papers\t\t|2| = Sort  DVDs\t\t|3| = Sort All\t\t|else| = RETURN\n");
            fflush(stdin);
            scanf("%d", &sortWhat2);
            switch (sortWhat2)
            {
            case 0:
                sortBook(book, bookCounter);
                printObject_BOOK(book, bookCounter);
                break;
            case 1:
                sortPaper(paper, paperCounter);
                printObject_PAPER(paper, paperCounter);
                break;
            case 2:
                sortDvd(dvd, dvdCounter);
                printObject_DVD(dvd, dvdCounter);
                break;
            case 3:
                sortBook(book, bookCounter);
                sortPaper(paper, paperCounter);
                sortDvd(dvd, dvdCounter);
                printObject_BOOK(book, bookCounter);
                printObject_PAPER(paper, paperCounter);
                printObject_DVD(dvd, dvdCounter);
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
