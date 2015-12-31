#ifndef P_I_H
#define P_I_H

//类：整数对
typedef int Integer;
class pairInteger{
public:
	Integer a;
	Integer b;
	//构造函数
	pairInteger(){}
	void setPair(Integer a, Integer b);
	void getPair();
	void printPair();
	//求最大公约数，指定试除法或欧几里得辗转相除法
	enum flagMethod {Try, Euclidean};
	Integer GCD(flagMethod flagMethod);
	//求最大数
	Integer max();
};
#endif