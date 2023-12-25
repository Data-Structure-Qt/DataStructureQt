#include "BinaryTreeUI.h"

#include <QMessageBox>

BinaryTreeUI::BinaryTreeUI(QWidget *parent)
    : QWidget(parent), ui(new Ui::BinaryTreeUI), m_scene(NULL) {
  ui->setupUi(this);
  listshow = nullptr;
}
void BinaryTreeUI::onSceneDetached(CEditorScene *scene) {
  scene->disconnect(this);
}
void BinaryTreeUI::setScene(CNodeEditorScene *scene) {
  if (m_scene)
    onSceneDetached(m_scene);
  m_scene = scene;
  setEnabled(m_scene);
  if (m_scene)
    onSceneAttached(m_scene);
}
void BinaryTreeUI::onSceneAttached(CEditorScene *scene) {}
void BinaryTreeUI::setCQuickHelpUI(CQuickHelpUI *quickHelp) {
  m_quickHelp = quickHelp;
  setEnabled(m_quickHelp);
}
void BinaryTreeUI::setCEditorView(CEditorView *editorView) {
  m_editorView = editorView;
  setEnabled(m_editorView);
}
BinaryTreeUI::~BinaryTreeUI() {}

// ���ƶ�����
void BinaryTreeUI::on_drawTree_btn_clicked() {
  QString inorderSequence = ui->inorderSeqEdit->text();
  QString layerorderSequence = ui->layerorderSeqEdit->text();

  if (inorderSequence.size() != layerorderSequence.size()) {
    QMessageBox::warning(
        this, QString::fromLocal8Bit("����"),
        QString::fromLocal8Bit("����ͺ�������벻�Ϸ����ַ������Ȳ�ͬ��"),
        QMessageBox::Ok);
    m_scene->clearScreen();
    return;
  }

  m_scene->clearScreen();

  avlTree = new CBiTree();

  root = avlTree->buildTree(inorderSequence, layerorderSequence);

    int depth = 0;
  DepthOfBiTree(root, depth);
    double highSize = 2400 * 0.618 / (double)depth;
  if (highSize > 75) {
    highSize = 75;
  }
  const double wide = pow(2, depth) - 1;
  const double wideSize = 9 * wide;

  frametime[0] = 0;
  onlytotaltime = 0;
  history_wideSize[0] = wideSize;
  history_highSize[0] = highSize;

  // insertIdCode[i] = codeid;
  
  inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, 0);

  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
    animationDrawWithChar(onlytotaltime, j);
  }

  
  m_editorView->fitToView();
  m_scene->addUndoState();
  timestamp = 0;
}

//�����Ǵ���ƽ�������
// void BinaryTreeUI::on_binarytree_create_btn_clicked() {
//  m_scene->clearScreen(); //����
//
//  avlTree = new CBiTree();   //�½���
//  root = avlTree->getRoot(); //�½��ڵ�
//
//  QString data = ui->BinaryTreeDataEdit->text();
//  list = data.split(",");
//
//  for (int i = 0; i < list.size(); ++i) {
//    bool flag;
//    const int res = list.at(i).toUInt(&flag);
//    if (!flag) {
//      return;
//    }
//    list_array[i] = res; //��Ϊ����
//  }
//
//  for (int i = 0; i < list.size(); i++) {
//    root = avlTree->insert(root, list_array[i]);
//    //������������
//    int depth = 0;
//    DepthOfBiTree(root, depth);
//    //������ÿ���׼�߶�
//    double highSize = 2400 * 0.618 / (double)depth;
//    if (highSize > 75) {
//      highSize = 75;
//    }
//    //���������һ��������
//    const double wide = pow(2, depth) - 1;
//    //���������һ�������
//    const double wideSize = 9 * wide;
//
//    frametime[i] = 0;
//    onlytotaltime = i;
//    history_wideSize[i] = wideSize;
//    history_highSize[i] = highSize;
//
//    // insertIdCode[i] = codeid;
//    // �ݹ�չʾ������ ��λ���Ϊ 15 ������
//    inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, i);
//  }
//
//  // //��ʼ��ʾ����
//  // string InOrd;
//  // PreOrderBiTree(root, InOrd);
//  // QString temp = "DLR:" + QString::fromStdString(InOrd);
//  // m_scene->printInOrd(100, -200, temp);
//  // string MidOrd;
//  // InOrderBiTree(root, MidOrd);
//  // temp = "LDR:" + QString::fromStdString(MidOrd);
//  // m_scene->printInOrd(100, -170, temp);
//  // string LasOrd;
//  // PostOrderBiTree(root, LasOrd);
//  // temp = "LRD:" + QString::fromStdString(LasOrd);
//  // m_scene->printInOrd(100, -140, temp);
//  // m_scene->clearScreen(); //����
//
//  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
//    animationDrawWithChar(onlytotaltime, j);
//  }
//  m_quickHelp->btree_create_code(insertIdCode[frametime[onlytotaltime]]);
//  //��Ӧ����
//  m_editorView->fitToView();
//  //��Ӧ����
//  m_scene->addUndoState();
//  timestamp = 0;
//}

