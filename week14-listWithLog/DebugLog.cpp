#include "DebugLog.h"
#include <windows.h>
#include <atlstr.h>
#include <string.h>
DebugLog::DebugLog(char* log){
	ofstream file("debug.log",ios::out|ios::app);
	char str[50];
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	sprintf(str, "%d/%d/%d %02d:%02d:%02d.%03d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds);
	file << log << '\t' << str << '\n';
}