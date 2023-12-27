#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Connect the slots to the corresponding buttons
	connect(ui->concatenateButton, SIGNAL(clicked()), this, SLOT(on_concatenateButton_clicked()));
	connect(ui->reverseButton, SIGNAL(clicked()), this, SLOT(on_reverseButton_clicked()));
	connect(ui->compareButton, SIGNAL(clicked()), this, SLOT(on_compareButton_clicked()));
	connect(ui->substringButton, SIGNAL(clicked()), this, SLOT(on_substringButton_clicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_concatenateButton_clicked()
{
	QString str1 = ui->lineEdit1->text();
	QString str2 = ui->lineEdit2->text();
	QString result = str1 + str2;
	ui->resultLabel->setText("Concatenated String: " + result);
}

void MainWindow::on_reverseButton_clicked()
{
	QString str = ui->lineEdit1->text();
	QString reversed = str;
	std::reverse(reversed.begin(), reversed.end());
	ui->resultLabel->setText("Reversed String: " + reversed);
}

void MainWindow::on_compareButton_clicked()
{
	QString str1 = ui->lineEdit1->text();
	QString str2 = ui->lineEdit2->text();
	int comparisonResult = str1.compare(str2);

	if (comparisonResult < 0)
		ui->resultLabel->setText("String 1 is smaller than String 2");
	else if (comparisonResult > 0)
		ui->resultLabel->setText("String 1 is larger than String 2");
	else
		ui->resultLabel->setText("Strings are equal");
}

void MainWindow::on_substringButton_clicked()
{
	QString str = ui->lineEdit1->text();
	int start = ui->startSpinBox->value();
	int length = ui->lengthSpinBox->value();

	QString substring = str.mid(start, length);
	ui->resultLabel->setText("Substring: " + substring);
}
