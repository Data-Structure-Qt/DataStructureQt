#include <algorithm> 
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <queue>
#include <QDebug>
#include <QColor>
using namespace std;

//B_��
typedef int KeyType;
typedef struct node {
	int keynum;                   //���ؼ��ָ���
	KeyType key[10];              //�ؼ��֣�0����
	struct node *parent;          //˫��ָ��
	struct node *ptr[10];         //����ָ������ 
}BTNode, *BTree;

typedef struct {                    //���ҷ������� 
	BTNode *pt;
	int i;                          //�ؼ���λ��; 
	int fag;                        //���ҳɹ�����־
}Result;

typedef struct LNode {              //��������������� 
	BTree data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct Animation {			//����Ƭ��
	int x;
	int y;
	int data1;
	int data2;
	int p_x;
	int p_y;
	int flag;
	int codeid;
};

typedef enum status {               //ö������ 
	TRUE,
	FALSE,
	OK,
	ERROR,
	OVERFLOW1,
	EMPTY
}Status;

