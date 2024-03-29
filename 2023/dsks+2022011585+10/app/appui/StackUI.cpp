#include "StackUI.h"
#include "ui_StackUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTime>
StackUI::StackUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::StackUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}
void StackUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}

void StackUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void StackUI::onSceneAttached(CEditorScene* scene)
{}
void StackUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}
void StackUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}
StackUI::~StackUI()
{}
void StackUI::on_creat_btn_clicked()
{
	for (int i = 1; i <= QStackList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	while (QStackList.size() != 0) // 先清空再创建
	{
		QStackList.clear();
	}

	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();

	if (!isParenthesesMatched(data))//isParenthesesMatched()是判断括号是否匹配的函数
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("括号不匹配"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}

	QStringList temp = data.split(",");
	printf("name is");

	for (int i = 0; i < temp.size(); ++i)
	{
		Stacknode* node = new Stacknode();
		node->m_StrName = temp.at(i);
		QStackList.push(node);
		printf("name is");
	}


	m_quickHelp->stack_insert_code(2);
	timestamp++;
	onlytotaltime = timestamp;
	frametime[timestamp] = QStackList.size() - 1;

	for (int i = 0; i < QStackList.size(); ++i)
	{
		QString tmp = (*(QStackList.at(i))).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		m_scene->insertnode(i, x);
		frametimeValue[timestamp][i] = x; // 存入
	}

	m_scene->addstack();
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}


void StackUI::on_clean_btn_clicked()
{
	// 清除输入框内容
	ui->dataEdit->clear();

	// 清除场景中的元素
	for (int i = 1; i <= QStackList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	m_scene->clearScreen();

	// 清空栈
	QStackList.clear();

	// 检查括号匹配
	QString data = ui->dataEdit->text();
	if (!isParenthesesMatched(data))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("括号不匹配"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}

	// 继续原始的时间戳逻辑
	timestamp++;
	onlytotaltime = timestamp;
	frametime[timestamp] = -1; // 没有元素，从0开始
}
bool StackUI::isParenthesesMatched(const QString& str)
{
	int count = 0;
	for (const QChar& ch : str)
	{
		if (ch == '(')
		{
			count++;
		}
		else if (ch == ')')
		{
			count--;
			if (count < 0)
			{
				return false; // 右括号多余左括号
			}
		}
	}
	return count == 0; // 左右括号数量相等，匹配
}
void StackUI::on_push_btn_clicked()
{
	m_quickHelp->stack_insert_code(2);
	for (int i = 1; i <= QStackList.size(); ++i) // 清屏后创建
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insertEdit->text();
	int list_size = QStackList.size();
	Stacknode* node = new Stacknode();
	node->m_StrName = data;
	// 尾部插入
	QStackList.push(node);
	int leftBracketCount = 0;
	int rightBracketCount = 0;
	if (QStackList.size() >= 7)
	{
		timestamp++;
		onlytotaltime = timestamp;
		frametime[timestamp] = 5; // 6元素，从0开始
		for (int i = 0; i < 6; ++i)
		{
			QString tmp = (*(QStackList.at(i))).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			m_scene->insertnode(i, x);
			frametimeValue[timestamp][i] = x; // 存入
		}
		m_scene->addstack();
		// 适应窗口
		m_editorView->fitToView();
		// 适应网格
		m_scene->addUndoState();
		m_quickHelp->stack_insert_code(1);
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), 
			QString::fromLocal8Bit("栈溢出!请输入6个以内数字"),QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	timestamp++;
	onlytotaltime = timestamp;
	frametime[timestamp] = QStackList.size() - 1; // 元素，从0开始
	for (int i = 0; i < QStackList.size(); ++i)
	{
		QString tmp = (*(QStackList.at(i))).m_StrName;
		for (QChar ch : tmp)
		{
			if (ch == '(' )
			{
				leftBracketCount++;
			}
			else if (ch == ')')
			{
				rightBracketCount++;
				if (rightBracketCount > leftBracketCount)
				{
					// 括号不匹配
					return;
				}
			}
		}
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		frametimeValue[timestamp][i] = x; // 存入
	}
	if (leftBracketCount != rightBracketCount)
	{
		// 括号不匹配
		return;
	}
}
void StackUI::on_pop_btn_clicked() // 尾部移除按钮槽函数
{
	m_quickHelp->stack_pop_code(2);
	for (int i = 1; i <= QStackList.size(); ++i) // 清屏后创建
	{
		m_scene->deletenode(i);
	}
	if (!QStackList.isEmpty())
	{
		QStackList.pop(); // 删除最后一个元素
	}
	else
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), 
			QString::fromLocal8Bit("栈已空!无法继续出栈"), QMessageBox::Cancel | QMessageBox::Ok);
		m_quickHelp->stack_pop_code(1);
		return;
	}
	timestamp++;
	onlytotaltime = timestamp;
	frametime[timestamp] = QStackList.size() - 1; // 元素，从0开始
	int leftBracketCount = 0;
	int rightBracketCount = 0;
	for (int i = 0; i < QStackList.size(); ++i)
	{
		QString tmp = (*(QStackList.at(i))).m_StrName;
		for (QChar ch : tmp)
		{
			if (ch == '(')
			{
				leftBracketCount++;
			}
			else if (ch == ')')
			{
				rightBracketCount++;
				if (rightBracketCount > leftBracketCount)
				{
					// 括号不匹配
					return;
				}
			}
		}
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		frametimeValue[timestamp][i] = x; // 存入
	}
	if (leftBracketCount != rightBracketCount)
	{
		// 括号不匹配
		return;
	}
}


void StackUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 1;
	m_scene->clearScreen();//清屏
	m_scene->addstack();
	for (int j = 0; j <= frametime[1]; j++)
	{
		m_scene->insertnode(j, frametimeValue[timestamp][j]);
	}
}
void StackUI::stepBackButton()
{
	endplaybuttonflag = 1;
	if (timestamp > 1)
	{
		timestamp--;
		m_scene->clearScreen();//清屏
		m_scene->addstack();
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			m_scene->insertnode(j, frametimeValue[timestamp][j]);
		}
	}
}
void StackUI::playButton()
{
	endplaybuttonflag = 0;
	for(timestamp;timestamp<=onlytotaltime&& endplaybuttonflag!=1;timestamp++)
	{
		m_scene->clearScreen();//清屏
		m_scene->addstack();
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			m_scene->insertnode(j, frametimeValue[timestamp][j]);
		}
		sleepTime(500);
	}
}

void StackUI::suspendButton()
{
	endplaybuttonflag = 1;
}
void StackUI::stepForwardButton()
{
	endplaybuttonflag = 1;
	if (timestamp < onlytotaltime)
	{
		timestamp++;
		m_scene->clearScreen();//清屏
		m_scene->addstack();
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			/*animationDraw(timestamp, j);*/
			m_scene->insertnode(j, frametimeValue[timestamp][j]);
		}
	}
}
void StackUI::goToEndButton()
{
	endplaybuttonflag = 1;
	m_scene->clearScreen();//清屏
	m_scene->addstack();
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		m_scene->insertnode(j, frametimeValue[timestamp][j]);
	}
}
void StackUI::sleepTime(int time)
{
	//获取自定义休眠时间
	QTime dieTime = QTime::currentTime().addMSecs(time);
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}
