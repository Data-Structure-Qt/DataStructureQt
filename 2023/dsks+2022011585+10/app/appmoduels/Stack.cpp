#include "Stack.h"
Stack::Stack()
{
	int s = 10; //默认的栈容量为10
}
Stack::~Stack()
{
}
/*栈的判空操作*/
bool Stack::isEmpty()
{
	return count == 0; //栈元素为0时为栈空
};
/*返回栈的大小*/
int Stack::size()
{
	return count;
};
/*插入元素*/
void Stack::push(Stacknode* t)
{
	if (count != capacity)//先判断是否栈满
	{
		array[count++] = t;
	}
};
/*弹栈*/
Stacknode* Stack::pop()
{
	if (count != 0)//先判断是否是空栈
	{
		return array[--count];
	}

};
/*获取栈顶元素*/
Stacknode* Stack::top()
{
	if (count != 0)
	{
		return array[count -1];
	}
};
/*栈清空*/
void Stack::clear()
{
	while (count != 0)//先判断是否是空栈
	{
		array[count] = NULL;
		count--;
	}
	return;
};
Stacknode* Stack::at(int i)
{
	return  array[i];
}