#include "abstractsaosolver.h"


int main(int argc, const char * argv[]) {
	// insert code here...
	Castle new_castle;
	new_castle.LoadData(string("my.txt"));
	BruteSAOSolver new_solver;
	new_solver.Solve(new_castle, "new.txt");
	return 0;
}
