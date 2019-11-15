//������� ����������
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <ctime>

#define MaxN 10

using namespace std;

//�-��� ��� ������ �������� �����
void swapEl(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}
void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
// ������������� ������ 
void print(int N, int *a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

//�-��� "������"-����������
void ShakerSort(int *arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;
	}
	cout << "\n��������: " << leftMark - 1 << endl; // �������� ���������� ��������
}
//����������� ���������� 
void sortP(int *a, int N)
{
	int i, j, count = 0;
	for (i = 0; i < N; i++)
		count++;
		for (j = 0; j < N - 1; j++)
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				count++;
			}
	cout << "\n��������: " << count << endl; // �������� ���������� ��������
}

//���������� ���������
 void insert(int *a, int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = a[i];
		int j = i;
		count++;
		while (j > 0 && a[j - 1] > temp)
		{
			swap(&a[j], &a[j - 1]);
			j--;
			count++;
		}
	}
	cout << "\n��������: " << count << endl; // �������� ���������� ��������
}
//�������� �����
int BiSearch(int *a, int N)
{
	int value;
	printf("������� ����� ������� ������ �����:\n");
	scanf_s("%d", &value);
	int L = 0, R = N - 1;
	int m = L + static_cast<int>((R - L) / 2);
	while (L <= R && a[m] != value)
	{
		if (a[m] < value)
			L = m + 1;
		else
			R = m - 1;
		m = L + (R - L) / 2;
	}
	if (a[m] == value)
		printf("Index:%d Value:%d", m, a[m]);
	else
		printf("Value not found");

	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int a[MaxN];
	int N = MaxN;
	//int N;
	//// ������ ������ ������������� ������� 
	//FILE *in;
	//fopen_s(&in, "data.txt", "r");
	//fscanf_s(in, "%d", &N);
	//int i;
	//for (i = 0; i < N; i++)
	//{
	//	fscanf_s(in, "%i", &a[i]);
	//}
	//fclose(in);
	for (int i = 0; i < N; i++) a[i] = rand() % 100 - 50;
	puts("\n����������������� ������\n");
	print(N, a);
	int number;
	unsigned int time1, time2, time3, time4, time5, time6;
	unsigned int search_time1, search_time2, search_time3;

	do {
		printf("\n������� ����� ������ ����������.\n");
		printf("1 - ����������� ����������\n");
		printf("2 - \"������\"-����������\n");
		printf("3 - ���������� ��������\n");
		printf("0 - ������� ��� ������ �� ���������");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1: printf("����������� ����������.\n");
			time1 = clock(); // ��������� �����
			sortP(a, N);
			time2 = clock(); // �������� �����
			search_time1 = time2 - time1; // ������� �����
			print(N, a);
			printf("����� ������ ���������:%d", search_time1);
			break;
		case 2:
			puts("\"������\"-����������");
			time3 = clock(); // ��������� �����
			ShakerSort(a, N);
			time4 = clock(); // �������� �����
			search_time2 = time4 - time3; // ������� �����
			print(N, a);
			printf("����� ������ ���������:%d", search_time2);
			break;
		case 3:
			puts("���������� ��������");
			time5 = clock(); // ��������� �����
			insert(a, N);
			time6 = clock(); // �������� �����
			search_time3 = time6 - time5; // ������� �����
			print(N, a);
			printf("����� ������ ���������:%d", search_time3);
			break;
		case 0: printf("Bey-bye!\n");
			break;
		default: printf("Wrong selected!\n");
		}
	} while (number != 0);
	printf("�������� �������� ������.\n");
	BiSearch(a, N);
	system("pause");
	return 0;
}