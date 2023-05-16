#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>   //!rand()
#include <unistd.h> //!sleep()

#ifdef __APPLE__
#define clrscr() system("clear")
#define HELLO() printf("Hey Apple User!\n")
#elif _Windows
#define clrscr() system("cls")
#define HELLO() printf("Hey you poor Windows user\n")
#elif __linux__
#define clrscr() system("clear")
#define HELLO() printf("You Gigachad Linux User\n")
#else
#define clrscr() printf("GET A GOOD PC\n")
#define HELLO() printf("What dafuq are you running as OS\n")
#endif

void printBoard(char Board[]);
//! Prints the Playing Area using two for loops to simulate a 2D Array

void startingscreen(char Board[], char Ball[]);
//! Prints the strting screen for 5 Sec then returns to main

void getposBall(int *xpos, char Board[]);
//! Gets the starting Position of the Ball, either by user-Input or Rand() and returns the starting position of the Ball

void resetBoard(char Board1[], char Board2[]);
//! Resets the Board to the Compile-State to erase placed 'O'

void error(int errorcode);
//! An Error occured and programm terminates with error message

void addpoints(char checknum, int *points);
//! Adds Collected Points to Points Variable

void endscreen(int xposstrart, int xposatend, int points, char Board[]);
//! Prints the Board and Ball a final time

int main()
{
    char Board[] = "~~~~~~6/\\~~~~~|1\\~~/\\~~~~/\\~7|~/3/~~\\~~~~~\\~|~~/~~~~/5/\\~~\\|/\\~~~~~~~~~\\~8|";  // The Playing Board
    char Board2[] = "~~~~~~6/\\~~~~~|1\\~~/\\~~~~/\\~7|~/3/~~\\~~~~~\\~|~~/~~~~/5/\\~~\\|/\\~~~~~~~~~\\~8|"; // Copy to use to reset Board

    int xpos;        // The X-Position of the Ball
    int xposatstart; // Starting X-Position of the Ball to use at the end
    int points = 0;  // Couting Variable for the Collected Points

    getposBall(&xpos, Board); // get the xpos + Print-StartScreen
    xposatstart = xpos;       // Save xpos
    xpos--;                   //-1 to get index number

    for (int i = 0; i < 5; i++)
    {
        clrscr();
        if (Board[xpos] == '~')
        {
            Board[xpos] = 'O';
            printBoard(Board);
            resetBoard(Board, Board2);
            xpos += 15;
        }
        else if (Board[xpos] == '/')
        {
            xpos--;
            if (Board[xpos] == '|')
            {
                xpos += 14;
            }
            if (Board[xpos] == '~')
            {
                Board[xpos] = 'O';
                printBoard(Board);
                resetBoard(Board, Board2);
                xpos += 15;
            }
            else if (Board[xpos] == '/')
            {
                error(1);
            }
            else if (Board[xpos] == '\\')
            {
                error(2);
            }
            else
            {
                Board[xpos] = 'O';
                printBoard(Board);
                resetBoard(Board, Board2);
                addpoints(Board[xpos], &points);
                xpos += 15;
            }
        }
        else if (Board[xpos] == '\\')
        {
            xpos++;
            if (Board[xpos] == '|')
            {
                xpos -= 14;
            }
            if (Board[xpos] == '~')
            {
                Board[xpos] = 'O';
                printBoard(Board);
                resetBoard(Board, Board2);
                xpos += 15;
            }
            else if (Board[xpos] == '/')
            {
                error(3);
            }
            else if (Board[xpos] == '\\')
            {
                error(4);
            }
            else
            {
                Board[xpos] = 'O';
                printBoard(Board);
                resetBoard(Board, Board2);
                addpoints(Board[xpos], &points);
                xpos += 15;
            }
        }
        else
        {
            Board[xpos] = 'O';
            printBoard(Board);
            resetBoard(Board, Board2);
            addpoints(Board[xpos], &points);
            xpos += 15;
        }
    }
    //* xpos - (5 * 15) + 1 calculates the end xpos in the row
    // Logic: 5 ROWS * 15 Collumns = Total amount of items in the array, subracting the final xpos = the xpos as a number between 1-14
    // Adding a one to get from index counting (0,1,2) to regular counting (1,2,3)
    endscreen(xposatstart, xpos - (5 * 15) + 1, points, Board);
    return EXIT_SUCCESS;
}

