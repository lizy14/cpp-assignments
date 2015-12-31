//李肇阳 清华大学软件学院

//创建于 2015-7-20
//to be compiled with Microsoft Visual Studio 2012 (MSVC 11.0)

#include <iostream>
#include <string>
using namespace std;

class Member{
public:
	const string name;
	const int age;
public:
	Member(string name_ = "?", int age_ = 0):name(name_),age(age_){
	}
	friend ostream& operator<< (ostream& os, Member& member);
};
ostream& operator<< (ostream& os, Member& member){
	os << member.name;
	if(member.age>=0)
		os	<< ", age: " << member.age;
	return os;
}

class MemberList{
public:
	Member* members;
	int nMembers;
	MemberList(Member* members_, int nMembers_){
		members=members_;
		nMembers=nMembers_;
	}
	Member operator[](string name){
		int i;
		for(i=0; i<nMembers; i++){
			if(name == members[i].name)
				return members[i];
		}
		return Member("member '" + name + "' not found", -1);
	}
};


int main()
{
	Member newCommers[5] = { 
		Member("Zhang San", 22),
		Member("Li Si", 19),
		Member("Wang Wu", 18),
		Member("Zhao Liu", 24) 
	};
	for (int i = 0; i < 5; i++)
	{
		cout << newCommers[i] << endl;
	}

	string name[5] = { "Zhang San", "Li Si", "Wang Wu", "Zhao Liu", "Pin Yin" };
	MemberList list(newCommers, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << list[name[i]] << endl;
	}

	return 0;
}
