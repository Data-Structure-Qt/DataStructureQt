#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_concatenateButton_clicked();
	void on_reverseButton_clicked();
	void on_compareButton_clicked();
	void on_substringButton_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
