#include "BigRoot.h"
/*构造函数*/

BigRoot::BigRoot(int cap)
{
	ArraySize = cap;   //初始化数组的大小
	size = 0;
	maxheap = new int[ArraySize]; //开辟空间
};

/*析构函数*/
BigRoot::~BigRoot()
{
	delete[]maxheap;//释放空间
}

/*从下往上调整堆--插入元素时使用*/
void BigRoot::filterUp(int index)
{
	//记录下当前节点
	int value = maxheap[index];
	while (index > 0)
	{
		//得到其双亲节点
		int indexparent = (index - 1) / 2;

		if (value < maxheap[indexparent])
			break;
		else  //交换两节点
		{
			//新节点被其父节点覆盖
			maxheap[index] = maxheap[indexparent];
			//记录下新节点的位置
			index = indexparent;
		}
	}
	//给新节点赋值
	maxheap[index] = value;
};

/*插入元素*/
bool BigRoot::insert(int val)
{
	if (ArraySize == size)  //如果数组放不下
		return false;
	maxheap[size] = val;   //数组末尾放入新节点
	filterUp(size);        //自下而上调整节点
	size++;                //堆的元素数量加1
	return true;
};

/*从上到下调整堆--删除元素时使用*/
void BigRoot::filterDown(int current, int end)
{
	int child = current * 2 + 1;  //当前结点的左孩子

	int value = maxheap[current];  //保存当前节点

	while (child <= end)
	{
		//选出两个孩子中较大的孩子
		if (child < end && maxheap[child] < maxheap[child + 1])
			child++;
		if (value > maxheap[child])//无需调整
			break;
		else
		{
			maxheap[current] = maxheap[child]; //孩子节点覆盖当前节点
			current = child;                   //当前节点为较大的孩子节点
			child = child * 2 + 1;             //child重新指向当前节点的左孩子节点
		}
	}
	maxheap[current] = value;                  //找到合理地位置后 赋值
};
/*删除元素*/
bool BigRoot::remove(int key)
{
	if (size == 0)
		return false;
	int index;  //被删除元素的下标

	for (index = 0; index < size; index++)
	{

		if (maxheap[index] == key)
			break;  //找到被删元素的下标
	}

	if (index == size)
		return false;  //数组中没有要删除的元素

	//使用数组最后一个元素来代替该被删除元素
	maxheap[index] = maxheap[size - 1];

	//覆盖完成后　从上到下调整堆
	filterDown(index, size--);

	return true;
};
/*获取堆顶元素*/
int BigRoot::getTop()
{
	if (size != 0)
		return maxheap[0];
};

/*打印大顶堆*/
void BigRoot::print()
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		qDebug() << maxheap[i] << " ";
	}
	qDebug() << endl;
};

/*根据指定数组创建大顶堆*/
bool BigRoot::creatMaxHeap(int a[], int size)
{
	if (ArraySize < size)
		return false;
	for (int i = 0; i < size; i++)
		insert(a[i]);

	return true;
};
int BigRoot::getSize()
{
	return size;
}

int BigRoot::getIndexNum(int index)
{
	return maxheap[index];
}

//int main()
//{
//	BigRoot heap1(11);
//
//	//逐个元素创建大顶堆
//	for (int i = 0; i < 10; i++)
//		heap1.insert(i);
//	cout << "堆顶元素为：" << heap1.getTop() << endl;
//	heap1.print();
//
//	/*从堆中删除元素5*/
//	heap1.remove(5);
//	heap1.print();
//	heap1.insert(10);
//	heap1.print();
//
//	//根据指定数组创建大顶堆*/
//	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	BigRoot heap2(11);
//	heap2.creatMaxHeap(array, 10);
//	cout << "堆顶元素为：" << heap2.getTop() << endl;
//	heap2.print();
//
//	return 0;
//}