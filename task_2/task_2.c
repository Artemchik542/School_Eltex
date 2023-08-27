#include <stdio.h>

#define LENGTH_1 3
#define LENGTH_2 5


void printMatrix(int matrix[][LENGTH_1], const int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			matrix[i][j] = i * length + j + 1;
		}

	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void printArray(int vector[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		vector[i] = i + 1;
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d ", vector[i]);
	}
	for (int i = 0; i < length / 2; i++)
	{
		int temp = vector[i];
		vector[i] = vector[length - i - 1];
		vector [length - i - 1] = temp;
	}
	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
	printf("\n");
}

void printTriangularMatrix(int matrix[][LENGTH_1], int const length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if(i + j >= length - 1)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}

	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void printSpiralMatrix(int matrix[][LENGTH_2], int const length)
{
	
	int count = 1;
	int up_l = 0, up_r = 0;
	int down_l = 0, down_r = 0;
	int i = 0, j = 0;

	while(count <= length * length)
	{
		matrix[i][j] = count;
		if (i == up_l && j < length - down_r - 1)
			++j;
		else if (j == length - down_r - 1 && i < length - up_r - 1)
			++i;
		else if (i == length - up_r - 1 && j > down_l)
			--j;
		else
			--i;

		if ((i == up_l + 1) && (j == down_l) 
				&& (down_l != length - down_r - 1))
		{
			++up_l;
			++up_r;
			++down_l;
			++down_r;
		}
		count++;
	}
	printf("\n");
	
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}

}


int main()
{
	int number = 0xDDCCBBAA;
	int vector[LENGTH_2];
	int matrix[LENGTH_1][LENGTH_1];
	int large_matrix[LENGTH_2][LENGTH_2];
	
	
	printMatrix(matrix, LENGTH_1);
	printArray(vector, LENGTH_2);
	printTriangularMatrix(matrix, LENGTH_1);
	printSpiralMatrix(large_matrix, LENGTH_2);

	return 0;
}
