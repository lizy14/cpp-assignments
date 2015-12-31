#ifndef CALENDAR_H
#define CALENDAR_H


int isLeapYear(int year);
int dayInMonth(int year, int month);

class Calendar{
private:
	int year, month, day;
public:
	Calendar(){}
	void getDateFromUser();
	int  getDateFromSystem();
	void printDate(char*);
	int  setDate(int, int, int);
	void increaseOneDay();
	void decreaseOneDay();
	void increaseDays(int d){
		int i;
		for(i=0;i<d;i++)
			increaseOneDay();
	};
	void decreaseDays(int d){
		int i;
		for(i=0;i<d;i++)
			decreaseOneDay();
	};
	void moveDays(int d){
		if(d>0){
			increaseDays(d);
		}else{
			decreaseDays(-d);
		}
	};
};

#endif