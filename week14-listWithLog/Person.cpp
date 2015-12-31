#include "Person.h"
#include "List.h"

int compareByPower(Person A, Person B){
	return A.power-B.power;
}
int compareBySum(Person A, Person B){
	return A.sum()-B.sum();
}

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
int Person::sum(){
		return strength+intelligence+power+charisma+luck;
}
void reportFileFailure(){
	cout << "读取文件失败！" << endl;
	char buffer[_MAX_PATH];
	buffer[0] = 0;
	if (_getcwd(buffer, _MAX_PATH)){
		//Gets the current working directory.
		cout << "当前工作目录是: " << buffer << endl;
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
		inFile >> p->strength;             // 体力
		inFile >> p->intelligence;         // 智力
		inFile >> p->power;                // 武力
		inFile >> p->charisma;             // 魅力
		inFile >> p->luck;                 // 运气
	}
	inFile.close();
}

//按易读格式输出
//作为一级元素
#define tab "    " <<
ostream& operator<< (ostream& os, Person& node){
	os << "Person\n";
	os << tab"(\n";
	os << tab tab"[姓名] => " << node.name << '\n';
	os << tab tab"[体力] => " << node.strength << '\n';
	os << tab tab"[智力] => " << node.intelligence << '\n';
	os << tab tab"[武力] => " << node.power << '\n';
	os << tab tab"[魅力] => " << node.charisma << '\n';
	os << tab tab"[运气] => " << node.luck << '\n';
	os << tab tab"[总分] => " << node.sum() << '\n';
	os << tab")";
	return os;
}