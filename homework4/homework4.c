#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

void arrFill(int **arr, int sizeX, int sizeY) {
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			arr[i][j] = rand() % (100) + 1;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void arr1Fill(int** arr, int* arr1, int sizeX, int sizeY) {
	int n = 0;
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			arr1[n] = arr[i][j];
			n++;
		}
	}
}

void changeEl(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void changeElFloat(float* a, float* b) {
	float c = *a;
	*a = *b;
	*b = c;
}

void arrSort(int** arr, int* arr1, int sizeX, int sizeY) {
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			arr[i][j] = arr1[j + i * sizeY];
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bubbleSort(int* arr, int sizeArr1) {
	int saveEl = 0;
	for (int i = 0; i < sizeArr1; i++)
	{
		for (int j = 0; j < sizeArr1-i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				changeEl(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void arrFillMan(float* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		printf("Enter %d number:", i);
		scanf("%f", &arr[i]);
	}
}

void invertArr(float* arr, int arrSize) {
	int size = arrSize >> 1;
	for (int i = 0; i < size; i++)
	{
		changeElFloat(&arr[i], &arr[arrSize - i  - 1]);
	}
}
r
void arrCalc(float* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		if (arr[i] > 400)
		{
			printf("Number %d conversation result is %.3f and it is greater than 400\n", i, arr[i]);
		}
	}
}

int main() {
	{
		// Task 1 - Я не была уверена, как именно надо было делать сортировку. Как сортировать двумерный массив
		// придумать не получилось, поэтому, двумерный массив переписывала в одномерный, сортировала и переписывала обратно.
		// Не уверена, можно ли было так делать. Можно было не создавать двумерный массив, просто получать размеры, сразу
		// находить общее число ячеек и создавать одномерный массив такой длины, сортировать его и выводить на экран
		// так, что бы это выглядело как двумерный массив.
		unsigned int sizeX = 0, sizeY = 0;
		int** arr;
		int* arr1;
		int sizeArr1 = 0;
		unsigned int i;
		printf("Enter size of matrix: ");
		scanf("%d %d", &sizeY, &sizeX);
		sizeArr1 = sizeX * sizeY;

		arr = (int**)malloc(sizeX * sizeof(int*));
		arr1 = (int*)malloc(sizeArr1 * sizeof(int));
		for (i = 0; i < sizeX; i++)
		{
			arr[i] = (int*)malloc(sizeY * sizeof(int));
		}

		arrFill(arr, sizeX, sizeY);
		arr1Fill(arr, arr1, sizeX, sizeY);
		bubbleSort(arr1, sizeArr1);
		arrSort(arr, arr1, sizeX, sizeY);

		for (i = 0; i < sizeX; i++)
		{
			free(arr[i]);
		}
		free(arr);
		free(arr1);
	}

	{ //Task 2
		const int arrSize = 11;
		float arr[11] = { 0.0 };
		arrFillMan(arr, arrSize);
		invertArr(arr, arrSize);
		arrCalc(arr, arrSize);
		
	}

	return 0;
}
