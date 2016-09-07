#include "arrays.h"


void Sort(double * array, int arrayLength)
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

void fillArray(double * array, int arrayLength)
{
	
}


