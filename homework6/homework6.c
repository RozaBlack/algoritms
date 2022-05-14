#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define Bin_numb int
#define SIZE 24
#define true 1 == 1
#define false 1 != 1

Bin_numb Numb[SIZE];
typedef int boolean;
int cursor = -1;

#define SZ 10
typedef struct {
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;
int end = -1;

boolean push(Bin_numb data) {
	if (cursor < SIZE) {
		Numb[++cursor] = data;
		return true;
	}
	else {
		printf("%s\n", "Stack overflow");
		return false;
	}
}

Bin_numb pop() {
	if (cursor != -1)
	{
		return Numb[cursor--];
	}
	else {
		printf("%s\n", "Stack is empty");
		return -1;
	}
}

void init() {
	for (int i = 0; i < SZ; ++i)
	{
		arr[i] = NULL;
	}
	head = 0;
	tail = 0;
	items = 0;
}

void printQueue() {
	printf("[ ");
	for (int i = 0; i < SZ; i++)
	{
		if (arr[i] == NULL) {
			printf(" [ *, * ] ");
		}
		else
		{
			printf(" [ %d, %d ] ", arr[i]->pr, arr[i]->dat);
		}
	}
	printf(" ]\n");
}

void ins1(int pr, int dat) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;
	if (items == SIZE)
	{
		printf("%s", "Queue is full");
	}
	else if(end == SIZE - 1)
	{
		end = -1;
	}
	arr[++end] = node;
	items++;
}

Node* rem1() {
	if (items == 0)
	{
		return NULL;
	}
	else
	{
		int i = 0;
		int idx = 0;
		int max = arr[0]->pr;
		for (i = 1; i < items; i++)
		{
			if (arr[i]->pr > max)
			{
				max = arr[i]->pr;
				idx = i;
			}
		}
		Node* tmp = arr[idx];
		while (idx < items)
		{
			arr[idx] = arr[idx+1];
			idx++;
		}
		arr[idx] = NULL;
		items--;
		end--;
		return tmp;
	}
}

int main()
{
	int decNumb = 0;
	printf("%s", "Enter number: ");
	scanf("%d", &decNumb);
	int exper;
	while (decNumb > 0) {
		exper = push(decNumb % 2);
		decNumb = decNumb >> 1;
	}

	while (cursor != -1)
	{
		printf("%d", pop());
	}
	printf("\n");

	init();
	ins1(1, 11);
	ins1(3, 22);
	ins1(4, 33);
	ins1(2, 44);
	ins1(3, 55);
	ins1(4, 66);
	ins1(5, 77);
	ins1(1, 88);
	ins1(2, 99);
	ins1(6, 100);
	printQueue();
	for (int i = 0; i < 7; ++i)
	{
		Node* n = rem1();
		printf("pr = %d, dat = %d \n", n->pr, n->dat);
	}
	printQueue();

	ins1(1, 110);
	ins1(2, 110);
	ins1(1, 110);
	printQueue();
	printf("Press any key to continue");
	_getch();

	return 0;
}
