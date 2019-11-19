//Коптева Александра
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define N 3 
#define M 3 

using namespace std;
int map[N][M] = { {1, 1, 1}, {0, 1, 0}, {0, 1, 0} }; //карта маршрута

void Print(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
//1.  *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.

int W(int K, int P)
{
	int i, j;
	int A[N][M] = { 0 };
	for (i = 0; i < K; i++) {
		if (map[0][i] == 0)  A[0][i] = 0;
		else if (A[0][i-1]==0) A[0][i] = 0;
		else A[0][i] = 1;
	}
	for (i = 1; i < K; i++) {
		if (map[i][0] == 0) A[i][0] = 0;
		else if (A[i - 1][0] == 0) A[i][0] = 0;
		else A[i][0] = 1;
		for (j = 1; j < P; j++)
		{
			if (map[i][j] == 0) A[i][j] = 0;  
			else  A[i][j] = A[i][j - 1] + A[i - 1][j]; // W(i - 1, j) + W(i, j - 1);
		}
	}
	Print(N, M, A);
	return 0;
}

//2.  Решить  задачу  о  нахождении  длины  максимальной  подпоследовательности  с  помощью матрицы.
int lcs_length(char * A, char * B)
{
	if (*A == '\0' || *B == '\0') return 0;
	else if (*A == *B) return 1 + lcs_length(A + 1, B + 1);
	else return max(lcs_length(A + 1, B), lcs_length(A, B + 1));
}


int main(int argc, char *argv[])
{
	char  A, B;
	A = '3285';
	B = '3258';
	W(N, M);
	printf("%d", lcs_length( &A,&B));
	system("pause");
	return 0;
}