////�����Ǵ������������
// void BinaryTreeUI::on_binarytree_SimulationTree_creat_btn_clicked() {
//  m_scene->clearScreen();    //����
//  avlTree = new CBiTree();   //�½���
//  root = avlTree->getRoot(); //�½��ڵ�
//  QString data = ui->BinaryTreeDataEdit->text();
//  list = data.split(",");
//  list_array[1010];
//  for (int i = 0; i < list.size(); ++i) {
//    QString tmp = list.at(i);
//    bool flag;
//    int x = tmp.toUInt(&flag);
//    if (!flag)
//      return;
//    list_array[i] = x; //����Ϊ����
//  }
//  for (int i = 0; i < list.size(); i++)
//    root = avlTree->insert(root, list_array[i]);
//  //��ʼ��ʾ����
//  string InOrd;
//  PreOrderBiTree(root, InOrd);
//  QString temp = "DLR:" + QString::fromStdString(InOrd);
//  m_scene->printInOrd(100, -200, temp);
//  string MidOrd;
//  InOrderBiTree(root, MidOrd);
//  temp = "LDR:" + QString::fromStdString(MidOrd);
//  m_scene->printInOrd(100, -170, temp);
//  string LasOrd;
//  PostOrderBiTree(root, LasOrd);
//  temp = "LRD:" + QString::fromStdString(LasOrd);
//  m_scene->printInOrd(100, -140, temp);
//  for (double i = 0; i <= 20; i = i + 0.1) {
//    m_scene->clearScreen(); //����
//    inOrderPrint_SimulationTree(root, 0, 400, (i + 1) * 10, 90, 1 + i * 1.5,
//    0,
//                                400);
//    QTime time;
//    time.start();
//    while (time.elapsed() < 0.00005)
//      ;                                //�ȴ�ʱ��
//    QCoreApplication::processEvents(); //�����¼�
//    //��Ӧ����
//    m_editorView->fitToView();
//    //��Ӧ����
//    m_scene->addUndoState();
//  }
//}

