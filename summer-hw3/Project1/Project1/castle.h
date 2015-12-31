//
//  castle.h
//  hw3
//
//  Created by 曹张杰 on 7/22/15.
//  Copyright ? 2015 曹张杰. All rights reserved.
//

#ifndef castle_h
#define castle_h

#include <iostream>
#include <vector>
using namespace std;

class BruteSAOSolver;

struct node_in_line
{
	long long strength;
	int node_num;
	long long time;
};

class Castle
{
private:
	friend class BruteSAOSolver;
	friend class FastSAOSolver;
	struct node
	{
		long long least_equipment;
		long long strength_of_monster;
		long long bonus;
		long long strength_for_node;
	};

	struct layer
	{
		vector<node_in_line> line;
		int node_number;            //存储节点数
		int edge_number;            //存储边数
		node * all_node;            //存储节点信息
		long long ** all_edge;      //存储节点间的边权重
	};

	int layer_number;
	layer * all_layer;
	vector<vector<node_in_line> > best_line;
	long long all_time;
public:
	Castle(){ all_layer = nullptr; }
	void LoadData(string inputFileName);

};


#endif /* castle_h */
