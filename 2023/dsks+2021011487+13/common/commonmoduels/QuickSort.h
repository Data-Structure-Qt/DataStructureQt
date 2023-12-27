#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QTimeLine>
#include <QMutex>
#include <QWaitCondition>

#include "SortObejct.h"

//��������
//���Ʒ���������̺ͽ�����������ûд
class QuickSort : public SortObejct
{
	Q_OBJECT
public:
	explicit QuickSort(QObject *parent = nullptr);
	~QuickSort();

	void runStart(int interval) override;
	void runStep() override;
	void paint(QPainter *painter, int width, int height) override;

private:
	//�������ڿӷ�
	void doSort(int left, int right);
	int doSortPart(int left, int right);

private:
	//��ΪĿǰdatareset�ǳ�ʼ��ʱ���еģ�����û�ж�������
	QMutex _waitMutex;
	QWaitCondition _waitCondition;
	std::atomic<bool> _runningFlag = false; //�Ƿ���������

	int _interval = 1; //������ʱ���
	QTimer _sortTimer; //�����趨ʱ��

	int _leftTemp = 0; //��߽�
	int _rightTemp = 0; //�ұ߽�
	int _beginTemp = 0; //��ָ��
	int _endTemp = 0; //��ָ��
	int _pitTemp = 0; //��λ

	double _animationProgress = 0;
	QTimeLine _animationLine; //���ڶ���
};

#endif // QUICKSORT_H
