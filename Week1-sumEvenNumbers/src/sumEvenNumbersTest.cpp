//������ �廪��ѧ���ѧԺ 2015-3-3
//����������n, ���㲻����n��������ż��֮��, ���n��ż��֮��
#include <iostream>
#include "sumEvenNumbersTest.h"

void sumEvenNumbersTest(){
	while(233){
		int x;
		std::cin >> x;

		//����Ϸ��Լ���
		if(x<=0){
			std::cout << "illegal input. " << std::endl;;
			continue;
		}
		
		//��ͷ���1�����õȲ�������͹�ʽ
		arithmeticProgression evenNumbers(2,2);//��ż����
		int sum=evenNumbers.sum(x/2);

		//��ͷ���2���ۼ�
		int sumtest=0;
		{
			int a=2;
			int i;
			for(i=0;i<x/2;i++){
				sumtest+=a;
				a+=2;
			}
		}

		//һ���Լ���
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
