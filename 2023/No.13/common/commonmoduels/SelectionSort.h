#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <QObject>
#include <QTimer>
#include <QTimeLine>

#include "SortObejct.h"

//ѡ������
class SelectionSort : public SortObejct
{
	Q_OBJECT
public:
	explicit SelectionSort(QObject *parent = nullptr);

	void runStart(int interval) override;
	void runStep() override;
	void paint(QPainter *painter, int width, int height) override;

private:
	//Ŀǰ����ʱһ���Եģ�����û�и�λ����
	int _i = 0;
	int _j = 1;
	int _min = 0;
	int _iTemp = 0;
	int _jTemp = 1;
	int _minTemp = 0;

	QTimer _sortTimer; //��������

	double _animationProgress = 0;
	QTimeLine _animationLine; //���ڶ���
};

#endif // SELECTIONSORT_H
