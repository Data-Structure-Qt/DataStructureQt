#pragma once
#include <QColor>
#include <QPoint>

class  BlockingSearch{
public:
	BlockingSearch();  //���캯��
	~BlockingSearch();  //��������
	QPoint m_Point;    //������������λ��
	QColor m_Color;    //����������ɫ
	QString m_StrName; //������������
	bool m_Visit;      //���������Ƿ����
	int m_Row;         //��������ʾ����
};

