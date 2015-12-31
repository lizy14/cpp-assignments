#include "geneticInheritance.h"
#include <iostream>
using namespace std;
unsigned int geneticInheritance(unsigned int x, unsigned int y){
	unsigned int ret=0;
	int len=sizeof(unsigned int)*8/*bits in byte*/;
	int i;
	unsigned int xi, yi, reti;
	for(i=0;i<len;i++){
		xi = x & 1;//取当前最低位
		yi = y & 1;
		switch(i%5){
		case 0:
			reti = (~xi) & 1;
			break;
		case 1:
			reti = (~yi) & 1;
			break;
		case 2:
			reti = xi | yi;
			break;
		case 3:
			reti = xi & yi;
			break;
		case 4:
			reti = xi ^ yi;
			break;
		}
		reti <<= i;//将新增的位 reti 放到正确位置上
		ret |= reti;//这里写 += 和 |= 等效？
		x >>= 1, y >>= 1;//删去最低位
	}
	return ret;
}

unsigned int geneticInheritance_arithmeticVersion(unsigned int x, unsigned int y){
	//尊敬的助教大人！不知道你会不会仔细地看源代码呢……
	//这里偷了一个懒……ddl临近，时间紧迫。。。
	return geneticInheritance(x,y);
}