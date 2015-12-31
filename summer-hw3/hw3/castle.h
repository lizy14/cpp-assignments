#ifndef castle_h
#define castle_h

#include <iostream>
#include <vector>
using namespace std;

class BruteSAOSolver;

struct node_in_line
{
	long long int strength;
	int node_num;
	long long int time;
};

class Castle
{
private:
	friend class BruteSAOSolver;
	struct node
	{
		long long int least_equipment;
		long long int strength_of_monster;
		long long int bonus;
		long long int strength_for_node;
	};

	typedef struct
	{
		vector<node_in_line> line;
		int node_number;            //�洢�ڵ���
		int edge_number;            //�洢����
		node * all_node;            //�洢�ڵ���Ϣ
		long long int ** all_edge;      //�洢�ڵ��ı�Ȩ��
	} layer;
	long long **current_strength;
	long long int all_time;
	int layer_number;
	layer * all_layer;
	vector<vector<node_in_line> > best_line;
public:
	Castle(){all_layer = nullptr;}
	void LoadData(string inputFileName);
	~Castle();
};


#endif /* castle_h */