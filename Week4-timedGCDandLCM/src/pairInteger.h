#ifndef P_I_H
#define P_I_H

//�ࣺ������
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

	//�����Լ����ָ���Գ�����ŷ�����շת�����
	Integer GCD();

	//����С������
	Integer LCM();

	//�������
	Integer max();
};
#endif