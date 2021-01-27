#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
void game()
{
	int i = 1;
	int ret;
	int guess = 0;
	printf("游戏开始\n");
	ret = rand() % 100 + 1;//生成1-100之间随机数

	//2.猜数字

	while (1)
	{
		while (i)//优化
		{
			printf("(提示：数字范围在1--100中)\n");//
			i--;
		}
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else	if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你猜对了");
			break;
		}
	}

}
void menu()
{
	printf("***************************************************\n");
	printf("********************猜数字游戏*********************\n");
	printf("**   1.开始游戏                     0.退出游戏   **\n");
	printf("***************************************************\n");
}
int main()
{
	int ret = 0;
	int input = 0;
	//游戏菜单
	menu();
	//1.生成随机数
	/*拿时间戳生成起点*/
	//time_t time(time_t *timer)     time_t本质上是个整形
	//ret= rand((unsigned)time(NULL)); 	//rand生成伪随机数 范围在0---RAND_MAX(十六进制为0x7fff  十进制为32767)
									  //  ULL 空指针  此括号中需要指针
	srand((unsigned)time(NULL));
	do
	{
		printf("请选择:>");
	again:
		scanf("%d", &input);
		switch (input)
		{
		case 1:

			game();
			printf("是否继续游戏(按1继续游戏   按0结束游戏)\n");

			break;
		case 0:
			printf("游戏结束");
			break;
		default:

			printf("选择错误，请重新选择\n");
			goto again;

		}

	} while (input);
	return 0;
}
