#include "globals.h"
/*
文件名: main.cpp
描　述: SAO 解算器的主程序

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-07-22

环　境: Visual Studio 2012 (MSVC++ 11.0)
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
