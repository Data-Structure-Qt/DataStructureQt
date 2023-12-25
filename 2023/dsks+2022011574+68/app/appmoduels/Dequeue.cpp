#include "Dequeue.h"
Dequeue::Dequeue()
{
	int capacity = 20; //Ĭ�ϵĶ�������Ϊ 20

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
	if (count != 20) //���ж��Ƿ������
	{
		array[count++] = t;
	}
};
/*��ͷ�����*/
void Dequeue::headenqueue(Dequeuenode* t)
{
	if (count != 20) //���ж��Ƿ������
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
Dequeuenode* Dequeue::at2(int loca,int i)
{
	return situation[loca][i];
}

void Dequeue::shellsort(int &gap,int i)//����ϣ�������� ����Ϊ��������
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
/*���ض��еĴ�С*/
bool Dequeue::numswap()
{
	return flag;
};