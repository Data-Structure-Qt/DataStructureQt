#include "Stacknode.h"
class Stack {
public:
  Stack(); //Ĭ�ϵ�ջ����Ϊ 10
  ~Stack();

public:
  Stacknode *top();        //��ȡջ��Ԫ��
  void push(Stacknode *t); //ѹջ����
  Stacknode *pop();        //��ջ����
  bool isEmpty();          //�пղ���
  int size();              //��ջ�Ĵ�С
  void clear();            //ջ���
  Stacknode *at(int i);    //ջλ�õ�����

private:
  int count = 0;        //ջ��Ԫ������
  int capacity;         //ջ������
  Stacknode *array[20]; //�ײ�Ϊ����
};