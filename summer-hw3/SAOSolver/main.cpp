#include "globals.h"
/*
�ļ���: main.cpp
�衡��: SAO ��������������

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-07-22

������: Visual Studio 2012 (MSVC++ 11.0)
*/


#include "Castle.h"
#include "Solver.h"

#include "timing.h"

#define INPUT_FILE_NAME "castleMap.txt"
#define OUTPUT_FILE_NAME "castleSolution.txt"
int main(int argc, char *argv[]){
	srand(time(NULL));
	Castle castle;
	Timing timer;timer.start();
	
	castle.LoadData(INPUT_FILE_NAME);
	castle.randomize();
#ifdef DEBUGGING
	cout << "Castle Loaded. " << endl;
#endif
#ifdef DEBUGGING_ALL_RUN_BRUTE_FORCE
	if(1){
#else
	if(castle.nRooms() <= 10){
#endif
		BruteForceSAOSolver().Solve(castle, OUTPUT_FILE_NAME);
	}else{
		FastSAOSolver().Solve(castle, OUTPUT_FILE_NAME);
	}
	
	timer.end();timer.reportCPUtime();
	return 0;
}
