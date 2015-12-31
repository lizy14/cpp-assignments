#pragma once
/*

����������Ϣ��

�ɴ��ļ��ж�ȡ��Ϣ
��Listģ����ʹ��
ʵ���ļ� Persons.cpp

������
������2015-6-5	
*/

#include <fstream>
#include <direct.h>
#include <iostream>
#include "List.h"
using namespace std;

//����
class Person{
public:
	char name[20];             // ����
	int  strength;             // ����
	int  intelligence;         // ����
	int  power;                // ����
	int  charisma;             // ����
	int  luck;                 // ����
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