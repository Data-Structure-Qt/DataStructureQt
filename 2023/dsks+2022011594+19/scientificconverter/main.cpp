#include <QApplication>
#include "scientificconverter.h"
#include <QDebug>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	ScientificConverter converter;
	converter.show();

	// 处理转换请求的槽函数
	QObject::connect(&converter, &ScientificConverter::conversionRequested, [&](const QString &scientificNotation) {
		// 进行科学计数法转换为实数的操作
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
