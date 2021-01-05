/*
 * Header file for solving the puzzle - functions declaration
*/

int solveSudoku(int x, int y, int board[9][9]);

int sameRow(int x, int y, int num, int board[9][9]);

int sameColumn(int x, int y, int num, int board[9][9]);

int sameSquare(int x, int y, int num, int board[9][9]);