//�������ڵ�ɾ������
// void BinaryTreeUI::on_binarytree_node_delete_btn_clicked() {
//  QString data = ui->BinaryTreeDataEdit_2->text();
//  bool flag;
//  int x = data.toUInt(&flag);
//  if (!flag)
//    return;
//  CBiTreeNode *node = avlTree->search(root, x);
//  if (node != NULL)
//    CBiTreeNode *dnode = avlTree->deleteNode(root, node);
//  m_scene->clearScreen(); //����
//  //��ʼ��ʾ����
//  string InOrd;
//  PreOrderBiTree(root, InOrd);
//  QString temp = "DLR:" + QString::fromStdString(InOrd);
//  m_scene->printInOrd(100, -200, temp);
//  string MidOrd;
//  InOrderBiTree(root, MidOrd);
//  temp = "LDR:" + QString::fromStdString(MidOrd);
//  m_scene->printInOrd(100, -170, temp);
//  string LasOrd;
//  PostOrderBiTree(root, LasOrd);
//  temp = "LRD:" + QString::fromStdString(LasOrd);
//  m_scene->printInOrd(100, -140, temp);
//  //������������
//  int depth = 0;
//  DepthOfBiTree(root, depth);
//  //������ÿ���׼�߶�
//  double highSize = 2400 * 0.618 / (double)depth;
//  if (highSize > 75) {
//    highSize = 75;
//  }
//  //���������һ��������
//  double wide = pow(2, depth) - 1;
//  //���������һ�������
//  double wideSize = 9 * wide;
//  onlytotaltime--;
//  frametime[onlytotaltime] = 0;
//  history_wideSize[onlytotaltime] = wideSize;
//  history_highSize[onlytotaltime] = highSize;
//  inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);
//  m_scene->clearScreen(); //����
//  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
//    animationDraw(onlytotaltime, j);
//  }
//  //��Ӧ����
//  m_editorView->fitToView();
//  //��Ӧ����
//  m_scene->addUndoState();
//}

//������ɾ������
// void BinaryTreeUI::on_binarytree_delete_btn_clicked() {
//  list.clear();
//  for (int i = 0; i < 1010; ++i) {
//    list_array[i] = 0;
//  }
//  avlTree->destroy(root);
//  m_scene->clearScreen(); //����
//}

//ƽ��������ڵ���Һ���
// void BinaryTreeUI::on_binarytree_node_search_btn_clicked() {
//  QString data = ui->BinaryTreeDataEdit_2->text();
//  bool flag;
//  int x = data.toUInt(&flag);
//  if (!flag)
//    return;
//  m_scene->clearScreen(); //����
//  //��ʼ��ʾ����
//  string InOrd;
//  PreOrderBiTree(root, InOrd);
//  QString temp = "DLR:" + QString::fromStdString(InOrd);
//  m_scene->printInOrd(100, -200, temp);
//  string MidOrd;
//  InOrderBiTree(root, MidOrd);
//  temp = "LDR:" + QString::fromStdString(MidOrd);
//  m_scene->printInOrd(100, -170, temp);
//  string LasOrd;
//  PostOrderBiTree(root, LasOrd);
//  temp = "LRD:" + QString::fromStdString(LasOrd);
//  m_scene->printInOrd(100, -140, temp);
//  //������������
//  int depth = 0;
//  DepthOfBiTree(root, depth);
//  //������ÿ���׼�߶�
//  double highSize = 2400 * 0.618 / (double)depth;
//  if (highSize > 75) {
//    highSize = 75;
//  }
//  //���������һ��������
//  double wide = pow(2, depth) - 1;
//  //���������һ�������
//  double wideSize = 9 * wide;
//  framesearchtime = 0;
//  // onlytotaltime = 0;
//  history_wideSize[0] = wideSize;
//  history_highSize[0] = highSize;
//  //�ݹ�չʾ������ ��λ���Ϊ 15 ������
//  inOrderPrint_search(root, 0, 0, wideSize, highSize, 0, 0, x, 0);
//  m_scene->clearScreen(); //����
//  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
//    animationDraw(onlytotaltime, j);
//  }
//  //��Ӧ����
//  m_editorView->fitToView();
//  //��Ӧ����
//  m_scene->addUndoState();
//  for (int j = 0; j <= framesearchtime; j++) {
//    animationDrawSearch(0, j, x);
//    sleepTime(500);
//  }
//  timestamp = 0;
//}

// ������ʼ��ť�ۺ���
void BinaryTreeUI::goToBeginButton() {
  endplaybuttonflag = 1;
  timestamp = 0;
  m_scene->clearScreen(); //����
  for (int j = 0; j <= frametime[0]; j++) {
    animationDrawWithChar(0, j);
  }
  m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}

