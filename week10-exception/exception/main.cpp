#include <iostream>
using namespace std;
class unknownInputException{};
class wrongInputException{};
class overflowException{};
class endofInputException{};
int isAddOverflow(int a, int b) {
	__asm {
		mov eax,a
		add eax,b
		jo  overflowed
		xor eax,eax
		jmp no_overflowed
overflowed:
		mov eax,1
no_overflowed:
	}
}
int isMulOverflow(int a, int b) {
	if(a==0 || b==0) return 0;
	if( a >= 0 && b >=0  ) {
		return INT_MAX / a < b;
	}
	else if( a < 0 && b < 0 ) {
		return INT_MAX / a > b;
	}
	else if( a * b == INT_MIN ) {
		return 0;
	}
	else {
		return a < 0 ? isMulOverflow(-a, b) : isMulOverflow(a, -b);
	}
}
#define CharToDigit(x) ((x)-'0')
#define isDigit(x) (((x)>=0 && (x)<=9))
int tryGetInteger(char* prompt){
	cin.clear();
	cin.sync(); 
	int result = 0;
	char input[255]={0};
	cout << "������" << prompt << " [һ������]��" << endl << ">";
	cin.getline(input, 255);
	if(cin.eof()||!strcmp("exit",input))
		throw endofInputException();
	if(!cin.good())
		throw unknownInputException();


	int length=strlen(input);
	// 23
	// 012
	//length=2
	int negative;
	negative=(input[0]=='-');
	for(int i=negative; i<length; i++){
		if(!isDigit(CharToDigit(input[i]))){
			throw wrongInputException();
		}
		if(isMulOverflow(result, 10)||isAddOverflow(result*10, CharToDigit(input[i]))){
			throw overflowException();
		}
		result *= 10;
		result += CharToDigit(input[i]);
	}
	if(negative)result=-result;
	return result;
} // end function
int getInteger(char* prompt){
	int result;
tryAgain:
	result=0;
	try{
		result = tryGetInteger("");
	}
	catch(wrongInputException){
		cout << "�����ʽ���󡣰����Ƿ��ַ������������롣" << endl;
		goto tryAgain;
	}
	catch(overflowException){
		cout << "���������󣬷�������������������롣" << endl;
		goto tryAgain;
	}
	catch(unknownInputException){
		cout << "std::cin �������������ԡ�" << endl;
		goto tryAgain;
	}
	catch(endofInputException){
		cout << "��������ֹ��" << endl;
		return 0;
	}
	return result;
}
int main(){
	cout << "������������� " << getInteger("") << " ��\n";
	return 0;
}