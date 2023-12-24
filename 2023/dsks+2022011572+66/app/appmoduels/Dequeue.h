#pragma once 
#include "Dequeuenode.h" 
class Dequeue
{
public:
	Dequeue();    //Ĭ�ϵĶ�������Ϊ8 
	~Dequeue();
public:
	Dequeuenode * gethead();//��ȡ���ж�Ԫ�� 
	bool isEmpty();   //�пղ��� 
	int size();    //����еĴ�С 
	void tailenqueue(Dequeuenode * t);
	void headenqueue(Dequeuenode * t);
	void headdequeue();
	void taildequeue();
	void clear();   //������� 
	Dequeuenode* at(int i); //����λ�õ����� 

private:
	int count = 0;         //���е�Ԫ������ 
	int capacity;        //���е����� 
	Dequeuenode* array[20];//�ײ�Ϊ���� 
};