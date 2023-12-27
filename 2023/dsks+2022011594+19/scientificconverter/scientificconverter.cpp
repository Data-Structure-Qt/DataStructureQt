// scientificconverter.cpp
#include "scientificconverter.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <sstream>
#include <iomanip>
ScientificConverter::ScientificConverter(QWidget *parent)
	: QWidget(parent) {
	inputLineEdit = new QLineEdit(this);
	convertButton = new QPushButton("Convert", this);
	resultLabel = new QLabel("Result: ", this);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(inputLineEdit);
	layout->addWidget(convertButton);
	layout->addWidget(resultLabel);

	connect(convertButton, &QPushButton::clicked, this, [this]() {
		QString scientificNotation = inputLineEdit->text();
		emit conversionRequested(scientificNotation);
	});

	connect(this, &ScientificConverter::conversionRequested, this, &ScientificConverter::convertScientificToDouble);
}
QString ScientificConverter::convertToShortestForm(double number) {
		// ����Ƿ���ָ����Χ��
		if (std::abs(number) < 1e-4) {
			// �����ָ����Χ�ڣ����ֶ�����Ϊʮ������ʽ
			
			return QString::number(number, 'f', 15);
		}
		else {
			// ����ʹ�ÿ�ѧ������
			return QString::number(number, 'g', 15);
		}
	

}
void ScientificConverter::convertScientificToDouble(const QString &scientificNotation){
	bool ok;
	double result = scientificNotation.toDouble(&ok);

	if (ok) {
		QString resultAsString = convertToShortestForm(result);
		resultLabel->setText("Result: " + resultAsString);
	}
	else {
		resultLabel->setText("Conversion failed!");
	}
}




