#include "Dequeue.h"
Dequeue::Dequeue()
{
	int capacity = 20; //默认的队列容量为 20

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
	if (count != 20) //先判断是否队列满
	{
		array[count++] = t;
	}
};
/*队头入队列*/
void Dequeue::headenqueue(Dequeuenode* t)
{
	if (count != 20) //先判断是否队列满
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
Dequeuenode* Dequeue::at2(int loca,int i)
{
	return situation[loca][i];
}

void Dequeue::shellsort(int &gap,int i)//调用希尔排序函数 输入为单个增量
{
		
	flag = false;
			auto temp = array[i];
			int j = i - gap;
			int numj = array[j]->m_StrName.toInt();
			int numtemp = temp->m_StrName.toInt();
			for (; j >= 0; j -= gap) {
				numj = array[j]->m_StrName.toInt();
				if (numj > numtemp) {
					array[j + gap] = array[j];
					flag = true;
				}
				else
				{
					break;
				}
			}
			array[j + gap] = temp;
		
		switch (gap)
		{
		case 9:
			for (int i = 0; i < count; i++) {
				situation[0][i] = array[i];
			}
			break;
		case 4:
			for (int i = 0; i < count; i++) {
				situation[1][i] = array[i];
			}
			break;
		case 2:
			for (int i = 0; i < count; i++) {
				situation[2][i] = array[i];
			}
			break;
		case 1:
			for (int i = 0; i < count; i++) {
				situation[3][i] = array[i];
			}
			break;
		default:
			break;
		}
};
/*返回队列的大小*/
bool Dequeue::numswap()
{
	return flag;
};