/*
��д�ߣ�������

�������ڣ�2015-03-27

���ԣ�C++

��д�����Ի�����Microsoft Visual Studio 2012 (Visual C++ 11.0)
*/



//ͳ����
/*

ʹ��ǰ������� init() ��ʼ��������ڵ��� init() ���ö���
���� addItem() ��׷��һ���µ����ݡ�

*/


#ifndef S_TONGJI_H
#define S_TONGJI_H

class Statistics
{
private:
	double min;
	double max;
	double sum;
	double sumSquare;
	int n;
public:
	Statistics() {}
	~Statistics() {}

public:
	void init();

	void addItem(double x);
	double getSum(){return sum;}
	double getAverage();
	double getGeometricMean();
	double getMin(){return min;}
	double getMax(){return max;}
	int getN(){return n;}
	void reportAll();
}; //end of class

#endif