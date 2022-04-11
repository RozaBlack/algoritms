#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

void arrFill(int* arr, int len) {
		for (int i = 0; i < len; i++)
		{
			arr[i] = rand() % (100) + 1;
		}
}

void printArr(int* arr, int len) {
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void changeEl(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void sortInserts(int* arr, int len) {
	int temp, pos;
	for (int i = 0; i < len; i++)
	{
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

void qs(int* arr, int first, int last) {
	int i = first, j = last;
	int x = arr[(first + last) >> 1];
	do
	{
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			changeEl(&arr[i], &arr[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (i < last) { qs(arr, i, last); }
	if (first < j) { qs(arr, first, j); }
}

void qsImp(int* arr, int first, int last) {
	int i = first, j = last;
	int central = 0;
	if (j - i <= 10)
	{
		sortInserts(arr, j - i);
	}
	else
	{
		central = (j - i) >> 1;
		if (arr[i] > arr[central])
		{
			changeEl(&arr[i], &arr[central]);
		}
		else if (arr[central] > arr[j])
		{
			changeEl(&arr[j], &arr[central]);
		}
		qs(arr, 0, j - i);
	}
}

void bucketSort(int* arr, int len) {
	const int max = len;
	const int b = 10;

	int buckets[b][max + 1];
	for (int i = 0; i < b; i++)
	{
		buckets[i][max] = 0;
	}

	for (int digit = 1; digit < 100000000; digit*=10)
	{
		for (int i = 0; i < max; i++)
		{
			if (arr[i] % 2 == 0)
			{
				int d = (arr[i] / digit) % b;
				buckets[d][buckets[d][max]++] = arr[i];
			}
		}
		
		int idx = 0;
		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < buckets[i][max]; ++j)
			{
				if (arr[idx] % 2 == 0) {
					arr[idx] = buckets[i][j];
					idx++;
				}
				else {
					--j;
					idx++;
				}
			}
			buckets[i][max] = 0;
		}
	}

}

int main()
{
	unsigned int len = 0;
	int* arr;
	printf("Enter size of matrix: ");
	scanf("%d", &len);

	arr = (int*)malloc(len * sizeof(int));

	arrFill(arr, len);
	printArr(arr, len);
	qsImp(arr, 0, len - 1);
	printArr(arr, len);
	printf("\n");
	
	/*int arr1[12] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
	int len1 = 12;
	printArr(arr1, len1);
	bucketSort(arr1, len1);
	printArr(arr1, len1);*/
	
	arrFill(arr, len);
	printArr(arr, len);
	bucketSort(arr, len);
	printArr(arr, len);
	printf("\n");

	free(arr);
}
