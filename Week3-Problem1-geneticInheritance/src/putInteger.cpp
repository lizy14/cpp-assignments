#include "putInteger.h"
#include <cstdio>
#include <cmath>


//以下 2 个函数是以前 C 写的，直接拿过来的

void printdigit(Integer r, Integer b, int q)
{
	if (!q)
		if (r < 10)
			printf("%d", r);
		else
			putchar(r + 'A' - 10);
	else
		printf("%d", r);
}
void convert(Integer a, Integer b, int q)
{
	Integer c = a / b, r = a % b;
	if (c == 0)
	{
		printdigit(r, b, q);
		return;
	}
	else
	{
		convert(c, b, q);
		if (q) putchar('.');
		printdigit(r, b, q);
	}
}

void putIntegerBinary(Integer x){
	Integer x0=x;
	int len=0;//记录需要补高位 0 的个数
	if(x0==0){
		len=sizeof(Integer)*8-1;
	}else{
		while(233){
			if(x==0)break;
			len+=1;
			x>>=1;
		}
		len=sizeof(Integer)*8-len;
	}
	for(int i=0;i<len;i++)
		putchar('0');
	//printf("^%d^", len);
	convert(x0,2,0);
	putchar('\n');
	return;
}