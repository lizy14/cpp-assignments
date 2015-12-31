#include "globals.h"
/*
文件名: Castle.cpp
描　述: Castle.h 对应实现

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-07-22
*/
#include "Castle.h"
#include <fstream>
#include <algorithm>
int Castle::nRooms(){
	int ret=0;
	typedef vector<CastleLevel>::iterator LevelIterator;
	LevelIterator end = levels.end();
	for(LevelIterator i=levels.begin(); i != end; ++i){
		ret+=(*i).nRooms;
	}
	return ret;
}
void Castle::LoadData(string inputFileName){
	ifstream file(inputFileName);
	file >> nLevels;
	levels.resize(nLevels-1);
	for(int i=0; i<nLevels-1; i++){
		//read a level
		CastleLevel& level=levels[i];
		level.castle=this;
		level.id=i;
		file >> level.nRooms >> level.nPaths;
		levels[i].rooms.resize(levels[i].nRooms);
		levels[i].paths.resize(levels[i].nPaths);
		for(int j=0; j<levels[i].nRooms; j++){
			int MS_; int GSM_; int R_; char U_;
			file >> MS_ >> GSM_ >> R_ >> U_;
			levels[i].rooms[j]=(CastleRoom(MS_, GSM_, R_, U_, &level, j));
		}
		for(int j=0; j<levels[i].nPaths; j++){
			int A_; int B_; int T_;
			file >> A_ >> B_ >> T_;
			levels[i].paths[j]=(CastlePath(A_-1, B_-1, T_, &level));
		}
		//end of reading a level
	}
}
void Castle::randomize(){
	for(int i=0; i<nLevels-1; i++){
		random_shuffle(levels[i].paths.begin(),levels[i].paths.end());
	}
}
CastlePath::CastlePath(int idA_, int idB_, int T_, CastleLevel* level_){
	if(idA_>idB_){
		//swap idA_ with idB_ to ensure that idA_ < idB_
		int idTmp; idTmp=idA_, idA_=idB_, idB_=idTmp;
	}
	idS=idA_, idE=idB_, T=T_, level=level_;
}
CastleRoom::CastleRoom(int MS_, int GSM_, int R_, char U_, CastleLevel* level_, int id_){
	MS=MS_, GSM=GSM_, R=R_, U=('Y'==U_), level=level_, id=id_;
}
int CastleLevel::connected(int idA_, int idB_){
	if(idA_==idB_) return 0;
	if(idA_>idB_){
		//swap idA_ with idB_ to ensure that idA_ < idB_
		int idTmp; idTmp=idA_, idA_=idB_, idB_=idTmp;
	}
	typedef vector<CastlePath>::iterator PathIterator;
	PathIterator end = paths.end();
	for(PathIterator i=paths.begin(); i != end; ++i){
		if((*i).idS == idA_ && (*i).idE == idB_)
			return (*i).T;
	}
	return 0;
}