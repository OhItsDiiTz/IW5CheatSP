#pragma once
#include <Windows.h>
#include <string>
#include "MinHook/MinHook.h"

#include "GameStructs.h"
#include "GameHooks.h"
#include "GameFunctions.h"
#include "BuiltinFunctions.h"

#pragma warning ( disable : 4996 )



template <typename T> inline MH_STATUS MH_CreateHookEx(LPVOID pTarget, LPVOID pDetour, T** ppOriginal, const char * pHookName);
template <typename T> inline MH_STATUS MH_CreateHookApiEx(LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, T** ppOriginal);

