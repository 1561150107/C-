#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"





void game()
{
   //雷的信息存储
	//1.布置好雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//布置雷
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine, ROW, COL, show);//从mine获取信息输入到show

}



void menu()
{
	printf("***********************************************\n");
	printf("*********************扫雷**********************\n");
	printf("*****1.开始游戏                 0.退出游戏*****\n");
	printf("***********************************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("请选择>:");
        scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("非法输入，请重试\n");
			break;
		}
	} while (input);
	


}

int main()
{
	test();
	return 0;
}