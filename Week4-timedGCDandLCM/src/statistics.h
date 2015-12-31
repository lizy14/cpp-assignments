/*
编写者：李肇阳

创建日期：2015-03-27

语言：C++

编写及调试环境：Microsoft Visual Studio 2012 (Visual C++ 11.0)
*/



//统计类
/*

使用前必须调用 init() 初始化。亦可在调用 init() 后复用对象。
调用 addItem() 以追加一个新的数据。

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