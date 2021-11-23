/**
 * @file operation.h
 * @author your name 
 * @brief Declaring the functions for user operations
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef OPERATIONS_H /* IF NOT DEFINE THE OPERATIONS_H*/

#define OPERATIONS_H /* DEFINING THE OPERATIONS_H*/
/* INCLUDING THE STRUCTURE_H */
int display_board(char board[3][3]);
int input(int number);
int winner(char board[3][3]);
#endif
