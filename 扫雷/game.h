#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
#include<stdio.h>
#include<time.h>
void init_board(char board[ROWS][COLS], int row, int col, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], int row,int col,char show[ROWS][COLS]);
void open(char mine[ROWS][ROWS], int row, int col, char show[ROWS][COLS],int x,int y);
