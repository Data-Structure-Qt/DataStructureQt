#pragma once
#include <QPoint>
#include <QColor>
class QListNode
{
public:
	QListNode();//���캯��
	~QListNode();//��������
	QPoint m_Point;//������������λ��
	QColor m_Color; //����������ɫ
	QString m_Name; //������������
	bool m_Visit;//���������Ƿ����
	int m_Row;//��������ʾ����
};