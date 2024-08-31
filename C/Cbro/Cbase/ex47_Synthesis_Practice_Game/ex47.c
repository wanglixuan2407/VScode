#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define ROW 3
#define COL 3
#define DIAG 3
/*Tic-Tac-Toe*/

char board [ROW][COL];  //Global variables
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main()
{
    char winner = ' ';
    char response;
    char buffer;

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();
    while (winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces == 0)
        {
            break;
        }
        
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces == 0)
        {
            break;
        }

    }
    
    printBoard(); // If player wins, the last move needs to print.
    printWinner(winner);

    printf("\nWould you like to play again?(Y/N):");
    scanf("%c",&buffer);
    scanf("%c",&response);
    response = toupper(response);
    } while (response == 'Y');//do while:used to inplement "play again"function 

    printf("Thanks for playing!\n");

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j]=' ';
        }
        
    }
    
}
void printBoard()
{
    printf(" %c | %c | %c | ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---|\n");
    printf(" %c | %c | %c | ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---|\n");
    printf(" %c | %c | %c |",board[2][0],board[2][1],board[2][2]);
    printf("\n---|---|---|\n");
    printf("\n");
}
int checkFreeSpaces()
{
    int freespaces = ROW * COL;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (board[i][j] != ' ')
            {
                freespaces --;
            }
            else
            {
                ;
            }
            
        }
        
    }
    return freespaces;
    
}
void playerMove()
{
    int x;
    int y;
do
{
    printf("Enter row #(1-3):");
    scanf("%d",&x);
    x--;
    printf("Enter column #(1-3):");
    scanf("%d",&y);
    y--;

    if (board[x][y] !=' ')
    {
        printf("Invalid move!\n");
    }
    else
    {
        board[x][y]=PLAYER;
        break;
    }
    
} while (board[x][y] !=' ');

}

char checkWinner()
{
    /*check rows*/
    for (int i = 0; i < ROW; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0]==board[i][2])
        {
            return board[i][0];
        }
        else
        {
            ;
        }
    }
    /*check columns*/
    for (int j = 0; j < COL; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            return board[0][j];
        }
        else
        {
            ;
        }
        
    }

    /*check diagnals*/
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[1][1];
    }
    else if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
    {
        return board[1][1];
    }
    else
    {
        ;
    }
    return ' ';
}
void computerMove()
{
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() >0 )
    {
        do
        {
            x = rand() % ROW;
            y = rand() % COL;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
    
}
void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You win!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("You lose!\n");
    }
    else
    {
        printf("Draw!\n");
    }
    
}