//
//  abstractsaosolver.h
//  hw3
//
//  Created by ≤‹’≈Ω‹ on 7/22/15.
//  Copyright ? 2015 ≤‹’≈Ω‹. All rights reserved.
//

#ifndef abstractsaosolver_h
#define abstractsaosolver_h

#include "castle.h"

class AbstractSAOSolver
{
public:
	virtual void Solve(Castle castle, string outputFileName) = 0;
};

class BruteSAOSolver : public AbstractSAOSolver
{
public:
	void Solve(Castle castle, string outputFileName);
	void findLine(Castle &, int, int);
	long long getTime(long long, long long);
};

class FastSAOSolver : public AbstractSAOSolver
{
private:
	long long FastSAOSolver::findForLayer(Castle &, int, long long, vector<vector<int> > &);
	void initMatrix(int, int*);
	void initStrengthVector(int, vector<int> &);
	void updateMatrix(int*, Castle &, vector<int> &, int, long long **, int, vector<vector<int> > &, vector<int>, vector<int>);
	long long calc(long long, long long);
	int minValue(vector<long long>);
	bool isIn(vector<int>, int);
	void copyLine(int, int, vector<vector<int> > &, int *, int);
public:
	void Solve(Castle castle, string outputFileName);
};

#endif /* abstractsaosolver_h */
