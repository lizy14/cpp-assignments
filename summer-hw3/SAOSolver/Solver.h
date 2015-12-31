/*
�ļ���: Solver.h
�衡��: SAO �������������

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-07-22
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
����һ��������AbstractSAOSolver�����溬�д��麯��void Solve(Castle castle, string outputFileName)��

��������̳���AbstractSAOSolver��ʵ����Solve������
һ������BruteForceSAOSolver�����е�solve����ͨ���������п��ܴ��ҵ���ý�ķ�����Ѱ�����Ž⣬�������Ž��ӡ������
һ������FastSAOSolver�����е�solve����ͨ����������Ĳ������ҵ��Ϻý⣬�����Ϻý��ӡ������
*/

/*
//TODO:
//WARNING: ���� Castle() ��û��д�������캯��������ȫ������ Solve() ���������÷�ʽ����
*/

class AbstractSAOSolver{
public:
	virtual void Solve(const Castle& castle, string outputFileName)=0;//pure
};

class BruteForceSAOSolver : AbstractSAOSolver{
public:
	int depth;//���ٵݹ���ȣ����ڵ���

	const Castle* castle;//WARNING: UNFASE
	vector<CastleRoom*> track;
	vector<CastleRoom*> bestTrack;
	int trackTime;
	int bestTime;

	
	int GS;
	typedef struct{
		int visited;//��¼�ѱ����ʵĴ������ѱ����������޹֡�>1 ���ѳɻ�����Ҫ�ж��Ƿ�Ϊ��Ч��
		int lastGS;//�ϴη��ʱ������� GS
#ifdef DEBUGGING_OLD_STYLE_GET_TIME
		int timingVisited;//������
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

	void startFrom(const CastleRoom*);//��Ҫ�ݹ麯��
	
	void foundTrack();//������н�

	void printTrack();
	void printBestTrack(int x, ostream& os = cout);

	int getTime(int debugFlag=0);//ͳ��track����ʱ��������������
	int div(int x, int y){
		//����ȡ��
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