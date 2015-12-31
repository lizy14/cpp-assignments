#pragma once
/*

双向链表模板类
李肇阳
创建于 2015-6-5
修改于 2015-6-9 
  新增：重载了 new 和 delete 运算符，记录 new 和 delete 的调用

均在本文件中实现，没有对应 cpp 文件。
*/

#include <iostream>
#include "DebugLog.h"
using namespace std;

//声明

template <typename Type>
class List{
private:
	List *next;
	List *prev;//指针为私有成员。保护起来！
public:
	Type entity;//数据段
public:
	void* operator new(size_t size){
		DebugLog("new called");
		return malloc(size);
	}
	void operator delete(void* p){
		DebugLog("delete called");
		free(p);
	}
	List();
	~List();
	int length();//返回链表中元素数量
	List* findNext(){return next;};
	List* findPrevious(){return prev};
	List* createNode(); //return a ptr to the new node if success, NULL if failed
	List* createNode(Type entity); ////initialize the entity in the new node
	void removeNode(List*);
	List<Type>& operator[] (int i);
	template <typename Type>friend ostream& operator<< (ostream& os, List<Type>& node);
	template <typename Type>friend void bubbleSort(List<Type>& node, int(*f)(Type, Type));//传入比较函数的指针
};

template <typename Type>ostream& operator<< (ostream& os, List<Type>& node);
template <typename Type>void bubbleSort(List<Type>& node, int(*f)(Type, Type));//传入比较函数的指针


//实现
//模板类的成员函数的实现好像不能单独放在 .cpp 文件中，报错“无法解析的外部符号”，无解
template <typename Type>
void swap(List<Type>* A, List<Type>* B){
	Type T;
	T=A->entity, A->entity=B->entity, B->entity=T; 
}
template <typename Type>
void bubbleSort(List<Type>& node, int(*f)(Type, Type)){
	List<Type> *head = &node, *p = head;
	int flag=0;//标示是否已排好序，决定是否需要进行下一轮判断
	while(!flag){
		flag=1;
		p=head;
		do{
			if(f(p->entity, p->next->entity)<0){
				swap(p, p->next);//交换数据段
				flag=0;
			}
			p=p->next;
		}while(p->next!=head);
	}
	return;
}

template <typename Type>
List<Type>::List(){
	this->prev = NULL;
	this->next = NULL;
}
template <typename Type>
List<Type>::~List(){
	if (prev == NULL)
		return;
	prev->next = NULL;
	delete next;
}
template <typename Type>
List<Type>* List<Type>::createNode(){
	if (prev == NULL){
		prev = this;
		next = this;
	}else{
		List<Type> *p = prev;
		prev = new List; //SAFE: released in List::~List()
		if(!prev) return NULL;
		prev->next = this;
		p->next = prev;
		prev->prev = p;
	}
	return prev;
}
template <typename Type>
List<Type>* List<Type>::createNode(Type newEntity){
	List* newNode = this->createNode();
	if(!newNode)return NULL;
	newNode->entity=newEntity;
	return prev;
}
template <typename Type>
int List<Type>::length(){
	if (prev == NULL)
		return 0;
	List *p = this;
	int n = 0;
	do{
		n++;
		p = p->next;
	}while(p!=this);
	return n;
}
template <typename Type>
ostream& operator<< (ostream& os, List<Type>& node){
	os << "List\n(\n";
	if (node.prev == NULL){
		os << "    [empty list]" << endl;
	}else{
		List<Type> *p=&node;
		int n=0;
		do{
			os << "    [" << n << "] => " << (p->entity) << endl;
			p = p->next;
			n++;
		}while(p!=&node);
	}
	os << ")\n";
	return os;
}
template <typename Type>
List<Type> & List<Type>::operator [ ] (int i)
{
	if (i==0)
		return (*this);
	if (this->prev==NULL)
		return (*this);
	int k;
	List<Type>* p;
	if (i>=0)
	{
		for (k=0, p=this; k<i; k++)
		{
			p= p->next;
		} // for循环结束
	}
	else
	{
		for (k=0, p=this; k>i; k--)
		{
			p= p->prev;
		} // for循环结束
	}
	return(*p);
} // 类List<Type>的操作符重载函数operator [ ]定义结束
template <typename Type>
void List<Type>::removeNode(List<Type> * p)
{
	if (prev == NULL)
		return;
	List<Type>* q;
	if (p==this) // 删除第1个记录
	{
		if (p->prev==this) // 单节点
		{
			p->prev=NULL;
			return;
		} // if结构结束
		//gb_copySingleNode(*this, *(p->next));
		this->entity = p->next->entity;
		p = p->next;
	} // if结构结束
	for (q=next; ((q!=p)&&(q!=this)) ; )
	{
		if (q!=NULL)
			q=q->next;
		else break;
	} // for循环结束
	if (q==this)
		return;
	if (q!=p)
		return;
	q=p->prev;
	q->next = p->next;
	q=p->next;
	q->prev = p->prev;
	p->prev = p;
	// p->next = NULL;
	delete p;
} // 类List<Type>的成员函数mb_deleteNode定义结束
