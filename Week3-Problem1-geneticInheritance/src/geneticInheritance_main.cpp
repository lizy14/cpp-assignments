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
	int x = getInteger("第 1 个基因的代号");
	int y = getInteger("第 2 个基因的代号");
	//end of input

	int result=geneticInheritance(x,y);
	std::cout << "第 1 个基因："; putIntegerBinary(x);
	std::cout << "第 2 个基因："; putIntegerBinary(y);
	std::cout << "遗传结果：   "; putIntegerBinary(result);
	std::cout << std::endl;
	//std::cout << "遗传结果：   0x" << std::hex << result << std::endl << std::endl;
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
			std::cout << "测试 #" << ++count << std::endl;
			std::cout << "x = "; putIntegerBinary(x);
			std::cout << "y = "; putIntegerBinary(y);
			int r1=geneticInheritance(x,y);
			int r2=geneticInheritance_arithmeticVersion(x,y);
			std::cout << "r1= "; putIntegerBinary(r1);
			std::cout << "r2= "; putIntegerBinary(r2);
			if(r1==r2){
				pass++;
				std::cout << "一致。\n";
			}else{
				std::cout << "不一致！\n";
			}
		}
	}
	std::cout << "运行了 " << count << " 组测试用例，通过 " << pass << " 组。通过率 " << pass*100/count << "%。\n";
}