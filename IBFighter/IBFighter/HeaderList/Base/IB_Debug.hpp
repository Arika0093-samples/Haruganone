// --------------------------------------------------------
// Simple Debug Function/Macro
// --------------------------------------------------------
#pragma once

// --------------------------------------------------------
// include base files
// --------------------------------------------------------
#include <windows.h>
#include <stdio.h>
#include <imagehlp.h>
#include <typeinfo>
#include <tchar.h>

// --------------------------------------------------------
// pre
// --------------------------------------------------------
void OutputDebugStringToFormat(LPCTSTR Format, ...);
char* Demangle(const char *dm);

// --------------------------------------------------------
// simple macro
// --------------------------------------------------------
#if defined(_DEBUG) || defined(DEBUG)
	// --------------------------------------------------------
	// @Debug
	// --------------------------------------------------------
	#define DebugOutput(Str)		OutputDebugStringToFormat(Str)
	#define DebugOutputNum(Num)		OutputDebugStringToFormat(#Num": %f", Num)
	#define DebugOutputType(Val)	OutputDebugStringToFormat(#Val": %s", Demangle(typeid(Val).name()));
	#define Assert(x) \
		if(!(x)){ \
			OutputDebugStringToFormat("Assert in %s(Line: %d)" \
				, __FILE__, __LINE__); \
			DebugBreak(); \
		}
	#define Verify(x)				Assert(x)
#else
	// --------------------------------------------------------
	// @Release
	// --------------------------------------------------------
	#define DebugOutput(Str)
	#define DebugOutputNum(Num)
	#define DebugOutputType(Val)
	#define Assert(x)
	#define Verify(x) x
#endif // end _DEBUG

