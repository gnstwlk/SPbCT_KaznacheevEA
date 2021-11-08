#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include "ntsecapi.h"
BOOL GetUserSID(TOKEN_USER*, PDWORD pdwSize);
void main(void) {
	PSID pSid;
	DWORD TokenUserBufSize = 256;
	TOKEN_USER* pUser;
	HANDLE hHeap;
	LSA_HANDLE hPolicy = NULL;
	LSA_OBJECT_ATTRIBUTES ObjAttributes = { 0 };
	ULONG Count = 0, i = 0, PrivDispBufLen = 512, Language = 0;
	PLSA_UNICODE_STRING Privileges = NULL;
	WCHAR PrivBuf[512], PrivDispBuf[512];
	CHAR TempPrivDispBuf[512], TempPrivBuf[512];
	BOOL Return;
	hHeap = GetProcessHeap();
	pUser = (TOKEN_USER*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, TokenUserBufSize);
	if (!GetUserSID(pUser, &TokenUserBufSize)) printf("GetUserSid Error\n");
	pSid = pUser->User.Sid;
	if (!IsValidSid(pSid)) { printf("Sid Error\n"); return; }ObjAttributes.Length = sizeof(ObjAttributes);
	LsaOpenPolicy(NULL, &ObjAttributes, POLICY_VIEW_LOCAL_INFORMATION |
		POLICY_LOOKUP_NAMES | POLICY_CREATE_ACCOUNT, &hPolicy);
	LsaEnumerateAccountRights(hPolicy, pSid, &Privileges, &Count);
	printf("Current user has %d privileges:\n", Count);
	for (i = 0; i < Count; i++) {
		lstrcpyn(PrivBuf, Privileges[i].Buffer, Privileges[i].Length);
		PrivBuf[Privileges[i].Length] = 0;
		PrivDispBufLen = 512;
		Return = LookupPrivilegeDisplayName(NULL, PrivBuf, PrivDispBuf, &PrivDispBufLen,
			&Language);
		if (!Return) lstrcpy(PrivDispBuf, TEXT("Дружественное имя привилегии не найдено"));

		CharToOem(PrivDispBuf, TempPrivDispBuf);
		CharToOem(PrivBuf, TempPrivBuf);
		printf("%s (%s)\n", TempPrivBuf, TempPrivDispBuf);
	}
	if (Privileges) LsaFreeMemory(Privileges);
	LsaClose(hPolicy);
	HeapFree(hHeap, 0, pUser);
}
BOOL GetUserSID(TOKEN_USER* pUser, PDWORD pdwSize) {
	BOOL fSuccess = FALSE;
	HANDLE hToken = NULL;
	DWORD dwSize;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) return FALSE;
	if (!GetTokenInformation(hToken, TokenUser, pUser, *pdwSize, &dwSize))
		return FALSE;
	fSuccess = TRUE;
	if (hToken != NULL) CloseHandle(hToken);
	return(fSuccess);
}