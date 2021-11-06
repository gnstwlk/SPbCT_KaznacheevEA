#pragma once
/* Envirmnt.h — Здесь определяются константы UNICODE и _МТ. */
 
/* Лучше и проще определить константу UNICODE в проекте. */
 
/* Используйте команды меню: Project…Settings…C/C++. Затем, перейдя */
 
/* в окно Project Options, добавьте в нижней части: /D "UNICODE". */
 
/* Проделайте то же самое для констант _МТ и _STATIC_LIB. */
 
 
//#define UNICODE 
 
#undef UNICODE 
 
#ifdef UNICODE 
 
#define _UNICODE 
 
#endif
 
#ifndef UNICODE 
 
#undef _UNICODE 
 
#endif
 
//#define _STATICLIB
 
/* Определите _STATICLIB, если создаете */
 
/* или компонуете статическую библиотеку. */ 
 
#define LANG_DFLT LANG_ENGLISH 
 
#define SUBLANG_DFLT SUBLANG_ENGLISH_US
