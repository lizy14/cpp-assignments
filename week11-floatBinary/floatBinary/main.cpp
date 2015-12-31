//main.cpp

//double 的二进制表示法演示程序

//清华大学软件学院李肇阳

//最后修改于2015-5-19

#include "putInteger.h"
#include <iostream>
using namespace std;

//取消注释下一行，即使用测试数据
//#define REPORT

//输出 double 的二进制表示
void putDoubleBinary(double y);

//输出 double 及其二进制表示
void putDoubleAndBinary(double y);

void putDoubleBinary(double y){
	putIntegerBinary((Integer&)y);
}

void putDoubleAndBinary(double y){
	cout << y << endl;
	putDoubleBinary(y);
}

int main(){
	cout << "double 的二进制表示法演示程序" << endl;
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
	cout << "请您输入浮点数，Ctrl+C结束。" << endl;
	while(233){
		cout << "> ";
		cin >> x;
		if (cin.good()){
			putDoubleAndBinary(x);
		}
		else
			cout << "输入出错。" << endl;
		cin.clear();
		cin.sync();
	}
}