// ��������һ����ť�ۺ���
void BinaryTreeUI::stepBackButton() {
  endplaybuttonflag = 1;
  if (timestamp > 0) {
    timestamp--;
    m_scene->clearScreen(); //����
    for (int j = 0; j <= frametime[timestamp]; j++) {
      animationDrawWithChar(timestamp, j);
      m_quickHelp->btree_create_code(insertIdCode[j]);
    }
    m_quickHelp->btree_create_code(insertIdCode[timestamp]);
  }
}

// ��ʼ���а�ť�ۺ���
void BinaryTreeUI::playButton() {
  endplaybuttonflag = 0;
  for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
       timestamp++) {
    m_scene->clearScreen(); //����
    for (int j = 0; j <= frametime[timestamp]; j++) {
      animationDrawWithChar(timestamp, j);
    }
    m_quickHelp->btree_create_code(insertIdCode[timestamp]);
    sleepTime(500);
  }
}

// ��ͣ��ť�ۺ���
void BinaryTreeUI::suspendButton() { endplaybuttonflag = 1; }

// ǰ��һ����ť�ۺ���
void BinaryTreeUI::stepForwardButton() {
  endplaybuttonflag = 1;
  if (timestamp < onlytotaltime) {
    timestamp++;
    m_scene->clearScreen(); //����
    for (int j = 0; j <= frametime[timestamp]; j++) {
      animationDrawWithChar(timestamp, j);
    }
    m_quickHelp->btree_create_code(insertIdCode[timestamp]);
  }
}

// �������ť�ۺ���
void BinaryTreeUI::goToEndButton() {
  endplaybuttonflag = 1;
  m_scene->clearScreen(); //����
  timestamp = onlytotaltime;
  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
    animationDrawWithChar(onlytotaltime, j);
  }
  m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}

// ƽ����������ƺ���
void BinaryTreeUI::inOrderPrint(CBiTreeNode *root, double x, double y,
                                double wideSize, double highSize, double p_x,
                                double p_y, int frame) {
  if (root == NULL) {
    return;
  }

  wideSize /= 2; //ÿ�ν���λֵ���Զ��������ڸ��ڵ������

  if (root->left) {
    frametime[frame]++;
    insertIdCode[frametime[frame]] = 2;
    animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
    //��������
    inOrderPrint(root->left, x - wideSize, y + highSize, wideSize, highSize, x,
                 y, frame);
  }

  if (root->right) {
    frametime[frame]++;
    insertIdCode[frametime[frame]] = 3;
    animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
    //�����Һ���
    inOrderPrint(root->right, x + wideSize, y + highSize, wideSize, highSize, x,
                 y, frame);
  }

  frametime[frame]++;
  animationRecord(onlytotaltime, frametime[frame], x, y, root->key, -1, p_x,
                  p_y);
  insertIdCode[frametime[frame]] = 1;
}

// ƽ���������������
void BinaryTreeUI::inOrderPrint_search(CBiTreeNode *root, double x, double y,
                                       double wideSize, double highSize,
                                       double p_x, double p_y, int data,
                                       int frame) {
  if (root == NULL)
    return;
  wideSize = wideSize / 2; //ÿ�ν���λֵ���Զ��������ڸ��ڵ������
  if (root != NULL) {
    if (root->key == data) //�ҹ�
    {
      framesearchtime++;
      animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y,
                            1, 2);
      animationPrint(0, framesearchtime);
      return;
    } else if (data < root->key) //�ҹ�
    {
      framesearchtime++;
      animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y,
                            1, 3);
      animationPrint(0, framesearchtime);
    } else if (data > root->key) //�ҹ�
    {
      framesearchtime++;
      animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y,
                            1, 5);
      animationPrint(0, framesearchtime);
    }
  }
  if (root->left != NULL && data < root->key) {
    inOrderPrint_search(root->left, x - wideSize, y + highSize, wideSize,
                        highSize, x, y, data, 1);
  }
  if (root->right != NULL && data > root->key) {
    inOrderPrint_search(root->right, x + wideSize, y + highSize, wideSize,
                        highSize, x, y, data, 2);
  }
}

