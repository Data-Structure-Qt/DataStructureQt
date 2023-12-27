#include "Stacknode.h"
class Stack {
public:
  Stack(); //默认的栈容量为 10
  ~Stack();

public:
  Stacknode *top();        //获取栈顶元素
  void push(Stacknode *t); //压栈操作
  Stacknode *pop();        //弹栈操作
  bool isEmpty();          //判空操作
  int size();              //求栈的大小
  void clear();            //栈清空
  Stacknode *at(int i);    //栈位置的数据

private:
  int count = 0;        //栈的元素数量
  int capacity;         //栈的容量
  Stacknode *array[20]; //底层为数组
};