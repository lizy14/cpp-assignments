//������ �廪��ѧ���ѧԺ 2015-3-3
//�Ȳ�������
#include "arithmeticProgression.h"
arithmeticProgression::arithmeticProgression(int a1, int d){
	this->a1=a1, this->d=d;
	return;
}
int arithmeticProgression::sum(int n){
	if(n<=0){}
	int sum = this->a1*n + n*(n-1)*this->d/2;
	return sum;
};

int arithmeticProgression::an(int n){
	if(n<=0){}
	return this->a1+(n-1)*this->d;
}