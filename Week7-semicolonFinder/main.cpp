

#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
#define MAX_LINE_LENGTH 10
#define MAX_FILENAME_LENGTH 100


int main(){

	//open inFile


	/*char filename[MAX_FILENAME_LENGTH]={0};
	getFileName:

	cout << "�������ļ�����\n>";
	cin  >> filename;
	*/
	getFileName:char filename[100]="data.txt";


	ifstream inFile;
	inFile.open(filename, ios::in);
	if(!inFile){
		cout << "�޷��� " << filename <<" ��\n";
		goto getFileName;//���п������㶮�ģ�ͼʡ���� goto ���󲻿۷�
	}
	//end of open inFile

	ofstream logFile("log.txt", ios::out);
	if(!logFile){cout << "�޷��� log.txt ����д�룡"; return 0;}
	logFile << "ʱ�䣺" << time(NULL) << "\n�ļ�����" << filename << "\n";


	//open outFile
	char* dot = strrchr(filename, '.');
	if(!dot){
		strcat(filename, ".formatted");
	}else{
		char buffer[MAX_FILENAME_LENGTH]=".formatted";
		strcat(buffer, dot);
		*dot = 0;
		strcat(filename, buffer);
	}//end of generating output filename
	ofstream outFile(filename,ios::out);
	if(!logFile){cout << "�޷��� " << filename <<" ����д�룡"; return 0;}
	//end of open outFile



	int nSemicolon=0;
	int nWrongSemicolon=0;
	char buffer[MAX_LINE_LENGTH];
	char chr;
	while (!inFile.eof()){
		inFile.get(buffer, MAX_LINE_LENGTH, ';');
		inFile.clear();
		outFile << buffer;

		//Ӧ�� get() �򵽴� _Count ��ֹͣ
		if(inFile.eof())break;
		inFile.get(chr);
		outFile << chr;
		if(inFile.eof())break;
		if(chr != ';')continue;

		findSemicolon:
		nSemicolon ++;

		//�����һ���ַ�
		if(inFile.eof())break;
		inFile.get(chr);
		if(inFile.eof())break;
		if(chr=='\r' || chr=='\n'){
			outFile << chr;
		}else{
			nWrongSemicolon ++;
			outFile << "\n" << chr;
		}

		if(chr==';')goto findSemicolon;
		//��������Ӧ����������ֺš�
		//��֪�� goto �ƻ��ṹ�������á�������ʵ��û�취��ԭ��:(
	}

	logFile << "������ " << nSemicolon << " ���ֺţ����� " << nWrongSemicolon << " �����Ϲ淶��\n";
	inFile.close();
	outFile.close();


	logFile.close();

	cout << "\n��ʽ�����ɡ�\n������ " << nSemicolon << " ���ֺţ����� " << nWrongSemicolon << " �����Ϲ淶��\n";
	cout << "\n�ѽ���ʽ����Ĵ��뱣���� " << filename << "����־�ѱ����� log.txt��\n";
	return 0;
}