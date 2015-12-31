#include "getInteger.h"
#include <time.h>
#include "calendar.h"
#include <cstdio>

int isLeapYear(int year){
	return ( (!(year % 4)) && (year % 100) || (!(year % 400)) );
}
const int dayInMonth_[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int dayInMonth(int year, int month){
	if(month==2) return(isLeapYear(year)? 29: 28);
	return dayInMonth_[month-1];
}
void Calendar::getDateFromUser(){
	int input;
	year=getInteger("年份");
	while(!(input=getInteger("月份"),(input>=1&&input<=12))){
		puts("月份不合法！");
	};
	month=input;
	while(!(input=getInteger("日期"),(input>=1&&input<=dayInMonth(year,month)))){
		puts("日期不合法！");
	};
	day=input;
}
int Calendar::getDateFromSystem(){
	time_t timer; 
	time(&timer); 
	tm* t_tm = localtime(&timer); 
	return setDate(t_tm->tm_year+1900,t_tm->tm_mon+1,t_tm->tm_mday);
}
int Calendar::setDate(int year_, int month_, int day_){
	if(!(month_>=1 && month_<=12))return 1;
	if(!(day_>=1 && day_<=dayInMonth(year_, month_)))return 1;
	year=year_, month=month_, day=day_;
	return 0;
}
void Calendar::increaseOneDay(){
	day++;
	if(day>dayInMonth(year,month)){
		month++, day=1;
		if(month>12)year++, month=1;
	}
}
void Calendar::decreaseOneDay(){
	day--;
	if(day<=0){
		month--;
		if(month<=0){
			year--, month=12;
		}
		day=dayInMonth(year, month);
	}
}
void Calendar::printDate(char* separator){
	if(year<0){
		puts("您已回到公元前……");
		return;
	}
	printf("%d%s%d%s%d\n",year,separator,month,separator,day);
	
}