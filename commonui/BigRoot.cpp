#include "BigRoot.h"
/*���캯��*/

BigRoot::BigRoot(int cap)
{
	ArraySize = cap;   //��ʼ������Ĵ�С
	size = 0;
	maxheap = new int[ArraySize]; //���ٿռ�
};

/*��������*/
BigRoot::~BigRoot()
{
	delete[]maxheap;//�ͷſռ�
}

/*�������ϵ�����--����Ԫ��ʱʹ��*/
void BigRoot::filterUp(int index)
{
	//��¼�µ�ǰ�ڵ�
	int value = maxheap[index];
	while (index > 0)
	{
		//�õ���˫�׽ڵ�
		int indexparent = (index - 1) / 2;

		if (value < maxheap[indexparent])
			break;
		else  //�������ڵ�
		{
			//�½ڵ㱻�丸�ڵ㸲��
			maxheap[index] = maxheap[indexparent];
			//��¼���½ڵ��λ��
			index = indexparent;
		}
	}
	//���½ڵ㸳ֵ
	maxheap[index] = value;
};

/*����Ԫ��*/
bool BigRoot::insert(int val)
{
	if (ArraySize == size)  //�������Ų���
		return false;
	maxheap[size] = val;   //����ĩβ�����½ڵ�
	filterUp(size);        //���¶��ϵ����ڵ�
	size++;                //�ѵ�Ԫ��������1
	return true;
};

/*���ϵ��µ�����--ɾ��Ԫ��ʱʹ��*/
void BigRoot::filterDown(int current, int end)
{
	int child = current * 2 + 1;  //��ǰ��������

	int value = maxheap[current];  //���浱ǰ�ڵ�

	while (child <= end)
	{
		//ѡ�����������нϴ�ĺ���
		if (child < end && maxheap[child] < maxheap[child + 1])
			child++;
		if (value > maxheap[child])//�������
			break;
		else
		{
			maxheap[current] = maxheap[child]; //���ӽڵ㸲�ǵ�ǰ�ڵ�
			current = child;                   //��ǰ�ڵ�Ϊ�ϴ�ĺ��ӽڵ�
			child = child * 2 + 1;             //child����ָ��ǰ�ڵ�����ӽڵ�
		}
	}
	maxheap[current] = value;                  //�ҵ������λ�ú� ��ֵ
};
/*ɾ��Ԫ��*/
bool BigRoot::remove(int key)
{
	if (size == 0)
		return false;
	int index;  //��ɾ��Ԫ�ص��±�

	for (index = 0; index < size; index++)
	{

		if (maxheap[index] == key)
			break;  //�ҵ���ɾԪ�ص��±�
	}

	if (index == size)
		return false;  //������û��Ҫɾ����Ԫ��

	//ʹ���������һ��Ԫ��������ñ�ɾ��Ԫ��
	maxheap[index] = maxheap[size - 1];

	//������ɺ󡡴��ϵ��µ�����
	filterDown(index, size--);

	return true;
};
/*��ȡ�Ѷ�Ԫ��*/
int BigRoot::getTop()
{
	if (size != 0)
		return maxheap[0];
};

/*��ӡ�󶥶�*/
void BigRoot::print()
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		qDebug() << maxheap[i] << " ";
	}
	qDebug() << endl;
};

/*����ָ�����鴴���󶥶�*/
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
//	//���Ԫ�ش����󶥶�
//	for (int i = 0; i < 10; i++)
//		heap1.insert(i);
//	cout << "�Ѷ�Ԫ��Ϊ��" << heap1.getTop() << endl;
//	heap1.print();
//
//	/*�Ӷ���ɾ��Ԫ��5*/
//	heap1.remove(5);
//	heap1.print();
//	heap1.insert(10);
//	heap1.print();
//
//	//����ָ�����鴴���󶥶�*/
//	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	BigRoot heap2(11);
//	heap2.creatMaxHeap(array, 10);
//	cout << "�Ѷ�Ԫ��Ϊ��" << heap2.getTop() << endl;
//	heap2.print();
//
//	return 0;
//}