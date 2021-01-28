#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init_board(char ch_board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ch_board[i][j] = ' ';
		}
	}
}

void display_board(char ch_board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//打印一行数据
			printf(" %c ", ch_board[i][j]);
			if (j < col - 1)
			{
				printf("|");//打印的是字符旁边的"|"
			}

		}
		printf("\n");
		//上面循环打印的是
		// a | a | a  


		//打印分割行
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");//打印的是“---”旁边的“|”
				}
			}
			printf("\n");
		}
		//上面循环打印的是
		// a | a | a  
		//---|---|---
	}
}

//玩家下棋
void playmove(char ch_board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
	printf("请玩家输入坐标:>");
	scanf("%d%d", &x,&y);
	system("cls");
		if (x >= 1 && x <=row && y >= 1 && y <=col)//虽然数组坐标以（0,0）开始，但是没学过数组的人会以为坐标以（1,1）开始，所以得用X=1
		{
			if (ch_board[x-1][y-1] == ' ')
			{
			 ch_board[x-1][y-1]='*';
				break;
			}
			else
				printf("这里已经被人下了，请重新选择\n");
			display_board(ch_board, ROW, COL);
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			display_board(ch_board, ROW, COL);

		}
	}
}



//电脑下棋
computermove(char ch_board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑走:>\n");
	Sleep(1000);
	while (1)
	{
		x = rand() % row;
		y = rand() % row;
		if (ch_board[x][y] == ' ')
		{
			ch_board[x][y] = '#';
			break;
		}

	}
	system("cls");


}

//判断输赢
int isfull(char ch_board[ROW][COL],int row,int col)//判断是否平局
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; i < col; j++)
		{
			if (ch_board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

int iswin(char ch_board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//横三行
		if (ch_board[i][0] == ch_board[i][1] && ch_board[i][1] == ch_board[i][2] && ch_board[i][1] != ' ')
		{
			return ch_board[i][1];
		}

	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (ch_board[0][i] == ch_board[1][i] && ch_board[0][i] == ch_board[2][i] && ch_board[1][i] != ' ')
		{
			return ch_board[1][i];
		}
	}


	//俩个对角线
	if (ch_board[0][0] == ch_board[1][1] && ch_board[1][1] == ch_board[2][2] && ch_board[1][1] != ' ')
		return ch_board[1][1];
	if (ch_board[0][2] == ch_board[1][1] && ch_board[1][1] == ch_board[2][0] && ch_board[1][i] != ' ')
		return ch_board[1][1];
	//判断是否平局
	if (isfull(ch_board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}