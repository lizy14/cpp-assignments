//
//  main.cpp
//  hw3
//
//  Created by ���Ž� on 7/22/15.
//  Copyright ? 2015 ���Ž�. All rights reserved.
//

#include "abstractsaosolver.h"


int main(int argc, const char * argv[]) {
	// insert code here...
	Castle new_castle;
	new_castle.LoadData(string("my.txt"));
	BruteSAOSolver new_solver;
	new_solver.Solve(new_castle, "2333");
	return 0;
}
