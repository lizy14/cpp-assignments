#include "geneticInheritance.h"
#include <iostream>
using namespace std;
unsigned int geneticInheritance(unsigned int x, unsigned int y){
	unsigned int ret=0;
	int len=sizeof(unsigned int)*8/*bits in byte*/;
	int i;
	unsigned int xi, yi, reti;
	for(i=0;i<len;i++){
		xi = x & 1;//ȡ��ǰ���λ
		yi = y & 1;
		switch(i%5){
		case 0:
			reti = (~xi) & 1;
			break;
		case 1:
			reti = (~yi) & 1;
			break;
		case 2:
			reti = xi | yi;
			break;
		case 3:
			reti = xi & yi;
			break;
		case 4:
			reti = xi ^ yi;
			break;
		}
		reti <<= i;//��������λ reti �ŵ���ȷλ����
		ret |= reti;//����д += �� |= ��Ч��
		x >>= 1, y >>= 1;//ɾȥ���λ
	}
	return ret;
}

unsigned int geneticInheritance_arithmeticVersion(unsigned int x, unsigned int y){
	//�𾴵����̴��ˣ���֪����᲻����ϸ�ؿ�Դ�����ء���
	//����͵��һ��������ddl�ٽ���ʱ����ȡ�����
	return geneticInheritance(x,y);
}