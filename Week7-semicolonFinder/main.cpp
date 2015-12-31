

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

	cout << "请输入文件名：\n>";
	cin  >> filename;
	*/
	getFileName:char filename[100]="data.txt";


	ifstream inFile;
	inFile.open(filename, ios::in);
	if(!inFile){
		cout << "无法打开 " << filename <<" ！\n";
		goto getFileName;//期中考试周你懂的，图省事用 goto 了求不扣分
	}
	//end of open inFile

	ofstream logFile("log.txt", ios::out);
	if(!logFile){cout << "无法打开 log.txt 进行写入！"; return 0;}
	logFile << "时间：" << time(NULL) << "\n文件名：" << filename << "\n";


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
	if(!logFile){cout << "无法打开 " << filename <<" 进行写入！"; return 0;}
	//end of open outFile



	int nSemicolon=0;
	int nWrongSemicolon=0;
	char buffer[MAX_LINE_LENGTH];
	char chr;
	while (!inFile.eof()){
		inFile.get(buffer, MAX_LINE_LENGTH, ';');
		inFile.clear();
		outFile << buffer;

		//应对 get() 因到达 _Count 而停止
		if(inFile.eof())break;
		inFile.get(chr);
		outFile << chr;
		if(inFile.eof())break;
		if(chr != ';')continue;

		findSemicolon:
		nSemicolon ++;

		//检查下一个字符
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
		//此行用于应对连续多个分号。
		//我知道 goto 破坏结构化不该用。。但是实在没办法求原谅:(
	}

	logFile << "共发现 " << nSemicolon << " 个分号，其中 " << nWrongSemicolon << " 个不合规范。\n";
	inFile.close();
	outFile.close();


	logFile.close();

	cout << "\n格式检查完成。\n共发现 " << nSemicolon << " 个分号，其中 " << nWrongSemicolon << " 个不合规范。\n";
	cout << "\n已将格式化后的代码保存至 " << filename << "，日志已保存至 log.txt。\n";
	return 0;
}