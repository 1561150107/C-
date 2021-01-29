void move(int n, char A, char B, char C)
{
	if (n == 1)
	{
		
		printf(" 从%c--->%c\n",  A, C);
		
	}
	else
	{
		move(n - 1, A, C, B);
	    
		printf(" 从%c--->%c\n",  A, C);

		move(n - 1, B, A, C);
	}
}


int main()
{
	int n = 0;
	int i = 0;
	printf("请输入您想要移动的块数:>");
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}