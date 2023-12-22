#include "Dequeue.h"
Dequeue::Dequeue()
{
	int s = 8; //默认的队列容量为 8
}
Dequeue::~Dequeue()
{
}
/*队列的判空操作*/
bool Dequeue::isEmpty()
{
	if (count == 0)
	{
		return 1; //队列元素为 0 时为队列空
	}
	else {
		return 0;
	}
};
/*返回队列的大小*/
int Dequeue::size()
{
	return count;
};
/*队尾入队列*/
void Dequeue::tailenqueue(Dequeuenode* t)
{
	if (count != 8) //先判断是否队列满
	{
		array[count++] = t;
	}
};
/*队头入队列*/
void Dequeue::headenqueue(Dequeuenode* t)
{
	if (count != 8) //先判断是否队列满
	{ //队列后面元素向后移一位
		for (int i = count; i > 0; i--) {
			array[i] = array[i - 1];
		}
		count++;
		//队头插入元素
		array[0] = t;
	}
};
/*队头出队列*/
void Dequeue::headdequeue()
{
	if (count != 0) //先判断是否是空队列
	{
		//队列后面元素向前移一位
		for (int i = 0; i < count; i++) {
			array[i] = array[i + 1];
		}
		count--;
	}
};
/*队尾出队列*/
void Dequeue::taildequeue()
{
	if (count != 0) //先判断是否是空队列
	{
		//删除队列最后元素
		array[count] = NULL;
		count--;
	}
};
/*获取队列头元素*/
Dequeuenode* Dequeue::gethead()
{
	if (count != 0)
	{
		return array[0];
	}
};
/*队列清空*/
void Dequeue::clear()
{
	while (count != 0)
	{
		array[count] = NULL;
		count--;
	};
	return;
};
/*读取队列位于 i 处元素*/
Dequeuenode* Dequeue::at(int i)
{
	return array[i];
}
