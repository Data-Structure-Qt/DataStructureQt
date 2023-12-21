#include "MainWidget.h"
#include <QRandomGenerator>

MainWidget::MainWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::MainWidgetClass())
{
	ui->setupUi(this);

	// 连接添加按钮的点击事件
	connect(ui->btnAdd, &QPushButton::clicked, this, [=]() {
		QString numStr = ui->editNum->text();
		if (numStr.isEmpty())
			return;

		ui->widget->insert(numStr.toInt());
		});

	// 连接删除按钮的点击事件
	connect(ui->btnDelete, &QPushButton::clicked, this, [=]() {
		QString numStr = ui->editNum->text();
		if (numStr.isEmpty())
			return;

		ui->widget->deleteKey(numStr.toInt());
		});

	// 连接随机生成按钮的点击事件
	connect(ui->btnRandom, &QPushButton::clicked, this, [=]() {
		int randomElement = QRandomGenerator::global()->bounded(100);

		ui->widget->insert(randomElement);
		});
}

MainWidget::~MainWidget()
{
	delete ui;
}