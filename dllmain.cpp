// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <Windows.h>
#include <iostream>


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        MessageBoxA(NULL, "NexusAC Delete", "HELLO JJ#2631", MB_OK | MB_ICONINFORMATION);
        system("taskkill /f /im powershell.exe");

        break;
    }
    return TRUE;
}

