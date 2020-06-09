#include <stdio.h>



// Function to check if a given row is valid. It will return:
// -1 if the row contains an invalid value
// 1 is the row is valid.
int valid_row(int row, int mat[][9]) {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int count = 0;
	int i = 0;
	int j = 0;
	for (int i =0; i < 9; i++) 
	{
		// Checking for values outside 1 and 9; 
		// 0 is considered valid because it 
		// denotes an empty cell.
		// Removing zeros and the checking for values and
		// outside 1 and 9 is another way of doing 
		// the same thing.
		if (mat[row][i] < 1 || mat[row][i] > 9) 
			return -1;
		
		for (int j = 0; j < 9; j++)
		{
			if (mat[row][i] == arr[j])
			{
				count = count + 1;
				arr[j] = 0;
			}
		}
	}
	if (count == 9)
		return 1;
	return -1;
}



// Function to check if a given col is valid. It will return:
// -1 if the col contains an invalid value
// 1 is the col is valid.
int valid_col(int col, int mat[][9]) {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int count = 0;
	int i = 0;
	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (mat[i][col] < 1 || mat[i][col]  > 9)
			return -1;
		
		
		for (int j = 0; j < 9; j++)
		{
			if (mat[i][col] == arr[j])
			{
				count = count + 1;
				arr[j] = 0;
				break;
			}
		}
	}

	if (count == 9)
		return 1;
	return -1;
}




// function to check if all the subsquares are valid
int valid_subsquares(int mat[][9])
{
	for (int row = 0; row < 9; row = row + 3)
	{
		for (int col = 0; col < 9; col = col + 3)
		{
			int count = 0;
			int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			for (int r = row; r < row + 3; r++) {
				for (int c = col; c < col + 3; c++) {

					for (int iter = 0; iter < 9; iter++)
					{
						if (arr[iter] == mat[r][c])
						{
							count = count + 1;
							arr[iter] = 0;
						}

					}
				}

			}

			if (count != 9)
				return -1;

		}
	}
	return 1;

}


// function to check if the board is invalid
void vaild_board(int mat[][9])
{
	for (int i = 0; i < 9; i++)
	{
		int res_row = valid_row(i, mat);
		int res_col = valid_col(i, mat);
		if (res_row < 1 || res_col < 1)
		{
			printf("the board is INVALID\n");
			return;
		}
		
	}
	int sub_seq = valid_subsquares(mat);
	if (sub_seq < -1)
		printf("the board is INVALID\n");

	
	printf("the board is VALID\n");


}

// Function to print the board.
void print_board(int mat[][9]) {
	putchar('\n');
	for (int row = 0; row < 9; row++)
	{
		putchar('['); putchar(' ');
		for (int col = 0; col < 9; col++)
		{
			putchar(mat[row][col] + '0');
			putchar(' ');
		}
		putchar(' '); putchar(']');
		putchar('\n');
	}
}


int main() {


	//invalid.
	int board[9][9] = {
	{1, 4, 7, 2, 5, 6, 8, 9, 3},
	{2, 5, 6, 0, 0, 1, 0, 0, 0},
	{3, 0, 5, 0, 0, 0, 0, 0, 0},
	{0, 8, 4, 0, 2, 0, 0, 0, 4},
	{0, 0, 3, 4, 1, 0, 0, 2, 0},
	{9, 0, 2, 0, 0, 0, 6, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 9},
	{4, 0, 8, 0, 0, 2, 0, 0, 0},
	{0, 0, 9, 0, 0, 8, 0, 0, 7},
	};
	print_board(board);
	vaild_board(board);



	//valid
	int board1[9][9] = {
		{3 ,1, 6, 5, 7, 8, 4, 9, 2},
		{5 ,2 ,9, 1, 3 ,4 ,7 ,6 ,8},
		{4 ,8 ,7 ,6 ,2 ,9, 5 ,3 ,1},
		{2 ,6, 3 ,4, 1, 5 ,9 ,8, 7},
		{9 ,7 ,4 ,8, 6 ,3 ,1 ,2 ,5},
		{8 ,5 ,1, 7 ,9 ,2, 6 ,4 ,3},
		{1 ,3 ,8 ,9 ,4 ,7 ,2, 5, 6},
		{6 ,9 ,2 ,3, 5 ,1 ,8 ,7 ,4},
		{7 ,4, 5 ,2 ,8, 6, 3 ,1 ,9} };

	print_board(board1);
	vaild_board(board1);




	//invalid
	int board2[9][9] = {
			{3 ,1, 6, 5, 7, 8, 4, 9, 2},
			{1 ,2 ,9, 1, 3 ,4 ,7 ,6 ,8},
			{4 ,8 ,7 ,6 ,2 ,9, 5 ,3 ,1},
			{2 ,6, 3 ,4, 1, 5 ,9 ,8, 7},
			{9 ,7 ,4 ,8, 6 ,3 ,1 ,2 ,5},
			{8 ,5 ,1, 7 ,9 ,2, 6 ,4 ,3},
			{1 ,3 ,8 ,9 ,4 ,7 ,2, 5, 6},
			{6 ,9 ,2 ,3, 5 ,1 ,8 ,7 ,4},
			{7 ,4, 5 ,2 ,8, 6, 3 ,1 ,9} };

	print_board(board2);
	vaild_board(board2);


	//valid

	int board3[9][9] = {
	{5, 1, 7, 6, 9, 8, 2, 3, 4},
	{2, 8, 9, 1, 3, 4, 7, 5, 6},
	{3, 4, 6, 2, 7, 5, 8, 9, 1},
	{6, 7, 2, 8, 4, 9, 3, 1, 5},
	{1, 3, 8, 5, 2, 6, 9, 4, 7},
	{9, 5, 4, 7, 1, 3, 6, 8, 2},
	{4, 9, 5, 3, 6, 2, 1, 7, 8},
	{7, 2, 3, 4, 8, 1, 5, 6, 9},
	{8, 6, 1, 9, 5, 7, 4, 2, 3} };


	print_board(board3);
	vaild_board(board3);

	//valid
	int board4[9][9] = {
	{ 8, 1, 2, 7, 5, 3, 6, 4, 9},
	{9, 4, 3, 6, 8, 2, 1, 7, 5},
	{6, 7, 5, 4, 9, 1, 2, 8, 3},
	{1, 5, 4, 2, 3, 7, 8, 9, 6},
	{3, 6, 9, 8, 4, 5, 7, 2, 1},
	{2, 8, 7, 1, 6, 9, 5, 3, 4},
	{5, 2, 1, 9, 7, 4, 3, 6, 8},
	{4, 3, 8, 5, 2, 6, 9, 1, 7},
	{7, 9, 6, 3, 1, 8, 4, 5, 2} };

	print_board(board4);
	vaild_board(board4);




	//invalid
	int board5[9][9] = {
	{ 8,2, 1, 7, 5, 3, 6, 4, 9},
	{9, 4, 3, 6, 8, 2, 1, 7, 5},
	{6, 7, 5, 4, 9, 1, 2, 8, 3},
	{1, 5, 4, 2, 3, 7, 8, 9, 6},
	{3, 6, 9, 8, 4, 5, 7, 2, 1},
	{2, 8, 7, 1, 6, 9, 5, 3, 4},
	{5, 2, 1, 9, 4, 7, 3, 6, 8},
	{4, 3, 8, 5, 2, 6, 9, 1, 7},
	{7, 9, 6, 3, 1, 8, 4, 5, 2} };

	print_board(board5);
	vaild_board(board5);







	return 0;
}