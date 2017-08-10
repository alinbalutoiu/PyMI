// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WIN32
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#else
#define TRUE true
#define FALSE false
#define CRITICAL_SECTION char
#define PCRITICAL_SECTION char*
#define InitializeCriticalSection(X)
#define DeleteCriticalSection(X)
#define EnterCriticalSection(X)
#define LeaveCriticalSection(X)
#define ZeroMemory(Dest,Size) memset((Dest), 0, (Size))
#define memcpy_s(Dest, Dummy, Src, Size) memcpy((Dest), (Src), (Size))
#define MultiByteToWideChar(D1, D2, S, N, PWC, N2) std::mbtowc((PWC), (S), (N))
#define lstrlen wcslen
#define lstrlenA strlen
#define DWORD char32_t
#define MI_AUTH_TYPE_CREDSSP MI_T("CredSSP")
#define MI_DESTINATIONOPTIONS_TRANPSORT_HTTPS ("HTTPS")
#include <locale>
#endif 

#include <MI.h>

#ifdef _DEBUG
#define _DEBUG_TMP
#undef _DEBUG
#endif

#include <Python.h>
#include <structmember.h>

#ifdef _DEBUG_TMP
#define _DEBUG 1
#undef _DEBUG_TMP
#endif

#if PY_MAJOR_VERSION >= 3
#define IS_PY3K
#define PYUNICODEASVARCHARARG1TYPE PyObject
#else
#define PYUNICODEASVARCHARARG1TYPE PyUnicodeObject

#define PyDateTime_DELTA_GET_DAYS(o)         (((PyDateTime_Delta*)o)->days)
#define PyDateTime_DELTA_GET_SECONDS(o)      (((PyDateTime_Delta*)o)->seconds)
#define PyDateTime_DELTA_GET_MICROSECONDS(o)            \
    (((PyDateTime_Delta*)o)->microseconds)

#endif

// TODO: reference additional headers your program requires here
