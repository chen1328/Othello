#include <stdio.h>
#include "maxsize.h"


void Step(int turn, int row, int col, char checkboard[MAXSIZE][MAXSIZE]);
int OwnRemainStep(int turn, char checkboard[MAXSIZE][MAXSIZE]);
int OtherRemainStep(int turn, char checkboard[MAXSIZE][MAXSIZE]);

void Step(int turn, int row, int col, char checkboard[MAXSIZE][MAXSIZE])
{
	char step[2] = { 'W','B' };
	checkboard[row][col] = step[turn];
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx != 0 || dy != 0)
			{
				int count = 1;
				bool isHaveWhite = 0;
				while (checkboard[row + dy * count][col + dx * count] == step[1 - turn] && IsInCheckboard(row + dy * count, col + dx * count))
				{
					isHaveWhite = 1;
					count++;
				}
				if (checkboard[row + dy * count][col + dx * count] == step[turn] && isHaveWhite && IsInCheckboard(row + dy * count, col + dx * count))
				{
					int maxCount = count;
					for (int tempCount = 1; tempCount < maxCount; tempCount++)
						checkboard[row + dy * tempCount][col + dx * tempCount] = step[turn];
				}
			}
		}
	}
	return;
}
int OwnRemainStep(int turn, char checkboard[MAXSIZE][MAXSIZE])
{
	char step[2] = { 'W','B' };
	int ownRemainStep = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			if (checkboard[i][j] == '+')
			{
				bool isHaveOwnStep = 0;
				for (int dx = -1; dx <= 1 && !isHaveOwnStep; dx++)
				{
					for (int dy = -1; dy <= 1 && !isHaveOwnStep; dy++)
					{
						if (dx != 0 || dy != 0)
						{
							int count = 1;
							bool isHaveOtherStep = 0;
							while (checkboard[i + dy * count][j + dx * count] == step[1 - turn] && IsInCheckboard(i + dy * count, j + dx * count))
							{
								isHaveOtherStep = 1;
								count++;
							}
							if (checkboard[i + dy * count][j + dx * count] == step[turn] && isHaveOtherStep && IsInCheckboard(i + dy * count, j + dx * count))
							{
								isHaveOwnStep = 1;
								ownRemainStep++;
							}
						}
					}
				}
			}
		}
	}
	return ownRemainStep;
}
int OtherRemainStep(int turn, char checkboard[MAXSIZE][MAXSIZE])
{
	char step[2] = { 'B','W' };
	int otherRemainStep = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			if (checkboard[i][j] == '+')
			{
				bool isHaveOwnStep = 0;
				for (int dx = -1; dx <= 1 && !isHaveOwnStep; dx++)
				{
					for (int dy = -1; dy <= 1 && !isHaveOwnStep; dy++)
					{
						if (dx != 0 || dy != 0)
						{
							int count = 1;
							bool isHaveOtherStep = 0;
							while (checkboard[i + dy * count][j + dx * count] == step[1 - turn] && IsInCheckboard(i + dy * count, j + dx * count))
							{
								isHaveOtherStep = 1;
								count++;
							}
							if (checkboard[i + dy * count][j + dx * count] == step[turn] && isHaveOtherStep && IsInCheckboard(i + dy * count, j + dx * count))
							{
								isHaveOwnStep = 1;
								otherRemainStep++;
							}
						}
					}
				}
			}
		}
	}
	return otherRemainStep;
}