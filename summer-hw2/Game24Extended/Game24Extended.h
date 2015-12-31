#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

class Game24Ex{
public:
	long long int target;
	long long int closest;
	int found;//是否找到了最小值
	int* candidates;
	int nCandidates;
	void Do();//开始计算24点。本函数调用 findPermutation() 穷举全排列
	int findPermutation(int curr);//全排列递归函数。找到一个排列后调用 findOp() 穷举运算符组合
	int findOp();//生成运算符组合。本函数构造 Game24ExFormula 对象，求表达式的值并检验
	

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
	int ops;//表示一组运算符组合。每一位表示相应位置上是 + 还是 *
	void print();//输出表达式
	long long int eval();//求值

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