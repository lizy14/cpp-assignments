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
	cout << "ԭʼ���ݣ�" << list;
	bubbleSort(list, &compareByPower);
	cout << "�����������" << list;
	bubbleSort(list, &compareBySum);
	cout << "���ܷ������" << list;
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
