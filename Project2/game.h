#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void init_board(char ch_board[ROW][COL], int row, int col);
void display_board(char ch_board[ROW][COL], int row, int col);
void playmove(char ch_board[ROW][COL], int row, int col);
computermove(char ch_board[ROW][COL], int row, int col);
int iswin(char ch_board[ROW][COL], int row, int col);
int isfull(char ch_board[ROW][COL], int row, int col);


//������Ϸ״̬
//����Ӯ ����  '#'
//���Ӯ ����  '*'
//ƽ��   ����  'Q'
//����   ����  'C'