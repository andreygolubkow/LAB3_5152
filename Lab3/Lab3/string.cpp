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
	if ((GetLength(string) > (substringLength - startIndex))&(startIndex>-1)&(substringLength>0))
	{
		int j = 0;
		for (int i = startIndex;i < substringLength + startIndex;i++)
		{
			substring[j] = string[i];
			j++;
		}
		substring[j ] = '\0';
		return true;
	}
	else
	{
		return false;
	}
}

bool GetFilename(char * fullFilename, char * filename)
{
	int slashPos = 0;
	slashPos=LastIndexOf(fullFilename, '\\');
	if ((!(GetLength(fullFilename) - 1 == slashPos))&(slashPos!=-1))
	{
		int dotPos = 0;
		dotPos = LastIndexOf(fullFilename, '.');

		if (dotPos != -1)
		{

			if (GetSubstring(fullFilename, filename, slashPos + 1, dotPos - slashPos - 1))
			{
				
				return true;
			}
			else
			{	
				filename = nullptr;
				return false;
		
			}
		}
		else
		{
			
			filename = nullptr;
			return false;
		}
	}
	else
	{
		filename = nullptr;
		return false;
	}
}

bool GetFileExtension(char * fullFilename, char * fileExtension)
{
		int dotPos = 0;
		dotPos = LastIndexOf(fullFilename, '.');

		if ((dotPos != -1)&&(GetLength(fullFilename)>0)&&(GetLength(fullFilename)!=dotPos+1))
		{

			if (GetSubstring(fullFilename, fileExtension, dotPos + 1, GetLength(fullFilename)-dotPos-1))
			{

				
				fileExtension = nullptr;
				return true;
			}
			else
			{
				
				fileExtension = nullptr;
				return false;
			}
		}
		else
		{
			
			fileExtension = nullptr;
			return false;
		}
	}

bool GetFilePath(char * fullFilename, char * filePath)
{
	int slashPos = 0;
	slashPos = LastIndexOf(fullFilename, '\\');

	if ((slashPos != -1) && (GetLength(fullFilename)>0) && (GetLength(fullFilename) != slashPos + 1))
	{

		if (GetSubstring(fullFilename, filePath, 0, slashPos ))
		{


			return true;
		}
		else
		{

			filePath = nullptr;
			return false;
		}
	}
	else
	{

		filePath = nullptr;
		return false;	
	}
	return false;
}



 
void TestStr()
{
	char S[] = "TestStr\0";
	char s[255]="";
	std::cout << "\nTestStr\nLength:" << GetLength(S) << "\n";
	std::cout << "pos 't' = " << IndexOf(S, 't')<<"\n";
	std::cout << "LastPos 't' = " << LastIndexOf(S, 't') << "\n";
	GetSubstring(S, s, 2, 4);
	std::printf("\n%s\n", s);
	std::cout << "\nPATH: c:\\progrrams\\input.exe\n";
	GetFilename("c:\\progrrams\\input.exe", s);
	std::printf("\n%s", s);
	GetFileExtension("c:\\progrrams\\input.exe", s);
	std::printf("\n%s", s);
	GetFilePath("c:\\progrrams\\input.exe", s);
	std::printf("\n%s", s);

}
