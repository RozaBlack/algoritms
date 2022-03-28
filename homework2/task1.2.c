#include <stdio.h>
#include <malloc.h>
#include <math.h>

int main() {
	printf("%s", "Enter a number: ");
	int a;
	int k = 0;
	int res = 0;
	int* A;
	scanf("%d", &a);

	if (a>=1 && a<=3)
	{
		printf("\n%s ", "a is a prime number");
	}
	else
	{
		int b = round(sqrt(a));
		A = (int*)malloc((b+1) * sizeof(int));

		for (int i = 0; i <= b; i++) {
			A[i] = i + 2;
			printf("%d ", A[i]);
		}

		for (int N = 2; N <= b +1; N++) {
			if (A[N-2] != 0) {
				k = N + N;
				while (k <= b+1) {
					A[k-2] = 0;
					k += N;
				}
			}
		}
		printf("\n");
		for (int N = 0; N < b; N++) {
			printf("%d ", A[N]);
		}

		for (int i = 0; i <= b; i++)
		{
			if (A[i] != 0)
			{
				if (a % A[i] == 0)
				{
					res = 1;
					break;
				}
			}
		}

		if (res == 0)
		{
			printf("\n%s ", "a is a prime number");
		}
		else
		{
			printf("\n%s ", "a is not a prime number");
		}

		free(A);
		getchar();
	}
	return 0;
}