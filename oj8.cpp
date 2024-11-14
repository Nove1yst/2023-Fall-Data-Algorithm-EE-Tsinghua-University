# define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 4 //四阶拉丁
int a[N][N];
void Latin(int row, int n);
int check(int row, int column, int n);
void print(int a[][N]);

int main(){
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = 0;//方阵初始化
	Latin(0, 1);//从元素 1 开始
}

void Latin(int row, int n)
{
	int i;
	if (n > N)//所有N个元素都完成放置，输出方阵
	{
		print(a);
		return;
	}
	if (row > N - 1)//元素 n 完成放置，开始放置下一元素
	{
		Latin(0, n + 1);
		return;
	}
	else//下面这一坨和八皇后基本完全一样
		for (i = 0; i < N; i++)
		{
			if (check(row, i, n))
			{
				a[row][i] = n;
				Latin(row + 1, n);
				a[row][i] = 0;
			}

		}

}

int check(int row, int column, int n)//检查在该位置放置 n 是否合法
{
	int i;
	if (a[row][column] != 0)	//有元素在该位置
		return 0;
	for (i = 0; i < N; i++)
		if (a[row][i] == n)//行上已存在n
			return 0;
	for (i = 0; i < N; i++)
		if (a[i][column] == n)//列上已存在n
			return 0;
	return 1;
}
void print(int a[][N])//方阵输出函数
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
}
