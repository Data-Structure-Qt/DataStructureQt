#pragma once 
#include <QPoint> 
#include <QColor> 
class Dequeuenode
{
public:
	Dequeuenode();
	virtual ~Dequeuenode();
	QPoint m_Point;//ջ�������λ�� 
	QColor m_Color; //ջ�����ɫ 
	QString m_StrName; //ջ������� 
};