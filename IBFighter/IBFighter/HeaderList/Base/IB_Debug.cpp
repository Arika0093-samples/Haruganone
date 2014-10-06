// --------------------------------------------------------
// include base files
// --------------------------------------------------------
#include "IB_BaseInclude.hpp"

// --------------------------------------------------------
// Function
// --------------------------------------------------------
void OutputDebugStringToFormat(LPCTSTR Format, ...)
{
	va_list	argp;
    char pszBuf[ 256];
    va_start(argp, Format);
    vsprintf(pszBuf, Format, argp);
    va_end(argp);
    OutputDebugString(pszBuf);
    OutputDebugString("\n");
}

char* Demangle(const char *dm)
{
	// some memory leek
	char* rlt = new char[1024];
	UnDecorateSymbolName(dm, rlt, 1024 - 1, UNDNAME_NAME_ONLY);
	return rlt;
}

