// laba282.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _WIN32_WINNT 0x0500
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <sddl.h>
void main(void) {
	DWORD TokenUserBufSize = 256;
	LPTSTR StringSid;
	TOKEN_USER* ptUser;
	HANDLE hHeap;
	HANDLE hToken = NULL;
	hHeap = GetProcessHeap();
	ptUser = (TOKEN_USER*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, TokenUserBufSize);
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
		printf("OpenProcessToken Error\n");
	if (!GetTokenInformation(hToken, // описатель маркера доступа
		TokenUser, // нужна информация о пользователе
		ptUser, // буфер для информации
		TokenUserBufSize, &TokenUserBufSize))
		printf("GetTokenInformation Error\n");;

	if (!ConvertSidToStringSid(ptUser->User.Sid, &StringSid))
		printf("Convert SID to string SID failed.");
	wprintf(L"StringSid %s\n", StringSid);
	CloseHandle(hToken);
	LocalFree(StringSid);
	HeapFree(hHeap, 0, ptUser);
}