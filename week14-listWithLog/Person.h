#pragma once
/*

三国人物信息类

可从文件中读取信息
供List模板类使用
实现文件 Persons.cpp

李肇阳
创建于2015-6-5	
*/

#include <fstream>
#include <direct.h>
#include <iostream>
#include "List.h"
using namespace std;

//声明
class Person{
public:
	char name[20];             // 姓名
	int  strength;             // 体力
	int  intelligence;         // 智力
	int  power;                // 武力
	int  charisma;             // 魅力
	int  luck;                 // 运气
	int  sum();
	Person(Person&);
	Person();
};
ostream& operator<< (ostream& os, Person& node);
void getPersonsFromFile(List<Person> & r, char* fileName);


int compareByPower(Person A, Person B);
int compareBySum(Person A, Person B);

void reportFileFailure();
void getPersonsFromFile(List<Person> & r, char* fileName);
ostream& operator<< (ostream& os, Person& node);