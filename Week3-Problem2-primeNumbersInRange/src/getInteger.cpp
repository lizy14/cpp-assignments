#include <iostream>

using namespace std;

#include "getInteger.h"

int getInteger(char* prompt)
{
	int result = 0;
	do{
		cout << "请输入" << prompt << " [一个整数]：" << endl << ">";
		cin >> result;
		if (cin.good())
			break;
		else{
			if(cin.eof()){
				cout << "输入被终止。输入结束。" << endl;
				break;
			} //end if
			cout << "输入格式有误，请重新输入。" << endl;
			cin.clear();
			cin.sync(); 
		} //end if
	}
	while(233); 
	return result;
} // end function