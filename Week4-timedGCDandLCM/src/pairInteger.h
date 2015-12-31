#ifndef P_I_H
#define P_I_H

//类：整数对
typedef int Integer;
class pairInteger{

public:
	Integer a;
	Integer b;

public:
	
	pairInteger(){}
	~pairInteger(){}

	void setPair(Integer a, Integer b);
	void getPair();
	void printPair();

	//求最大公约数，指定试除法或欧几里得辗转相除法
	Integer GCD();

	//求最小公倍数
	Integer LCM();

	//求最大数
	Integer max();
};
#endif