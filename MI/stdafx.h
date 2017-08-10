// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WIN32
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <windows.h>
#else
#define TRUE true
#define FALSE false
#define ZeroMemory(Dest,Size) memset((Dest), 0, (Size))
#define memcpy_s(Dest, Dummy, Src, Size) memcpy((Dest), (Src), (Size))
#define MultiByteToWideChar(D1, D2, S, N, PWC, N2) std::mbtowc((PWC), (S), (N))
#define lstrlen wcslen
#endif

#include <MI.h>
#include <exception>
#include <string>
#include <tuple>
#include <map>
