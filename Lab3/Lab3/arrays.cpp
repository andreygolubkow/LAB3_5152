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
}


