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
		int node_number;            //存储节点数
		int edge_number;            //存储边数
		node * all_node;            //存储节点信息
		long long int ** all_edge;      //存储节点间的边权重
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