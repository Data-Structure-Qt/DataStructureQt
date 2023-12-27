#include "Dequeue.h"
Dequeue::Dequeue()
{
	int s = 8; //Ĭ�ϵĶ�������Ϊ 8
}
Dequeue::~Dequeue()
{
}
/*���е��пղ���*/
bool Dequeue::isEmpty()
{
	if (count == 0)
	{
		return 1; //����Ԫ��Ϊ 0 ʱΪ���п�
	}
	else {
		return 0;
	}
};
/*���ض��еĴ�С*/
int Dequeue::size()
{
	return count;
};
/*��β�����*/
void Dequeue::tailenqueue(Dequeuenode* t)
{
	if (count != 8) //���ж��Ƿ������
	{
		array[count++] = t;
	}
};
/*��ͷ�����*/
void Dequeue::headenqueue(Dequeuenode* t)
{
	if (count != 8) //���ж��Ƿ������
	{ //���к���Ԫ�������һλ
		for (int i = count; i > 0; i--) {
			array[i] = array[i - 1];
		}
		count++;
		//��ͷ����Ԫ��
		array[0] = t;
	}
};
/*��ͷ������*/
void Dequeue::headdequeue()
{
	if (count != 0) //���ж��Ƿ��ǿն���
	{
		//���к���Ԫ����ǰ��һλ
		for (int i = 0; i < count; i++) {
			array[i] = array[i + 1];
		}
		count--;
	}
};
/*��β������*/
void Dequeue::taildequeue()
{
	if (count != 0) //���ж��Ƿ��ǿն���
	{
		//ɾ���������Ԫ��
		array[count] = NULL;
		count--;
	}
};
/*��ȡ����ͷԪ��*/
Dequeuenode* Dequeue::gethead()
{
	if (count != 0)
	{
		return array[0];
	}
};
/*�������*/
void Dequeue::clear()
{
	while (count != 0)
	{
		array[count] = NULL;
		count--;
	};
	return;
};
/*��ȡ����λ�� i ��Ԫ��*/
Dequeuenode* Dequeue::at(int i)
{
	return array[i];
}
