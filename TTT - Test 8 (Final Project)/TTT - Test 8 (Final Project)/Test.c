// Jonathan Norton
// ITT-310: Programming for Security Professionals
// 05/29/2022
// Professor Jeremy Wright
// Milestone 5
// Test 8 (Final Project)

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
		char line[100];
		memset(line, 0, 100);
		do {
			fgets(line, 100, stdin);
			sscanf_s(line, "%c", &response);
			if (response == 'Y' || response == 'N') { break;}
		} while (1);
		response = toupper(response);
	} while (response == 'Y');

	printf("Thank you for playing :)");

	return 0;
}

// This function manages the user/ player's ability to choose the column and row during their turn
void playerMove()
{
	int(x);
	int(y);

	do
	{
		printf("Enter row #(1-3): ");
		scanf_s("%d", &x);
		x--;
		printf("Enter column #(1-3): ");
		scanf_s("%d", &y);
		y--;

		if (board[x][y] != ' ')
		{
			printf("Invalid move\n");
		}
		else
		{
			board[x][y] = PLAYER;
			break;
		}
	} while (board[x][y] != ' ');

}
// This function control the computer move, randomly generating numbers so that the computer can play the user
void computerMove()
{
	// This will create a seed to generate random numbers
	srand(time(0));
	int x;
	int y;

	if (checkFreeSpaces() > 0)
	{
		do
		{
			x = rand() % 3;
			y = rand() % 3;
		} while (board[x][y] != ' ');

		board[x][y] = COMPUTER;
	}
	else
	{
		printWinner(' ');
	}
}
// This allows the board to be reset once the game is over.
void resetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
// This is an active function that checks for free spaces during the user and computer's turn
int checkFreeSpaces()
{
	int freeSpaces = 9;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				freeSpaces--;
			}
		}
	}
	return freeSpaces;
}
// This allows the board to pull up in the CMD, the board almost looks like the # symbol
void printBoard()
{
	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}
// This function allows the game to see the winner (either the computer or the player)
void printWinner(char winner)
{
	if (winner == PLAYER)
	{
		printf("Excellent job....you WIN!");
	}
	else if (winner == COMPUTER)
	{
		printf("You lost... try harder!");
	}
	else {
		printf("Good job... I guess.. it was a tie");
	}
}
// Checking the winner is an important function to have, otherwise the winner would be automatically selected
char checkWinner()
{
	// This will check the win conditions for each row
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return board[i][0];
		}
	}
	// Checks columns
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	// Checks diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return board[0][2];
	}

	return ' ';
}