void BinaryTreeUI::inOrderPrint_SimulationTree(CBiTreeNode *root, double x,
                                               double y, double Branch_length,
                                               double Branch_angle,
                                               double Change_angle, double p_x,
                                               double p_y) //�ݹ�չʾ����
{
  if (root == NULL)
    return;
  if (root->left != NULL) {
    double angle = Branch_angle + Change_angle;           //��ʱ��Ƕ�
    double radian = angle * 3.14159265 / 180;             //���㻡��
    double Branch_length_x = Branch_length * cos(radian); // x λ��
    double Branch_length_y = Branch_length * sin(radian); // y λ��
    inOrderPrint_SimulationTree(root->left, x + Branch_length_x,
                                y - Branch_length_y, Branch_length * 0.8, angle,
                                Change_angle, x, y); //����
  }
  if (root->right != NULL) {
    double angle = Branch_angle - Change_angle + 2;       //˳ʱ��Ƕ�
    double radian = angle * 3.14159265 / 180;             //���㻡��
    double Branch_length_x = Branch_length * cos(radian); // x λ��
    double Branch_length_y = Branch_length * sin(radian); // y λ��
    inOrderPrint_SimulationTree(root->right, x + Branch_length_x,
                                y - Branch_length_y, Branch_length * 0.8, angle,
                                Change_angle, x, y); //�Һ���
  }
  //���Ƶ�ǰ�ڵ�
  if (root != NULL)
    m_scene->drawCircle_simulate(x, y, root->key, p_x, p_y);
}

void BinaryTreeUI::PreOrderBiTree(CBiTreeNode *root, string &In) //�������
{
  if (root) {
    char inStr[10];
    itoa(root->key, inStr, 10);
    In += inStr;
    PreOrderBiTree(root->left, In);
    PreOrderBiTree(root->right, In);
  }
}

void BinaryTreeUI::InOrderBiTree(CBiTreeNode *root, string &In)
//�������
{
  if (root) {
    InOrderBiTree(root->left, In);
    char inStr[10];
    itoa(root->key, inStr, 10);
    In += inStr;
    InOrderBiTree(root->right, In);
  }
}

void BinaryTreeUI::PostOrderBiTree(CBiTreeNode *root, string &In) {
  if (root) {
    PostOrderBiTree(root->left, In);
    PostOrderBiTree(root->right, In);
    char inStr[10];
    itoa(root->key, inStr, 10);
    In += inStr;
  }
}

//��ȡ���ĸ߶�
void BinaryTreeUI::DepthOfBiTree(CBiTreeNode *root, int &In) {
  if (root) {
    DepthOfBiTree(root->left, In);
    DepthOfBiTree(root->right, In);
    if (root->height >= 0) {
      if (root->height >= In) {
        In = root->height;
      }
    }
  }
}

void BinaryTreeUI::sleepTime(int time) {
  QTime dieTime = QTime::currentTime().addMSecs(time);
  while (QTime::currentTime() < dieTime) {
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  }
}

void BinaryTreeUI::animationRecord(int totaltime, int frame, int x, int y,
                                   int data1, int data2, int p_x, int p_y) {
  animation[totaltime][frame].x = x;
  animation[totaltime][frame].y = y;
  animation[totaltime][frame].data1 = data1;
  animation[totaltime][frame].data2 = data2;
  animation[totaltime][frame].p_x = p_x;
  animation[totaltime][frame].p_y = p_y;
}

