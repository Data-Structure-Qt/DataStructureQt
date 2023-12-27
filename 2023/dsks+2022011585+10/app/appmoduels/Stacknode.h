#pragma once
#include <QPoint>
#include <QColor>
class Stacknode
{
public:
	Stacknode();
	virtual ~Stacknode();
	QPoint m_Point;//栈结点坐标位置
	QColor m_Color; //栈结点颜色
	QString m_StrName; //栈结点名称
};

