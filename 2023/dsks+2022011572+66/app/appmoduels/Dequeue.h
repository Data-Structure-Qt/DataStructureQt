#pragma once 
#include "Dequeuenode.h" 
class Dequeue
{
public:
	Dequeue();    //默认的队列容量为8 
	~Dequeue();
public:
	Dequeuenode * gethead();//获取队列顶元素 
	bool isEmpty();   //判空操作 
	int size();    //求队列的大小 
	void tailenqueue(Dequeuenode * t);
	void headenqueue(Dequeuenode * t);
	void headdequeue();
	void taildequeue();
	void clear();   //队列清空 
	Dequeuenode* at(int i); //队列位置的数据 

private:
	int count = 0;         //队列的元素数量 
	int capacity;        //队列的容量 
	Dequeuenode* array[20];//底层为数组 
};