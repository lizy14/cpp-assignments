#pragma once
/*

����������Ϣ��

�ɴ��ļ��ж�ȡ��Ϣ
��Listģ����ʹ��

������
������2015-6-5	
*/

#include <fstream>
#include <direct.h>

//����
class Person{
public:
	char name[20];             // ����
	int  strength;             // ����
	int  intelligence;         // ����
	int  power;                // ����
	int  charisma;             // ����
	int  luck;                 // ����
	int  sum(){
		return strength+intelligence+power+charisma+luck;
	}
	Person(Person&);
	Person();
};
ostream& operator<< (ostream& os, Person& node);
void getPersonsFromFile(List<Person> & r, char* fileName);

int compareByPower(Person A, Person B){
	return A.power-B.power;
}
int compareBySum(Person A, Person B){
	return A.sum()-B.sum();
}


//ʵ��
Person::Person(){
	name[0]='\0';
}
Person::Person(Person& src){
	strcpy_s(name, 20, src.name);
	strength=src.strength;
	intelligence=src.intelligence;
	charisma=src.charisma;
	power=src.power;
	luck=src.luck;
}
void reportFileFailure(){
	cout << "��ȡ�ļ�ʧ�ܣ�" << endl;
	char buffer[_MAX_PATH];
	buffer[0] = 0;
	if (_getcwd(buffer, _MAX_PATH)){
		//Gets the current working directory.
		cout << "��ǰ����Ŀ¼��: " << buffer << endl;
	}
}
void getPersonsFromFile(List<Person> & r, char* fileName){
	if (fileName==NULL)
		return;
	ifstream inFile(fileName, ios::in);
	char name[20];
	Person *p = NULL;
	while (!inFile.eof()){
		inFile >> name;
		if(name[0] =='#')
			break;
		if (!inFile.good()){
			reportFileFailure();
			break;
		}
		p = &r.createNode()->entity;
		strcpy_s(p->name, 20, name);
		inFile >> p->strength;             // ����
		inFile >> p->intelligence;         // ����
		inFile >> p->power;                // ����
		inFile >> p->charisma;             // ����
		inFile >> p->luck;                 // ����
	}
	inFile.close();
}

//���׶���ʽ���
//��Ϊһ��Ԫ��
#define tab "    " <<
ostream& operator<< (ostream& os, Person& node){
	os << "Person\n";
	os << tab"(\n";
	os << tab tab"[����] => " << node.name << '\n';
	os << tab tab"[����] => " << node.strength << '\n';
	os << tab tab"[����] => " << node.intelligence << '\n';
	os << tab tab"[����] => " << node.power << '\n';
	os << tab tab"[����] => " << node.charisma << '\n';
	os << tab tab"[����] => " << node.luck << '\n';
	os << tab tab"[�ܷ�] => " << node.sum() << '\n';
	os << tab")";
	return os;
}