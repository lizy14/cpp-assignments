//李肇阳 清华大学软件学院

//创建于 2015-7-20
//to be compiled with Microsoft Visual Studio 2012 (MSVC 11.0)

#include <iostream>
#include <string>
using namespace std;

template<class Type>
Type Max(Type a, Type b){
	return a>b?a:b;
}

int main()
{
	int i = 1;
	int j = 2;
	cout << "Max(i, j): " << Max(i, j) << endl;
	double f1 = 11.1;
	double f2 = 22.2;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;
	string s1 = "AAAAA";
	string s2 = "BBBBB";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;
	return 0;
}

