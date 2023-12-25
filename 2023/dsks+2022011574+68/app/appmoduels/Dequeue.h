#pragma once
#include "Dequeuenode.h"
class Dequeue
{
public:
	Dequeue(); //Ĭ�ϵĶ�������Ϊ 8
	~Dequeue();
public:
	Dequeuenode * gethead();//��ȡ���ж�Ԫ��
	bool isEmpty(); //�пղ���
	int size(); //����еĴ�С
	bool numswap();//�ж�����������Ƿ�����˽���
	void tailenqueue(Dequeuenode * t);
	void headenqueue(Dequeuenode * t);
	void headdequeue();
	void taildequeue();
	void clear(); //�������
	void shellsort(int &gap,int i);//ϣ������
	Dequeuenode* at(int i); //����λ�õ�����
	Dequeuenode* at2(int loca, int i); //����������λ�õ�����
private:
	bool flag = false;//����������Ƿ�����˽���
	int count = 0; //���е�Ԫ������
	int capacity; //���е�����
	Dequeuenode* array[20];//�ײ�Ϊ����
	Dequeuenode* situation[5][20];//��������¼����
};