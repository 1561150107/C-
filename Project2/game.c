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
			//��ӡһ������
			printf(" %c ", ch_board[i][j]);
			if (j < col - 1)
			{
				printf("|");//��ӡ�����ַ��Աߵ�"|"
			}

		}
		printf("\n");
		//����ѭ����ӡ����
		// a | a | a  


		//��ӡ�ָ���
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");//��ӡ���ǡ�---���Աߵġ�|��
				}
			}
			printf("\n");
		}
		//����ѭ����ӡ����
		// a | a | a  
		//---|---|---
	}
}

//�������
void playmove(char ch_board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
	printf("�������������:>");
	scanf("%d%d", &x,&y);
	system("cls");
		if (x >= 1 && x <=row && y >= 1 && y <=col)//��Ȼ���������ԣ�0,0����ʼ������ûѧ��������˻���Ϊ�����ԣ�1,1����ʼ�����Ե���X=1
		{
			if (ch_board[x-1][y-1] == ' ')
			{
			 ch_board[x-1][y-1]='*';
				break;
			}
			else
				printf("�����Ѿ��������ˣ�������ѡ��\n");
			display_board(ch_board, ROW, COL);
		}
		else
		{
			printf("����Ƿ�������������\n");
			display_board(ch_board, ROW, COL);

		}
	}
}



//��������
computermove(char ch_board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("������:>\n");
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

//�ж���Ӯ
int isfull(char ch_board[ROW][COL],int row,int col)//�ж��Ƿ�ƽ��
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
		//������
		if (ch_board[i][0] == ch_board[i][1] && ch_board[i][1] == ch_board[i][2] && ch_board[i][1] != ' ')
		{
			return ch_board[i][1];
		}

	}
	//������
	for (i = 0; i < col; i++)
	{
		if (ch_board[0][i] == ch_board[1][i] && ch_board[0][i] == ch_board[2][i] && ch_board[1][i] != ' ')
		{
			return ch_board[1][i];
		}
	}


	//�����Խ���
	if (ch_board[0][0] == ch_board[1][1] && ch_board[1][1] == ch_board[2][2] && ch_board[1][1] != ' ')
		return ch_board[1][1];
	if (ch_board[0][2] == ch_board[1][1] && ch_board[1][1] == ch_board[2][0] && ch_board[1][i] != ' ')
		return ch_board[1][1];
	//�ж��Ƿ�ƽ��
	if (isfull(ch_board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}