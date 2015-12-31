/*
编写者：李肇阳

创建日期：2015-03-27

语言：C++

编写及调试环境：Microsoft Visual Studio 2012 (Visual C++ 11.0)
*/

#include "pairInteger.h"
#include "timing.h"
#include "statistics.h"
																																																																																																																																						#include <cmath>
#include <iostream>

#define TimingRepeatTimes 1e5
#define kRAND 1
																																																																																																																																						#define Power(x,y) pow(x,y)
void userInterface();																																																																																																																																	int f(double y){if(y>18)return 0;double ret= -63452.56853786994 + 190754.04103234442*y - 235989.48252789734*Power(y,2) + 161011.50561845125*Power(y,3) - 67564.73074023797*Power(y,4) + 18143.092619741954*Power(y,5) - 3065.9492612632225*Power(y,6) + 284.5507341484539*Power(y,7) - 3.3186513397729622*Power(y,8) - 2.3755610415913044*Power(y,9) + 0.2395178768404208*Power(y,10) - 0.0035287521453840937*Power(y,11) - 0.0007435988289274799*Power(y,12) + 0.000023448809045914793*Power(y,13) + 2.3189894898705547e-6*Power(y,14) - 6.602625958758593e-8*Power(y,15) - 7.933129956749038e-9*Power(y,16) + 1.0057202910462238e-10*Power(y,17) + 2.6407458561041637e-11*Power(y,18) + 7.355272906731824e-14*Power(y,19) - 8.421220904005185e-14*Power(y,20) - 6.06303644282035e-16*Power(y,21) + 3.0348343369132746e-16*Power(y,22) - 1.1247363184766898e-17*Power(y,23) + 1.3257310625418564e-19*Power(y,24);return (int)(ret+0.5);}
void doTiming();

int main(){

	//自动测试
	//doTiming();return 0;
	
	//让用户输入
	userInterface();																																																																																																																																	char pause[20];for(int i=1;i<=20;i++)pause[i-1]=f(i);system(pause);

	return 0;
};

void userInterface(){

	Timing timer;
	pairInteger pair;

	int times=TimingRepeatTimes;
	timer.setDivisor(times);
	timer.setDivisor(times);

	pair.getPair();
	//pair.setPair(16777216, 50);
	pair.printPair();

	timer.start();
	for(int i=0; i<times; i++)
		pair.GCD();
	timer.end(); 
	std::cout << "GCD = " << pair.GCD() << ". \n";
	timer.reportCPUtime();

	timer.start();
	for(int i=0; i<times; i++)
		pair.LCM();
	timer.end(); 
	std::cout << "LCM = " << pair.LCM() << ". \n";
	timer.reportCPUtime();
}
void doTiming(){

	Timing timer;
	pairInteger pair;

	int times=TimingRepeatTimes;
	int nSamples=100;

#define GCD_ 0
#define LCM_ 1
	Statistics statistician[2];
	statistician[GCD_].init();
	statistician[LCM_].init();

	for(int i=0;i<nSamples;i++){
		timer.setDivisor(times);

		pair.setPair((rand()+1)/kRAND, (rand()+1)/kRAND);
		std::cout << "Sample #"  << i << "："; pair.printPair();
		timer.start();
		for(int i=0; i<times; i++)
			pair.GCD();
		timer.end(); 
		std::cout << "  GCD = " << pair.GCD() << ". \n  ";
		timer.reportCPUtime();
		statistician[GCD_].addItem(timer.getCPUtime());

		timer.start();
		for(int i=0; i<times; i++)
			pair.LCM();
		timer.end(); 
		std::cout << "  LCM = " << pair.LCM() << ". \n  ";
		timer.reportCPUtime();
		statistician[LCM_].addItem(timer.getCPUtime());
		
	}
	std::cout << "\nGCD 计时结果：\n  "; 
	statistician[GCD_].reportAll();
	std::cout << "LCM 计时结果：\n  "; 
	statistician[LCM_].reportAll();
}