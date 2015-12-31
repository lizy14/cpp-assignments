#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

class Game24Ex{
public:
	long long int target;
	long long int closest;
	int found;//�Ƿ��ҵ�����Сֵ
	int* candidates;
	int nCandidates;
	void Do();//��ʼ����24�㡣���������� findPermutation() ���ȫ����
	int findPermutation(int curr);//ȫ���еݹ麯�����ҵ�һ�����к���� findOp() �����������
	int findOp();//�����������ϡ����������� Game24ExFormula ��������ʽ��ֵ������
	

	Game24Ex(long long int target_, int* candidates_, int nCandidates_){
		target = target_;
		nCandidates = nCandidates_;
		candidates = (int*)malloc(nCandidates_*sizeof(int));
		for(int i=0; i<nCandidates_; i++){
			candidates[i] = candidates_[i];
		}
		closest = 0;
		found = 0;
	}
	~Game24Ex(){
		delete candidates;
	}	
};
class Game24ExFormula{
public:
	int* candidates;
	int nCandidates;
	int ops;//��ʾһ���������ϡ�ÿһλ��ʾ��Ӧλ������ + ���� *
	void print();//������ʽ
	long long int eval();//��ֵ

	Game24ExFormula(int* candidates_, int nCandidates_, int ops_){
		ops = ops_;
		nCandidates = nCandidates_;
		candidates = (int*)malloc(nCandidates_*sizeof(int));
		for(int i=0; i<nCandidates_; i++){
			candidates[i] = candidates_[i];
		}
	}
	~Game24ExFormula(){
		delete candidates;
	}
};