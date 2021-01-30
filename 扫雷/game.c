 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init_board(char board[ROWS][COLS], int row, int col, char set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}

}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <=col; i++)//��ӡ�к�
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <=row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (int j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row+1;//1-9
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y]='1';
			count--;
		}
	}
}


//'0'-'0'=0
//'1'-'0'=1
//'3'-'0'=3

int get_mine_count(char mine[ROWS][COLS], int x, int y) 
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}

void findmine(char mine[ROWS][ROWS], int row, int col, char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<=row*col-EASY_COUNT)
	{
		printf("�������Ų��׵�����:>");
		scanf("%d%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//����Ϸ�
		{
			if (mine[x][y] == '1')
			{
				printf("���ź�������ը����\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{//ͳ��x��y������Χ������
				int count = get_mine_count(mine, x, y);
				show[x][y] = count+'0';			
				displayboard(show, row, col);
				win++;
				
				
			}
		}
		else
			printf("��������Ƿ�������������\n");
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
	}
}