void printBoard(char Board[])
{
    // prints the Playing Area using two for loops to simulate a 2D Array
    int pos = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 15; i++)
        {
            printf("%c", Board[pos]);
            pos++;
        }
        printf("\n");
    }
    sleep(1); // pause Programm for a second to let the animation look smooother
}

void startingscreen(char Board[], char Ball[])
{
    // Prints the strting screen for 5 Sec then returns to main
    int pos = 0;
    printf("%s\n", Ball); // Prints the Ball String
    for (int i = 0; i < 5; i++)
    // Print the Board-Array as a 2D Playing Field
    {
        for (int i = 0; i < 15; i++)
        {
            printf("%c", Board[pos]);
            pos++;
        }
        printf("\n");
    }
    sleep(2); // for Start-Screen Amount of seconds
}

void getposBall(int *xpos, char Board[])
{
    // Gets the starting Position of the Ball, either by user-Input or Rand() and returns the starting position of the Ball
    int pos = 0;
    char *Ball = malloc(15);
    if (Ball == NULL)
    {
        printf("Sorry! Unable to allocate memory\n");
        free(Ball);
        exit(0);
    }
    for (int i = 0; i < 15; i++)
    // Fill Array with _ (empty)
    {
        Ball[i] = '_';
    }
    Ball[14] = '\0'; // add \0 to use %s while printing
    srand((unsigned)time(NULL));
    printf("Enter the starting position of the BALL (1-14), or enter something else for a random position: ");
    scanf("%d", &pos);
    if (!(pos >= 1 && pos <= 14))
    // If the input != 1-14 get a random number between 1-14 to put the 'O' into
    {
        pos = (rand() % 14);
    }
    Ball[pos - 1] = 'O';
    startingscreen(Board, Ball);
    *xpos = pos; //* Set the xpos variable in main() to the xpos here (pointer to maybe return something else later)
    free(Ball);
}

void resetBoard(char Board1[], char Board2[])
// Resets the Board to the Compile-State to erase placed 'O'
{
    for (int i = 0; i < strlen(Board2); i++)
    {
        Board1[i] = Board2[i];
    }
}

void error(int errorcode)
// An Error occured and programm terminates with error message
{
    switch (errorcode)
    {
    case 1:
        printf("Errorcode %d: The Ball is stuck between two // \n", errorcode);
        break;
    case 2:
        printf("Errorcode %d: The Ball is stuck between two \\/ \n", errorcode);
        break;
    case 3:
        printf("Errorcode %d: The Ball is stuck between two \\/ \n", errorcode);
        break;
    case 4:
        printf("Errorcode %d: The Ball is stuck between two \\\\ \n", errorcode);
        break;
    }
    exit(EXIT_SUCCESS);
}

void addpoints(char checknum, int *points)
// Adds Collected Points to Points Variable
{
    int i = checknum - '0'; // Converts a char 'NUMBER' to an integer Logic: 'NUMBER' - 48 ('0')
    *points = *points + i;
}

void endscreen(int xposstrart, int xposatend, int points, char Board[])
// Prints the Board and Ball a final time
{
    char *Ball = malloc(15);
    if (Ball == NULL)
    {
        printf("Sorry! Unable to allocate memory\n");
        free(Ball);
        exit(0);
    }
    for (int i = 0; i < 15; i++)
    // Fill Array with _ (empty)
    {
        Ball[i] = '_';
    }
    Ball[14] = '\0';           // add \0 to the end use %s while printing
    Ball[xposatend - 1] = 'O'; //-1 to convert to index address
    clrscr();
    printBoard(Board);
    printf("%s\n", Ball);
    printf("Starting point: %d\nEndpoint: %d\nPoints: %d\n", xposstrart, xposatend, points);
    free(Ball);
}