#include <stdio.h>
#include <stdlib.h>

void clrscr();                                                  // Clear Terminal
void title();                                                   // Print Titlescreen
void printBoard(char Board[3][3]);                              // Print printBoard
int gamemodeselect();                                           // slect the Gamemode PvP or Vs_AI
int playerselect();                                             // Select Playermodel
void PvPmain();                                                 // Main for PvP
void Player(char Board[3][3], char Playericon, int entrypoint); // Playerinput
void isfinished(char Board[3][3], char Playericon);             // checks if the player has won
void VS_AI_main();                                              // Main for Vs_ai

int main()
{
    int Gamemode = 0;

    Gamemode = gamemodeselect(); // select gamemode

    if (Gamemode)
        VS_AI_main(); // start AI
    else
        PvPmain(); // start PvP
    printf("\n");  // Why? MacOS Terminal
    return EXIT_SUCCESS;
}

void clrscr()
{
    // Clear Terminal to keep Execution clean and visible
    system("clear");
}
void title()
{
    // Prints the Title screen
    printf("___________TIC-TAC-TOE___________\n\n");
}
void printBoard(char Board[3][3])
{
    // Prints Playing Area
    for (int i = 0; i < 3; i++)
    { // row
        printf("\t");
        for (int j = 0; j < 3; j++)
        { // collumn
            printf("%c\t", Board[j][i]);
        }
        printf("\n\n");
    }
}

int gamemodeselect()
{
    // select Gamemode PVP o PvAI
    int Gamemode;
    do
    {
        clrscr();
        title();
        printf(" \t| Select Gamemode | \n");
        printf("[0] = VS Player\t\t [1] = VS AI \n");
        scanf("%d", &Gamemode);
        clrscr();
    } while (Gamemode != 0 && Gamemode != 1);
    return Gamemode;
}

int playerselect()
{
    // Playerselect: 1 = X | 2 = O
    int Spielfigur = 0;
    do
    {
        clrscr();
        title();
        printf(" \t| Select player | \n");
        printf("[0] = X\t\t\t[1] = O\n");
        scanf("%d", &Spielfigur);
        if (Spielfigur == 0 || Spielfigur == 1)
        {
            return Spielfigur;
        }
    } while (Spielfigur != 1 || Spielfigur != 2);
}

void PvPmain()
{
    char Board[3][3] = {'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I'};
    int Playericon = 0; // Temporary variable for selection of model
    char Player1 = 'O'; // The Player
    char Player2 = 'O'; // The AI

    Playericon = playerselect(); // select Playermodel
    if (Playericon)
    {
        Player2 = 'X'; // Give a player the model
    }
    else
    {
        Player1 = 'X'; // Give a player a model
    }

    for (;;)
    {
        clrscr();
        printf("Player1:\n ");
        Player(Board, Player1, 0); // Player 1 to function Player
        isfinished(Board, Player1);
        if (!(Board[0][0] == 'I' || Board[0][1] == 'I' || Board[0][2] == 'I' || Board[1][0] == 'I' || Board[1][1] == 'I' || Board[1][2] == 'I' || Board[2][0] == 'I' || Board[2][1] == 'I' || Board[2][2] == 'I'))
        // Checks if the game has ended via DRAW
        {
            printf("DRAW!\n");
            exit(0);
        }
        clrscr();
        printf("Player2:\n ");
        Player(Board, Player2, 0); // PLayer 2 to function
        isfinished(Board, Player2);
        // Checks if the game has ended via DRAW
        if (!(Board[0][0] == 'I' || Board[0][1] == 'I' || Board[0][2] == 'I' || Board[1][0] == 'I' || Board[1][1] == 'I' || Board[1][2] == 'I' || Board[2][0] == 'I' || Board[2][1] == 'I' || Board[2][2] == 'I'))
        {
            printf("DRAW!\n");
            exit(0);
        }
    }
}

void Player(char Board[3][3], char Playericon, int entrypoint)
{
    int hor = 0;
    int vert = 0;

    clrscr();
    if (entrypoint == 1)
        printf("Not accepted Coordinates\n");
    else if (entrypoint == 2)
        printf("Coordinate already occupied\n");
    title();
    printBoard(Board);
    printf("[horizontal][vertical]\n");
    printf("Enter the first coordinate of your tile: ");
    fflush(stdin);
    vert = getchar();
    printf("Enter the second coordinate of your tile: ");
    fflush(stdin);
    hor = getchar();
    vert = vert - 49; // ASCII 0-2 = 49-51
    hor = hor - 49;   // ASCII 0-2 = 49-51
    if ((hor <= 0 && hor >= 2) || (vert <= 0 && vert >= 2))
    { // numbers too big
        clrscr();
        printf("Not accepted Coordinates\n");
        Player(Board, Playericon, 1);
    }
    else if (!(Board[vert][hor] == 'I'))
    { // Already occupied by a Player
        clrscr();
        printf("Coordinate already occupied\n");
        Player(Board, Playericon, 2);
    }
    else
    { // Player selected and now its his
        Board[vert][hor] = Playericon;
        clrscr();
        isfinished(Board, Playericon); // checks if the Player has won
    }
    return;
}

