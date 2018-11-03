#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <fstream>
#include "Solver.h"
using namespace std;
int solutions = 1;
square all_squares[82];
bool solved_once = 0;
char grid_optimal[9][9] = { 0 };
char grid_solution[9][9];
bool check_counter_square(square x, square y)
{
	return x.zero_counter > y.zero_counter;
}
bool check_index_square(square x, square y)
{
	return x.index < y.index;
}
void grid_copy(char grid[][9], char grid2[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid2[i][j] = grid[i][j];
		}
	}
}
bool check_sorting(mini_square x, mini_square y)
{
	return x.zero_counter > y.zero_counter;
}
void copy_mini_to_square(mini_square arr1[], string arr2[][9], int index)
{
	for (int i = 0; i < 9; i++)
	{
		int k = name_to_index(arr2[index][i][0], arr2[index][i][1]);
		arr1[i].name = all_squares[k].name;
		arr1[i].values = all_squares[k].values;
		arr1[i].zero_counter = all_squares[k].zero_counter;
		arr1[i].all_squares_index = k;
		name_to_grid(arr1[i].name, arr1[i].grid_index[0], arr1[i].grid_index[1]);
	}
}
int name_to_index(char x, char y)
{
	return (x - 65) * 9 + y - 48;
}
string grid_to_name(int x, int y)
{
	string name;
	name += (char)x + 65;
	name += (char)y + 49;
	return name;
}
void name_to_grid(string name, int &i, int &j)
{
	i = name[0] - 65;
	j = name[1] - 49;
}
void all_grid_to_zero(char grid[][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = '0';
		}
	}
}
void input_grid(char grid[][9], int &filled_squares) // for grid input 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] != '0')
				filled_squares++;
		}
	}
}
char return_grid_value(int square_index, char grid[][9])
{
	int a, b;
	name_to_grid(all_squares[square_index].name, a, b);
	return grid[a][b];
}
bool remove_value_from_twins(char value, int square_index)
{
	for (int i = 0; i < 20; i++)
	{
		int index = name_to_index(all_squares[square_index].twin[i][0], all_squares[square_index].twin[i][1]);
		if (erase_char_from_my_values(index, value) == 0)
		{
			return 0;
		}
	}
	return 1;
}
bool erase_char_from_my_values(int square_index, char value)
{
	if (value == '0')
		return 1;
	int index = value - 49;
	if (all_squares[square_index].values[index] != '0')
	{
		all_squares[square_index].values[index] = '0';
		all_squares[square_index].zero_counter++;
		if (all_squares[square_index].zero_counter == 9)
		{
			return 0;
		}
	}
	return 1;
}
bool assign_set_delete(int square_index, char Char, char grid[][9], int &filled)
{
	//Assign
	int a, b;
	name_to_grid(all_squares[square_index].name, a, b);
	if (Char != grid[a][b] && Char != '0')
		filled++;
	grid[a][b] = Char;
	//set values as a given square 
	all_squares[square_index].values = "000000000";
	all_squares[square_index].zero_counter = -1;
	//delete from twins
	if (remove_value_from_twins(Char, square_index) == 0)
	{
		return 0;
	}
	for (int i = 0; i < 20; i++)
	{
		int index = name_to_index(all_squares[square_index].twin[i][0], all_squares[square_index].twin[i][1]);
		if (all_squares[index].zero_counter == 8)
		{
			char value = 23;
			for (int j = 0; j < 9; j++)
			{
				if (all_squares[index].values[j] != '0')
				{
					value = all_squares[index].values[j];
					break;
				}
			}
			if (assign_set_delete(index, value, grid, filled) == 0)
				return 0;
		}
	}
	return 1;
}
void check_on_values(char grid[][9], int &filled)
{
	all_squares[0].values = "000000000";
	all_squares[0].zero_counter = -1;
	all_squares[0].name = "aa";
	for (int i = 1; i < 82; i++)
	{
		char value = return_grid_value(i, grid);
		if (value == '0')
		{
			remove_twins_values_from_me(i, grid);
		}
		else
		{
			all_squares[i].values = "000000000";
			all_squares[i].zero_counter = -1;
			remove_value_from_twins(value, i);
		}
	}
}
void remove_twins_values_from_me(int square_index, char grid[][9])
{
	for (int i = 0; i < 20; i++)
	{
		char value = return_grid_value(name_to_index(all_squares[square_index].twin[i][0], all_squares[square_index].twin[i][1]), grid);
		erase_char_from_my_values(square_index, value);
	}
}
void chapter1()
{
	/*
	in this chapter we define :
	1) the names of the square's "twins" , twins are the squares that affect each square of the 81 squares
	that if we put value x in one of them "it's twins" then we can't put x into this square
	each square have 20 twin , 8 in his square units and 6 are the rest of his row and 6 of his column
	2) the values that i can put in each square (1 -> 9) replace the one i can't put with "0"
	3) counter that count how many zeroes in this square values
	4) name of each square
	*/
	int square_index = 1;
	for (char i = 'A'; i <= 'I'; i++)
	{
		for (char j = '1'; j <= '9'; j++)
		{
			all_squares[square_index].name += i;
			all_squares[square_index].name += j;
			all_squares[square_index].index = square_index;
			square_index++;
		}
	}
	for (int i = 1; i < 82; i++)
	{
		all_squares[i].values = "123456789";
		all_squares[i].zero_counter = 0;
		int twin_index = 0;
		for (char j = '1'; j <= '9'; j++)
		{
			if (all_squares[i].name[1] != j)
			{
				all_squares[i].twin[twin_index] = all_squares[i].name[0];
				all_squares[i].twin[twin_index] += j;
				twin_index++;
			}
		}
		for (char j = 'A'; j <= 'I'; j++)
		{
			if (all_squares[i].name[0] != j)
			{
				all_squares[i].twin[twin_index] = j;
				all_squares[i].twin[twin_index] += all_squares[i].name[1];
				twin_index++;
			}
		}
		char a = all_squares[i].name[0];
		char b = all_squares[i].name[1];
		char letter1 = 'x';
		char letter2 = 'x';
		char num1 = 'x';
		char num2 = 'x';
		if ((a - 'A') % 3 == 0)
		{
			letter1 = a + 1;
			letter2 = a + 2;
		}
		else if ((a - 'A') % 3 == 1)
		{
			letter1 = a - 1;
			letter2 = a + 1;
		}
		else
		{
			letter1 = a - 2;
			letter2 = a - 1;
		}
		if ((b - '1') % 3 == 0)
		{
			num1 = b + 1;
			num2 = b + 2;
		}
		else if ((b - '1') % 3 == 1)
		{
			num1 = b - 1;
			num2 = b + 1;
		}
		else
		{
			num1 = b - 2;
			num2 = b - 1;
		}
		all_squares[i].twin[16] = letter1;
		all_squares[i].twin[16] += num1;
		all_squares[i].twin[17] = letter1;
		all_squares[i].twin[17] += num2;
		all_squares[i].twin[18] = letter2;
		all_squares[i].twin[18] += num1;
		all_squares[i].twin[19] = letter2;
		all_squares[i].twin[19] += num2;
	}
}
bool pre_solver(char grid[][9], string col[][9], string rows[][9], string unit[][9], int &filled_squares)
{
	while (1)
	{
		bool Found_solution = 0;
		mini_square members[9];
		for (int i = 0; i < 9; i++)
		{
			copy_mini_to_square(members, col, i);
			if (solver(grid, members, filled_squares, Found_solution) == 0)
				return 0;
		}
		for (int i = 0; i < 9; i++)
		{
			copy_mini_to_square(members, rows, i);
			if (solver(grid, members, filled_squares, Found_solution) == 0)
				return 0;
		}
		for (int i = 0; i < 9; i++)
		{
			copy_mini_to_square(members, unit, i);
			if (solver(grid, members, filled_squares, Found_solution) == 0)
				return 0;
		}
		if (Found_solution == 0)
			break;
	}
	return 1;
}
bool solver(char grid[][9], mini_square members[], int &filled_squares, bool &passed)
{
	sort(members, members + 9, check_sorting);
	value_counter times_seen[9];
	for (char i = '1'; i <= '9'; i++)
	{
		times_seen[i - 49].value = i;
		times_seen[i - 49].counter = 0;
	}
	for (int i = 0; i < 9; i++)
	{
		if (all_squares[members[i].all_squares_index].zero_counter == 8)
		{
			passed = 1;
			char value = 0;
			for (int j = 0; j < 9; j++)

			{
				if (all_squares[members[i].all_squares_index].values[j] != '0')
				{
					value = members[i].values[j];
					break;
				}
			}
			if (assign_set_delete(members[i].all_squares_index, value, grid, filled_squares) == 0)
			{
				return 0;
			}
		}
		int a, b;
		name_to_grid(members[i].name, a, b);
		if (grid[a][b] == '0')
		{
			for (int j = 0; j < 9; j++)
			{
				if (all_squares[members[i].all_squares_index].values[j] != '0')
				{
					times_seen[members[i].values[j] - 49].counter++;
					times_seen[members[i].values[j] - 49].index = members[i].all_squares_index;
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (times_seen[i].counter == 1)
		{
			passed = 1;
			if (assign_set_delete(times_seen[i].index, times_seen[i].value, grid, filled_squares) == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
void restore_point(char grid[9][9])
{
	grid_copy(grid, grid_optimal);
}
bool uncertain(char grid[][9], int filled, string col[][9], string rows[][9], string unit[][9])
{
	for (int i = 1; i < 82; i++)
	{
		all_squares[i].values = "123456789";
		all_squares[i].zero_counter = 0;
	}
	check_on_values(grid, filled);
	return pre_solver(grid, col, rows, unit, filled);
}
bool solved()
{
	for (int i = 1; i < 82; i++)
	{
		if (all_squares[i].zero_counter != -1)
			return 0;
	}
	return 1;
}
void chapter_4(int squares_filled, string col[][9], string rows[][9], string unit[][9])
{
	if (solutions == 0)
		return;
	char grid_new[9][9];
	grid_copy(grid_optimal, grid_new);
	if (uncertain(grid_new, squares_filled, col, rows, unit) == 0)
		return;
	if (solved() == 1)
	{
		grid_copy(grid_new, grid_solution);
		solutions = 0;
		return;
	}
	square best_choice_square;
	if (1)
	{
		sort(all_squares, all_squares + 82, check_counter_square);
		best_choice_square.zero_counter = all_squares[0].zero_counter;
		best_choice_square.name = all_squares[0].name;
		best_choice_square.values = all_squares[0].values;
		best_choice_square.index = all_squares[0].index;
		sort(all_squares, all_squares + 82, check_index_square);
	}
	int a, b;
	name_to_grid(best_choice_square.name, a, b);
	for (int i = 0; i < 9; i++)
	{
		if (best_choice_square.values[i] != '0')
		{
			grid_optimal[a][b] = best_choice_square.values[i];
			chapter_4(squares_filled, col, rows, unit);
			grid_optimal[a][b] = '0';
		}
	}
}
bool grid_solver(char grid_input[][9])
{
	string column[][9] = { { "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1" }
		,{ "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2" },{ "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3" }
		,{ "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4" },{ "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5" }
		,{ "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6" },{ "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7" }
	,{ "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8" },{ "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9" } };


	string row[][9] = { { "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9" }
		,{ "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9" },{ "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9" }
		,{ "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9" },{ "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9" }
		,{ "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9" },{ "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9" }
	,{ "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9" },{ "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9" } };

	string square_unit[][9] = { { "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3" }
		,{ "A4", "A5", "A6", "B4", "B5", "B6", "C4", "C5", "C6" },{ "A7", "A8", "A9", "B7", "B8", "B9", "C7", "C8", "C9" }
		,{ "D1", "D2", "D3", "E1", "E2", "E3", "F1", "F2", "F3" },{ "D4", "D5", "D6", "E4", "E5", "E6", "F4", "F5", "F6" }
		,{ "D7", "D8", "D9", "E7", "E8", "E9", "F7", "F8", "F9" },{ "G1", "G2", "G3", "H1", "H2", "H3", "I1", "I2", "I3" }
	,{ "G4", "G5", "G6", "H4", "H5", "H6", "I4", "I5", "I6" },{ "G7", "G8", "G9", "H7", "H8", "H9", "I7", "I8", "I9" } };
	chapter1();
	restore_point(grid_input);
	int filled_squares = 0;
	int number[9] = { 0 }, all = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid_input[i][j] != '0')
			{
				if (number[grid_input[i][j] - '1'] != 0)
					all--;
				number[grid_input[i][j] - '1']++;
			}
		}
	}
	if (all >= 2)
		return 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid_input[i][j] != '0')
				filled_squares++;
		}
	}
	solutions = 1;
	chapter_4(filled_squares, column, row, square_unit);
	grid_copy(grid_solution, grid_input);
	return 1;
}
void choose_hard(char grid[][10], char solution[][10], bool check_board[][10])
{
	fstream file;
	file.open("cells_17.txt");
	string grids[210], solutions[210];
	int c = 0;
	while (1)
	{
		file >> grids[c] >> solutions[c];
		if (grids[c] == "end")
			break;
		c++;
	}
	int x = 0, y = 0;

	x = abs(rand())%10;

	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			grid[i][j] = grids[x][y];
			solution[i][j] = solutions[x][y];
			if (grids[x][y] == '0')
			{
				check_board[i][j] = 0;
			}
			else
			{
				check_board[i][j] = 1;
			}
			y++;
		}
	}
}
bool Check_if_Board_is_Valid(char suduko_board[][9])
{
	int numbers[9];
	for (int rows = 0; rows < 9; rows++)
	{
		for (int counter = 0; counter < 9; counter++)
		{
			numbers[counter] = 0;
		}
		for (int columns = 0; columns < 9; columns++)
		{
			if (suduko_board[rows][columns] != '0')
			{
				numbers[suduko_board[rows][columns] - 49]++;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			if (numbers[counter] > 1)
			{
				return 0;
			}
		}
	}
	for (int columns = 0; columns < 9; columns++)
	{
		for (int counter = 0; counter < 9; counter++)
		{
			numbers[counter] = 0;
		}
		for (int rows = 0; rows < 9; rows++)
		{
			if (suduko_board[rows][columns] != '0')
			{
				numbers[suduko_board[rows][columns] - 49]++;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			if (numbers[counter] > 1)
			{
				return 0;
			}
		}
	}
	for (int rows = 0; rows < 9; rows = rows + 3)
	{
		for (int counter = 0; counter < 9; counter++)
		{
			numbers[counter] = 0;
		}
		for (int columns = 0; columns < 3; columns++)
		{
			if (suduko_board[rows][columns] != '0')
			{
				numbers[suduko_board[rows][columns]]++;
			}
			if (suduko_board[rows + 1][columns] != '0')
			{
				numbers[suduko_board[rows + 1][columns]]++;
			}
			if (suduko_board[rows + 2][columns] != '0')
			{
				numbers[suduko_board[rows + 2][columns]]++;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			if (numbers[counter] > 1)
			{
				return 0;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			numbers[counter] = 0;
		}
		for (int columns = 3; columns < 6; columns++)
		{
			if (suduko_board[rows][columns] != '0')
			{
				numbers[suduko_board[rows][columns]]++;
			}
			if (suduko_board[rows + 1][columns] != '0')
			{
				numbers[suduko_board[rows + 1][columns]]++;
			}
			if (suduko_board[rows + 2][columns] != '0')
			{
				numbers[suduko_board[rows + 2][columns]]++;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			if (numbers[counter] > 1)
			{
				return 0;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			numbers[counter] = 0;
		}
		for (int columns = 6; columns < 9; columns++)
		{
			if (suduko_board[rows][columns] != '0')
			{
				numbers[suduko_board[rows][columns]]++;
			}
			if (suduko_board[rows + 1][columns] != '0')
			{
				numbers[suduko_board[rows + 1][columns]]++;
			}
			if (suduko_board[rows + 2][columns] != '0')
			{
				numbers[suduko_board[rows + 2][columns]]++;
			}
		}
		for (int counter = 0; counter < 9; counter++)
		{
			if (numbers[counter] > 1)
			{
				return 0;
			}
		}
	}
	return 1;
}