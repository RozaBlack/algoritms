#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

void decToBin(int a, char* binNum, int* binNumInt, int b) {
	if (a > 0) {
		decToBin(a/2, binNum, binNumInt, b+1);
		strcat(binNum, (a%2==0) ? "0" : "1");
		binNumInt[31 - b] = a%2;
	}
}

int aRaisTob(int a, int b) {
	if (b > 0) {
		return a * aRaisTob(a, b - 1);
	}
	return 1;
}

int aRaisTob2 (int a, int b) {
	if (b > 0) {
		if (b % 2 == 0)
		{
			return aRaisTob(a*a, b/2);
		}
		else
		{
			return a * aRaisTob(a, b - 1);
		}
	}
	return 1;
}

int routes(int x, int y, int desk[][6]) {
	if ((x == 0 && y == 0) || desk[y][x] == 1)
	{
		return 0;
	}
	else if ((x == 0) && desk[y][x] == 0)
	{
		if (y > 1)
		{
			return routes(x, y - 1, desk);
		}
		return 1;
	}
	else if ((y == 0) && desk[y][x] == 0)
	{
		if (x > 1)
		{
			return routes(x - 1, y, desk);
		}
		return 1;
	}
	else if ((x == 0 || y == 0) && desk[y][x] == 1)
	{
		return 0;
	}
		return routes(x - 1, y, desk) + routes(x, y - 1, desk);
}

int main() {
	//Task 1
	{
		printf("%s", "Enter a number: ");
		int a;
		char binNum[34] = "b'";
		int binNumInt[32] = {0};
		scanf("%d", &a);
		decToBin(a, binNum, binNumInt, 0);
		printf("%s\n", binNum);
		for(int i = 0; i < 32; i++) {
			printf("%d", binNumInt[i]);
		}
	}
	
	//Task 2
	{
		int a = 0;
		int b = 0;
		int res = 0;
		int res2 = 0;

		printf("\n%s", "Enter a: ");
		scanf("%d", &a);
		printf("%s", "Enter b: ");
		scanf("%d", &b);

		res = aRaisTob(a, b);
		printf("a^b = %d\n", res);

		res2 = aRaisTob2(a, b);
		printf("a^b = %d\n", res2);
	}
	
	//Task 3
	{
		const int sizeX = 6, sizeY = 6;
		int desk[6][6] = {{0, 0, 1, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 1, 1, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0},
										{0, 0, 0, 0, 0, 0}};

		for (int y = 0; y < sizeY; y++)
		{
			for (int x = 0; x < sizeX; x++)
			{
				printf("%5d", routes(x, y, desk));
			}
			printf("\n");
		}
	}
	
	return 0;
}
