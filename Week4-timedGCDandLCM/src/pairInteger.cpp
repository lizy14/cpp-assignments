#include "pairInteger.h"
#include "getInteger.h"
#include <iostream>
using namespace std;
void pairInteger::getPair(){
	Integer a=0, b=0;
	a=getInteger("第 1 个数");
	b=getInteger("第 2 个数");
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
Integer pairInteger::GCD(){
	
	Integer i=0, result;
	Integer a=this->a, b=this->b;

	while(b!=0){
		if(a<b){i=a,a=b,b=i;}
		i=a%b;
		a=b;
		b=i;
	}
	return a;
}
Integer pairInteger::LCM(){
	Integer a=this->a, b=this->b;
	return (a*b)/this->GCD();
}