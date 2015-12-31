#include "primeNumbersInRange.h"
#include <iostream>
#include "getInteger.h"

void userInterface();
void test();

int main(){
	//test();
	userInterface();
	return 0;
}
void userInterface(){
	int min=getInteger("下界");
	int max=getInteger("上界");
	primeNumbersInRange(min, max, "\n");
	std::cout << "输出已结束。";
}
void test(){
	int samples[]={2,23,233,2333,23333,233333,2333333};
	int samples_length[]={1,10,100,1000,10000};
	int len=sizeof(samples)/sizeof(int);
	int len_length=sizeof(samples_length)/sizeof(int);
	int min,max;
	int i,j,count=0,pass=0;
	std::cout << "{";
	for(i=0;i<len;i++){
		for(j=0;j<len_length;j++){
			min=samples[i];
			max=min+samples_length[j];
			++count;

			std::cout << "{" << min << "," << max << ",{";
			primeNumbersInRange(min, max, ",");
			std::cout << "}},\n";
			
		}
	}
	std::cout << "}";
}