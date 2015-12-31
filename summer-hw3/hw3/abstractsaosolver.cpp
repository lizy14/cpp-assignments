#include "abstractsaosolver.h"

void BruteSAOSolver::Solve(Castle castle, string outputFileName)
{
	findLine(castle, 0, 0);
	ofstream fout;
	fout.open(outputFileName);
	if(fout.is_open())
	{
		fout << castle.all_time << endl;
		for(int i = 0; i < castle.best_line.size())
		{
			for(int j = 0; j < castle.best_line[i].size())
				fout << castle.best_line[i][j].node_num << endl;
		}
	}

}

void BruteSAOSolver::findLine(Castle & castle, int temp_current_node, int temp_current_layer)
{
	int current_layer= temp_current_layer;
	int current_node = temp_current_node;
	long long temp_current;
	long long int temp_bonus;
	long long int temp_equipment;
	long long int temp_strength_of_monster;
	if(current_layer >= (castle.layer_number - 1))
	{
		//如果找到路径成功
		long long int temp_time = 0;
		temp_time += castle.all_layer[current_layer].line[0].time;
		if(castle.all_time > temp_time)
		{
			castle.all_time = temp_time;
			castle.best_line.clear();
			for(int i = 0; i < castle.layer_number; i++)
			{
				castle.best_line.push_back(castle.all_layer[i].line);
			}
		}
		return;
	}

	for(int i = 0; i <= castle.all_layer[current_layer].node_number; i++)
	{
		if(castle.all_layer[current_layer].all_edge[current_node][i] == -1)
			continue;
		if(i < castle.all_layer[current_layer].node_number)
		{
			if(castle.all_layer[current_layer].all_node[i].least_equipment
			> (castle.all_layer[current_layer].line.back()).strength)
				continue;
		}
		if(castle.all_layer[current_layer].all_edge[current_node][i] == -2)
		{
			if(castle.all_layer[current_layer + 1].all_node[0].least_equipment
		> (castle.all_layer[current_layer].line.back()).strength)
			continue;
			node_in_line *q = new node_in_line;
			temp_current = castle.current_strength[current_layer + 1][0];
			temp_bonus = castle.all_layer[current_layer + 1].all_node[0].bonus;
			temp_equipment = castle.all_layer[current_layer + 1].all_node[0].least_equipment;
			temp_strength_of_monster = castle.all_layer[current_layer + 1].all_node[0].strength_of_monster;
			castle.all_layer[current_layer + 1].line.clear();
			q->node_num = 0;
			q->time = getTime(castle.all_layer[current_layer + 1].all_node[0].strength_of_monster,
				castle.all_layer[current_layer].line.back().strength) 
				+ castle.all_layer[current_layer].line.back().time;
			q->strength = castle.all_layer[current_layer].line.back().strength
				+ castle.all_layer[current_layer + 1].all_node[0].bonus;
			castle.current_strength[current_layer + 1][0] = q->strength;
			castle.all_layer[current_layer + 1].line.push_back(*q);
			castle.all_layer[current_layer + 1].all_node[0].bonus = 0;
			castle.all_layer[current_layer + 1].all_node[0].least_equipment = 0;
			castle.all_layer[current_layer + 1].all_node[0].strength_of_monster = 0;
			findLine(castle, 0, current_layer + 1);
			castle.current_strength[current_layer + 1][0] = temp_current;
			castle.all_layer[current_layer + 1].all_node[0].bonus = temp_bonus;
			castle.all_layer[current_layer + 1].all_node[0].least_equipment = temp_equipment;
			castle.all_layer[current_layer + 1].all_node[0].strength_of_monster = temp_strength_of_monster;
		}
		else
		{
			node_in_line *p = new node_in_line;
			p->node_num = i;
			p->time = getTime(castle.all_layer[current_layer].all_node[i].strength_of_monster,
				castle.all_layer[current_layer].line.back().strength)
				+ castle.all_layer[current_layer].line.back().time
				+ castle.all_layer[current_layer].all_edge[current_node][i];
			p->strength = castle.all_layer[current_layer].line.back().strength
				+ castle.all_layer[current_layer].all_node[i].bonus;
			if(p->strength > castle.current_strength[current_layer][i])
			{
				temp_current = castle.current_strength[current_layer][i];
				castle.current_strength[current_layer][i] = p->strength;
				castle.all_layer[current_layer].line.push_back(*p);
				temp_bonus = castle.all_layer[current_layer].all_node[i].bonus;
				temp_equipment = castle.all_layer[current_layer].all_node[i].least_equipment;
				temp_strength_of_monster = castle.all_layer[current_layer].all_node[i].strength_of_monster;
				castle.all_layer[current_layer].all_node[i].bonus = 0;
				castle.all_layer[current_layer].all_node[i].least_equipment = 0;
				castle.all_layer[current_layer].all_node[i].strength_of_monster = 0;
				findLine(castle, i, current_layer);
				castle.all_layer[current_layer].all_node[i].bonus = temp_bonus;
				castle.all_layer[current_layer].all_node[i].least_equipment = temp_equipment;
				castle.all_layer[current_layer].all_node[i].strength_of_monster = temp_strength_of_monster;
				castle.current_strength[current_layer][i] = temp_current;
				castle.all_layer[current_layer].line.pop_back();
			}
			else delete p;
		}
	}
}

long long int BruteSAOSolver::getTime(long long int strength_of_monster, long long int strength_of_man)
{
	if(strength_of_monster % strength_of_man == 0)
	{
		return (strength_of_monster / strength_of_man);
	}
	else
	{
		return ((strength_of_monster / strength_of_man) + 1);
	}
}

void FastSAOSolver::Solve(Castle castle, string outputFileName)
{

}
