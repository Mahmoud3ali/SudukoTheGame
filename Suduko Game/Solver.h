#include <iostream>
using namespace std;
struct square
{
	int zero_counter;
	string name; //name of the square according to our naming style 
	string twin[20]; // names of all members in the grid that depend on this square's value and vise versa 
	string values; // the values i can put in this square "123456789" 
	int index;
};
struct mini_square
{
	string name;
	string values;
	int grid_index[2];
	int all_squares_index;
	int zero_counter;
};
struct value_counter
{
	char value;
	int counter;
	int index;
};
bool uncertain(char grid[][9], int filled, string col[][9], string rows[][9], string unit[][9]);
bool check_counter_square(square x, square y);
bool check_index_square(square x, square y);
void grid_copy(char grid[][9], char grid_2[][9]);
bool check_sorting(mini_square x, mini_square y);
int name_to_index(char x, char y);
string grid_to_name(int x, int y);
void name_to_grid(string name, int &i, int &j);
void all_grid_to_zero(char grid[][9]);
void input_grid(char grid[][9], int &filled_squares);
char return_grid_value(int square_index, char grid[][9]);
bool remove_value_from_twins(char value, int square_index);
bool erase_char_from_my_values(int square_index, char value);
void remove_twins_values_from_me(int square_index, char grid[][9]);
void copy_mini_to_square(mini_square arr1[], string arr2[][9], int index);
bool assign_set_delete(int square_index, char Char, char grid[][9], int &filled);
void check_on_values(char grid[][9], int &filled);
void chapter1();
bool pre_solver(char grid[][9], string col[][9], string rows[][9], string unit[][9], int &filled_squares);
bool solver(char grid[][9], mini_square members[], int &filled_squares, bool &passed);
void restore_point(char grid[9][9]);
void chapter_4(int squares_filled, string col[][9], string rows[][9], string unit[][9]);
bool solved();
bool grid_solver(char grid_input[][9]);
void choose_hard(char grid[][10], char solution[][10], bool check_board[][10]);
bool Check_if_Board_is_Valid(char suduko_board[][9]);