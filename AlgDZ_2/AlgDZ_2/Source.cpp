// ������� ����������
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define N 20

using namespace std;

long convertToBin(long n)
{
	if (n == 0) return 0;
	else return convertToBin(n / 2) * 10 + n % 2;
}
//1. �����������  �������  ��������  �����  ��  ����������  �������  �  ��������,  ��������� ��������.
void solution1()
{
	long n;
	printf("������� �����:");
	scanf_s("%d", &n);
	printf("%d", convertToBin(n));
}
//2. ����������� ������� ���������� ����� a � ������� b :
//c. *����������, ��������� �������� �������� �������. 
int quickPow(int a, int b) {
	if (b == 0) return 1;
	else if (b % 2 == 0) a = quickPow(a, b / 2)*quickPow(a, b / 2);
	else  a = quickPow(a, b / 2)*quickPow(a, b / 2)*a;
	return a;
}

void solution2()
{
	int a, b;
	printf("������� ����� a:");
	scanf_s("%d", &a);
	printf("������� ������� ����� a:");
	scanf_s("%d", &b);
	printf("%d", quickPow(a, b));
}

/*3. **�����������  ������������  �����������  �����  �����,  ����������  ��  ������.  �
����������� ��� �������, ������ �������� �����:
	  1. ������� 1.
	  2. ������ �� 2.
������  �������  �����������  �����  ��  ������  ��  1,  ������  �����������  ���  �  2  ����.
����������, ������� ���������� ��������, ������� ����������� ����� 3 � ����� 20:
	  �. � �������������� �������.
	  b. *� �������������� ��������. */

int Rekur(int a, int b)
{
	//R[n]=R[n/2]+R[n-2]
	int result = 1;
	if (a < 4) {

		return 1;
	}
	else {
		if ((a >= 4) && (a % 2 == 0)) result = Rekur((a / 2), b) + Rekur((a - 2), b);
		else { result = Rekur(a, b); }
		a++;
	}
	return result;
}

int noRekur(int a, int b)
{
	//R[n]=R[n/2]+R[n-2]
	int mas[N];
	mas[0] = 1;
	mas[1] = 1;
	int i = 2;
	while (a <= b)
	{
		if (a % 2 == 0) mas[i] = mas[(a / 2)-1] + mas[(a-2)-1];
		else mas[i] = mas[i - 1];
		i++;
		a++;
	}
	//for (int j = 0; j < N;j++) printf("mas[%d]=%d\n", j, mas[j]);
	return mas[i - 1];
}


void solution3()
{
	int a = 3;
	int b = 20;
	printf("��� �������� c �������������� �������:\n");
	printf("���������� �������� %d, ������� ����������� ����� 3->20!\n", noRekur(a, b));
	printf("C ���������:\n");
	printf("���������� �������� %d, ������� ����������� ����� 3->20!\n", Rekur(a, b));
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	int number;
	do {
		printf("\n������� ����� ������:\n");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1: solution1();
			break;
		case 2: solution2();
			break;
		case 3: solution3();
			break;
		case 0: printf("Bey-bye!\n");
			break;
		default: printf("Wrong selected!\n");
		}
	} while (number != 0);
	system("pause");
	return 0;
}
