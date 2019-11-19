//Коптева Александра
#include<iostream>
#include <stdio.h> 
#include<stdlib.h>
#include <malloc.h>
#include<conio.h>
#define T  char

using namespace std;

// Опишем структуру узла списка 
struct TNode
{
	T value;
	struct TNode *next, *prev;
};
typedef struct TNode Node;
typedef  TNode *NodePtr;//указатель на узел

struct Stack
{
	Node *head;
	int size;
	int maxSize;
};
struct Stack Stack;

struct queue
{
	NodePtr head = NULL, tail = NULL;// начало и конец очереди(текущий эл-т)
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
	Node *tmp = (Node*)malloc(sizeof(Node));//создаем указатель на узел и выделяем для него место в памяти
	tmp->value = value;
	tmp->next = Stack.head;// записываем значение 
	Stack.head = tmp;// head вновь указывает на созданный эл-т
	Stack.size++; //увеличиваем количество эл-в в стеке
}

T pop() {
	if (Stack.size == 0)
	{
		printf("Stack is empty");
		return 0;
	}
	// Временный указатель 
	Node* tmp = NULL;
	// Значение «наверху» списка 
	T value;
	value = Stack.head->value;
	tmp = Stack.head;
	Stack.head = Stack.head->next;
	// Запись, на которую указывала «голова», удаляем, освобождая память 
	free(tmp);
	// Возвращаем значение, которое было в «голове» 
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
	printf("Введите число:");
	scanf_s("%d", &n);
	convertToBin(n);
	PrintStack();
}

/*
3. Написать  программу,  которая  определяет,  является  ли  введённая  скобочная
последовательность правильной. Примеры правильных скобочных выражений – (), ([])(), {}(),
([{}]), неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.

*/

void solution3()
{
	int i, j;
	char mas[100] = "{(2+2)*[3-7]]";
	char value;
	printf("%s\n", mas);
	//printf("Введите выражение:\n");
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
				printf("\nПара %c  и %c", value, mas[i]);
			}
			else {
				printf("\nНе пара %c  и %c", value, mas[i]);
			}
		}
		i++;
	}
}

//4. *Создать  функцию,  копирующую  односвязный  список  (то  есть  создающую  в  памяти  копию 
//односвязного списка без удаления первого списка).
void solution4()
{
}

//5 Задача
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
	// Выражение, разделенное пробелами (по одному пробелу!) 
	printf("%s\n", buf);
	T a;
	for (int i = 0; (buf[i] != '\0'); i++)
	{
		// Получаем элемент из строки 
		char el[20];                // Элемент (число или операция) 
		int j = 0;
		while (buf[i] != ' ' && buf[i] != '\0')
		{
			el[j] = buf[i];
			j++;
			i++;
		}
		el[j] = '\0';
		// Если элемент – число 
		if (isNumber(el))
			push(atoi(el));         // Кладём его в стек, преобразовав из  
									// строки в integer 
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
				printf("Некорректный ввод!\n");
			}
		}
	}
	printf("%d", pop());
}

//6. Реализовать очередь с использованием односвязного списка
//добавление в очередь
void PushTail(queue &Q, T value1)
{
	NodePtr p;
	p = new Node;     // выделение памяти для нового узела 
	p->value = value1;      // заполнение узла данными  
	p->prev = Q.tail; //указатель на конец списка
	p->next = NULL;  
	if (Q.tail)             // добавить узел в конец списка 
		Q.tail->next = p;
	Q.tail = p;
	if (!Q.head) Q.head = Q.tail;
}T PopQueue(queue &S)
{
	NodePtr top = S.head;
	T value2;
	if (!top)   // если очередь пуста, то 
	{
		printf("Нет эалеменотов, очередь пуста!\n");
		return 0;
	}
	value2 = top->value;
	S.head = top->next;
	if (S.head) S.head->prev = NULL; // переставить ссылки 
	else   S.tail = NULL;
	delete top; // освободить память 
	return value2;
}


void solution6()
{
	int N;
	printf("Введите число элементов очеред:\n");
	scanf_s("%d", &N);
	printf("Запись элементов очереди:\n");
	for (int i = 0; i < N; i++) {
		PushTail(Queue1, i);
		printf("%d ", i);
	}
	printf("\nИзвлечение элементов очеред:\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", PopQueue(Queue1));
	}
}


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	int number;
	do {
		printf("Выплненые задачи по номером 1,3,5,6.\n");
		printf("Введите номер задачи:\n");
		printf("Введите 0 для выхода из программы:\n");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1:
			printf("Задача - №1\n");
			solution1();
			break;
		case 3:
			printf("Задача - №3\n");
			solution3();
			break;
		case 5:
			printf("Задача - №5\n");
			solution5();
			break;
		case 6:
			printf("Задача - №6\n");
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