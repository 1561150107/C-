#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"





void game()
{
   //�׵���Ϣ�洢
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//��ӡ����
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//������
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine, ROW, COL, show);//��mine��ȡ��Ϣ���뵽show

}



void menu()
{
	printf("***********************************************\n");
	printf("*********************ɨ��**********************\n");
	printf("*****1.��ʼ��Ϸ                 0.�˳���Ϸ*****\n");
	printf("***********************************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("��ѡ��>:");
        scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�Ƿ����룬������\n");
			break;
		}
	} while (input);
	


}

int main()
{
	test();
	return 0;
}