#include <iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<string>
#include<vector>
#include<cmath>
#include<time.h>
#include<exception>
#include <QDebug>
using namespace std;
/*大顶堆类定义*/
class BigRoot
{
public:
	BigRoot(int cap);
	~BigRoot();
	bool insert(int val);     //往二叉堆中插入元素
	bool remove(int val);     //从二叉堆中删除元素
	void print();           //打印二叉堆
	int  getTop();          //获取堆顶元素
	bool creatMaxHeap(int a[], int size);//根据指定数组创建大顶堆
	int getSize();			//获取堆的大小，数组中有效元素的个数
	int getIndexNum(int index);		//获取数组指定位置的数字


private:

	int ArraySize;      //数组的大小
	int size;           //堆的大小，数组中有效元素的个数
	int*  maxheap;        //底层数组

	//从index节点往根节点调整堆
	void filterUp(int index);
	//从begin节点向end节点调整堆
	void filterDown(int begin, int end);

};