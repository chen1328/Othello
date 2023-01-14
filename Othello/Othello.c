#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maxsize.h"
#include "checkboard.h"
#include "turn.h"
#include "step.h"
#include "win.h"

int main(void)
{
	while (1)
	{
		char checkboard[MAXSIZE][MAXSIZE];
		StartCheckerboard(checkboard);
		int turn = 1;
		int row, col;
		char charCol;
		while (1)
		{
			PrintCheckerboard(checkboard);
			WhoseTurn(turn);
			while (1)
			{
				scanf("%d %c", &row, &charCol);
				row -= 1;
				col = (int)charCol - 65;
				if (IsValidStep(turn, row, col, checkboard))
					break;
			}
			Step(turn, row, col, checkboard);
			if (OtherRemainStep(turn, checkboard) == 0)
			{
				if (OwnRemainStep(turn, checkboard) == 0)
					break;
				printf("The opponent has no steps.\n");
				system("pause");
				turn = 1 - turn;
			}
			turn = 1 - turn;
			system("cls");
		}
		system("cls");
		PrintCheckerboard(checkboard);
		WhoWin(checkboard);
		char playAgain;
		while (1)
		{
			scanf("%c", &playAgain);
			if (IsPlayAgain(playAgain) >= 0)
				break;
		}
		if (IsPlayAgain(playAgain) == 0)
			break;
		system("cls");
	}
	system("pause");
	return 0;
}
