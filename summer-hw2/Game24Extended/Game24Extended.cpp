#include "Game24Extended.h"


/*
【输入】 
	第一行两个正整数 N 和 D，分别表示数的个数和目标结果。第二行为 N 个数字，以空格分隔。
	【输出】 
	如果能够得到D，则输出一个对应算式。如果没有办法通过加乘得到D，则输出No以及大于D的最小值。
*/


int main(){
	int n;
	long long int target;
	cin >> n >> target;
	int* candidates = (int*)malloc(n*sizeof(int));
	int i;
	for(i=0; i<n; i++)
		cin >> candidates[i];
	Game24Ex game(target, candidates, n);
	game.Do();
}
void Game24Ex::Do(){
	findPermutation(0);
	if(!found){
		cout << "No" << endl << closest << endl;
	}
}
int Game24Ex::findPermutation(int curr){
	
	if (curr==nCandidates-1){
		//found permutation
		if(findOp())return 1;
	}
	else{
		for (int i = curr; i < nCandidates; i++){
			int t;
			t = candidates[curr], candidates[curr] = candidates[i], candidates[i] = t;
			if(findPermutation(curr+1)) return 1;
			t = candidates[curr], candidates[curr] = candidates[i], candidates[i] = t;
		}
	}
	return 0;
}
int Game24Ex::findOp(){
	int n=(1<<(nCandidates));
	for(int i=0; i<n; i++){
		Game24ExFormula formula(candidates, nCandidates, i);
		long long int val = formula.eval();
		if(val==target){
			formula.print();
			found=1;
			//terminate Game24Ex::Do()
			return 1;
		}else if(val>target){
			//update closest
			if(closest==0 || val<closest)closest=val;
		}
	}
	return 0;
}


long long int Game24ExFormula::eval(){
	long long int sum = candidates[0];
	int j;
	int ops_=ops;
	for(j=1; j<nCandidates; j++, ops_>>=1){
		if(ops_ & 1){
			sum *= candidates[j];
		}else{
			sum += candidates[j];
		}
	}
	return sum;
}
void Game24ExFormula::print(){
	int j;
	int ops_=ops;
	cout << candidates[0];
	for(j=1; j<nCandidates; j++, ops_>>=1){
		if(ops_ & 1){
			cout << '*';
		}else{
			cout << '+';
		}
		cout << candidates[j];
	}
	cout << '\n';
}