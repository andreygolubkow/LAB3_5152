#include <iostream>
#include "string.h"

int GetLength(char * string)
{
	if (&string != nullptr)
	{
		int count = 0;
		for (count = 0;string[count] != '\0';count++);
		return count;
	} 
	else
	{
		return -1;
	}
}

void TestStr()
{
	char S[] = "TestStr";
	std::cout<<"\nTEST STR\nLength:"<<GetLength(S)<<"\n";
}
 