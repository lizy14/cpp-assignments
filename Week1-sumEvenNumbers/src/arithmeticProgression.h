#ifndef A_P_H
#define A_P_H

class arithmeticProgression{
public:
	int a1;
	int d;
public:
	arithmeticProgression(int a1, int d);
	arithmeticProgression(){}
	int sum(int n);
	int an(int n);
};
#endif