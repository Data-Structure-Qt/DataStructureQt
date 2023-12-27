#include "StackUI.h"
#include "CNodeEditorScene.h"
#include "ui_StackUI.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QTime>

StackUI::StackUI(QWidget *parent)
    : QWidget(parent), ui(new Ui::StackUI), m_scene(NULL) {
  ui->setupUi(this);
}

void StackUI::onSceneDetached(CEditorScene *scene) { scene->disconnect(this); }

void StackUI::setScene(CNodeEditorScene *scene) {
  if (m_scene)
    onSceneDetached(m_scene);
  m_scene = scene;
  setEnabled(m_scene);
  if (m_scene)
    onSceneAttached(m_scene);
}

void StackUI::onSceneAttached(CEditorScene *scene) {}

void StackUI::setCQuickHelpUI(CQuickHelpUI *quickHelp) {
  m_quickHelp = quickHelp;
  setEnabled(m_quickHelp);
}

void StackUI::setCEditorView(CEditorView *editorView) {
  m_editorView = editorView;
  setEnabled(m_editorView);
}

StackUI::~StackUI() {}

void StackUI::on_creat_btn_clicked() {
  for (int i = 1; i <= QStackList.size(); ++i) {
    m_scene->deletenode(i);
  }
  while (QStackList.size() != 0) //������ٴ���
  {
    QStackList.clear();
  }
  QList<CNode *> nodes = m_scene->getSelectedNodes();
  QString data = ui->dataEdit->text();
  QStringList temp = data.split(",");
  printf("name is");
  for (int i = 0; i < temp.size(); ++i) {
    Stacknode *node = new Stacknode();
    node->m_StrName = temp.at(i);
    QStackList.push(node);
    printf("name is");
  }
  printf("name is %s", (*(QStackList.top())).m_StrName);
  if (QStackList.size() >= 7) {
    timestamp++;
    onlytotaltime = timestamp;
    frametime[timestamp] = 5; //������ 6 ��Ԫ�أ��� 0 ��ʼ
    for (int i = 0; i < 6; ++i) {
      QString tmp = (*(QStackList.at(i))).m_StrName;
      bool flag;
      int x = tmp.toUInt(&flag);
      if (!flag)
        return;
      m_scene->insertnode(i, x);
      frametimeValue[timestamp][i] = x; //����
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
      QStackList.pop();
    }
    m_scene->addstack();
    //��Ӧ����
    m_editorView->fitToView();
    //��Ӧ����
    m_scene->addUndoState();
    m_quickHelp->stack_insert_code(1);
    QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
                         QString::fromLocal8Bit("ջ���!������ 6 ����������"),
                         QMessageBox::Cancel | QMessageBox::Ok);
    return;
  }
  m_quickHelp->stack_insert_code(2);
  timestamp++;
  onlytotaltime = timestamp;
  frametime[timestamp] = QStackList.size() - 1;
  //������ QStackList.size()��Ԫ�أ��� 0 ��ʼ
  for (int i = 0; i < QStackList.size(); ++i) {
    QString tmp = (*(QStackList.at(i))).m_StrName;
    bool flag;
    int x = tmp.toUInt(&flag);
    if (!flag)
      return;
    m_scene->insertnode(i, x);
    frametimeValue[timestamp][i] = x; //����
  }
  m_scene->addstack();
  //��Ӧ����
  m_editorView->fitToView();
  //��Ӧ����
  m_scene->addUndoState();
}

void StackUI::on_clean_btn_clicked() //�����ť�ۺ���
{
  ui->dataEdit->clear();
  for (int i = 1; i <= QStackList.size(); ++i) {
    m_scene->deletenode(i);
  }
  m_scene->clearScreen();
  QStackList.clear();
  timestamp++;
  onlytotaltime = timestamp;
  frametime[timestamp] = -1; //û��Ԫ�أ��� 0 ��ʼ
}

