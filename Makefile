#
# Makefile
#
# CC 50
# Pset 4
#

sudoku: Makefile sudoku.c includes/sudoku.h includes/puzzle.c includes/puzzle.h
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -Wno-unused-but-set-variable -o sudoku sudoku.c includes/puzzle.c -lncurses

clean:
	rm -f *.o a.out core log.txt sudoku
