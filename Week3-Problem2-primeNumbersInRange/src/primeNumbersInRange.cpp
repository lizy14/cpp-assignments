#include "primeNumbersInRange.h"
#include <iostream>
int isPrime(int n);

int primeNumbersInRange(int min, int max, char* separator){
	int i;
	for(i=min;i<=max;i++){
		if(isPrime(i))
			std::cout << i << separator;
	}
	if(min>max) return 1;
	return 0;
}


//以下宏和函数是以前 C 写的
#define for_(i,x,y) for(i=x; i<=y; i++)
int isPrime(int n)
{
	int i;
	if(n==1) return 0;
	for_(i, 2, n-1)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}
