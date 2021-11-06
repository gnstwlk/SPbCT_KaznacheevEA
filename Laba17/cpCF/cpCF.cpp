#include "EvryThng.h"
#include <windows.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, LPTSTR argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		printf("Использование: cpCF file1 file2\n");
		return 1;
	}

	if (!CopyFile(argv[1], argv[2], FALSE))
	{
		printf("Ошибка CopyFile: %x\n", GetLastError());
		return 2;
	}
	return 0;
}