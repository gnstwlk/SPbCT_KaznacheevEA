#pragma once
#include <vector>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif


extern "C" MATHLIBRARY_API void ATTRIBUTE(LPSTR a);

