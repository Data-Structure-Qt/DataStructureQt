#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QObject>
#include <QTimer>
#include <QTimeLine>

#include "SortObejct.h"

//ð������
class BubbleSort : public SortObejct
{
	Q_OBJECT
public:
	explicit BubbleSort(QObject *parent = nullptr);

	void runStart(int interval) override;
	void runStep() override;
	void paint(QPainter *painter, int width, int height) override;

private:
	int _i = 0;
	int _j = 0;
	int _jTemp = 0;
	int _swapIndex = 0;

	QTimer _sortTimer; //��������

	double _animationProgress = 0;
	QTimeLine _animationLine; //���ڶ���
};

#endif // BUBBLESORT_H
