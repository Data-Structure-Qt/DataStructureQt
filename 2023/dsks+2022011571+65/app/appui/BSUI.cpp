#include "LinklistUI.h"
#include "CNodeEditorScene.h"
#include "ui_LinklistUI.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <qDebug>






//#include <QApplication>
//#include <QTableView>
//#include <QHeaderView>
//#include <QStandardItemModel>
//int form(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//
//	/* ���������ͼ */
//	QTableView *tableView = new QTableView;
//
//	/* ���ñ����ͼ��С */
//	tableView->resize(850, 400);
//
//	/* ��������ģ�� */
//	QStandardItemModel* model = new QStandardItemModel();
//
//	/* ���ñ�������(��������ΪQStringList����) */
//	model->setHorizontalHeaderLabels({ "ID", "User Name", "City", "Classify", "Score", "Sign" });
//
//	/* ����Ӧ�����У����������ռ� */
//	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//
//	/* ���ع�10�����ݣ���ÿ����6������ */
//	for (int i = 0; i < 10; i++) {
//		/* ���ص�һ��(ID)���� */
//		model->setItem(i, 0, new QStandardItem(QString("100%1").arg(i)));
//		/* ���صڶ���(User Name)���� */
//		model->setItem(i, 1, new QStandardItem(QString("User%1").arg(i)));
//		/* ���ص�����(City)���� */
//		model->setItem(i, 2, new QStandardItem("Shanghai"));
//		/* ���ص�����(Classify)���� */
//		model->setItem(i, 3, new QStandardItem("Engineer"));
//		/* ���ص�����(Score)���� */
//		model->setItem(i, 4, new QStandardItem("80"));
//		/* ���ص�����(Sign)���� */
//		model->setItem(i, 5, new QStandardItem("Hello world!"));
//	}
//
//	/* ���ñ����ͼ���� */
//	tableView->setModel(model);
//
//	/* ��ʾ */
//	tableView->show();
//
//	return a.exec();
//}






void LinklistUI::on_Block_create_btn_clicked() {
	//m_scene->clearScreen();//����
	//for (int i = 1; i <= QBlock.size(); ++i) //ɾ�����нڵ�
	//{
	//	m_scene->deletenode(i);
	//}
	QList<CNode *> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	//for (int i = 0; i < 1; ++i) {
	//	blockingsearch *node = new blockingsearch();
	//	node->m_strname = temp.at(i);
	//	//��ӽ�����
	//	qblock.append(*node);
	//}
	for (int i = 0; i < temp.size(); ++i) {
		BlockingSearch *node = new BlockingSearch();
		node->m_StrName = temp.at(i);
		//��ӽ�����
		QBlock.append(*node);
	}

	if (!QBlock.isEmpty()) {
		QString tmp = QBlock.at(0).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (flag) {
			m_scene->insertblock(0, x); // ����Ļ����
		}
	}

	for (int j = 0; j < temp.size(); ++j) {
		onlytotaltime = j;
		for (int i = 0; i < QBlock.size(); ++i) {
			QString tmp = QBlock.at(i).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			// modded
			frametime[i] = i;
			animationRecord(onlytotaltime, frametime[i], i, x);
			// end modded
		}
	}
	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	m_quickHelp->head_insert_code(1);
	timestamp = 0;
}