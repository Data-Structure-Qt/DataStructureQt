#pragma once
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <QDebug>
#include <QColor>
using namespace std;
class CBiTreeNode
{
public:
	int key; //����ֵ
	int height; //���ĸ߶ȣ������Ϊ0
	CBiTreeNode* left; //����
	CBiTreeNode* right; //�Һ���
	QPoint m_Point;//�������������λ��
	QColor m_Color; //�����������ɫ
	QString m_StrName; //�������������
	int m_Value;//���������ֵ
	bool m_Visit;//����������Ƿ����
	QPoint m_DisplayPoint;//�������µ���ʾλ��
	//������������Һ���ָ��͸����ָ��
	CBiTreeNode *m_PLChild, *m_PRChild, *m_PParent;
	int m_Leftwidth;//���������������
/*���캯��*/
	CBiTreeNode(int k, CBiTreeNode* left, CBiTreeNode* right) :key(k), height(0),
	left(left), right(right) {}
};
class CBiTree
{
private:
	CBiTreeNode* root; //���ڵ�
public:
	CBiTree() :root(NULL) {};//���캯��
	CBiTreeNode* getRoot() { return root; }//���ظ��ڵ�
	void preOrder(CBiTreeNode* root);//�������
	void inOrder(CBiTreeNode* root);//�������
	void postOrder(CBiTreeNode* root);//�������
	//��ƽ���������root�в���ֵΪkey�Ľ�㲢���ظý��
	CBiTreeNode* search(CBiTreeNode* root, int key);
	//��ƽ����������в�����Сֵ��㲢����
	CBiTreeNode* minimus(CBiTreeNode* node);
	//��ƽ����������в������ֵ��㲢����
	CBiTreeNode* maximus(CBiTreeNode* node);
	//���ؽ��ĸ߶�
	int height(CBiTreeNode* node);
	//LL��ת
	CBiTreeNode* leftLeftRotate(CBiTreeNode* root);
	//RR��ת
	CBiTreeNode* rightRightRotate(CBiTreeNode* root);
	//LR��ת
	CBiTreeNode* leftRightRotate(CBiTreeNode* root);
	//RL��ת
	CBiTreeNode* rightLeftRotate(CBiTreeNode* root);
	//������
	CBiTreeNode* insert(CBiTreeNode* root, int key);
	//ɾ�����node
	CBiTreeNode* deleteNode(CBiTreeNode* root, CBiTreeNode* node);
	//����ƽ���������
	void destroy(CBiTreeNode* root);
	//��ӡ������
	void TreePrint(CBiTreeNode* root);
	//�������
	void InOrder(CBiTreeNode* root, string &In);
}
;