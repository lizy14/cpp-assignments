/*
��д�ߣ�������

�������ڣ�2015-03-27

���ԣ�C++

��д�����Ի�����Microsoft Visual Studio 2012 (Visual C++ 11.0)
*/


//��ʱ����
/*

*/


#ifndef TIMING_H
#define TIMING_H
#include <ctime>

class Timing
{
private:
	clock_t clockStart, clockEnd;
	int divisor; 

public:
	Timing();
	~Timing() {}

public:
	void start();
	void end();
	void reportCPUtime(); 
	double getCPUtime(); 
	void setDivisor(int t) {divisor=t;}
}; //end of class

#endif
