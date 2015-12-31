#include"abstractsaosolver.h"
#include<fstream>
#include<algorithm>
void FastSAOSolver::Solve(Castle castle, string outputFileName)
{
	long long temp_strength;
	vector<vector<int> > better_line;
	ofstream fout;

	fout.open(outputFileName);
	if (!fout.is_open())
	{
		cout << "文件无法打开。" << endl;
		return;
	}

	better_line = vector<vector<int> >();
	temp_strength = 100;
	for (int i = 0 ; i < castle.layer_number; i++)
	{
		temp_strength = findForLayer(castle, i, temp_strength, better_line);
	}

	fout << castle.all_time;
	for (int j = 0; j < castle.layer_number - 1; j++)
	{
		for (int i = 0; i < better_line[j].size(); i++)
		{
			fout << better_line[j][i] << endl;
		}
	}
	fout.close();
}

long long FastSAOSolver::findForLayer(Castle & castle, int current_layer, long long strength, vector<vector<int> > & line) //所有路径倒着记录
{
	vector<int> go_on;     //记录可以上一层的节点
	int number_of_equipment;
	vector<int> node_number_of_equipment;
	int start_node;
	int *matrix;         //存储路径的矩阵
	vector<int> strength_vector;  //存储当前能力值的向量,在到达该节点之前

	number_of_equipment = 0;
	matrix = nullptr;
	initMatrix(castle.all_layer[current_layer].node_number, matrix);
	initStrengthVector(castle.all_layer[current_layer].node_number, strength_vector);
	for(int i = 0; i < castle.all_layer[current_layer].node_number; i++)
	{
		if(castle.all_layer[current_layer].all_edge[i][castle.all_layer[current_layer].node_number] == -2)
			go_on.push_back(i);
	}

	for (int i = 0; i < castle.all_layer[current_layer].node_number; i++)
	{
		if (castle.all_layer[current_layer].all_node[i].bonus > 0)
		{
			number_of_equipment++;
			node_number_of_equipment.push_back(i);
		}
	}
	sort(node_number_of_equipment.begin(), node_number_of_equipment.end());
	start_node = 0;
	updateMatrix(matrix, castle, strength_vector, start_node, 
		castle.all_layer[current_layer].all_edge, current_layer, line, go_on, node_number_of_equipment);
	//更新源节点到宝箱和出口距离及能力值...
	//为已探知的宝箱设立其边矩阵

	long long *temp_buffer; //用来存临时数据
	
	for(int i = 0; i < line.size(); i++)
	{
		if(line[i][0] == 1)
		{
			for(int j = 2; j < line[i].size(); j++)
			{
				temp_buffer = new long long[3*(line[i].size()- 3)];
				temp_buffer[(j-3) * 3] = castle.all_layer[current_layer].all_node[j].bonus;
				castle.all_layer[current_layer].all_node[j].bonus = 0;
				temp_buffer[(j-3) * 3 + 1] = castle.all_layer[current_layer].all_node[j].least_equipment;
				castle.all_layer[current_layer].all_node[j].least_equipment = 0;
				temp_buffer[(j-3) * 3 + 2] = castle.all_layer[current_layer].all_node[j].strength_of_monster;
				castle.all_layer[current_layer].all_node[j].strength_of_monster = 0;
			}
			start_node = line[i][2];
			initMatrix(castle.all_layer[current_layer].node_number, matrix);
			updateMatrix(matrix, castle, strength_vector, start_node, 
			castle.all_layer[current_layer].all_edge, current_layer, line, go_on, node_number_of_equipment);
			for(int j = 2; j < line[i].size(); j++)
			{
				temp_buffer = new long long[3*(line[i].size()- 3)];
				castle.all_layer[current_layer].all_node[j].bonus = temp_buffer[(j-3) * 3];
				castle.all_layer[current_layer].all_node[j].least_equipment = temp_buffer[(j-3) * 3 + 1];
				castle.all_layer[current_layer].all_node[j].strength_of_monster = temp_buffer[(j-3) * 3 + 2];
			}
		}
	}

	/*if(current_layer <= 0.46 * castle.layer_number)
	{
		strengthStrategy(line);
	}
	else if(current_layer <= 0.66 * castle.layer_number)
	{
		middleStrategy(line);
	}
	else
	{
	timeStrategy(line);
	vector<vector<int> > &
	}*/
}

