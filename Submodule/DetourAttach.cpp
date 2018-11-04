#pragma once

#include "detours.h"
#include "DetourAttach.h"

using wepspeedread_t = void(__thiscall*) ();
wepspeedread_t orig_wepspeedread = (wepspeedread_t)(0x6734a6);

DWORD nextaction = 0x6734a8;

/*--------------------------------------------------------------------------------------------*/
void __fastcall hook_wepspeedread()
{
	orig_wepspeedread();

}

//DETOUR convenience function
void DetourWSD(BOOL attach) {
	LONG errorCode;

	//DETOUR/HOOK
	_MESSAGE("BEGIN DETOUR TRANSACTION!");
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	switch (attach) {
	case true:
		_MESSAGE("BEGIN DETOUR ATTACH function %p to function %p!", hook_wepspeedread, orig_wepspeedread);
		errorCode = DetourAttach(&(PVOID&)orig_wepspeedread, hook_wepspeedread);
		break;
	case false:
		_MESSAGE("BEGIN DETOUR DETACH function %p from function %p!", hook_wepspeedread, orig_wepspeedread);
		errorCode = DetourDetach(&(PVOID&)orig_wepspeedread, hook_wepspeedread);
		break;
	}
	_MESSAGE("BEGIN DETOUR COMMIT!");

	if (DetourTransactionCommit() == NO_ERROR) {
		_MESSAGE("COMMIT %s SUCCESSFUL!", (attach ? "ATTACH" : "DETACH"));
	}

	if (!errorCode) {
		_MESSAGE("DETOUR SUCCESSFUL!");
	}
	else {
		_MESSAGE("DETOUR UNSUCCESSFUL. :(");
		_MESSAGE("DETOUR ERROR CODE: %li", errorCode);
	}

}