#pragma once
#include <QColor>
#include <QPoint>

class LinklistNode {
public:
  LinklistNode();    //���캯��
  ~LinklistNode();   //��������
  QPoint m_Point;    //������������λ��
  QColor m_Color;    //����������ɫ
  QString m_StrName; //������������
  bool m_Visit;      //���������Ƿ����
  int m_Row;         //��������ʾ����
};