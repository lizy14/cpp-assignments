//main.cpp

//double �Ķ����Ʊ�ʾ����ʾ����

//�廪��ѧ���ѧԺ������

//����޸���2015-5-19

#include "putInteger.h"
#include <iostream>
using namespace std;

//ȡ��ע����һ�У���ʹ�ò�������
//#define REPORT

//��� double �Ķ����Ʊ�ʾ
void putDoubleBinary(double y);

//��� double ��������Ʊ�ʾ
void putDoubleAndBinary(double y);

void putDoubleBinary(double y){
	putIntegerBinary((Integer&)y);
}

void putDoubleAndBinary(double y){
	cout << y << endl;
	putDoubleBinary(y);
}

int main(){
	cout << "double �Ķ����Ʊ�ʾ����ʾ����" << endl;
	double x=0.0;

#ifdef REPORT
	putDoubleAndBinary(x/x);
	putDoubleAndBinary(1.0/x);
	putDoubleAndBinary(-1.0/x);
	putDoubleAndBinary(+0.0);
	putDoubleAndBinary(-0.0);
	putDoubleAndBinary(0.1);
	putDoubleAndBinary(2.3);
	putDoubleAndBinary(-4.5);
#endif
	cout << "�������븡������Ctrl+C������" << endl;
	while(233){
		cout << "> ";
		cin >> x;
		if (cin.good()){
			putDoubleAndBinary(x);
		}
		else
			cout << "�������" << endl;
		cin.clear();
		cin.sync();
	}
}