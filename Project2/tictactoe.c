#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	int ret = 0;
	//��ά������������Ϣ
	char ch_board[ROW][COL] = { 0 };//��ʼ������Ϊ�ո�
	display_board(ch_board, ROW, COL);//��ӡ����
	init_board(ch_board, ROW, COL);
	while (1)
	{
	

		//�������
		playmove(ch_board, ROW, COL);
		display_board(ch_board, ROW, COL);//��ӡ����
		//�ж�����Ƿ�Ӯ
		ret = iswin(ch_board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
		computermove(ch_board, ROW, COL);
		display_board(ch_board, ROW, COL);//��ӡ����
	    //�жϵ����Ƿ�Ӯ
		ret = iswin(ch_board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}

	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}
void menu()
{
	printf("**********************************************************************\n");
	printf("********************************������********************************\n");
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
		
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			Sleep(1000);
			printf("��Ϸ������ʼ\n");
			Sleep(1000);
			system("cls");
			game();
			break;
		case 2:
			printf("��Ϸ�����������������¡������Ҷ�Ϊ1,2,3��\n");
			printf("��ʤ������\n");
			printf("���С����С���б��ֻҪ��һ����������һ���ʤ��\n");
			again:
			printf("�����˳���������1\n");
			scanf("%d", &input1);
			if (input1 == 1)
			{
				system("cls");
				break;
			}
			else
				printf("�Ƿ�ѡ�������\n");
				goto again;
		default:
			printf("�Ƿ�ѡ�������\n");
			break;
		}
		
	} while (input);
}


int main()
{
	test();
}










	



	

