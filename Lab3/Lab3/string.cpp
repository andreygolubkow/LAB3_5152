#include <iostream>
#include "string.h"

int GetLength(char * string)//Получаем длину строки
{
	if (&string != nullptr)
	{
		int count = 0;//Идем по строке пока не найдем терминальный ноль
		for (count = 0;(string[count] != '\0')&&(count<256);count++);
		return count;//Когда нашли возвращаем кол-во символов до него
	} 
	else
	{
		return -1;
	}
}

int IndexOf(char * string, char c)//Ищем символ в строке
{
	if (GetLength(string) > 0)
	{
		int pos = 0;
		for (pos = 0; (pos < 256) && (string[pos] != c);pos++);
		if (string[pos] == c)//Если нашли то возвращаем индекс
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

int LastIndexOf(char * string, char c)//Ищем символ с конца строки
{
	if (GetLength(string) > 0)
	{
		int pos = 0;
		for (pos = GetLength(string) - 1; (pos > 0) && (string[pos] != c);pos--);
		if (string[pos] == c)//проходим с конца строки все элементы пока не найдем символ
		{
			return pos;//возвращаем позицию символа
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
//получем подстроку
bool GetSubstring(char * string, char * substring, int startIndex, int substringLength)
{
	if ((GetLength(string) > (substringLength - startIndex))&(startIndex>-1)&(substringLength>0))
	{
		int j = 0;
		for (int i = startIndex;i < substringLength + startIndex;i++)
		{
			substring[j] = string[i]; //копируем символы со стартового индекса
			j++;
		}
		substring[j ] = '\0';//вконце ставим терм ноль
		return true;
	}
	else
	{
		return false;
	}
}
//Получаем имя файла
bool GetFilename(char * fullFilename, char * filename)
{
	int slashPos = 0;
	slashPos=LastIndexOf(fullFilename, '\\');//ищем последний слэш
	if ((!(GetLength(fullFilename) - 1 == slashPos))&(slashPos!=-1))
	{
		int dotPos = 0;
		dotPos = LastIndexOf(fullFilename, '.');

		if (dotPos != -1)
		{

			if (GetSubstring(fullFilename, filename, slashPos + 1, dotPos - slashPos - 1))
			{
				
				return true;
			}//Копируем текст от слэша жо точки
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
//получаем расширение файла
bool GetFileExtension(char * fullFilename, char * fileExtension)
{
		int dotPos = 0;
		dotPos = LastIndexOf(fullFilename, '.');//нашли точку

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
		}//копируем текст от точки до конца строки
	}

bool GetFilePath(char * fullFilename, char * filePath)//получаем путь
{
	int slashPos = 0;
	slashPos = LastIndexOf(fullFilename, '\\');//ищем слэш
	//копируем все от начала строки до слэша
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



 
void TestStr()//тестим
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
