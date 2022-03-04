#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * menger - menger sponge print function
 * @level: Levels to print for menger sponge
 * Return: Nothing
 */

void menger(int level)
{
	int i = 0;
	int j = 0;
	int tempi = 0;
	int tempj = 0;
	int size = (int)pow(3, level);
	int print = 0;

	if (level == 0)
		printf("#\n");
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				tempi = i;
				tempj = j;
				print = 0;
				while (tempi != 0 && tempj != 0)
				{
					if (tempi % 3 == 1 && tempj % 3 == 1)
					{
						printf(" ");
						print = 1;
						break;
					}
					tempi /= 3;
					tempj /= 3;
				}
				if (print == 0)
					printf("#");
			}
			printf("\n");
		}
	}
}
