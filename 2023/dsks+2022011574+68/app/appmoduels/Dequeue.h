#pragma once
#include "Dequeuenode.h"
class Dequeue
{
public:
	Dequeue(); //默认的队列容量为 8
	~Dequeue();
public:
	Dequeuenode * gethead();//获取队列顶元素
	bool isEmpty(); //判空操作
	int size(); //求队列的大小
	bool numswap();//判断排序过程中是否进行了交换
	void tailenqueue(Dequeuenode * t);
	void headenqueue(Dequeuenode * t);
	void headdequeue();
	void taildequeue();
	void clear(); //队列清空
	void shellsort(int &gap,int i);//希尔排序
	Dequeuenode* at(int i); //队列位置的数据
	Dequeuenode* at2(int loca, int i); //排序结果队列位置的数据
private:
	bool flag = false;//排序过程中是否进行了交换
	int count = 0; //队列的元素数量
	int capacity; //队列的容量
	Dequeuenode* array[20];//底层为数组
	Dequeuenode* situation[5][20];//排序结果记录数组
};