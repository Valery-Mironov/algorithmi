//Коптева Александра
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <ctime>

#define MaxN 10

using namespace std;

//ф-ция для обмена значений ячеек
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
// Распечатываем массив 
void print(int N, int *a)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

//ф-ция "шейкер"-сортировки
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
	cout << "\nИтераций: " << leftMark - 1 << endl; // просмотр количества итераций
}
//Пузырьковая сортировка 
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
	cout << "\nИтераций: " << count << endl; // просмотр количества итераций
}

//Сортировка вставками
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
	cout << "\nИтераций: " << count << endl; // просмотр количества итераций
}
//Бинарный поиск
int BiSearch(int *a, int N)
{
	int value;
	printf("Введите число которое хотите найти:\n");
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
	//// Создаём массив максимального размера 
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
	puts("\nНеотсортированный массив\n");
	print(N, a);
	int number;
	unsigned int time1, time2, time3, time4, time5, time6;
	unsigned int search_time1, search_time2, search_time3;

	do {
		printf("\nВведите номер метода сортировки.\n");
		printf("1 - Пузырьковая сортировка\n");
		printf("2 - \"Шейкер\"-сортировка\n");
		printf("3 - Сортировка вставкой\n");
		printf("0 - Введите для выхода из программы");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1: printf("Пузырьковая сортировка.\n");
			time1 = clock(); // начальное время
			sortP(a, N);
			time2 = clock(); // конечное время
			search_time1 = time2 - time1; // искомое время
			print(N, a);
			printf("Время работы алгоритма:%d", search_time1);
			break;
		case 2:
			puts("\"Шейкер\"-сортировка");
			time3 = clock(); // начальное время
			ShakerSort(a, N);
			time4 = clock(); // конечное время
			search_time2 = time4 - time3; // искомое время
			print(N, a);
			printf("Время работы алгоритма:%d", search_time2);
			break;
		case 3:
			puts("Сортировка вставкой");
			time5 = clock(); // начальное время
			insert(a, N);
			time6 = clock(); // конечное время
			search_time3 = time6 - time5; // искомое время
			print(N, a);
			printf("Время работы алгоритма:%d", search_time3);
			break;
		case 0: printf("Bey-bye!\n");
			break;
		default: printf("Wrong selected!\n");
		}
	} while (number != 0);
	printf("Бинарный алгоритм поиска.\n");
	BiSearch(a, N);
	system("pause");
	return 0;
}