void FastSAOSolver::initMatrix(int node_number, int *matrix)
{
	if (matrix == nullptr)
	{
		matrix = new int [node_number];
	}
	for (int i = 0; i < node_number; i++)
	{
		matrix[i] = -1;
	}
}

void FastSAOSolver::initStrengthVector(int node_number, vector<int> & vector1)
{
	vector1.clear();
	for (int j = 0; j < node_number; j++)
	{
		vector1.push_back(0);
	}
}

void FastSAOSolver::updateMatrix(int *matrix, Castle & castle, vector<int> & strength_vector,
								 int start_node, long long **edge_matrix, int layer_number, 
								 vector<vector<int> > & line, vector<int> go_on, vector<int> node_equipment)
{
	vector<int> temp_node;
	int node_number;
	int index;
	long long temp_time = 0;

	node_number = strength_vector.size();
	vector<long long> time(LLONG_MAX, node_number);
	int temp = strength_vector[start_node];
	strength_vector.clear();
	for (int i = 0; i < node_number; i++)
	{
		strength_vector.push_back(0);
	}
	strength_vector[start_node] = temp;
	time[start_node] = calc(castle.all_layer[layer_number].all_node[start_node].strength_of_monster, strength_vector[start_node]);
	for (int i = 0; i < node_number; i++)
	{
		if (edge_matrix[start_node][i] != -1)
		{
			temp_node.push_back(i);
			strength_vector[i] = strength_vector[start_node];
			time[i] += (time[start_node] + calc(castle.all_layer[layer_number].all_node[i].strength_of_monster, strength_vector[start_node]));
			matrix[i] = start_node;
			time[start_node] = LLONG_MAX;   //这个节点的时间之后好、不会再用，防止对minValue的筛选有干扰
		}
	}
	while(1)
	{
		index = minValue(time);
		for(int i = 0; i < node_number; i++)
		{
			if(isIn(temp_node, i))
			{
				continue;
			}
			temp_time = time[start_node] 
			+ calc(castle.all_layer[layer_number].all_node[i].strength_of_monster, strength_vector[index]);
			
			if(temp_time < time[i])   //如果时间比现有最小时间短，更新数据
			{
				time[i] = temp_time;
				matrix[i] = index;
				strength_vector[i] = strength_vector[index];
			}
		}
		if(time[index] == LLONG_MAX - 1)
			break;
		time[index] = LLONG_MAX - 1;
		temp_time = 0;
	}
	for(int i = 0; i < node_equipment.size(); i++)  //建立起点到宝箱的路径
	{
		if(time[i] < LLONG_MAX)
		{
			copyLine(start_node, i, line, matrix, 1);
		}
	}

	for(int j = 0; j < go_on.size(); j++)   //建立起点到上楼点的路径
	{
		if(time[j] < LLONG_MAX)
		{
			copyLine(start_node, j, line, matrix, 0);
		}
	}
}

void FastSAOSolver::copyLine(int start, int dst, vector<vector<int> > & line, int * matrix, int flag)
{
	int temp_;    //找节点用的辅助变量
	vector<int> *temp = new vector<int>();
	temp->push_back(flag);
	temp->push_back(start);
	temp->push_back(dst);
	temp_ = dst;
	while(temp_ != start)
	{
		temp->push_back(matrix[temp_]);
		temp_ = matrix[temp_];
	}
	line.push_back(*temp);
	return;
}

long long FastSAOSolver::calc(long long number1, long long number2)
{
	if (number1 % number2 == 0)
	{
		return (number1 / number2);
	}
	else
	{
		return (number1 / number2) + 1;
	}
}

int FastSAOSolver::minValue(vector<long long> my_vector)
{
	int len = my_vector.size();
	int temp = my_vector[0];
	int i;
	for(i = 1; i < len; i++)
	{
		if(temp > my_vector[i])
		{
			temp = my_vector[i];
		}
	}
	return i;
}

bool FastSAOSolver::isIn(vector<int> my_vector, int num)
{
	int len = my_vector.size();
	int i;
	for(i = 1; i < len; i++)
	{
		my_vector[i] = num;
		return true;
	}
	return false;
}


