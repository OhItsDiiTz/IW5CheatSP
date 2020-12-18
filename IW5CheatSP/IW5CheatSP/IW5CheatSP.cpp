#include "IW5CheatSP.h"





BOOL WINAPI DllMain(HMODULE hModule, DWORD Reason, LPVOID lpVoid) {
	
	if (Reason == DLL_PROCESS_ATTACH) {
		AllocConsole();
		SetConsoleTitle("Console: IW5CheatSP");
		freopen("CONOUT$", "w", stdout);

		MH_Initialize();

		MH_CreateHookEx((void*)(0x00610200), &VM_Notify_Hook, &VM_Notify_Stub, "VM_Notify");

		MH_EnableHook(MH_ALL_HOOKS);

	}

	if (Reason == DLL_PROCESS_DETACH) {
		FreeConsole();

	}

	return TRUE;
}

template <typename T> inline MH_STATUS MH_CreateHookEx(LPVOID pTarget, LPVOID pDetour, T** ppOriginal, const char * pHookName) {
	printf("Hooking %s Hooked Jumping from 0x%X to 0x%X\n", pHookName, pTarget, pDetour);
	MH_STATUS ret = MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
	return ret;
}

template <typename T> inline MH_STATUS MH_CreateHookApiEx(LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, T** ppOriginal) {
	return MH_CreateHookApi(pszModule, pszProcName, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
}
