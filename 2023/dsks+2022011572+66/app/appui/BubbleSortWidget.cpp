#include "BubbleSortWidget.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QPushButton>
#include <QEventLoop>
#include "CQuickHelpUI.h"
BubbleSortWidget::BubbleSortWidget(int w, int h, QWidget* parent)
	: QWidget(parent)
{
	setFixedSize(w, h);
}

BubbleSortWidget::~BubbleSortWidget()
{}

void BubbleSortWidget::setData(const QVector<int>& data)
{
	arr.clear();
	arr = data;
	//视图块清空
	ClearSquare();
	CreateSquare();
}


void BubbleSortWidget::CreateSquare()
{
	int squareX = (width() - arr.size() * 80) / 2;

	//创建数据视图正方格
	for (int i = 0; i < arr.size(); i++)
	{
		QPushButton* btn = new QPushButton(this);
		btn->setObjectName(QString::number(i));
		btn->setText(QString::number(arr[i]));
		btn->setGeometry(squareX, height() / 2, 70, 70);
		btn->show();
		squareX += 80;
	}
}

void BubbleSortWidget::ClearSquare()
{
	for (int i = children().size() - 1; i >= 0; --i) {
		QObject* child = children().at(i);

		if (child) {
			// 如果子对象是QPushButton，则删除它
			if (dynamic_cast<QPushButton*>(child)) {
				//child->deleteLater();
				delete child;
			}
		}
	}
	update();
}

void BubbleSortWidget::BubbleSortStart(CQuickHelpUI* help)
{
	//分别从左开始(将最大放到最右) 从右开始(将最小放到最左)   
	//flag用于记录左右已排序位置
	int left = 0, right = arr.size() - 1, flag;
	while (left < right)
	{
		help->showFSort();
		flag = 0;
		//正向冒泡
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				AnimationPlay(i, i + 1);
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
		right--;
		//反向冒泡
		help->showBSort();
		for (int i = right; i > left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				AnimationPlay(i, i - 1);
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
			}
		}
		left++;

	}

}

void BubbleSortWidget::AnimationPlay(int a, int b)
{
	//获取交互的btn
	QPushButton* btnA = dynamic_cast<QPushButton*>(findChild<QPushButton*>(QString::number(a)));
	QPushButton* btnB = dynamic_cast<QPushButton*>(findChild<QPushButton*>(QString::number(b)));

	if (btnA && btnB)
	{
		QRect A = btnA->geometry();
		QRect B = btnB->geometry();
		btnA->setStyleSheet("background-color:blue;color:rgb(255, 255, 255);");
		btnB->setStyleSheet("background-color:blue;color:rgb(255, 255, 255);");
		QPropertyAnimation* animationA = new QPropertyAnimation(btnA, "geometry");
		QPropertyAnimation* animationB = new QPropertyAnimation(btnB, "geometry");
		animationA->setDuration(1000); // 设置动画持续时间为1000毫秒
		animationB->setDuration(1000);
		// 设置动画的起始值和结束值
		animationA->setStartValue(A);
		animationA->setEndValue(B);

		animationB->setStartValue(B);
		animationB->setEndValue(A);

		//并行动画容器
		QParallelAnimationGroup* group = new QParallelAnimationGroup();
		group->addAnimation(animationA);
		group->addAnimation(animationB);
		// 启动动画
		group->start();
		//交换btn的objectName
		btnA->setObjectName(QString::number(b));
		btnB->setObjectName(QString::number(a));
		//延时执行算法
		Delay_MSec(1500);
		btnA->setStyleSheet("");
		btnB->setStyleSheet("");
	}

}

void BubbleSortWidget::Delay_MSec(unsigned int msec)
{
	QEventLoop loop;//定义一个新的事件循环
	QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
	loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

