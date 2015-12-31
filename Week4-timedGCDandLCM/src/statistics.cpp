/*
编写者：李肇阳

创建日期：2015-03-27

语言：C++

编写及调试环境：Microsoft Visual Studio 2012 (Visual C++ 11.0)
*/


#include "statistics.h"
#include <iostream>
#include <cmath>
void Statistics::init(){
	min=0, max=0, n=0, sum=0, sumSquare=0;
}

void Statistics::reportAll(){
	std::cout << "统计了 " << n << " 个数据，平均值 " << getAverage() 
		<< "，最小值 " << this->getMin()
		<< "，最大值 " << getMax() 
		<< "。\n";
}

double Statistics::getGeometricMean(){
	return sqrt(sumSquare/n);
}

void Statistics::addItem(double x){
	
	if(n==0){
		min=max=x;
	}else{
		if(x>max)
			max=x;
		if(x<min)
			min=x;
	}
	n++;
	sum += x;
	sumSquare += x*x;
}

double Statistics::getAverage(){
	return sum/n;
}