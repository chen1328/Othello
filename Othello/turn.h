#include <stdio.h>
#include <stdbool.h>
#include "maxsize.h"

void WhoseTurn(int turn);
bool IsValidStep(int turn, int row, int col, char checkboard[MAXSIZE][MAXSIZE]);

void WhoseTurn(int turn)
{
	if (turn == 1)
		printf("It's black's turn,");
	else
		printf("It's white's turn,");
	printf("please enter a number(1 ~ %d) and a character(A ~ H),the former is row,the latter is column:\n", MAXSIZE);
	return;
}
bool IsInCheckboard(int boundRow, int boundCol)
{
	if (boundRow >= 0 && boundRow < MAXSIZE && boundCol >= 0 && boundCol < MAXSIZE)
		return 1;
	return 0;
}
bool IsValidStep(int turn, int row, int col, char checkboard[MAXSIZE][MAXSIZE])
{
	if (IsInCheckboard(row, col) && checkboard[row][col] == '+')
	{
		char step[2] = { 'W','B' };
		bool isHaveOwn = 0;
		for (int dx = -1; dx <= 1 && !isHaveOwn; dx++)
		{
			for (int dy = -1; dy <= 1 && !isHaveOwn; dy++)
			{
				if (dx != 0 || dy != 0)
				{
					int count = 1;
					bool isHaveOther = 0;
					while (checkboard[row + dy * count][col + dx * count] == step[1 - turn] && IsInCheckboard(row + dy * count, col + dx * count))
					{
						isHaveOther = 1;
						count++;
					}
					if (checkboard[row + dy * count][col + dx * count] == step[turn] && isHaveOther && IsInCheckboard(row + dy * count, col + dx * count))
					{
						isHaveOwn = 1;
						return 1;
					}
				}
			}
		}
	}
	printf("\nValid step,please enter again.\n");
	return 0;
}