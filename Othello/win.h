#include <stdio.h>
#include "maxsize.h"

void WhoWin(char checkboard[MAXSIZE][MAXSIZE]);
int IsPlayAgain(char playAgain);

void WhoWin(char checkboard[MAXSIZE][MAXSIZE])
{
	int blackPieces = 0, whitePieces = 0;
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
		{
			if (checkboard[i][j] == 'B')
				blackPieces++;
			else if (checkboard[i][j] == 'W')
				whitePieces++;
		}
	if (blackPieces > whitePieces)
		printf("Black wins the game.\n");
	else if (blackPieces < whitePieces)
		printf("White wins the game.\n");
	else
		printf("Tie.\n");
	printf("The game ends.\nDo you want to play again?\nPlease enter Y or N\n");
	return;
}
int IsPlayAgain(char playAgain)
{
	if (playAgain == 'Y')
		return 1;
	else if (playAgain == 'N')
		return 0;
	else if (playAgain != '\n')
	{
		printf("\nError,please enter again.\n");
		return -1;
	}
	else
		return -2;
}