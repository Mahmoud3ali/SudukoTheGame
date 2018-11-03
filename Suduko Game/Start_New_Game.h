
int deleted_cells;
char suduko_board[10][10], copy_of_suduko_board[10][10];
bool check_board[10][10];
bool green_red[10][10];
char suduko[9][9];


void borad_maker(char suduko_board[10][10], char copy_of_suduko_board[10][10]);
void board_swaping(char suduko_board[10][10], char copy_of_suduko_board[10][10], bool check_board[10][10]);
void empties(char suduko_board[][10], bool check_board[][10], int deleted_cells);
int check_board_true_or_false_for_end(char suduko_board[10][10], char copy_of_suduko_board[10][10]);
void check_board_true_or_false(char suduko_board[10][10], char copy_of_suduko_board[10][10], bool check_board[10][10]);