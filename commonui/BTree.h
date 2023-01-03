#pragma once
#include<QString>
#include<QChar>
#include<QPoint>
#include<QLine>
#include<QColor>

typedef struct BNode {
	QChar data;//�������
	QPoint point;//�洢λ������
	bool sign;//�Ƿ���Ҫ�����
	int level;//�洢����
	struct BNode *left, *right;//���Һ��ӽ��
	BNode() {
		left = NULL; right = NULL;
		point = QPoint(0, 0);
		sign = 0;
		level = 0;
	}
	void setpoint(QPoint p) { point = p; }
}BNode;
class BTree
{
public:
	BTree() { root = nullptr; Mylines = nullptr; Mypoints = nullptr; Treesize = 0; }
	~BTree() { }

	void clear();//��������
	void createBTree(BNode* &T, int &i);//���򴴽�������
	void leveltravl();//������������浽levelStr��
	int size() { return Treesize; }//�����������
	int height(BNode *Node);  //�õ����ĸ߶�
	BNode  *getRoot() { return root; }//��ø��ڵ�
	QPoint *getPoints() { return Mypoints; }//�õ�����
	QLine *getLines() { return Mylines; }//�õ��߶�
	QString getpreStr() { return preStr; }
	QString getlevelStr() { return levelStr; }
	void setpreStr(QString s) { preStr = s; }
	void setmypoints();//���ý������
	void setroot(BNode* roott) { root = roott; }
private:
	BNode *root;
	QString preStr;//ǰ��������ַ���
	QString levelStr;//��������ַ���
	int Treesize;//���ڵ���
	QPoint *Mypoints;//�������������ļ���
	QLine *Mylines;//�ߵ�����

};

