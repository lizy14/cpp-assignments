#include <iostream>

using namespace std;

#include "getInteger.h"

int getInteger(char* prompt)
{
	int result = 0;
	do{
		cout << "������" << prompt << " [һ������]��" << endl << ">";
		cin >> result;
		if (cin.good())
			break;
		else{
			if(cin.eof()){
				cout << "���뱻��ֹ�����������" << endl;
				break;
			} //end if
			cout << "�����ʽ�������������롣" << endl;
			cin.clear();
			cin.sync(); 
		} //end if
	}
	while(233); 
	return result;
} // end function