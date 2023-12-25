#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<QString>
using namespace std;
struct CGraphVertexNode //ͼ�ı���
{
	int adjointVertex;
	CGraphVertexNode *next;
	CGraphVertexNode(int a = 0, CGraphVertexNode *n =
		NULL) :adjointVertex(a), next(n) {};
};
struct CGraphAdjointList {
	string data; //����
	CGraphVertexNode *firstEdage; //��һ����
};
//ͼ���ݽṹ
struct MGraph
{
	int numVertex; //�ڵ�����
	int numEdge; //������
	vector<CGraphAdjointList> adjointList; //����
	MGraph(int n = 10010) :adjointList(n) {};
};
typedef struct Animation { //����Ƭ��
	int totaltime;
	int functionid;
	QString para1;
	QString para2;
	int codefunctionid;
	int codefunctionlineid;
};
//Prim �㷨��Ҫ�����ݽṹ
enum VisitIf { unvisited, visited };
class EBox {
public:
	int ivex, jvex; //�ñ���������������λ��
	EBox *ilink, *jlink; //�ֱ�ָ�������������������һ����
	int weight;
};
class VexBox {
public:
	string data;
	EBox *firstedge; //ָ���һ�������ö���ı�
	VisitIf mark; //���ʱ��
};
class AMLGraph {
public:
	VexBox adjmulist[1010];
	int vexnum, edgenum; //����ͼ�ĵ�ǰ�������ͱ���
};
//Kruskal �㷨���ݽṹ
struct Edge_Kruskal {
	int u;
	int v;
	int weight;
	Edge_Kruskal() : u(0), v(0), weight(0) {}
	Edge_Kruskal(int _u, int _v, int _weight) {
		u = _u;
		v = _v;
		weight = _weight;
	}
	bool operator < (const Edge_Kruskal e) const {
		return this->weight < e.weight;
	}
};
