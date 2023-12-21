#pragma once 
#include <QPoint> 
#include <QColor> 
class LinklistNode
{
public:
	LinklistNode();//构造函数 
	~LinklistNode();//析构函数 

	QPoint m_Point;//单链表结点坐标位置 
	QColor m_Color; //单链表结点颜色 
	QString m_StrName; //单链表结点名称 
	bool m_Visit;//单链表结点是否访问 
	int m_Row;//链表结点显示行数 
};