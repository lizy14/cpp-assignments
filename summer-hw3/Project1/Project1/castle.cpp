//
//  castle.cpp
//  hw3
//
//  Created by 曹张杰 on 7/22/15.
//  Copyright ? 2015 曹张杰. All rights reserved.
//

#include <fstream>
#include "castle.h"

void Castle::LoadData(string inputFileName)
{
	best_line = vector<vector<node_in_line> >();
	all_time = 0;
	//ifstream fin(inputFileName.c_str());
	//fin >> layer_number;
	cin >> layer_number;
	if (layer_number <= 0)
	{
		cout << "层数错误" << endl;
	}
	else
	{
		all_layer = new layer[layer_number];
		for (int i = 0; i < layer_number; i++)
		{
			//fin >> all_layer[i].node_number;
			//fin >> all_layer[i].edge_number;
			cin >> all_layer[i].node_number;
			cin >> all_layer[i].edge_number;
			all_layer[i].all_node = new node[all_layer[i].node_number];
			all_layer[i].all_edge = new long long *[all_layer[i].node_number + 1];
			for (int k = 0; k < all_layer[i].node_number + 1; k++)
			{
				all_layer[i].all_edge[k] = new long long[all_layer[i].node_number + 1];
				for (int l = 0; l < all_layer[i].node_number + 1; l++)
				{
					all_layer[i].all_edge[k][l] = -1;
				}
			}

			/*//初始化每条边
			all_layer[i].from_to = new long long *[all_layer[i].node_number];
			all_layer[i].from_to = new long long [all_layer[i].node_number];
			for(int k = 0; k < all_layer[i].node_number; k++)
			{
			for(int l = 0; l < all_layer[i].node_number; l++)
			{
			all_layer[i].all_edge[k][l] = -1;
			}
			}*/

			//存每个节点的数据区
			for (int j = 0; j < all_layer[i].node_number; j++)
			{
				//fin >> all_layer[i].all_node[j].strength_of_monster;
				//fin >> all_layer[i].all_node[j].least_equipment;
				//fin >> all_layer[i].all_node[j].bonus;
				cin >> all_layer[i].all_node[j].strength_of_monster;
				cin >> all_layer[i].all_node[j].least_equipment;
				cin >> all_layer[i].all_node[j].bonus;
				//while(fin.get() != ' ')
				//   ;
				while (cin.peek() == ' ' || cin.peek() == '\n')
					cin.get();
				//if(fin.get() == 'Y')
				if (cin.get() == 'Y')
				{
					all_layer[i].all_edge[j][all_layer[i].node_number] = -2;
				}
			}



			//存起点和终点，边
			int temp_from;
			int temp_to;
			for (int r = 0; r < all_layer[i].edge_number; r++)
			{
				//fin >> temp_from;
				//fin >> temp_to;
				//fin >> all_layer[i].all_edge[temp_from][temp_to];
				cin >> temp_from;
				cin >> temp_to;
				cin >> all_layer[i].all_edge[temp_from - 1][temp_to - 1];
				long long a = all_layer[i].edge_number;
				all_layer[i].all_edge[temp_from - 1][temp_to - 1] = all_layer[i].all_edge[temp_to - 1][temp_from - 1];
			}

			all_layer[i].line = vector<node_in_line>();

			//第一层第一个节点的初始化
			if (i == 0)
			{
				node_in_line * p = new node_in_line;
				p->node_num = 0;
				p->strength = 100;
				p->time = 0;
				all_layer[i].line.push_back(*p);
			}
		}
	}
	//fin.close();
}
