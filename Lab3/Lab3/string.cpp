#include <iostream>
#include "string.h"

int GetLength(char * string)
{
	if (&string != nullptr)
	{
		int count = 0;
		for (count = 0;(string[count] != '\0')&&(count<256);count++);
		return count;
	} 
	else
	{
		return -1;
	}
}

int IndexOf(char * string, char c)
{
	if (GetLength(string) > 0)
	{
		int pos = 0;
		for (pos = 0; (pos < 256) && (string[pos] != c);pos++);
		if (string[pos] == c)
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

int LastIndexOf(char * string, char c)
{
	if (GetLength(string) > 0)
	{
		int pos = 0;
		for (pos = GetLength(string) - 1; (pos > 0) && (string[pos] != c);pos--);
		if (string[pos] == c)
		{
			return pos;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

bool GetSubstring(char * string, char * substring, int startIndex, int substringLength)
{
	return false;
}
 
void TestStr()
{
	char S[] = "TestStr\0";
	std::cout << "\nTestStr\nLength:" << GetLength(S) << "\n";
	std::cout << "pos 't' = " << IndexOf(S, 't')<<"\n";
	std::cout << "LastPos 't' = " << LastIndexOf(S, 't') << "\n";

}
