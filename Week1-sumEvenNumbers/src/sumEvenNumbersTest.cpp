//李肇阳 清华大学软件学院 2015-3-3
//接受正整数n, 计算不超过n的所有正偶数之和, 输出n及偶数之和
#include <iostream>
#include "sumEvenNumbersTest.h"

void sumEvenNumbersTest(){
	while(233){
		int x;
		std::cin >> x;

		//输入合法性检验
		if(x<=0){
			std::cout << "illegal input. " << std::endl;;
			continue;
		}
		
		//求和方法1，利用等差数列求和公式
		arithmeticProgression evenNumbers(2,2);//正偶数列
		int sum=evenNumbers.sum(x/2);

		//求和方法2，累加
		int sumtest=0;
		{
			int a=2;
			int i;
			for(i=0;i<x/2;i++){
				sumtest+=a;
				a+=2;
			}
		}

		//一致性检验
		if(sum!=sumtest){
			std::cout << "error. " << std::endl;
			continue;
		}

		std::cout
			<< "sum of even numbers less than or equal to " 
			<< x
			<< " is: " 
			<< sum
			<< std::endl;
	}
}
