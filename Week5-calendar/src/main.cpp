#include <iostream>
#include "calendar.h"
#include "getInteger.h"
using namespace std;
int main(){
	Calendar calendar;
	if(calendar.getDateFromSystem()){//failed to get date from system
		calendar.getDateFromUser();
		cout << "您输入的日期是：";
	}else{
		cout << "当前日期是：";
	}
	calendar.printDate("-");
	while(233){
		calendar.moveDays(getInteger("改变的天数"));
		cout << "改变后的日期是："; calendar.printDate("-");
	}
}