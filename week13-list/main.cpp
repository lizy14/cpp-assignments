#include "List.h"
#include "Person.h"
#include <iostream>
using namespace std;

void testList();
void testListPersonSort();

int main(){
	testListPersonSort();
	//testList();
	return 0;
}

void testListPersonSort(){
	List<Person> list;
	getPersonsFromFile(list, "persons.txt");
	cout << "原始数据：" << list;
	bubbleSort(list, &compareByPower);
	cout << "按武力排序后：" << list;
	bubbleSort(list, &compareBySum);
	cout << "按总分排序后：" << list;
}
void testList(){
	List<int> list;
	list.createNode()->entity=-5;
	list.createNode()->entity=666;
	list.createNode(2333);
	cout << list;
	list.removeNode(list.findNext());
	cout << list;
}
