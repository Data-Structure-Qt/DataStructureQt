// scientificconverter.h
#ifndef SCIENTIFICCONVERTER_H
#define SCIENTIFICCONVERTER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <iomanip>
class ScientificConverter : public QWidget {
	Q_OBJECT

public:
	ScientificConverter(QWidget *parent = nullptr);

signals:
	void conversionRequested(const QString &scientificNotation);

private slots:
	void convertScientificToDouble(const QString &scientificNotation);

private:
	QLineEdit *inputLineEdit;
	QPushButton *convertButton;
	QLabel *resultLabel;
	QString convertToShortestForm(double number);
};

#endif // SCIENTIFICCONVERTER_H
