#pragma once

int GetLength(char* string);
void TestStr();
int IndexOf(char* string, char c);
int LastIndexOf(char* string, char c);
bool GetSubstring(char*	string, char* substring, int startIndex, int substringLength);
bool GetFilename(char* fullFilename, char* filename);
bool GetFileExtension(char* fullFilename, char* fileExtension);
bool GetFilePath(char* fullFilename, char* filePath);