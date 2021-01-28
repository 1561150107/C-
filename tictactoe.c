//头文件
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


//四种游戏状态
//电脑赢 ——  '#'
//玩家赢 ——  '*'
//平局   ——  'Q'
//继续   ——  'C'





//函数实现
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




//主函数
#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	int ret = 0;
	//二维数组存放棋盘信息
	char ch_board[ROW][COL] = { 0 };//初始化棋盘为空格
	display_board(ch_board, ROW, COL);//打印棋盘
	init_board(ch_board, ROW, COL);
	while (1)
	{
	

		//玩家下棋
		playmove(ch_board, ROW, COL);
		display_board(ch_board, ROW, COL);//打印棋盘
		//判断玩家是否赢
		ret = iswin(ch_board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		computermove(ch_board, ROW, COL);
		display_board(ch_board, ROW, COL);//打印棋盘
	    //判断电脑是否赢
		ret = iswin(ch_board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}

	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}

}
void menu()
{
	printf("**********************************************************************\n");
	printf("********************************井字棋********************************\n");
	printf("*********** 0.exid           1.play           2.help******************\n");
	printf("**********************************************************************\n");

}
void test()
{
	int input = 0;
	int input1 = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			Sleep(1000);
			printf("游戏即将开始\n");
			Sleep(1000);
			system("cls");
			game();
			break;
		case 2:
			printf("游戏中输入的坐标从上至下、从左到右都为1,2,3。\n");
			printf("获胜条件：\n");
			printf("三行、三列、俩斜杠只要有一方棋子连在一起便胜利\n");
			again:
			printf("如需退出，请输入1\n");
			scanf("%d", &input1);
			if (input1 == 1)
			{
				system("cls");
				break;
			}
			else
				printf("非法选项，请重试\n");
				goto again;
		default:
			printf("非法选项，请重试\n");
			break;
		}
		
	} while (input);
}


int main()
{
	test();
}










	



	

