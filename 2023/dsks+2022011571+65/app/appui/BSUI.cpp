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
//	/* 创建表格视图 */
//	QTableView *tableView = new QTableView;
//
//	/* 设置表格视图大小 */
//	tableView->resize(850, 400);
//
//	/* 创建数据模型 */
//	QStandardItemModel* model = new QStandardItemModel();
//
//	/* 设置表格标题行(输入数据为QStringList类型) */
//	model->setHorizontalHeaderLabels({ "ID", "User Name", "City", "Classify", "Score", "Sign" });
//
//	/* 自适应所有列，让它布满空间 */
//	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//
//	/* 加载共10行数据，并每行有6列数据 */
//	for (int i = 0; i < 10; i++) {
//		/* 加载第一列(ID)数据 */
//		model->setItem(i, 0, new QStandardItem(QString("100%1").arg(i)));
//		/* 加载第二列(User Name)数据 */
//		model->setItem(i, 1, new QStandardItem(QString("User%1").arg(i)));
//		/* 加载第三列(City)数据 */
//		model->setItem(i, 2, new QStandardItem("Shanghai"));
//		/* 加载第四列(Classify)数据 */
//		model->setItem(i, 3, new QStandardItem("Engineer"));
//		/* 加载第五列(Score)数据 */
//		model->setItem(i, 4, new QStandardItem("80"));
//		/* 加载第六列(Sign)数据 */
//		model->setItem(i, 5, new QStandardItem("Hello world!"));
//	}
//
//	/* 设置表格视图数据 */
//	tableView->setModel(model);
//
//	/* 显示 */
//	tableView->show();
//
//	return a.exec();
//}






void LinklistUI::on_Block_create_btn_clicked() {
	//m_scene->clearScreen();//清屏
	//for (int i = 1; i <= QBlock.size(); ++i) //删除所有节点
	//{
	//	m_scene->deletenode(i);
	//}
	QList<CNode *> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	//for (int i = 0; i < 1; ++i) {
	//	blockingsearch *node = new blockingsearch();
	//	node->m_strname = temp.at(i);
	//	//添加进链表
	//	qblock.append(*node);
	//}
	for (int i = 0; i < temp.size(); ++i) {
		BlockingSearch *node = new BlockingSearch();
		node->m_StrName = temp.at(i);
		//添加进链表
		QBlock.append(*node);
	}

	if (!QBlock.isEmpty()) {
		QString tmp = QBlock.at(0).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (flag) {
			m_scene->insertblock(0, x); // 向屏幕绘制
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