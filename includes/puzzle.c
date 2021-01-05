/*
 * C file and functions for solving de puzzle
*/

#include <stdio.h>
#include "puzzle.h"

/*
 * Recursive algorithm that solves the board
*/

int solveSudoku(int x, int y, int board[9][9]) {

    int num = 1;
    int tx = 0;
    int ty = 0;

    if(board[x][y] != 0) {

        if(x == 8 && y == 8) {
            return 1;
        }

        if(x < 8) {
            x++;
        } else {
            x = 0;
            y++;
        }

        if(solveSudoku(x, y, board)) {
            return 1;
        } else {
            return 0;
        }
    }

    if(board[x][y] == 0) {
        while(num < 10) {
             if(!sameSquare(x, y, num, board) && !sameRow(x, y, num, board) && !sameColumn(x, y, num, board)) {            
                board[x][y] = num;
                if(x == 8 && y == 8) {
                    return 1;
                }

                if(x < 8) {
                    tx++;
                } else {
                    tx = 0;
                    ty = y + 1;
                }

                if(solveSudoku(tx, ty, board)) {
                    return 1;
                }                
            }   
            num++;         
        }
        board[x][y] = 0;
        return 0;
    }
    return 0;
}


/*
 * Will return 1 (true) if the number we're passing already exists in the same column
*/

int sameRow(int x, int y, int num, int board[9][9]) {

    for(int i = 0; i < 9; i++) {
        if(board[x][i] == num) {
            return 1;
        }
    }
    return 0;
}

/*
 * Will return 1 (true) if the number we're passing already exists in the same row
*/

int sameColumn(int x, int y, int num, int board[9][9]) {

    for(int i = 0; i < 9; i++) {
        if(board[i][y] == num) {
            return 1;
        }
    }
    return 0;
}

/*
 * Will return 1 (true) if the number we're passing already exists in the same square
*/

int sameSquare(int x, int y, int num, int board[9][9]) {

    if(x < 3) {
        x = 0;
    } else if(x < 6) {
        x = 3;
    } else {
        x = 6;
    }

    if(y < 3) {
        y = 0;
    } else if(y < 6) {
        y = 3;
    } else {
        y = 6;
    }

    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            if(board[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

