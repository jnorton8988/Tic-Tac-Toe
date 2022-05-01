// Jonathan Norton
// ITT-310: Programming for Security Professionals
// 05/01/2022
// Professor Jeremy Wright
// Milestone 2
// Test 2

// Tic-Tac-Toe is intended for one player, where they will vs the computer.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


// These are my global variables.
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


// These are the function prototypes used throughout the code. They are used before the main functions to help with rebuilding
void playerMove();
void computerMove();
void resetBoard();
int checkFreeSpaces();
void printBoard();
void printWinner(char);
char checkWinner();


// Here are the main functions, which is where the main body code will go
int main()
{
	char winner = ' ';
	char response;

	do
	{
		winner = ' ';
		response = ' ';
		resetBoard();

		while (winner = ' ' && checkFreeSpaces() != 0)
		{
			printBoard();

			playerMove();
			winner = checkWinner();
			if (winner != ' ' || checkFreeSpaces() == 0)
			{
				break;
			}

			computerMove();
			winner = checkWinner();
			if (winner != ' ' || checkFreeSpaces() == 0)
			{
				break;
			}
		}

		printBoard();
		printWinner(winner);

		printf("\nPlay again? (Y/N): ");
		scanf("%c");
		scanf("%c", &response);
		response = toupper(response);
	} while (response == 'Y');

	printf("Thank you for playing :)");

	return 0;
}


void playerMove()
{

}
void computerMove()
{

}
void resetBoard()
{

}
int checkFreeSpaces()
{

}
void printBoard()
{

}
void printWinner(char winner)
{

}
char checkWinner()
{

}