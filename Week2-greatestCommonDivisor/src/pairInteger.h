#ifndef P_I_H
#define P_I_H

//�ࣺ������
typedef int Integer;
class pairInteger{
public:
	Integer a;
	Integer b;
	//���캯��
	pairInteger(){}
	void setPair(Integer a, Integer b);
	void getPair();
	void printPair();
	//�����Լ����ָ���Գ�����ŷ�����շת�����
	enum flagMethod {Try, Euclidean};
	Integer GCD(flagMethod flagMethod);
	//�������
	Integer max();
};
#endif