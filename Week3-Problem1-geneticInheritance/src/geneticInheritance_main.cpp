#include "getInteger.h"
#include "geneticInheritance.h"
#include "putInteger.h"
#include <iostream>

void userInterface();
void test();
int main(){
	userInterface();
	//test();
	return 0;
}
void userInterface(){
	int x = getInteger("�� 1 ������Ĵ���");
	int y = getInteger("�� 2 ������Ĵ���");
	//end of input

	int result=geneticInheritance(x,y);
	std::cout << "�� 1 ������"; putIntegerBinary(x);
	std::cout << "�� 2 ������"; putIntegerBinary(y);
	std::cout << "�Ŵ������   "; putIntegerBinary(result);
	std::cout << std::endl;
	//std::cout << "�Ŵ������   0x" << std::hex << result << std::endl << std::endl;
}
void test(){
	int samples[]={-23,-2,-1,0,1,2,23,233,2333,23333,INT_MAX/4,INT_MAX/3};
	int len=sizeof(samples)/sizeof(int);
	int x,y;
	int i,j,count=0,pass=0;
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			x=samples[i];
			y=samples[j];
			std::cout << "���� #" << ++count << std::endl;
			std::cout << "x = "; putIntegerBinary(x);
			std::cout << "y = "; putIntegerBinary(y);
			int r1=geneticInheritance(x,y);
			int r2=geneticInheritance_arithmeticVersion(x,y);
			std::cout << "r1= "; putIntegerBinary(r1);
			std::cout << "r2= "; putIntegerBinary(r2);
			if(r1==r2){
				pass++;
				std::cout << "һ�¡�\n";
			}else{
				std::cout << "��һ�£�\n";
			}
		}
	}
	std::cout << "������ " << count << " �����������ͨ�� " << pass << " �顣ͨ���� " << pass*100/count << "%��\n";
}