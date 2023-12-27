#include "CNodeEditorScene.h"
#include "CNodeSceneActions.h"
#include "CNode.h"
#include "CNodePort.h"
#include "CEdge.h"
#include "CDirectEdge.h"
#include "CPolyEdge.h"
#include "CControlPoint.h"
#include "CEditorSceneDefines.h"
#include "CEditorScene_p.h"

#include <CGraphBase.h>

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QColorDialog> 
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <QTimeLine> 
#include <QElapsedTimer>
#include <QGraphicsItemAnimation>



void CNodeEditorScene::drawCircle(int x, int y, int data, int p_x, int p_y, int color)//����ԲȦ+��ͷ
{
	QGraphicsLineItem *lineItem = new QGraphicsLineItem();
	QPen pen2 = lineItem->pen();//���� �������
	pen2.setColor(QColor(100, 149, 237));//��߿����ɫ
	pen2.setWidth(2);
	lineItem->setPen(pen2);
	lineItem->setLine(x + 15, y + 15, p_x + 15, p_y + 15 + 14);
	addItem(lineItem);

	if (data != -1)
	{
		QGraphicsEllipseItem *rectItem = new QGraphicsEllipseItem;//����Բ��
		QPen pen = rectItem->pen();//���� �������
		pen.setColor(QColor(250,140,53));//��߿����ɫ
		rectItem->setPen(pen);
		if (color == 0)
			rectItem->setBrush(QBrush(QColor(0, 0, 0)));//����ɫ
		else
			rectItem->setBrush(QBrush(QColor(255, 0, 0)));//����ɫ
		rectItem->setRect(QRectF(x, y, 30, 30));
		addItem(rectItem);


		QGraphicsTextItem *pItem = new QGraphicsTextItem();
		pItem->setPlainText(QString::number(data));  // ���ı�
		pItem->setDefaultTextColor(QColor(255, 255, 0));  // �ı�ɫ
		pItem->setPos(QPointF(x + 4, y + 5));//λ��
		QFont font = pItem->font();
		font.setPixelSize(12);  // ���ش�С
		pItem->setFont(font);
		addItem(pItem);
	}
	else if (data == -1)
	{
		QGraphicsEllipseItem *rectItem = new QGraphicsEllipseItem;//����Բ��
		QPen pen = rectItem->pen();//���� �������
		pen.setColor(QColor(250,140,53));//��߿����ɫ
		rectItem->setPen(pen);
		if (color == 0)
			rectItem->setBrush(QBrush(QColor(0, 0, 0)));//����ɫ
		else
			rectItem->setBrush(QBrush(QColor(255, 0, 0)));//����ɫ
		rectItem->setRect(QRectF(x, y, 30, 30));
		addItem(rectItem);

		QGraphicsTextItem *pItem = new QGraphicsTextItem();
		pItem->setPlainText("NULL");  // ���ı�
		pItem->setDefaultTextColor(QColor(255, 255, 0));  // �ı�ɫ
		pItem->setPos(QPointF(x + 4, y + 5));//λ��
		QFont font = pItem->font();
		font.setPixelSize(12);  // ���ش�С
		pItem->setFont(font);
		addItem(pItem);
	}
}


void CNodeEditorScene::drawCircle2(int x, int y, int data1, int data2, int p_x, int p_y, int color)//����ԲȦ+��ͷ
{
	QGraphicsLineItem *lineItem = new QGraphicsLineItem();
	QPen pen2 = lineItem->pen();//���� �������
	pen2.setColor(QColor(100, 149, 237));//��߿����ɫ
	pen2.setWidth(2);
	lineItem->setPen(pen2);
	lineItem->setLine(x + 15, y + 15, p_x + 15, p_y + 15);
	addItem(lineItem);


	QGraphicsEllipseItem *rectItem = new QGraphicsEllipseItem;//����Բ��
	QPen pen = rectItem->pen();//���� �������
	pen.setColor(Qt::green);//��߿����ɫ
	rectItem->setPen(pen);
	if (color == 0)
		rectItem->setBrush(QBrush(QColor(0, 0, 0)));//����ɫ
	else
		rectItem->setBrush(QBrush(QColor(255, 0, 0)));//����ɫ
	rectItem->setRect(QRectF(x, y, 30, 30));
	addItem(rectItem);

	QGraphicsTextItem *pItem = new QGraphicsTextItem();
	pItem->setPlainText(QString::number(data1) + ',' + QString::number(data2));  // ���ı�
	pItem->setDefaultTextColor(QColor(0, 0, 0));  // �ı�ɫ
	pItem->setPos(QPointF(x + 4, y + 5));//λ��
	QFont font = pItem->font();
	font.setPixelSize(10);  // ���ش�С
	pItem->setFont(font);
	addItem(pItem);

}



