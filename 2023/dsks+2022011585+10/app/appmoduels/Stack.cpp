#include "Stack.h"
Stack::Stack()
{
	int s = 10; //Ĭ�ϵ�ջ����Ϊ10
}
Stack::~Stack()
{
}
/*ջ���пղ���*/
bool Stack::isEmpty()
{
	return count == 0; //ջԪ��Ϊ0ʱΪջ��
};
/*����ջ�Ĵ�С*/
int Stack::size()
{
	return count;
};
/*����Ԫ��*/
void Stack::push(Stacknode* t)
{
	if (count != capacity)//���ж��Ƿ�ջ��
	{
		array[count++] = t;
	}
};
/*��ջ*/
Stacknode* Stack::pop()
{
	if (count != 0)//���ж��Ƿ��ǿ�ջ
	{
		return array[--count];
	}

};
/*��ȡջ��Ԫ��*/
Stacknode* Stack::top()
{
	if (count != 0)
	{
		return array[count -1];
	}
};
/*ջ���*/
void Stack::clear()
{
	while (count != 0)//���ж��Ƿ��ǿ�ջ
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