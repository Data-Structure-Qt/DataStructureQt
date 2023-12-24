#pragma once

#include <QWidget>
#include <QTimer>
class CQuickHelpUI;
class BubbleSortWidget : public QWidget
{
	Q_OBJECT

public:
	BubbleSortWidget(int w, int h, QWidget* parent = nullptr);
	~BubbleSortWidget();
	void setData(const QVector<int>& data);
	QVector<int> getData() { return arr; };

	//双向冒泡排序
	void BubbleSortStart(CQuickHelpUI* help);
private:
	//创建正方格
	void CreateSquare();
	//清空正方格
	void ClearSquare();
	//动画效果移动(a和b是按钮的标号)
	void AnimationPlay(int a, int b);
	//非阻塞延时（msec是时间ms）
	void Delay_MSec(unsigned int msec);
private:
	QVector<int> arr;
	QTimer* timer = nullptr;
};
