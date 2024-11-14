# define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 4 //�Ľ�����
int a[N][N];
void Latin(int row, int n);
int check(int row, int column, int n);
void print(int a[][N]);

int main(){
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = 0;//�����ʼ��
	Latin(0, 1);//��Ԫ�� 1 ��ʼ
}

void Latin(int row, int n)
{
	int i;
	if (n > N)//����N��Ԫ�ض���ɷ��ã��������
	{
		print(a);
		return;
	}
	if (row > N - 1)//Ԫ�� n ��ɷ��ã���ʼ������һԪ��
	{
		Latin(0, n + 1);
		return;
	}
	else//������һ��Ͱ˻ʺ������ȫһ��
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

int check(int row, int column, int n)//����ڸ�λ�÷��� n �Ƿ�Ϸ�
{
	int i;
	if (a[row][column] != 0)	//��Ԫ���ڸ�λ��
		return 0;
	for (i = 0; i < N; i++)
		if (a[row][i] == n)//�����Ѵ���n
			return 0;
	for (i = 0; i < N; i++)
		if (a[i][column] == n)//�����Ѵ���n
			return 0;
	return 1;
}
void print(int a[][N])//�����������
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
