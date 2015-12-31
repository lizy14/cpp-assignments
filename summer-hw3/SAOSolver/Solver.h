/*
文件名: Solver.h
描　述: SAO 解算器类的声明

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-07-22
*/

#pragma once
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "Castle.h"

#include <cmath>
#include <ctime>
/*
定义一个抽象类AbstractSAOSolver，里面含有纯虚函数void Solve(Castle castle, string outputFileName)。

有两个类继承自AbstractSAOSolver并实现了Solve函数：
一个类是BruteForceSAOSolver。其中的solve函数通过遍历所有可能答案找到最好解的方法来寻找最优解，并将最优解打印出来。
一个类是FastSAOSolver。其中的solve函数通过其他更快的策略来找到较好解，并将较好解打印出来。
*/

/*
//TODO:
//WARNING: 由于 Castle() 类没有写拷贝构造函数，不安全，故在 Solve() 中须以引用方式传递
*/

class AbstractSAOSolver{
public:
	virtual void Solve(const Castle& castle, string outputFileName)=0;//pure
};

class BruteForceSAOSolver : AbstractSAOSolver{
public:
	int depth;//跟踪递归深度，用于调试

	const Castle* castle;//WARNING: UNFASE
	vector<CastleRoom*> track;
	vector<CastleRoom*> bestTrack;
	int trackTime;
	int bestTime;

	
	int GS;
	typedef struct{
		int visited;//记录已被访问的次数。已被访问则已无怪。>1 则已成环，需要判定是否为无效环
		int lastGS;//上次访问本房间后的 GS
#ifdef DEBUGGING_OLD_STYLE_GET_TIME
		int timingVisited;//已弃用
#endif
	} roomFlag;
	roomFlag **roomFlags;

	bool fastFlag;
	int expireTime;

public:
	string outputFileName;
	void Solve(const Castle& castle_, string outputFileName);
	
	const CastleRoom* getRoom(int levelID, int roomID);

	void visit(const CastleRoom*);
	void backOut(const CastleRoom*);

	void startFrom(const CastleRoom*);//主要递归函数
	
	void foundTrack();//处理可行解

	void printTrack();
	void printBestTrack(int x, ostream& os = cout);

	int getTime(int debugFlag=0);//统计track的用时。本函数已弃用
	int div(int x, int y){
		//向上取整
		if(y==0 || x==0) return 0;
		return (x+y-1)/y;
	}
	void init(){
		depth=0; 
		bestTime = 0;
		trackTime=0;
	}
	BruteForceSAOSolver(bool fastFlag_=false){
		init();
		fastFlag = fastFlag_;
	}
};

class FastSAOSolver : AbstractSAOSolver{
public:
	void Solve(const Castle& castle, string outputFileName);
};