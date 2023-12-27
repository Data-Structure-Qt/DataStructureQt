#include <algorithm> 
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <queue>
#include <QDebug>
#include <QColor>
using namespace std;

//B_树
typedef int KeyType;
typedef struct node {
	int keynum;                   //结点关键字个数
	KeyType key[10];              //关键字，0遗弃
	struct node *parent;          //双亲指针
	struct node *ptr[10];         //孩子指针数组 
}BTNode, *BTree;

typedef struct {                    //查找返回类型 
	BTNode *pt;
	int i;                          //关键字位置; 
	int fag;                        //查找成功与否标志
}Result;

typedef struct LNode {              //链表和链表结点类型 
	BTree data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct Animation {			//动画片段
	int x;
	int y;
	int data1;
	int data2;
	int p_x;
	int p_y;
	int flag;
	int codeid;
};

typedef enum status {               //枚举类型 
	TRUE,
	FALSE,
	OK,
	ERROR,
	OVERFLOW1,
	EMPTY
}Status;

