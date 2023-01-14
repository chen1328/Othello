#include <stdio.h>
#include "maxsize.h"

void StartCheckerboard(char checkboard[MAXSIZE][MAXSIZE]);
void PrintCheckerboard(char checkboard[MAXSIZE][MAXSIZE]);
void HowManyPieces(char checkboard[MAXSIZE][MAXSIZE]);

void StartCheckerboard(char checkboard[MAXSIZE][MAXSIZE])
{
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			checkboard[i][j] = '+';
	checkboard[MAXSIZE / 2 - 1][MAXSIZE / 2 - 1] = checkboard[MAXSIZE / 2][MAXSIZE / 2] = 'W';
	checkboard[MAXSIZE / 2][MAXSIZE / 2 - 1] = checkboard[MAXSIZE / 2 - 1][MAXSIZE / 2] = 'B';
	return;
}
void PrintCheckerboard(char checkboard[MAXSIZE][MAXSIZE])
{
	printf("Checkboard\n\n   ");
	for (int i = 65; i <= 72; i++)
		printf("%4c", (char)i);
	printf("\n");
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			if (j == 0)
				printf("%3d", i + 1);
			printf("   %c", checkboard[i][j]);
		}
		printf("\n");
		for (int j = 0; j < MAXSIZE; j++)
			printf(" ");
		printf("\n");
	}
	HowManyPieces(checkboard);
	return;
}
void HowManyPieces(char checkboard[MAXSIZE][MAXSIZE])
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
	printf("Black : %d pieces\nWhite : %d pieces\n\n", blackPieces, whitePieces);
	return;
}