#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>
using namespace std;
void borad_maker(char suduko_board[10][10], char copy_of_suduko_board[10][10])
{
	char time_now[10];
	int x = 1, y = 1, temp, mi, se;
	bool temp_arr[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	while (true)
	{
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		temp = abs((rand() + mi + se) % 10);
		if (temp)
		{
			/*This if statment to fill the first block
			. . .
			. 1 .
			. . .
			*/
			if (temp_arr[temp])
			{
				temp_arr[temp] = 0;
				suduko_board[x][y] = temp + 48;
				y++;
				if (y == 4)
				{
					y = 1;
					x++;
				}
				if (x == 4)
				{
					break;
				}
			}
		}
	}
	int rows = 1, columns;
	for (columns = 4; columns <= 6; columns++)
	{
		/*This for loop to fill the second block
		. . .
		. 2 .
		. . .
		*/
		suduko_board[rows][columns] = suduko_board[rows + 1][columns - 3];
		suduko_board[rows + 1][columns] = suduko_board[rows + 2][columns - 3];
		suduko_board[rows + 2][columns] = suduko_board[rows][columns - 3];
	}
	for (columns = 7; columns <= 9; columns++)
	{
		/*This for loop to fill the third block
		. . .
		. 3 .
		. . .
		*/
		suduko_board[rows][columns] = suduko_board[rows + 1][columns - 3];
		suduko_board[rows + 1][columns] = suduko_board[rows + 2][columns - 3];
		suduko_board[rows + 2][columns] = suduko_board[rows][columns - 3];
	}
	for (columns = 1; columns <= 9; columns = columns + 3)
	{
		/*This for loop to fill the second row of blocks
		. . .  . . .  . . .
		. 4 .  . 5 .  . 6 .
		. . .  . . .  . . .
		*/
		for (rows = 4; rows <= 6; rows++)
		{
			suduko_board[rows][columns] = suduko_board[rows - 3][columns + 1];
			suduko_board[rows][columns + 1] = suduko_board[rows - 3][columns + 2];
			suduko_board[rows][columns + 2] = suduko_board[rows - 3][columns];
		}
	}
	for (columns = 1; columns <= 9; columns = columns + 3)
	{
		/*This for loop to fill the third row of blocks
		. . .  . . .  . . .
		. 7 .  . 8 .  . 9 .
		. . .  . . .  . . .
		*/
		for (rows = 7; rows <= 9; rows++)
		{
			suduko_board[rows][columns] = suduko_board[rows - 3][columns + 1];
			suduko_board[rows][columns + 1] = suduko_board[rows - 3][columns + 2];
			suduko_board[rows][columns + 2] = suduko_board[rows - 3][columns];
		}
	}
	for (rows = 1; rows < 10; rows++)
	{
		for (columns = 1; columns < 10; columns++)
		{
			copy_of_suduko_board[rows][columns] = suduko_board[rows][columns];
		}
	}
}
void board_swaping(char suduko_board[10][10], char copy_of_suduko_board[10][10], bool check_board[10][10])
{
	char time_now[10];
	int mi, se, random, rows, columns;
	{
		/*This block to make vertical swapping between the small columns
		.   .   .
		.   .   .
		.   .   .
		*/
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		random = (rand() + mi + se) % 100;
		while (random)
		{
			/*This while loop to swap the first columns of blocks
			. . .
			. 1 .
			. . .

			. . .
			. 4 .
			. . .

			. . .
			. 7 .
			. . .
			*/
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][1], suduko_board[rows][2]);
					swap(check_board[rows][1], check_board[rows][2]);
					swap(copy_of_suduko_board[rows][1], copy_of_suduko_board[rows][2]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][2], suduko_board[rows][3]);
					swap(check_board[rows][2], check_board[rows][3]);
					swap(copy_of_suduko_board[rows][2], copy_of_suduko_board[rows][3]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][1], suduko_board[rows][3]);
					swap(check_board[rows][1], check_board[rows][3]);
					swap(copy_of_suduko_board[rows][1], copy_of_suduko_board[rows][3]);
				}
			}
			random--;
		}
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		random = (rand() + mi + se) % 100;
		while (random)
		{
			/*This while loop to swap the second columns of blocks
			. . .
			. 2 .
			. . .

			. . .
			. 5 .
			. . .

			. . .
			. 8 .
			. . .
			*/
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][4], suduko_board[rows][5]);
					swap(check_board[rows][4], check_board[rows][5]);
					swap(copy_of_suduko_board[rows][4], copy_of_suduko_board[rows][5]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][5], suduko_board[rows][6]);
					swap(check_board[rows][5], check_board[rows][6]);
					swap(copy_of_suduko_board[rows][5], copy_of_suduko_board[rows][6]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][4], suduko_board[rows][6]);
					swap(check_board[rows][4], check_board[rows][6]);
					swap(copy_of_suduko_board[rows][4], copy_of_suduko_board[rows][6]);
				}
			}
			random--;
		}
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		random = (rand() + mi + se) % 100;
		while (random)
		{
			/*This while loop to swap the third columns of blocks
			. . .
			. 3 .
			. . .

			. . .
			. 6 .
			. . .

			. . .
			. 9 .
			. . .
			*/
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][7], suduko_board[rows][8]);
					swap(check_board[rows][7], check_board[rows][8]);
					swap(copy_of_suduko_board[rows][7], copy_of_suduko_board[rows][8]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][8], suduko_board[rows][9]);
					swap(check_board[rows][8], check_board[rows][9]);
					swap(copy_of_suduko_board[rows][8], copy_of_suduko_board[rows][9]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (rows = 1; rows <= 9; rows++)
				{
					swap(suduko_board[rows][7], suduko_board[rows][9]);
					swap(check_board[rows][7], check_board[rows][9]);
					swap(copy_of_suduko_board[rows][7], copy_of_suduko_board[rows][9]);
				}
			}
			random--;
		}
	}

	{
		/*This block to make horizontal swapping between the small raws
		. . .

		. . .

		. . .
		*/
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		random = (rand() + mi + se) % 100;
		while (random)
		{
			/*This while loop to swap the first row of blocks
			. . .  . . .  . . .
			. 1 .  . 2 .  . 3 .
			. . .  . . .  . . .
			*/
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[1][columns], suduko_board[2][columns]);
					swap(check_board[1][columns], check_board[2][columns]);
					swap(copy_of_suduko_board[1][columns], copy_of_suduko_board[2][columns]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[2][columns], suduko_board[3][columns]);
					swap(check_board[2][columns], check_board[3][columns]);
					swap(copy_of_suduko_board[2][columns], copy_of_suduko_board[3][columns]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[1][columns], suduko_board[3][columns]);
					swap(check_board[1][columns], check_board[3][columns]);
					swap(copy_of_suduko_board[1][columns], copy_of_suduko_board[3][columns]);
				}
			}
			random--;
		}
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		random = (rand() + mi + se) % 100;
		while (random)
		{
			/*This while loop to swap the second row of blocks
			. . .  . . .  . . .
			. 4 .  . 5 .  . 6 .
			. . .  . . .  . . .
			*/
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[4][columns], suduko_board[5][columns]);
					swap(check_board[4][columns], check_board[5][columns]);
					swap(copy_of_suduko_board[4][columns], copy_of_suduko_board[5][columns]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[5][columns], suduko_board[6][columns]);
					swap(check_board[5][columns], check_board[6][columns]);
					swap(copy_of_suduko_board[5][columns], copy_of_suduko_board[6][columns]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[4][columns], suduko_board[6][columns]);
					swap(check_board[4][columns], check_board[6][columns]);
					swap(copy_of_suduko_board[4][columns], copy_of_suduko_board[6][columns]);
				}
			}
			random--;
		}
		_strtime_s(time_now, 10);
		mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
		se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
		random = (rand() + mi + se) % 100;
		while (random)
		{
			/*This while loop to swap the third row of blocks
			. . .  . . .  . . .
			. 7 .  . 8 .  . 9 .
			. . .  . . .  . . .
			*/
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[7][columns], suduko_board[8][columns]);
					swap(check_board[7][columns], check_board[8][columns]);
					swap(copy_of_suduko_board[7][columns], copy_of_suduko_board[8][columns]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[8][columns], suduko_board[9][columns]);
					swap(check_board[8][columns], check_board[9][columns]);
					swap(copy_of_suduko_board[8][columns], copy_of_suduko_board[9][columns]);
				}
			}
			if ((rand() + mi + se) % 2)
			{
				for (columns = 1; columns <= 9; columns++)
				{
					swap(suduko_board[7][columns], suduko_board[9][columns]);
					swap(check_board[7][columns], check_board[9][columns]);
					swap(copy_of_suduko_board[7][columns], copy_of_suduko_board[9][columns]);
				}
			}
			random--;
		}
	}
}
void empties(char suduko_board[][10], bool check_board[][10], int deleted_cells)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			check_board[i][j] = 1;
		}
	}
	int n = 4;
	while (n - 3 <= 9)
	{
		for (int i = n - 3; i < n; i++)
		{
			for (int j = n - 3; j < n; j++)
			{
				if(deleted_cells==48&&!(i == 1 && j == 1) && !(i == 1 && j == 3) && !(i == 3 && j == 2) && !(i == 4 && j == 4) && !(i == 5 && j == 4) && !(i == 6 && j == 5) && !(i == 5 && j == 6) && !(i == 2 && j == 1) && !(i == 7 && j == 8) && !(i == 9 && j == 9) && !(i == 9 && j == 7) && !(i == 8 && j == 9))
				{
				suduko_board[i][j] = '0';
				check_board[i][j] = 0;

				}
				else if (deleted_cells > 48)
				{

					suduko_board[i][j] = '0';
					check_board[i][j] = 0;
				}
			}
		}
		n += 3;
	}
	if (deleted_cells >= 48)
	{
		suduko_board[1][4] = '0';
		check_board[1][4] = 0;
		suduko_board[1][5] = '0'; ///
		check_board[1][5] = 0;
		suduko_board[2][5] = '0';
		check_board[2][5] = 0;
		suduko_board[2][8] = '0';///
		check_board[2][8] = 0;
		suduko_board[3][4] = '0';//
		check_board[3][4] = 0;
		suduko_board[3][9] = '0'; ///
		check_board[3][9] = 0;
		suduko_board[4][1] = '0';//
		check_board[4][1] = 0;
		suduko_board[4][7] = '0';
		check_board[4][7] = 0;
		suduko_board[5][8] = '0';//
		check_board[5][8] = 0;
		suduko_board[5][3] = '0';
		check_board[5][3] = 0;
		suduko_board[6][2] = '0';//
		check_board[6][2] = 0;
		suduko_board[6][7] = '0';//
		check_board[6][7] = 0;
		suduko_board[7][1] = '0';
		check_board[7][1] = 0;
		suduko_board[7][2] = '0'; //
		check_board[7][2] = 0;
		suduko_board[8][5] = '0';//
		check_board[8][5] = 0;
		suduko_board[8][4] = '0';//
		check_board[8][4] = 0;
		suduko_board[9][1] = '0';//
		check_board[9][1] = 0;
		suduko_board[9][3] = '0';
		check_board[9][3] = 0;
	}
	if (deleted_cells > 48)
	{
		suduko_board[1][7] = '0';
		check_board[1][7] = 0;
		suduko_board[2][9] = '0';
		check_board[2][9] = 0;
		suduko_board[3][8] = '0';
		check_board[3][8] = 0;
		suduko_board[3][6] = '0';
		check_board[3][6] = 0;
		suduko_board[4][8] = '0';
		check_board[4][8] = 0;
		suduko_board[5][2] = '0';
		check_board[5][2] = 0;
		suduko_board[6][3] = '0';
		check_board[6][3] = 0;
		
		suduko_board[6][9] = '0';
		check_board[6][9] = 0;
		suduko_board[7][4] = '0';
		check_board[7][4] = 0;
		suduko_board[7][6] = '0';
		check_board[7][6] = 0;
		suduko_board[8][2] = '0';
		check_board[8][2] = 0;
		
		suduko_board[9][6] = '0';
		check_board[9][6] = 0;

	}









}
void check_board_true_or_false(char suduko_board[10][10], char copy_of_suduko_board[10][10], bool check_board[10][10])
{
	/*
	loop on all suduko board
	if Char in suduko board is true turn on his bool in check board
	*/
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (suduko_board[i][j] == copy_of_suduko_board[i][j])
			{
				check_board[i][j] = 1;
			}
			else
			{
				check_board[i][j] = 0;
			}
		}
	}
}
int check_board_true_or_false_for_end(char suduko_board[10][10], char copy_of_suduko_board[10][10])
{
	/*
	loop on all suduko board
	if Char in suduko board is true turn on his bool in check board
	*/
	int solved_cells = 0;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (suduko_board[i][j] == copy_of_suduko_board[i][j])
			{
				solved_cells++;
			}
		}
	}
	return solved_cells;
}
