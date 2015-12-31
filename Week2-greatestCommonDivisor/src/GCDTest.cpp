#include "GCDTest.h"
#include <ctime>
#include <iostream>
using namespace std;
void GCDCalc(){
	pairInteger pair;
	pair.getPair();
	pair.printPair();
	cout << pair.GCD(pairInteger::flagMethod::Euclidean);
	return;
}
void GCDTest(){

	pairInteger pair;
	Integer a[]={1,2,3,4,5,6,7,8,9,10,20,40,50,80,110,233,235,1024,2040,4095};
	int n=sizeof(a)/sizeof(Integer);
	int i,j,k;
	int nSame=0, nDifferent=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			Integer GCD[4];
			pair.setPair(a[i], a[j]);
			GCD[0]=pair.GCD(pairInteger::flagMethod::Try);
			GCD[1]=pair.GCD(pairInteger::flagMethod::Euclidean);
			pair.setPair(a[j], a[i]);
			GCD[2]=pair.GCD(pairInteger::flagMethod::Try);
			GCD[3]=pair.GCD(pairInteger::flagMethod::Euclidean);
			cout << "���Ե� " << i*n+j+1 << " ��: (" << a[i] << ", " << a[j] << ")������ǣ�";
			for(k=0;k<4;k++){
				cout << GCD[k] << ", ";
			}
			if(GCD[0]==GCD[1] && GCD[1]==GCD[2] && GCD[2]==GCD[3]){
				cout << "һ��\n";
				nSame++;
			}else{
				cout << "�д���\n";
				nDifferent++;
			}
			
		}
	}
	cout << "�������� " << nDifferent+nSame << " ����ԣ�ͨ�� " << nSame << " �飬 δͨ�� " << nDifferent << " �飬ͨ���� " << 100*nSame/(nDifferent+nSame+0.0) <<"% ��\n";

}
void GCDPressureTest(){
	unsigned int timeStart=time(NULL);
	pairInteger pair;
	int n=10;
	int i,j,k;
	int nSame=0, nDifferent=0;
	int times=0;
	for(times=1;times<=10;times++){
	cout <<"����ִ�е� "  << times << " �����";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			Integer GCD[2];
			pair.setPair(INT_MAX/i, INT_MAX/j);
			GCD[1]=pair.GCD(pairInteger::flagMethod::Euclidean);
			pair.setPair(INT_MAX/j, INT_MAX/i);
			GCD[0]=pair.GCD(pairInteger::flagMethod::Euclidean);
			cout << "���Ե� " << i*n+j+1 << " ��: (" << INT_MAX/i << ", " << INT_MAX/j << ")������ǣ�";
			for(k=0;k<2;k++){
				cout << GCD[k] << ", ";
			}
			if(GCD[0]==GCD[1]){
				cout << "һ��\n";
				nSame++;
			}else{
				cout << "�д���\n";
				nDifferent++;
			}

		}
	}
	cout << "�������� " << nDifferent+nSame << " ����ԣ�ͨ�� " << nSame << " �飬 δͨ�� " << nDifferent << " �飬ͨ���� " << 100*nSame/(nDifferent+nSame+0.0) <<"% ��\n";

	}
	cout << "��ʱ��" << time(NULL)-timeStart << " �롣";
}