void StackUI::on_push_btn_clicked() {
  const QString data = ui->insertEdit->text();
  if (data.isEmpty()) {
    QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
                         QString::fromLocal8Bit("����Ϊ�գ�"),
                         QMessageBox::Cancel | QMessageBox::Ok);
    return;
  }

  m_quickHelp->stack_insert_code(2);
  for (int i = 1; i <= QStackList.size(); ++i) //�����󴴽�
  {
    m_scene->deletenode(i);
  }

  int list_size = QStackList.size();
  Stacknode *node = new Stacknode();
  node->m_StrName = data;
  // QStackList.insert(list_size, *node); //β������
  QStackList.push(node); //β������
  if (QStackList.size() >= 7) {
    timestamp++;
    onlytotaltime = timestamp;
    frametime[timestamp] = 5; // 6 Ԫ�أ��� 0 ��ʼ
    for (int i = 0; i < 6; ++i) {
      QString tmp = (*(QStackList.at(i))).m_StrName;
      bool flag;
      int x = tmp.toUInt(&flag);
      if (!flag)
        return;
      m_scene->insertnode(i, x);
      frametimeValue[timestamp][i] = x; //����
    }
    m_scene->addstack();
    //��Ӧ����
    m_editorView->fitToView();
    //��Ӧ����
    m_scene->addUndoState();
    m_quickHelp->stack_insert_code(1);
    QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
                         QString::fromLocal8Bit("ջ���!������ 6 ����������"),
                         QMessageBox::Cancel | QMessageBox::Ok);
    return;
  }
  m_quickHelp->stack_insert_code(2);
  timestamp++;
  onlytotaltime = timestamp;
  frametime[timestamp] = QStackList.size() - 1; //Ԫ�أ��� 0 ��ʼ
  for (int i = 0; i < QStackList.size(); ++i) {
    QString tmp = (*(QStackList.at(i))).m_StrName;
    bool ok2;
    int x = tmp.toUInt(&ok2);
    if (!ok2)

      return;
    m_scene->insertnode(i, x);
    frametimeValue[timestamp][i] = x; //����
  }
}

void StackUI::on_pop_btn_clicked() //β���Ƴ���ť�ۺ���
{
  m_quickHelp->stack_pop_code(2);
  for (int i = 1; i <= QStackList.size(); ++i) //�����󴴽�
  {
    m_scene->deletenode(i);
  }
  if (!QStackList.isEmpty()) {
    QStackList.pop(); //ɾ�����һ��Ԫ��
  } else {
    QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
                         QString::fromLocal8Bit("ջ�ѿ�!�޷�������ջ"),
                         QMessageBox::Cancel | QMessageBox::Ok);
    m_quickHelp->stack_pop_code(1);
    return;
  }
  timestamp++;
  onlytotaltime = timestamp;
  frametime[timestamp] = QStackList.size() - 1; //Ԫ�أ��� 0 ��ʼ
  for (int i = 0; i < QStackList.size(); ++i) {
    QString tmp = (*(QStackList.at(i))).m_StrName;
    bool ok2;
    int x = tmp.toUInt(&ok2);
    if (!ok2)
      return;
    m_scene->insertnode(i, x);
    frametimeValue[timestamp][i] = x; //����
  }
}

void StackUI::goToBeginButton() {
  endplaybuttonflag = 1;
  timestamp = 1;
  m_scene->clearScreen(); //����
  m_scene->addstack();
  for (int j = 0; j <= frametime[1]; j++) {
    m_scene->insertnode(j, frametimeValue[timestamp][j]);
  }
}

void StackUI::stepBackButton() {
  endplaybuttonflag = 1;
  if (timestamp > 1) {
    timestamp--;
    m_scene->clearScreen(); //����
    m_scene->addstack();
    for (int j = 0; j <= frametime[timestamp]; j++) {
      m_scene->insertnode(j, frametimeValue[timestamp][j]);
    }
  }
}

void StackUI::playButton() {
  endplaybuttonflag = 0;
  for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
       timestamp++) {
    m_scene->clearScreen(); //����
    m_scene->addstack();
    for (int j = 0; j <= frametime[timestamp]; j++) {
      m_scene->insertnode(j, frametimeValue[timestamp][j]);
    }
    sleepTime(500);
  }
}

void StackUI::suspendButton() { endplaybuttonflag = 1; }

void StackUI::stepForwardButton() {
  endplaybuttonflag = 1;
  if (timestamp < onlytotaltime) {
    timestamp++;
    m_scene->clearScreen(); //����
    m_scene->addstack();
    for (int j = 0; j <= frametime[timestamp]; j++) {
      /*animationDraw(timestamp, j);*/
      m_scene->insertnode(j, frametimeValue[timestamp][j]);
    }
  }
}

void StackUI::goToEndButton() {
  endplaybuttonflag = 1;
  m_scene->clearScreen(); //����
  m_scene->addstack();
  timestamp = onlytotaltime;
  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
    m_scene->insertnode(j, frametimeValue[timestamp][j]);
  }
}

void StackUI::sleepTime(int time) {
  //��ȡ�Զ�������ʱ��
  QTime dieTime = QTime::currentTime().addMSecs(time);
  while (QTime::currentTime() < dieTime) {
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  }
}
