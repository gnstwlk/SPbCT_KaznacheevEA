// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "MathLibrary.h"


void ATTRIBUTE(LPSTR a)
{
	SetFileAttributesA(a, FILE_ATTRIBUTE_READONLY);
}
