#include "arrays.h"
#include <iostream>
#include <ctime>

void Sort(double * array, int arrayLength) //sort array
{
	for (int i = 0;i < arrayLength;i++)
		for (int j = i;j < arrayLength;j++)
		{
			if (array[j] < array[i])
			{
				double tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}

}

void Fill(double * array, int arrayLength)
{
	srand(time(0));
	for (int i = 0;i < arrayLength;i++)
		array[i] = rand() % 20;
}


bool MultiplyMatrices(int ** matrixA, int aRows, int aCols, int ** matrixB, int bRows, int bCols, int ** resultMatrix)
{
	
	if (!(aRows > 0 || aCols > 0 || bRows > 0 || bRows > 0 || aCols == bRows))
	{
		return false;
	}
	else
	{

		int k = 0;
		for (int i = 0; i<aRows; i++)
			for (int j = 0; j<bCols; j++)
				for (resultMatrix[i][j] = 0, k = 0; k<aCols; k++)
					resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
		std::cout << "\n";
	for (int i = 0;i < aRows;i++)
		{
			for (int j = 0;j < bCols;j++)
				std::cout << resultMatrix[i][j]<<"\t";
			std::cout << "\n";
		}


	}

}


void TestArray()
{
	srand(time(0));
	int size = 0;
	size = rand() % 10 + 2;
	double *arr = new double[size];
	Fill(arr, size);
	for (int i = 0;i < size;i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
	Sort(arr, size);
	for (int i = 0;i < size;i++)
		std::cout << arr[i] << " ";
	delete[] arr;
	int N = 3;
	int M = 2;
	int L = 5;
	int **aM = new int *[N];
	for (int i = 0; i<N; i++)
		aM[i] = new int[M];
	int **bM = new int *[M];
	for (int i = 0; i<M; i++)
		bM[i] = new int[L];
	int **cM = new int *[N];
	for (int i = 0; i<N; i++)
		cM[i] = new int[L];
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++)
			aM[j][i] = rand() % 10;
		for (int j = 0;j < L;j++)
			bM[i][j] = rand() % 10;
	}
	std::cout << "\nMatrix A \n";
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
			std::cout << aM[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\nMatrix B \n";
	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < L;j++)
			std::cout << bM[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\nMatrix x Matrix";
	MultiplyMatrices(aM, N, M, bM, M,L, cM);
	for (int i = 0; i<N; i++)
		delete[] aM[i];
	delete[]aM;
	for (int i = 0; i<M; i++)
		delete[] bM[i];
	delete[] bM;
	for (int i = 0; i<N; i++)
		delete[] cM[i];
	delete[]cM;
}
