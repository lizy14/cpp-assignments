#include "globals.h"
/*
�ļ���: Solver.cpp
�衡��: Solver.h ��Ӧʵ��

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-07-22
*/
#include "Solver.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const CastleRoom* BruteForceSAOSolver::getRoom(int levelID, int roomID){
	return &(castle->levels[levelID].rooms[roomID]);
}

void BruteForceSAOSolver::visit(const CastleRoom* room){
	int roomID=room->id;
	int levelID=room->level->id;
#ifdef DEBUGGING_FULL
	cout << "  + " << levelID+1 << ',' << roomID+1 << ", GS= " << GS;
#endif	
	if(!roomFlags[levelID][roomID].visited){
		trackTime += div(room->MS, GS);
		int deltaGS=getRoom(levelID,roomID)->R;
		
#ifdef DEBUGGING_FULL
		cout << " +" << deltaGS;
#endif
		GS += deltaGS;
	}
	
	roomFlags[levelID][roomID].visited+=1;
	roomFlags[levelID][roomID].lastGS=GS;
	track.push_back((CastleRoom*)room);
#ifdef DEBUGGING_FULL
	cout << endl;
#endif
}
void BruteForceSAOSolver::backOut(const CastleRoom* room){
	int roomID=room->id;
	int levelID=room->level->id;
	
#ifdef DEBUGGING_FULL
	cout << "  - " << levelID+1 << ',' << roomID+1 << ", GS= " << GS ;
#endif
	if(roomFlags[levelID][roomID].visited==1){
		
		int deltaGS=getRoom(levelID,roomID)->R;
#ifdef DEBUGGING_FULL
		cout << " -" << deltaGS;
#endif
		GS -= deltaGS;
		trackTime -= div(room->MS, GS);
	}
	
	roomFlags[levelID][roomID].visited-=1;
	roomFlags[levelID][roomID].lastGS=GS;
	track.pop_back();
#ifdef DEBUGGING_FULL
	cout << endl;
#endif
}

//���ݵݹ麯��
#ifdef DEBUGGING_FULL
#define START_FROM_FUNCTION_RETURN {depth--;cout << "    ENDOFTRY ";printTrack();return;}
#else
#define START_FROM_FUNCTION_RETURN {depth--;return;}
#endif
void BruteForceSAOSolver::startFrom(const CastleRoom* room){
	
	if(fastFlag && clock()>expireTime){
		ofstream file(outputFileName);
		file << bestTime <<endl;
		printBestTrack(1, file);
		
		cout << "optimized track: "; printBestTrack(0, cout);
		cout << "total time: " << bestTime << endl;

		exit(0);
		
	}
	//cout << "D" << depth << "| ";
	depth++;
#ifdef DEBUGGING_FULL
	cout << "    BEGINTRY "; printTrack();
#endif
	int funcID=rand();
	

	int roomID=room->id;
	int levelID=room->level->id;

	if(bestTime && trackTime > bestTime){
		START_FROM_FUNCTION_RETURN
	}
	
		

	//���ֿ��н⣺���ڵ��ͨ���յ�
	if(castle->nLevels == levelID+2
		&& room->U){
			foundTrack();
			START_FROM_FUNCTION_RETURN
	}

	//Ѱ�ҿɴ�ڵ�
	int visiting;
	const CastleRoom* visiting_=NULL;

	//�ϲ�
	if(room->U){
		visiting_=&(castle->levels[levelID+1].rooms[0]);
		if(GS >= visiting_->GSM){// && !(levelID == lastBackOutLevelId && visiting == lastBackOutId)){
			visit(visiting_);
			startFrom(visiting_);
			backOut(visiting_);
		}

	}

	//ͬ��
	//typedef vector<CastlePath>::iterator PathIterator;
	//PathIterator end = room->level->paths.end();
	//for(PathIterator i=room->level->paths.begin(); i != end; ++i){
	
	//for(CastlePath i:room->level->paths){
	int nPaths_ = room->level->paths.size();
	for(int j=0; j<nPaths_; j++){
		CastlePath i = room->level->paths[j];

		visiting = -1;
		//if(room->level->connected(roomID,(i).idE))
		if(roomID==(i).idS)
			visiting = (i).idE;
		//if(room->level->connected(roomID,(i).idS))
		if(roomID==(i).idE)
			visiting = (i).idS;
		if(visiting == -1)
			continue;
	
		visiting_=getRoom(levelID, visiting);
		if(GS >= visiting_->GSM 
			&&!(roomFlags[levelID][visiting].visited>=1
				&& GS <= roomFlags[levelID][visiting].lastGS)
			
			){
			visit(visiting_);
			trackTime += room->level->connected(roomID, visiting);
			startFrom(visiting_);
			trackTime -= room->level->connected(roomID, visiting);
			backOut(visiting_);
		}
	}


	START_FROM_FUNCTION_RETURN
}

