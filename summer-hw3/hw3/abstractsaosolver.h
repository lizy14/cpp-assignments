#ifndef abstractsaosolver_h
#define abstractsaosolver_h

#include "castle.h"

class AbstractSAOSolver
{
public:
	virtual void Solve(Castle castle, string outputFileName) = 0;
};

class BruteSAOSolver: public AbstractSAOSolver
{
public:
	void Solve(Castle castle, string outputFileName);
	void findLine(Castle &, int, int);
	long long int getTime(long long int, long long int);
};

class FastSAOSolver: public AbstractSAOSolver
{
public:
	void Solve(Castle castle, string outputFileName);
};

#endif /* abstractsaosolver_h */
