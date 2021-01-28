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










	



	

