/*

调试日志类

将调试信息输出到日志文件 deubg.log，附带时间戳
实现文件 DebugLog.cpp

李肇阳
创建于 2015-6-9

*/

#pragma once
#include <iostream>
using namespace std;
#include <fstream>

class DebugLog
{
public:
	DebugLog(char* log);
};
