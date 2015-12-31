#include "pairInteger.h"
#include <iostream>
using namespace std;
void pairInteger::getPair(){
	Integer a=0, b=0;
	cout << "请输入第 1 个整数>>";
	cin >> a;
	cout << "请输入第 2 个整数>>";
	cin >> b;
	this->a=a, this->b=b;
	return;
}
void pairInteger::setPair(Integer a, Integer b){
	this->a=a, this->b=b;
	return;
}
inline Integer pairInteger::max(){
	return (this->a>this->b?this->a:this->b);
}
void pairInteger::printPair(){
	cout << "(" << this->a << ", " << this->b << ")\n";
}
Integer pairInteger::GCD(flagMethod flagMethod){
	Integer i=0;
	Integer a=this->a, b=this->b;
	switch(flagMethod){
	case Try:
		for(i=this->max();i>0;i--){
			if(a%i==0 && b%i==0)break;
		}
		return i;
		break;
	case Euclidean:
		while(b!=0){
			if(a<b){i=a,a=b,b=i;}
			i=a%b;
			a=b;
			b=i;
		}
		return a;
		break;
	}
}