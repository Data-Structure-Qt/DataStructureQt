#include <QApplication>
#include "scientificconverter.h"
#include <QDebug>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	ScientificConverter converter;
	converter.show();

	// ����ת������Ĳۺ���
	QObject::connect(&converter, &ScientificConverter::conversionRequested, [&](const QString &scientificNotation) {
		// ���п�ѧ������ת��Ϊʵ���Ĳ���
		bool ok;
		double result = scientificNotation.toDouble(&ok);
		if (ok) {
			qDebug() << "Converted value: " << result;
		}
		else {
			qDebug() << "Conversion failed!";
		}
	});

	return app.exec();
}
