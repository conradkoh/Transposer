// TransposerCLR.h

#pragma once
#pragma comment(lib, "shell32.lib")
#include <Windows.h>
#include "StringMethods.h"
using namespace std;
using namespace System;

namespace TransposerCLR {

	public ref class WindowsMethods
	{

	public:
		static bool OpenFile(const char* path){

			bool isSuccessful = false;
			wchar_t buffer[4096];
			mbstowcs(buffer, path, 4096); //writes path to buffer, from char to wchar_t
			
			HINSTANCE errornumber = ShellExecuteW(NULL, L"open", buffer, NULL, NULL, SW_SHOW); //ShellExecuteW is used for unicode names, ShellExecuteA for ANSI
			
			//there are 32 errors which ShellExecuteW will return if the file fails to open.
			//refer to https://msdn.microsoft.com/en-us/library/windows/desktop/bb762153%28v=vs.85%29.aspx

			if ((int)errornumber > 32){
				isSuccessful = true;
			}
			return isSuccessful;
		}

		static bool OpenProgram(const char* applicationPath, const char* argument){
			
		//IMPORTANT NOTE: command must include the application to open it. for example, application path can be C:\windows\notepad.exe but command must be "notepad.exe file.txt"
			//fix attempt
			
			string command = (string)applicationPath + " \"" + (string)argument + "\"";
			

		bool isSuccessful = false;

		wchar_t pathbuffer[4096];
		wchar_t cmdbuffer[4096];
		mbstowcs(pathbuffer, applicationPath, 4096);
		mbstowcs(cmdbuffer, command.c_str(), 4096);


		//LPCTSTR APPPATH = L"C:\\Windows\\notepad.exe";
		STARTUPINFOW si;
		PROCESS_INFORMATION pi;

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));


		if (CreateProcess(pathbuffer, cmdbuffer, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)){
			WaitForSingleObject(pi.hProcess, INFINITE);
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			isSuccessful = true;
		}

		return isSuccessful;
	}


	};
}
