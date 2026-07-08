#include "pch.h"
#include <windows.h>
#include <urlmon.h>
#include <iostream>
#include <sstream>

#pragma comment(lib, "urlmon.lib")

void Alert(std::string text) {
	MessageBoxA(NULL, text.c_str(), "ERROR", MB_OK | MB_ICONINFORMATION);
}

extern "C" __declspec(dllexport) void DownloadFiles(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow) {

    std::string arg = lpszCmdLine;
    std::istringstream iss(arg);

    std::string url, output;
    iss >> url >> output;

    if (url.empty() || output.empty()) {
        Alert("ERROR: Empty arguments");
        exit(-1);
    }

    HRESULT hResult = URLDownloadToFileA(NULL,
                                        url.c_str(),
                                        output.c_str(), 0, NULL);
}

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
        break;
    }
    return TRUE;
}
