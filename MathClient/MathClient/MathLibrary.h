#pragma once
#include <vector>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include<windows.h>



#ifdef MATHCLIENT_EXPORTS
#define MATHCLIENT_API __declspec(dllexport)
#else
#define MATHCLIENT_API __declspec(dllimport)
#endif


extern "C" MATHCLIENT_API void ATTRIBUTE(LPSTR a);