void BinaryTreeUI::animationSearchRecord(int totaltime, int frame, int x, int y,
                                         int data1, int data2, int p_x, int p_y,
                                         int flag, int codeid) {
  animationSearch[totaltime][frame].x = x;
  animationSearch[totaltime][frame].y = y;
  animationSearch[totaltime][frame].data1 = data1;
  animationSearch[totaltime][frame].data2 = data2;
  animationSearch[totaltime][frame].p_x = p_x;
  animationSearch[totaltime][frame].p_y = p_y;
  animationSearch[totaltime][frame].flag = flag;
  animationSearch[totaltime][frame].codeid = codeid;
}

void BinaryTreeUI::animationClean() {
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      animation[i][j].x = 0;
      animation[i][j].y = 0;
      animation[i][j].data1 = 0;
      animation[i][j].data2 = 0;
      animation[i][j].p_x = 0;
      animation[i][j].p_y = 0;
    }
  }
}

void BinaryTreeUI::animationPrint(int totaltime, int frametime) {
  qDebug() << "totaltime" << totaltime;
  qDebug() << "frametime" << frametime;
  int i = totaltime;
  int j = frametime;
  qDebug() << "animation[i].x " << animation[i][j].x;
  qDebug() << "animation[i].y " << animation[i][j].y;
  qDebug() << " animation[i].data1 " << animation[i][j].data1;
  qDebug() << " animation[i].data2 " << animation[i][j].data2;
  qDebug() << " animation[i].p_x " << animation[i][j].p_x;
  qDebug() << " animation[i].p_y " << animation[i][j].p_y;
}

void BinaryTreeUI::animationDraw(int totaltime, int frametime) {
  for (int i = 0; i < frametime; i++) //������������
  {
    if (animation[totaltime][frametime].data2 == -1) {
      m_scene->drawCircle(animation[totaltime][frametime].x,
                          animation[totaltime][frametime].y,
                          animation[totaltime][frametime].data1,
                          animation[totaltime][frametime].p_x,
                          animation[totaltime][frametime].p_y);
    } else if (animation[totaltime][frametime].data1 != -1) {
      m_scene->drawCircle2(animation[totaltime][frametime].x,
                           animation[totaltime][frametime].y,
                           animation[totaltime][frametime].data1,
                           animation[totaltime][frametime].data2,
                           animation[totaltime][frametime].p_x,
                           animation[totaltime][frametime].p_y);
    }
  }
}

void BinaryTreeUI::animationDrawWithChar(int totaltime, int frametime) {
  for (int i = 0; i < frametime; i++) //������������
  {
    if (animation[totaltime][frametime].data2 == -1) {
      m_scene->drawCircleWithChar(animation[totaltime][frametime].x,
                                  animation[totaltime][frametime].y,
                                  animation[totaltime][frametime].data1,
                                  animation[totaltime][frametime].p_x,
                                  animation[totaltime][frametime].p_y);
    } else if (animation[totaltime][frametime].data1 != -1) {
      m_scene->drawCircle2WithChar(animation[totaltime][frametime].x,
                                   animation[totaltime][frametime].y,
                                   animation[totaltime][frametime].data1,
                                   animation[totaltime][frametime].data2,
                                   animation[totaltime][frametime].p_x,
                                   animation[totaltime][frametime].p_y);
    }
  }
}

void BinaryTreeUI::animationDrawSearch(int totaltime, int frametime, int x) {
  for (int i = 0; i < frametime; i++) //������������
  {
    if (animationSearch[totaltime][frametime].data2 == -1) {
      m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
                                 animationSearch[totaltime][frametime].y,
                                 animationSearch[totaltime][frametime].data1,
                                 animationSearch[totaltime][frametime].p_x,
                                 animationSearch[totaltime][frametime].p_y, x);
    } else if (animation[totaltime][frametime].data1 != -1) {
      m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
                                 animationSearch[totaltime][frametime].y,
                                 animationSearch[totaltime][frametime].data1,
                                 animationSearch[totaltime][frametime].p_x,
                                 animationSearch[totaltime][frametime].p_y, x);
    }
  }
}