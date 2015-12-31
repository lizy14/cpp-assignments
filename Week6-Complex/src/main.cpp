#include "Complex.h"
#include <iostream>
void autoTest();
void userInterface();
int main(){
	autoTest();
	return 0;
}
void autoTest(){ 
	Complex x, y;
	double ixSamples[] = {0, 0,   1.1, 2.5,  3};
	double rxSamples[] = {0, 1.1, 0,   5,    6};
	double iySamples[] = {0, 0,   2.3, -2.5, 3.1};
	double rySamples[] = {0, 2.3, 0,   -5,   6.1};
	int nSamples = sizeof(ixSamples)/sizeof(double);

	for(int i=0; i<nSamples; i++){
		x.setValue(rxSamples[i],ixSamples[i]);
		y.setValue(rySamples[i],iySamples[i]);
		printf("============ SAMPLE #%d ============\n", i);
		puts("operand x");x.print();
		puts("operand y");y.print();

		puts("binary operators");
		puts("+");(x+y).print();
		puts("-");(x-y).print();
		puts("*");(x*y).print();
		puts("/");(x/y).print();

		puts("unary operators");
		
		puts("prefix ++");
		(++x).print();x.print();

		puts("prefix --");
		(--x).print();x.print();

		puts("postfix ++");
		(x++).print();x.print();

		puts("postfix --");
		(x--).print();x.print();
	}
}