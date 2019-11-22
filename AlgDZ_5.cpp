//������� ����������
#include<iostream>
#include <stdio.h> 
#include<stdlib.h>
#include <malloc.h>
#include<conio.h>
#define T  char

using namespace std;

// ������ ��������� ���� ������ 
struct TNode
{
	T value;
	struct TNode *next, *prev;
};
typedef struct TNode Node;
typedef  TNode *NodePtr;//��������� �� ����

struct Stack
{
	Node *head;
	int size;
	int maxSize;
};
struct Stack Stack;

struct queue
{
	NodePtr head = NULL, tail = NULL;// ������ � ����� �������(������� ��-�)
	int size;
	int maxSize;
};
struct queue Queue;
struct queue Queue1;

void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
		printf("Error stack size");
		exit(1);
	}
	Node *tmp = (Node*)malloc(sizeof(Node));//������� ��������� �� ���� � �������� ��� ���� ����� � ������
	tmp->value = value;
	tmp->next = Stack.head;// ���������� �������� 
	Stack.head = tmp;// head ����� ��������� �� ��������� ��-�
	Stack.size++; //����������� ���������� ��-� � �����
}

T pop() {
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return 0;
	}
	// ��������� ��������� 
	Node* tmp = NULL;
	// �������� �������� ������ 
	T value;
	value = Stack.head->value;
	tmp = Stack.head;
	Stack.head = Stack.head->next;
	// ������, �� ������� ��������� �������, �������, ���������� ������ 
	free(tmp);
	// ���������� ��������, ������� ���� � ������� 
	Stack.size--;
	return value;
}


void PrintStack()
{
	Node *current = Stack.head;
	while (current != NULL)
	{
		printf("%d", current->value);
		current = current->next;
	}
}

void convertToBin(int n)
{
	int result = 0;
	do {
		result = n % 2;
		push(result);
		n /= 2;
	} while (n != 0);
}
void solution1()
{
	int n;
	Stack.maxSize = 100;
	Stack.head = NULL;
	printf("������� �����:");
	scanf_s("%d", &n);
	convertToBin(n);
	PrintStack();
}

/*
3. ��������  ���������,  �������  ����������,  ��������  ��  ��������  ���������
������������������ ����������. ������� ���������� ��������� ��������� � (), ([])(), {}(),
([{}]), ������������ � )(, ())({), (, ])}), ([(]), ��� ������ � [, (, {.

*/

void solution3()
{
	int i, j;
	char mas[100] = "{(2+2)*[3-7]]";
	char value;
	printf("%s\n", mas);
	//printf("������� ���������:\n");
	//scanf_s("%s", &mas);

	i = 0;
	while (mas[i] != '\0') {
		if (mas[i] == '[' || mas[i] == '(' || mas[i] == '{')
		{
			push(mas[i]);
		}
		else if (mas[i] == ']' || mas[i] == ')' || mas[i] == '}')
		{
			value = pop();
			if ( ((mas[i] == ']') &&(value=='['))  || ((mas[i] == ')') && (value == '(')) || ((mas[i] == '}') && (value == '{'))) 
			{
				printf("\n���� %c  � %c", value, mas[i]);
			}
			else {
				printf("\n�� ���� %c  � %c", value, mas[i]);
			}
		}
		i++;
	}
}

//4. *�������  �������,  ����������  �����������  ������  (��  ����  ���������  �  ������  ����� 
//������������ ������ ��� �������� ������� ������).
void solution4()
{
}

//5 ������
int isNumber(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		if (!isdigit(str[i++]))
			return 0;
	return 1;
}

void solution5()
{
	int res = 0;
	// 2+2 = 2 2 + 
	// (2+2)*2=2 2 + 2 * 
	char buf[100] = "20 30 - 10 *"; // (20-30)*10 
	printf("Input postfix expression:");
	// ���������, ����������� ��������� (�� ������ �������!) 
	printf("%s\n", buf);
	T a;
	for (int i = 0; (buf[i] != '\0'); i++)
	{
		// �������� ������� �� ������ 
		char el[20];                // ������� (����� ��� ��������) 
		int j = 0;
		while (buf[i] != ' ' && buf[i] != '\0')
		{
			el[j] = buf[i];
			j++;
			i++;
		}
		el[j] = '\0';
		// ���� ������� � ����� 
		if (isNumber(el))
			push(atoi(el));         // ����� ��� � ����, ������������ ��  
									// ������ � integer 
		else
		{
			switch (el[0])
			{
			case '+':
				res = pop() + pop();
				push(res);
				break;
			case '-':
				res = -pop() + pop();
				push(res);
				break;
			case '*':
				res = pop() * pop();
				push(res);
				break;
			case '/':
				a = pop();
				res = pop() / a;
				push(res);
				break;
			default:
				printf("������������ ����!\n");
			}
		}
	}
	printf("%d", pop());
}

//6. ����������� ������� � �������������� ������������ ������
//���������� � �������
void PushTail(queue &Q, T value1)
{
	NodePtr p;
	p = new Node;     // ��������� ������ ��� ������ ����� 
	p->value = value1;      // ���������� ���� �������  
	p->prev = Q.tail; //��������� �� ����� ������
	p->next = NULL;  
	if (Q.tail)             // �������� ���� � ����� ������ 
		Q.tail->next = p;
	Q.tail = p;
	if (!Q.head) Q.head = Q.tail;
}T PopQueue(queue &S)
{
	NodePtr top = S.head;
	T value2;
	if (!top)   // ���� ������� �����, �� 
	{
		printf("��� �����������, ������� �����!\n");
		return 0;
	}
	value2 = top->value;
	S.head = top->next;
	if (S.head) S.head->prev = NULL; // ����������� ������ 
	else   S.tail = NULL;
	delete top; // ���������� ������ 
	return value2;
}


void solution6()
{
	int N;
	printf("������� ����� ��������� ������:\n");
	scanf_s("%d", &N);
	printf("������ ��������� �������:\n");
	for (int i = 0; i < N; i++) {
		PushTail(Queue1, i);
		printf("%d ", i);
	}
	printf("\n���������� ��������� ������:\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", PopQueue(Queue1));
	}
}


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	int number;
	do {
		printf("��������� ������ �� ������� 1,3,5,6.\n");
		printf("������� ����� ������:\n");
		printf("������� 0 ��� ������ �� ���������:\n");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1:
			printf("������ - �1\n");
			solution1();
			break;
		case 3:
			printf("������ - �3\n");
			solution3();
			break;
		case 5:
			printf("������ - �5\n");
			solution5();
			break;
		case 6:
			printf("������ - �6\n");
			solution6();
			break;
		case 0: printf("Bey-bye!\n");
			break;
		default: printf("Wrong selected!\n");
		}
	} while (number != 0);

	system("pause");
	return 0;
}