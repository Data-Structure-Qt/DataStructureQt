#pragma once
#include <QPoint>
#include <QColor>
class Stacknode
{
public:
	Stacknode();
	virtual ~Stacknode();
	QPoint m_Point;//ջ�������λ��
	QColor m_Color; //ջ�����ɫ
	QString m_StrName; //ջ�������
};

