#include "globals.h"
/*
�ļ���: Castle.h
�衡��: �Ǳ���ͼ�������

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-07-22
*/



#pragma once
#include <string>
using namespace std;
#include <vector>




/*
����һ��Castle�࣬��¼���γǱ������������ء������з��䡢ͨ������Ϣ��
���к��к���void LoadData(string inputFileName)���������ļ��ж�ȡ�Ǳ���Ϣ��
*/
class CastleLevel;
class Castle;
class CastleRoom;
class CastlePath;

class CastleRoom{
public:
	int MS;//�����ǿ׳�� 
	int GSM;//��������������� GS װ��ֵ, ��������ʱ��MS = GSM = 0
	int R;//�÷����б�������Ӧ��װ������ֵ, û�б���ʱ, R = 0
	bool U;//�÷����Ƿ���ͨ���ϲ�Ĵ�����
	CastleLevel* level;//����¥�� //WARNING: UNSAFE
	int id;//������ CastleLevel::rooms[] �е��±�һ��, +1 Ϊ���
public:
	CastleRoom(int MS_, int GSM_, int R_, char U_, CastleLevel* level_, int id_);
	CastleRoom(){}
};
class CastlePath{
	//�������������·��
public:
	int idS, idE;//��·��ֹ�㣬ά�� idS < idE
	int T;//��·���ȣ�������ʱ��
	CastleLevel* level;//����¥�� //WARNING: UNSAFE
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
	Castle* castle;//�����Ǳ� //WARNING: UNSAFE
	int id;//������ Castle::levels[] �е��±�һ��
	//TODO: û��д�������캯��
	//WARNING: UNSAFE

	int connected(int roomA, int roomB);
};
class Castle{
public:
	int nLevels;
	vector<CastleLevel> levels;
public:
	void LoadData(string inputFileName);//���ļ���ȡ�Ǳ�
	void randomize();//���Ǳ����������ÿһ��ı߼��������˳��
	int nRooms();
	//TODO: û��д�������캯��
	//WARNING: UNSAFE
};
