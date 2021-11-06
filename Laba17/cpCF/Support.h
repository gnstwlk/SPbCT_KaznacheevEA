#pragma once
/* Support.h */

/* Содержит определения всех символических констант и распространенных служебных функций, используемых в примерах программ. */

/* НЕСМОТРЯ НА ВКЛЮЧЕНИЕ ОПИСАНИЙ КОНСТАНТ UTILITY_EXPORTS И _STATICLIB, ИХ ЛУЧШЕ ОПРЕДЕЛЯТЬ НЕ ЗДЕСЬ, А В ПРОЕКТЕ. */

/* Имя "UTILITY_EXPORTS" генерируется средой разработки Visual Studio, если вы создаете проект DLL с именем "Utility", но его также можно определить в командной строке С. */

// UTILITY_3_0_EXPORTS определяется в проекте UTILITY_3_0.

#if defined(UTILITY_3_0_EXPORTS) 

#define LIBSPEC _declspec(dllexport)

#elif defined(__cplusplus)

#define LIBSPEC extern "C" _declspec(dllimport)

#else

#define LIBSPEC _declspec(dllimport)

#endif


#define EMPTY _T("") 

#define YES _T("y") 

#define NO _T("n") 

#define CR 0x0D 

#define LF 0x0A

#define TSIZE sizeof(TCHAR)


/* Предельные значения и константы. */

#define TYPE_FILE 1 /* Используется в ls, rm, и lsFP. */

#define TYPE_DIR 2

#define TYPE_DOT 3

#define MAX_OPTIONS 20 /* Максимальное количество параметров командной строки.*/ 

#define MAX_ARG 1000 /* Максимальное количество аргументов командной строки.*/ 

#define MAX_COMMAND_LINE MAX_PATH+50 /*Максимальный размер командной строки*/


/* Часто используемые функции. */

LIBSPEC BOOL ConsolePrompt(LPCTSTR, LPTSTR, DWORD, BOOL);

LIBSPEC BOOL PrintStrings(HANDLE, ...);

LIBSPEC BOOL PrintMsg(HANDLE, LPCTSTR);

LIBSPEC VOID ReportError(LPCTSTR, DWORD, BOOL);

LIBSPEC VOID ReportException(LPCTSTR, DWORD);

LIBSPEC DWORD Options(int, LPCTSTR*, LPCTSTR, ...);

LIBSPEC LPTSTR SkipArg(LPCTSTR);

LIBSPEC VOID GetArgs(LPCTSTR, int*, LPTSTR*);


/* Набор функций для работы с обобщенными строками в стиле string.h. Создавались по мере необходимости – первоначально была только одна функция! Реализация взята из [27]. */

LIBSPEC LPCTSTR wmemchr(LPCTSTR, TCHAR, DWORD);


#ifdef _UNICODE /* Это объявление уже должно было быть добавлено. */

#define _tstrrchr wcsrchr

#else

#define _tstrrchr strrchr

#endif


#ifdef _UNICODE /* Это объявление уже должно было быть добавлено. */

#define _memtchr wmemchr

#else

#define _memtchr memchr

#endif


/* Функции безопасности. */

LPSECURITY_ATTRIBUTES InitializeUnixSA(DWORD, LPTSTR, LPTSTR, LPDWORD, LPHANDLE);

LPSECURITY_ATTRIBUTES InitializeAccessOnlySA(DWORD, LPTSTR, LPTSTR, LPDWORD, LPHANDLE);

DWORD ReadFilePermissions(LPTSTR, LPTSTR, LPTSTR);

BOOL ChangeFilePermissions(DWORD, LPTSTR, LPDWORD, LPDWORD);

/* В упрощенной форме доступны в Visual C++ Version 5.0. */

//PSECURITY_DESCRIPTOR InitializeSD(DWORD, LPTSTR, LPTSTR, LPDWORD);


/* Константы, которые требуются для функций безопасности. */

#define LUSIZE 1024

#define ACCT_NAME_SIZE LUSIZE
