#pragma once
/*

˫������ģ����
������
������ 2015-6-5
�޸��� 2015-6-9 
  ������������ new �� delete ���������¼ new �� delete �ĵ���

���ڱ��ļ���ʵ�֣�û�ж�Ӧ cpp �ļ���
*/

#include <iostream>
#include "DebugLog.h"
using namespace std;

//����

template <typename Type>
class List{
private:
	List *next;
	List *prev;//ָ��Ϊ˽�г�Ա������������
public:
	Type entity;//���ݶ�
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
	int length();//����������Ԫ������
	List* findNext(){return next;};
	List* findPrevious(){return prev};
	List* createNode(); //return a ptr to the new node if success, NULL if failed
	List* createNode(Type entity); ////initialize the entity in the new node
	void removeNode(List*);
	List<Type>& operator[] (int i);
	template <typename Type>friend ostream& operator<< (ostream& os, List<Type>& node);
	template <typename Type>friend void bubbleSort(List<Type>& node, int(*f)(Type, Type));//����ȽϺ�����ָ��
};

template <typename Type>ostream& operator<< (ostream& os, List<Type>& node);
template <typename Type>void bubbleSort(List<Type>& node, int(*f)(Type, Type));//����ȽϺ�����ָ��


//ʵ��
//ģ����ĳ�Ա������ʵ�ֺ����ܵ������� .cpp �ļ��У������޷��������ⲿ���š����޽�
template <typename Type>
void swap(List<Type>* A, List<Type>* B){
	Type T;
	T=A->entity, A->entity=B->entity, B->entity=T; 
}
template <typename Type>
void bubbleSort(List<Type>& node, int(*f)(Type, Type)){
	List<Type> *head = &node, *p = head;
	int flag=0;//��ʾ�Ƿ����ź��򣬾����Ƿ���Ҫ������һ���ж�
	while(!flag){
		flag=1;
		p=head;
		do{
			if(f(p->entity, p->next->entity)<0){
				swap(p, p->next);//�������ݶ�
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
		} // forѭ������
	}
	else
	{
		for (k=0, p=this; k>i; k--)
		{
			p= p->prev;
		} // forѭ������
	}
	return(*p);
} // ��List<Type>�Ĳ��������غ���operator [ ]�������
template <typename Type>
void List<Type>::removeNode(List<Type> * p)
{
	if (prev == NULL)
		return;
	List<Type>* q;
	if (p==this) // ɾ����1����¼
	{
		if (p->prev==this) // ���ڵ�
		{
			p->prev=NULL;
			return;
		} // if�ṹ����
		//gb_copySingleNode(*this, *(p->next));
		this->entity = p->next->entity;
		p = p->next;
	} // if�ṹ����
	for (q=next; ((q!=p)&&(q!=this)) ; )
	{
		if (q!=NULL)
			q=q->next;
		else break;
	} // forѭ������
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
} // ��List<Type>�ĳ�Ա����mb_deleteNode�������
