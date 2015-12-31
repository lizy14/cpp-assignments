/*
��д�ߣ�������

�������ڣ�2015-03-27

���ԣ�C++

��д�����Ի�����Microsoft Visual Studio 2012 (Visual C++ 11.0)
*/


#include "statistics.h"
#include <iostream>
#include <cmath>
void Statistics::init(){
	min=0, max=0, n=0, sum=0, sumSquare=0;
}

void Statistics::reportAll(){
	std::cout << "ͳ���� " << n << " �����ݣ�ƽ��ֵ " << getAverage() 
		<< "����Сֵ " << this->getMin()
		<< "�����ֵ " << getMax() 
		<< "��\n";
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