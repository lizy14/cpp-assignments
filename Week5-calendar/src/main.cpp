#include <iostream>
#include "calendar.h"
#include "getInteger.h"
using namespace std;
int main(){
	Calendar calendar;
	if(calendar.getDateFromSystem()){//failed to get date from system
		calendar.getDateFromUser();
		cout << "������������ǣ�";
	}else{
		cout << "��ǰ�����ǣ�";
	}
	calendar.printDate("-");
	while(233){
		calendar.moveDays(getInteger("�ı������"));
		cout << "�ı��������ǣ�"; calendar.printDate("-");
	}
}