void isfinished(char Board[3][3], char Playericon)
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[0][i] == Playericon && Board[1][i] == Playericon && Board[2][i] == Playericon)
        { // Column
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Playericon);
            exit(0); // ends game
            title();
            printBoard(Board);
        }
        else if (Board[i][0] == Playericon && Board[i][1] == Playericon && Board[i][2] == Playericon)
        { // Row
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Playericon);
            exit(0); // ends game
            title();
            printBoard(Board);
        }
        else if (Board[0][0] == Playericon && Board[1][1] == Playericon && Board[2][2] == Playericon)
        { // diagonal
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Playericon);
            exit(0); // ends game
            title();
            printBoard(Board);
        }
        else if (Board[0][2] == Playericon && Board[1][1] == Playericon && Board[2][0] == Playericon)
        { // diagonal
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Playericon);
            exit(0); // ends game
            title();
            printBoard(Board);
        }
        else
        {
            return;
        }
    }
    return;
}

void VS_AI_main()
{
    char Board[3][3] = {'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I'};
    int Tempicon = 0;
    char Player1;
    char Player2;

    Tempicon = playerselect();
    if (Tempicon == 1)
    {
        Player1 = 'X';
        Player2 = 'O';
    }
    else
    {
        Player1 = 'O';
        Player2 = 'X';
    }

    printf(" The AI Beginns\n");
    Board[1][1] = Player2;
    printf("Player: \n");
    Player(Board, Player1, 0);
    if (Board[0][1] == Player1)
    {
        Board[0][0] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][2] == 'I')
        {
            Board[2][2] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0);
        }
        else
        {
            Board[2][0] = Player2;
            Player(Board, Player1, 0);
            if (Board[0][2] == Player1)
            {
                Board[1][0] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else if (Board[1][0] == Player1)
            {
                Board[0][2] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
        }
    }
    else if (Board[1][2] == Player1)
    {
        Board[0][0] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][2] == 'I')
        {
            Board[2][2] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0);
        }
        else
        {
            Board[2][0] = Player2;
            Player(Board, Player1, 0);
            if (Board[0][2] == Player1)
            {
                Board[1][0] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else if (Board[1][0] == Player1)
            {
                Board[0][2] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
        }
    }
    else if (Board[2][1] == Player1)
    {
        Board[0][0] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][2] == 'I')
        {
            Board[2][2] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0); // ends game
        }
        else
        {
            Board[2][0] = Player2;
            Player(Board, Player1, 0);
            if (Board[0][2] == Player1)
            {
                Board[1][0] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0); // ends game
            }
            else if (Board[1][0] == Player1)
            {
                Board[0][2] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0); // ends game
            }
        }
    }
    else if (Board[1][0] == Player1)
    {
        Board[0][0] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][2] == 'I')
        {
            Board[2][2] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0);
        }
        else
        {
            Board[2][0] = Player2;
            Player(Board, Player1, 0);
            if (Board[0][2] == Player1)
            {
                Board[1][0] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else if (Board[1][0] == Player1)
            {
                Board[0][2] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
        }
    }

    else if (Board[0][0] == Player1)
    {
        Board[0][2] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][0] == 'I')
        {
            Board[2][0] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0); // ends game
        }
        else
        {
            Board[1][0] = Player2;
            Player(Board, Player1, 0);
            if (Board[1][2] == 'I')
            {
                Board[1][2] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else
            {
                Board[0][1] = Player2;
                Player(Board, Player1, 0);
                if (Board[2][1] == 'I')
                {
                    Board[2][1] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("Player %c has won! \n", Player2);
                    exit(0);
                }
                else
                {
                    Board[2][2] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("\nDRAW!\n");
                    exit(0);
                }
            }
        }
    }
    else if (Board[2][2] == Player1)
    {
        Board[0][2] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][0] == 'I')
        {
            Board[2][0] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0); // ends game
        }
        else
        {
            Board[2][1] = Player2;
            Player(Board, Player1, 0);
            if (Board[0][1] == 'I')
            {
                Board[0][1] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else
            {
                Board[1][2] = Player2;
                Player(Board, Player1, 0);
                if (Board[1][0] == 'I')
                {
                    Board[1][0] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("Player %c has won! \n", Player2);
                    exit(0);
                }
                else
                {
                    Board[2][2] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("\nDRAW!\n");
                    exit(0);
                }
            }
        }
    }
    else if (Board[2][0] == Player1)
    {
        Board[0][0] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][2] == 'I')
        {
            Board[2][2] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0); // ends game
        }
        else
        {
            Board[2][1] = Player2;
            Player(Board, Player1, 0);
            if (Board[0][1] == 'I')
            {
                Board[0][1] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else
            {
                Board[1][0] = Player2;
                Player(Board, Player1, 0);
                if (Board[1][2] == 'I')
                {
                    Board[1][2] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("Player %c has won! \n", Player2);
                    exit(0);
                }
                else
                {
                    Board[0][2] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("\nDRAW!\n");
                    exit(0);
                }
            }
        }
    }
    else if (Board[0][2] == Player1)
    {
        Board[0][0] = Player2;
        Player(Board, Player1, 0);
        if (Board[2][2] == 'I')
        {
            Board[2][2] = Player2;
            clrscr();
            title();
            printBoard(Board);
            printf("Player %c has won! \n", Player2);
            exit(0);
        }
        else
        {
            Board[1][2] = Player2;
            Player(Board, Player1, 0);
            if (Board[1][0] == 'I')
            {
                Board[1][0] = Player2;
                clrscr();
                title();
                printBoard(Board);
                printf("Player %c has won! \n", Player2);
                exit(0);
            }
            else
            {
                Board[0][1] = Player2;
                Player(Board, Player1, 0);
                if (Board[2][1] == 'I')
                {
                    Board[2][1] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("Player %c has won! \n", Player2);
                    exit(0);
                }
                else
                {
                    Board[2][0] = Player2;
                    clrscr();
                    title();
                    printBoard(Board);
                    printf("\nDRAW!\n");
                    exit(0);
                }
            }
        }
    }
}

//  HE HE
