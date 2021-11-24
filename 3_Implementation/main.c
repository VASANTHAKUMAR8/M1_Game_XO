#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int display_board(char board[3][3]); 



int input(int number);



int winner(char board[3][3]);



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
