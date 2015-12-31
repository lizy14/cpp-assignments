#include "globals.h"
/*
文件名: Castle.h
描　述: 城堡地图类的声明

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-07-22
*/



#pragma once
#include <string>
using namespace std;
#include <vector>




/*
定义一个Castle类，记录浮游城堡“艾恩葛朗特”的所有房间、通道等信息。
类中含有函数void LoadData(string inputFileName)，用来从文件中读取城堡信息。
*/
class CastleLevel;
class Castle;
class CastleRoom;
class CastlePath;

class CastleRoom{
public:
	int MS;//怪物的强壮度 
	int GSM;//消灭怪物所需的最低 GS 装备值, 不含怪物时，MS = GSM = 0
	int R;//该房间中宝箱所对应的装备增量值, 没有宝箱时, R = 0
	bool U;//该房间是否有通往上层的传送门
	CastleLevel* level;//所属楼层 //WARNING: UNSAFE
	int id;//与其在 CastleLevel::rooms[] 中的下标一致, +1 为编号
public:
	CastleRoom(int MS_, int GSM_, int R_, char U_, CastleLevel* level_, int id_);
	CastleRoom(){}
};
class CastlePath{
	//连接两个房间的路径
public:
	int idS, idE;//道路起止点，维护 idS < idE
	int T;//道路长度（行走用时）
	CastleLevel* level;//所属楼层 //WARNING: UNSAFE
public:
	CastlePath(int idA_, int idB_, int T_, CastleLevel* level_);
	CastlePath(){}
};
class CastleLevel{
public:
	int nRooms;
	int nPaths;
	vector<CastleRoom> rooms;
	vector<CastlePath> paths;
	Castle* castle;//所属城堡 //WARNING: UNSAFE
	int id;//与其在 Castle::levels[] 中的下标一致
	//TODO: 没有写拷贝构造函数
	//WARNING: UNSAFE

	int connected(int roomA, int roomB);
};
class Castle{
public:
	int nLevels;
	vector<CastleLevel> levels;
public:
	void LoadData(string inputFileName);//从文件读取城堡
	void randomize();//将城堡随机化！将每一层的边集随机打乱顺序。
	int nRooms();
	//TODO: 没有写拷贝构造函数
	//WARNING: UNSAFE
};
