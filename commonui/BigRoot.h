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
/*�󶥶��ඨ��*/
class BigRoot
{
public:
	BigRoot(int cap);
	~BigRoot();
	bool insert(int val);     //��������в���Ԫ��
	bool remove(int val);     //�Ӷ������ɾ��Ԫ��
	void print();           //��ӡ�����
	int  getTop();          //��ȡ�Ѷ�Ԫ��
	bool creatMaxHeap(int a[], int size);//����ָ�����鴴���󶥶�
	int getSize();			//��ȡ�ѵĴ�С����������ЧԪ�صĸ���
	int getIndexNum(int index);		//��ȡ����ָ��λ�õ�����


private:

	int ArraySize;      //����Ĵ�С
	int size;           //�ѵĴ�С����������ЧԪ�صĸ���
	int*  maxheap;        //�ײ�����

	//��index�ڵ������ڵ������
	void filterUp(int index);
	//��begin�ڵ���end�ڵ������
	void filterDown(int begin, int end);

};