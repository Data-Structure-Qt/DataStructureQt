#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<QString>
#include <cstdlib>
#include <cstdio>
#include <new>
using namespace std;
struct CGraphVertexNode //图的边类
{
	int adjointVertex;
	CGraphVertexNode *next;
	CGraphVertexNode(int a = 0, CGraphVertexNode *n =
		NULL) :adjointVertex(a), next(n) {};
};
struct CGraphAdjointList {
	string data; //数据
	CGraphVertexNode *firstEdage; //第一条边
};
//图数据结构
struct MGraph
{
	int numVertex; //节点数量
	int numEdge; //边数量
	vector<CGraphAdjointList> adjointList; //容器
	MGraph(int n = 10010) :adjointList(n) {};
};
typedef struct Animation { //动画片段
	int totaltime;
	int functionid;
	QString para1;
	QString para2;
	int codefunctionid;
	int codefunctionlineid;
};
//Prim 算法需要的数据结构
enum VisitIf { unvisited, visited };
class EBox {
public:
	int ivex, jvex; //该边依附的两个顶点位置
	EBox *ilink, *jlink; //分别指向依附这两个顶点的下一条边
	int weight;
};
class VexBox {
public:
	string data;
	EBox *firstedge; //指向第一条依附该顶点的边
	VisitIf mark; //访问标记
};
class AMLGraph {
public:
	VexBox adjmulist[1010];
	int vexnum, edgenum; //无向图的当前顶点数和边数
};
//Kruskal 算法数据结构
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
//拓扑排序
struct topoNode
{
	int adjvex;
	topoNode* next;
};

/*--获取图的割点--*/
//使用邻接表作为图的存储结构 
#define MAX_VERTEX_NUM 2000  //图的最大顶点个数
typedef char VertexType;
typedef struct ArcNode
{
	int adjvex;              //边指向的顶点位置 
	struct ArcNode *nextarc;  //指向下一条边的指针 
}ArcNode;

typedef struct VNode
{
	VertexType data;   //顶点名称
	ArcNode *firstarc; //指向第一条依附该顶点的边 
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; //图的顶点数、边数 
}ALGraph;