//���ֿ��н⣡ͳ��ʱ�䲢���� best
void BruteForceSAOSolver::foundTrack(){
	int time_ = getTime();
#ifdef DEBUGGING
	cout << "" << time_ << ": " << trackTime << ": "; printTrack();
#endif
	
	if(bestTime==0 || time_ < bestTime){
		bestTime=time_;
		bestTrack = track;
	}
}
void BruteForceSAOSolver::printBestTrack(int x, ostream& os){
	typedef vector<CastleRoom*>::iterator pRoomIterator;
	pRoomIterator end = bestTrack.end();
	for(pRoomIterator i=bestTrack.begin(); i != end; ++i){
		if(!x){
			if(i==bestTrack.begin())
				os << "1,1 -> ";
			os << (*i)->level->id+1 << ',' <<  (*i)->id+1  <<" -> ";
		}
		else{
			if(i==bestTrack.begin())
				os << (*i)->id+1 << '\n';
			if(i == end-1)
				os << 0;
			else if((*i)->level->id != (*(i+1))->level->id){
				os << 0;
			}else{
				os << (*(i+1))->id+1;
			}

			os << '\n';

		}
	}
	os << '\n';
}
void BruteForceSAOSolver::printTrack(){
	typedef vector<CastleRoom*>::iterator pRoomIterator;
	pRoomIterator end = track.end();
	for(pRoomIterator i=track.begin(); i != end; ++i){
		
			if(i==track.begin())
				cout << "1,1 -> ";
			cout << (*i)->level->id+1 << ',' <<  (*i)->id+1  <<" -> ";
		
		
	}
	cout << '\n';
}
void BruteForceSAOSolver::Solve(const Castle& castle_, string outputFileName_){
	GS=100;
	castle = &castle_;
	outputFileName = outputFileName_;
	//���� roomFlags ����
	roomFlags = new roomFlag *[castle->nLevels-1];
	for(int i=0; i<castle->nLevels-1; i++){
		roomFlags[i]=new roomFlag[castle->levels[i].nRooms];
	}

	for(int i=0; i < castle->nLevels-1; i++){
		for(int j=0; j < castle->levels[i].nRooms; j++){
			roomFlags[i][j].lastGS = -1;
			roomFlags[i][j].visited = 0;
		
		}
	}//���� roomFlags �������

	startFrom(getRoom(0,0));
	
	

	
	cout << "best track: "; printBestTrack(0, cout);
	cout << "total time: " << bestTime << endl;
#ifdef DEBUGGING_OLD_STYLE_GET_TIME
	track=bestTrack;
	getTime(1);
#endif

	ofstream file(outputFileName);
	file << bestTime <<endl;
	printBestTrack(1, file);
	//�ͷ� roomFlags ����
	for(int i=0; i<castle->nLevels-1; i++){
		delete [] roomFlags[i];
	}
	delete roomFlags;
	//�ͷ� roomFlags �������
}
int BruteForceSAOSolver::getTime(int debugFlag){
#ifndef DEBUGGING_OLD_STYLE_GET_TIME
	return trackTime;
#else
	int sumT=0;
	int myGS=100;
	


	for(int i=0; i < castle->nLevels-1; i++){
		for(int j=0; j < castle->levels[i].nRooms; j++){
			roomFlags[i][j].timingVisited = 0;
		}
	}//���� timingVisited ����



	typedef vector<CastleRoom*>::iterator pRoomIterator;
	pRoomIterator end = track.end();
	for(pRoomIterator i=track.begin(); i != end; ++i){
		//��·���ϵ�һ����
		int levelID_=(*i)->level->id;
		int roomID_=(*i)->id;
		
		if(i==track.begin()){
			if((*i)->level->id ==0){
				//�����·�����׸��㡢���ڵ�һ��
				sumT += (*i)->level->connected(0,(*i)->id);
			}
		}
		if(!roomFlags[(*i)->level->id][(*i)->id].timingVisited){
			roomFlags[(*i)->level->id][(*i)->id].timingVisited=1;
			if((*i)->MS){
				//��δ��������㡢������й�
				sumT += div((*i)->MS, (myGS));
			}
			myGS += (*i)->R;
		}
		if(i == end-1)//����������һ����
			continue;

		if((*i)->level->id == ((*(i+1))->level->id)){
			//�������һ������ͬһ��
			sumT += (*i)->level->connected((*(i+1))->id,(*i)->id);
		}
	}


	return sumT;
#endif
}
void FastSAOSolver::Solve(const Castle& castle, string outputFileName){
	BruteForceSAOSolver solver(true);
	solver.expireTime = 4900;
	solver.Solve(castle, outputFileName);
}
