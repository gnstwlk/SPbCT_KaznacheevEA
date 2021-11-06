#include "EvryThng.h"
#include <Windows.h>
#include <process.h>
#include <stdarg.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 256
int main(int argc, LPTSTR argv[])
{
	setlocale(LC_ALL, "rus");
	HANDLE hIn, hOut;
	DWORD nIn, nOut;
	CHAR Buffer[BUF_SIZE];
	if (argc != 3)
	{
		printf("Использование: CpW file1 File2\n");
		return 1;
	}

	hIn = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE)
	{
		printf("Нельзя открыть входной файл.Ошибка:%x\n", GetLastError());
		return 2;
	}

	hOut = CreateFile(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE)
	{
		printf("Нельзя открыть выходной файл.Ошибка: %x\n", GetLastError());
		return 3;
	}
	
	while (ReadFile(hIn, Buffer, BUF_SIZE, &nIn, NULL) && nIn > 0)
	{
		WriteFile(hOut, Buffer, nIn, &nOut, NULL);
		if (nIn != nOut)
		{
			printf("Неисправимая ошибка записи : %x\n", GetLastError());
			return 4;
		}
		
	}
	CloseHandle(hIn);
	CloseHandle(hOut);
	return 0;
}