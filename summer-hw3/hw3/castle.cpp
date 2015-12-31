#include <fstream>
#include "castle.h"

void Castle::LoadData(string inputFileName)
{
    best_line = vector<vector<node_in_line> >();
    all_time = LLONG_MAX;
    ifstream fin(inputFileName);
    fin >> layer_number;
    if(layer_number <= 0)
    {
        cout << "层数错误" << endl;
    }
    else
    {
        all_layer = new layer[layer_number];
		all_layer[layer_number - 1].all_edge = nullptr;
		all_layer[layer_number - 1].all_node = new node;
		all_layer[layer_number - 1].all_node[0].least_equipment = 0;
		all_layer[layer_number - 1].all_node[0].bonus = 0;
		all_layer[layer_number - 1].all_node[0].strength_of_monster = 0;
		all_layer[layer_number - 1].node_number = 1;
		all_layer[layer_number - 1].edge_number = 1;
		all_layer[layer_number - 1].line = vector<node_in_line>();

		current_strength = new long long*[layer_number];
		current_strength[layer_number - 1] = new long long;
		current_strength[layer_number - 1][0] = 0;
        for(int i = 0; i < layer_number - 1; i++)
        {
            fin >> all_layer[i].node_number;
            fin >> all_layer[i].edge_number;
            all_layer[i].all_node = new node [all_layer[i].node_number];
            all_layer[i].all_edge = new long long int *[all_layer[i].node_number + 1];
			current_strength[i] = new long long[all_layer[i].node_number];
            for(int k = 0; k < all_layer[i].node_number + 1; k++)
            {
                all_layer[i].all_edge[k] = new long long int [all_layer[i].node_number + 1];
                for(int l = 0; l < all_layer[i].node_number + 1; l++)
                {
                    all_layer[i].all_edge[k][l] = -1;
                }
            }
            
            /*//初始化每条边
             all_layer[i].from_to = new long long int *[all_layer[i].node_number];
             all_layer[i].from_to = new long long int [all_layer[i].node_number];
             for(int k = 0; k < all_layer[i].node_number; k++)
             {
             for(int l = 0; l < all_layer[i].node_number; l++)
             {
             all_layer[i].all_edge[k][l] = -1;
             }
             }*/
            
            //存每个节点的数据区
            for(int j = 0; j < all_layer[i].node_number; j++)
            {
				current_strength[i][j] = 0;
                fin >> all_layer[i].all_node[j].strength_of_monster;
                fin >> all_layer[i].all_node[j].least_equipment;
                fin >> all_layer[i].all_node[j].bonus;
                while(fin.peek() == ' ' || fin.peek() == '\n')
                    fin.get();
                if(fin.get() == 'Y')                
                {
                    all_layer[i].all_edge[j][all_layer[i].node_number] = -2;
                }
            }
            
            
            
            //存起点和终点，边
            int temp_from;
            int temp_to;
            for(int r = 0; r < all_layer[i].edge_number; r++)
            {
                fin >> temp_from;
                fin >> temp_to;
                fin >> all_layer[i].all_edge[temp_from - 1][temp_to - 1];
                all_layer[i].all_edge[temp_to - 1][temp_from - 1] 
				= all_layer[i].all_edge[temp_from - 1][temp_to - 1];
            }
            
            all_layer[i].line = vector<node_in_line>();
            
            //第一层第一个节点的初始化
            if(i == 0)
            {
                node_in_line * p = new node_in_line;
                p->node_num = 0;
                p->strength = 100;
                p->time = 0;
                all_layer[i].line.push_back(*p);
				current_strength[0][0] = 100;
            }
        }
    }
    fin.close();
}

Castle::~Castle()
{
	for(int i = 0; i < layer_number; i++)
	{
		delete all_layer->all_node;
		for(int j = 0; j < all_layer[i].node_number; j++)
		{
			delete all_layer[i].all_edge[j];
		}
		delete all_layer[i].all_edge;
	}
	delete all_layer;
}
