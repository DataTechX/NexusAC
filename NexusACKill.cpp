////// NexusACKill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//////
////
#include <iostream>
#include <string>
using namespace std;


DWORD GetProcId(const char* procName)
{
    DWORD procId = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
        if (Process32First(hSnap, &procEntry))
        {
            do
            {
                if (!_stricmp(procEntry.szExeFile, procName))
                {
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
    CloseHandle(hSnap);
    return procId;

}
void Stealth()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth, 0);
}

NTSTATUS
RtlSetProcessIsCritical(
    BOOLEAN bNew,    	// new setting for process
    BOOLEAN* pbOld,    	// pointer which receives old setting (can be null)
    BOOLEAN bNeedScb);    	// need system critical breaks
typedef long (WINAPI* RtlSetProcessIsCritical) (
    IN BOOLEAN    bNew,
    OUT BOOLEAN* pbOld,
    IN BOOLEAN    bNeedScb);
int main()
{
    HANDLE ntdll = LoadLibrary("ntdll.dll");
    RtlSetProcessIsCritical SetCriticalProcess;

    SetCriticalProcess = (RtlSetProcessIsCritical)
        GetProcAddress((HINSTANCE)ntdll, "RtlSetProcessIsCritical");
    Stealth();
    SetConsoleTitleA("HELLO JJ#2631");
    system("Color 0B");

    std::cout << "[+] Anticheat Initializing..." << std::endl;



  /*  LPCSTR dllPath = AY_OBFUSCATE("C:\\Elixir\\NexusAC.dll");

    const char* processName = AY_OBFUSCATE("NexusAC.exe");
    DWORD procId = 0;

    while (!procId)
    {
        procId = GetProcId(processName);
        Sleep(1000);

    }

    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

    if (hProc && hProc != INVALID_HANDLE_VALUE)
    {
        void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

        HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

        if (hThread) {
            std::cout << hThread;
            CloseHandle(hThread);
        }

        if (hProc) {
            std::cout << hProc;
            CloseHandle(hProc);
        }
	}

    std::cout << "\n ===================================================" << std::endl;
    std::cout << " ================ Anticheat Running ================" << std::endl;
    std::cout << " ===================================================" << std::endl;
    Beep(300, 600);
    Beep(300, 600);
    Beep(300, 800);
    Beep(300, 900);
    Beep(300, 600);
    std::cout << "[+] Anticheat Initialized Successfully!" << std::endl;*/


   

    system("pause");
    return 0;

     inject dll

}

