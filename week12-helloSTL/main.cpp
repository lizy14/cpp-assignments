//cpp
//2015-5-26
//清华大学软件学院 李肇阳
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#include "print_r.h"

int main(int argc, char *argv[]){
	fstream file("data.txt");
	int input;
	vector<int> data;
	set<int> dataSet;
	while(!file.eof()){
		file >> input;
		data.push_back(input);
		dataSet.insert(input);
	}
	cout << "original: \n" << data;
	sort(data.begin(),data.end());
	cout << "after sorting: \n" << data;
	cout << "after removal of duplicates: \n" << dataSet;
}