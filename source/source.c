#include <windows.h>
#include "GG.h"

HMODULE exe;
BYTE *target;

void Patch() {
	int enable = 1;
	char *path = "bg/bg_ko.cmp";
	memcpy(target+0x5ed168,&enable,4); // Enable Korea Selection
	memcpy(target+0x576f38,&path,4); // AC Korea
	memcpy(target+0x576f88,&path,4); // Reload Korea
	return;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		exe = GetModuleHandle(NULL);
		target = (BYTE*)exe;
		Patch();
	}
	return TRUE;
}
