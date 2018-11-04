#pragma once



//static VOID (WINAPI* orig_wepspeedread)() = (void*)(0x01006F10);

//using wepspeedread_t = VOID(WINAPI*)();
//typedef VOID(WINAPI* wepspeedFunc)();
//wepspeedFunc orig_wepspeedread = (wepspeedFunc)(0x6734a6);

//static DWORD orig_addr = 0x6734a6;
//wepspeedread_t orig_wepspeedread = (wepspeedread_t)(0x6734a6);


void DetourWSD(BOOL attach = true);