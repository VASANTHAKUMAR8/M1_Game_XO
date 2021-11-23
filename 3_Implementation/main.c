#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h> 

int display_board(char board[3][3]); 
int display_board(char board[3][3]) 
{
	int i = 0; 
	int j = 0; 
	
	for (i = 0; i < 3; i++) 
	{
		printf(" \n ");
		for (j = 0; j < 3; j++) 
		{
			printf(" %c ", board[i][j]); 
		}
	}
	printf(" \n "); 
	return 0;
}


int input(int number);
int input(int number) 
{
	int row_or_column = 0; 
	char* string_to_print[7]; 
	if (number == 0) 
	{
		*string_to_print = "row";
	} else if (number == 1) 
	{
		*string_to_print = "column";
	} else {
		printf("\n This is not supposed to hapen. \n"); 
	}
	int valid = 0; 
	while (valid == 0)
	{
		printf("\n Choose a %s> ", *string_to_print); 
		scanf("%d", &row_or_column);  
		if (1 <= row_or_column && row_or_column <= 3)
		{
			printf("\n You have chosen %s #%d. \n", *string_to_print, row_or_column);
			valid = 1;
			
		} else {
			printf("\n %s = %d \n", *string_to_print, row_or_column); 
			printf("\n Invalid %s chosen, please try again. \n (The %s number must be either 1, 2, or 3.) \n", *string_to_print, *string_to_print);
			
		}
	}
	return row_or_column;
}


int winner(char board[3][3]);
int winner(char board[3][3]) 
{
	int winner_number = 0;
	int blank = 0;
	int i = 0; 
	int j = 0; 
	if (((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X')) || // first row
		((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X')) || // first column
		((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || // diagonal 1
		((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X')) || // second row
		((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X')) || // third row
		((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][1] == 'X')) || // second column
		((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X')) || // third column
		((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X')) // diagonal 2
		)
	{
		winner_number = 1;
	} else if (((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O')) || // first row
			   ((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O')) || // first column
			   ((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || // diagonal 1
			   ((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O')) || // second row
			   ((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O')) || // third row
			   ((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O')) || // second column
			   ((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O')) || // third column
			   ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O')) // diagonal 2
			   )
	{
		winner_number = 2;
	} else {
		for (i = 0; i < 3; i++) 
		{
			for (j = 0; j < 3; j++) 
			{
				if (board[i][j] == '_') {
					blank = 1; 
				}
			}
		}
		if (blank == 0) { 
			winner_number = 3;
		}
	}
	
	return winner_number;
}


int main (int argc, const char * argv[]) { 
	int number = 0; 
	int player = 1; 
	int flag = 0; 
	printf("\n Message for security and/or debugging: \n This program's path is %s and it is running with %i argument(s). \n", argv[0], argc); 
	char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}}; 
	int won = 0; 
	 
	printf("\n Here is a blank Tic-Tac-Toe board for you and a friend to play Tic-Tac-Toe on: \n");
	display_board(board); 
	while (won == 0) 
	{
		while (flag == 0) {
			printf("\n It is player #%i's turn. \n", player); 
			int row = input(number); 
			row--; 
			
			number++; 
			int column = input(number);
			column--;  
			
			if (player == 1 && board[row][column] == '_') {
				board[row][column] = 'X';
				
				flag = 1;
			} else if (player == 2 && board[row][column] == '_') {
				board[row][column] = 'O';
				
				flag = 2;
			} else if (board[row][column] == 'O') {
				printf("\n That space is taken by O. Please try again. \n");
			} else if (board[row][column] == 'X') {
				printf("\n That space is taken by X. Please try again. \n");
			} else {
				printf("This isn't supposed to happen"); 
				exit(1);
			}
			
			number = 0; 
		}
		printf("\n The board now looks like this: \n");
		display_board(board); 
		won = winner(board); 
		
		if (won == 1) { 
			printf("\n Player 1 wins! \n");
		} else if (won == 2) { 
			printf("\n Player 2 wins! \n");
		} else if (won == 3) { 
			printf("\n It's a tie. \n");
		} else {
			flag = 0; 
			won = 0;  
		}
		if (player == 1) { 
			player = 2; 
		} else if (player == 2) {
			player = 1;
		} else {
			printf("This isn't supposed to happen"); 
		}
	}
	printf(" \n "); 
    return 0;
}
