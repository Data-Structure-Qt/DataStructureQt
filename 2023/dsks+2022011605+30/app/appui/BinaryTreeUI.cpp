#include "BinaryTreeUI.h"
#include <QDebug>
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

// 二叉树
CBiTreeNode* CBiTree::buildTreeFromInorderPostorder(const QString& inorder, const QString& postorder) {
    if (inorder.isEmpty() || postorder.isEmpty() || inorder.length() != postorder.length()) {
        return nullptr; // 返回空指针表示无法构建树
    }

    // 获取后序遍历中最后一个节点作为根节点
    QChar rootValue = postorder.at(postorder.length() - 1);
    CBiTreeNode* root = new CBiTreeNode(rootValue); // 创建根节点

    // 在中序遍历中找到根节点的位置
    int rootIndexInInorder = inorder.indexOf(rootValue);

    qDebug() << "Root value:" << rootValue << "Root index in inorder:" << rootIndexInInorder;
    qDebug() << "Left Inorder:" << inorder.left(rootIndexInInorder) << "Left Postorder:" << postorder.left(rootIndexInInorder);
    qDebug() << "Right Inorder:" << inorder.mid(rootIndexInInorder + 1) << "Right Postorder:" << postorder.mid(rootIndexInInorder, postorder.length() - rootIndexInInorder - 1);

    // 递归构建左子树
    root->left = buildTreeFromInorderPostorder(inorder.left(rootIndexInInorder),
        postorder.left(rootIndexInInorder));


    root->right = buildTreeFromInorderPostorder(inorder.mid(rootIndexInInorder + 1),
        postorder.mid(rootIndexInInorder, postorder.length() - rootIndexInInorder - 1));


    qDebug() << "Root:" << root->key << "Left Child:" << (root->left ? root->left->key : 'N') << "Right Child:" << (root->right ? root->right->key : 'N');

    return root; // 返回根节点
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
	for (int i = 0; i < frametime; i++) //遍历整个动画
	{
		if (animation[totaltime][frametime].data2 == -1) {
			m_scene->drawCircle(animation[totaltime][frametime].x,
				animation[totaltime][frametime].y,
				animation[totaltime][frametime].data1,
				animation[totaltime][frametime].p_x,
				animation[totaltime][frametime].p_y);
		}
		else if (animation[totaltime][frametime].data1 != -1) {
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
	for (int i = 0; i < frametime; i++) //遍历整个动画
	{
		if (animation[totaltime][frametime].data2 == -1) {
			m_scene->drawCircleWithChar(animation[totaltime][frametime].x,
				animation[totaltime][frametime].y,
				animation[totaltime][frametime].data1,
				animation[totaltime][frametime].p_x,
				animation[totaltime][frametime].p_y);
		}
		else if (animation[totaltime][frametime].data1 != -1) {
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
	for (int i = 0; i < frametime; i++) //遍历整个动画
	{
		if (animationSearch[totaltime][frametime].data2 == -1) {
			m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y,
				animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
		}
		else if (animation[totaltime][frametime].data1 != -1) {
			m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y,
				animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
		}
	}
}

// 跳到开始按钮槽函数
void BinaryTreeUI::goToBeginButton() {
  endplaybuttonflag = 1;
  timestamp = 0;
  m_scene->clearScreen(); //清屏
  for (int j = 0; j <= frametime[0]; j++) {
    animationDrawWithChar(0, j);
  }
  m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}

// 跳到后退一步按钮槽函数
void BinaryTreeUI::stepBackButton() {
  endplaybuttonflag = 1;
  if (timestamp > 0) {
    timestamp--;
    m_scene->clearScreen(); //清屏
    for (int j = 0; j <= frametime[timestamp]; j++) {
      animationDrawWithChar(timestamp, j);
      m_quickHelp->btree_create_code(insertIdCode[j]);
    }
    m_quickHelp->btree_create_code(insertIdCode[timestamp]);
  }
}

// 开始运行按钮槽函数
void BinaryTreeUI::playButton() {
  endplaybuttonflag = 0;
  for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
       timestamp++) {
    m_scene->clearScreen(); //清屏
    for (int j = 0; j <= frametime[timestamp]; j++) {
      animationDrawWithChar(timestamp, j);
    }
    m_quickHelp->btree_create_code(insertIdCode[timestamp]);
    sleepTime(500);
  }
}

// 暂停按钮槽函数
void BinaryTreeUI::suspendButton() { endplaybuttonflag = 1; }

// 前进一步按钮槽函数
void BinaryTreeUI::stepForwardButton() {
  endplaybuttonflag = 1;
  if (timestamp < onlytotaltime) {
    timestamp++;
    m_scene->clearScreen(); //清屏
    for (int j = 0; j <= frametime[timestamp]; j++) {
      animationDrawWithChar(timestamp, j);
    }
    m_quickHelp->btree_create_code(insertIdCode[timestamp]);
  }
}

// 跳到最后按钮槽函数
void BinaryTreeUI::goToEndButton() {
  endplaybuttonflag = 1;
  m_scene->clearScreen(); //清屏
  timestamp = onlytotaltime;
  for (int j = 0; j <= frametime[onlytotaltime]; j++) {
    animationDrawWithChar(onlytotaltime, j);
  }
  m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}

// 二叉树绘制函数
void BinaryTreeUI::inOrderPrint(CBiTreeNode* root, double x, double y,
    double wideSize, double highSize, double p_x,
    double p_y, int frame) {
    if (root == NULL) {
        return;
    }

    const double horizontalSpacing = 50.0; // 调整节点间水平间距

    // 绘制左子树
    inOrderPrint(root->left, x - horizontalSpacing, y + highSize, wideSize / 2, highSize, x, y, frame);

    // 绘制当前节点
    frametime[frame]++;
    insertIdCode[frametime[frame]] = 1;

    // 设置节点颜色为黑色
    root->m_Color = QColor(Qt::black); // 假设 CBiTreeNode 类包含了 QColor m_Color 属性

    animationRecord(onlytotaltime, frametime[frame], x, y, root->key, -1, p_x, p_y);

    // 绘制右子树
    inOrderPrint(root->right, x + horizontalSpacing, y + highSize, wideSize / 2, highSize, x, y, frame);
}




// 平衡二叉树搜索函数
void BinaryTreeUI::inOrderPrint_search(CBiTreeNode *root, double x, double y,double wideSize, double highSize, double p_x, double p_y, int data,int frame) {
  if (root == NULL)
    return;
  wideSize = wideSize / 2; //每次将单位值除以二，绘制在根节点的左右
  if (root != NULL) {
    if (root->key == data) //找过
    {
      framesearchtime++;
      animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y,
                            1, 2);
      animationPrint(0, framesearchtime);
      return;
    } else if (data < root->key) //找过
    {
      framesearchtime++;
      animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y,
                            1, 3);
      animationPrint(0, framesearchtime);
    } else if (data > root->key) //找过
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
//递归展示函数
void BinaryTreeUI::inOrderPrint_SimulationTree(CBiTreeNode *root, double x, double y, double Branch_length, double Branch_angle, double Change_angle, double p_x,double p_y) 
{
	//参数：
	//  root：二叉树的根节点指针
	//	x、y：当前节点的坐标
	//	Branch_length：分支的长度
	//	Branch_angle：分支的初始角度
	//	Change_angle：改变的角度
	//	p_x、p_y：父节点的坐标
  if (root == NULL)
    return;//如果当前节点root为空，直接返回
  //处理左子树
  if (root->left != NULL) {
    double angle = Branch_angle + Change_angle;           //逆时针角度
    double radian = angle * 3.14159265 / 180;             //计算弧度
    double Branch_length_x = Branch_length * cos(radian); // x 位移
    double Branch_length_y = Branch_length * sin(radian); // y 位移
    inOrderPrint_SimulationTree(root->left, x + Branch_length_x,
                                y - Branch_length_y, Branch_length * 0.8, angle,
                                Change_angle, x, y); //左孩子
  }
  //处理右子树
  if (root->right != NULL) {
    double angle = Branch_angle - Change_angle + 2;       //顺时针角度
    double radian = angle * 3.14159265 / 180;             //计算弧度
    double Branch_length_x = Branch_length * cos(radian); // x 位移
    double Branch_length_y = Branch_length * sin(radian); // y 位移
    inOrderPrint_SimulationTree(root->right, x + Branch_length_x,
                                y - Branch_length_y, Branch_length * 0.8, angle,
                                Change_angle, x, y); //右孩子
  }
  //绘制当前节点
  if (root != NULL)
    m_scene->drawCircle_simulate(x, y, root->key, p_x, p_y);
}

void BinaryTreeUI::PreOrderBiTree(CBiTreeNode *root, string &In) //先序遍历
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

//获取树的高度
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


//恢复二叉树的槽函数
void BinaryTreeUI::on__createTree_btn_clicked() {
//从UI中获取中序遍历和后序遍历的输入字符串
	QString inorder = ui->inorderEdit->text();
	QString postorder = ui->postordeerEdit->text();
//检查中序和后序遍历的输入字符串长度是否相同。
//如果不同，显示错误消息，并清空场景。
	if (inorder.size() != postorder.size()) {
		QMessageBox::warning(
			this, QString::fromLocal8Bit("错误"),
			QString::fromLocal8Bit("中序和后序的输入字符串长度不同"),
			QMessageBox::Ok);
		m_scene->clearScreen();
		return;
	}
	m_scene->clearScreen();
//创建一个 CBiTree 对象
	avlTree = new CBiTree();

	// 构建中序和后序遍历共同构成的二叉树
	root = avlTree->buildTreeFromInorderPostorder(inorder, postorder);
	//计算二叉树的深度和每层标准高度
	int depth = 0;
	DepthOfBiTree(root, depth);
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//求树的最后一层间隔数量
	const double wide = pow(2, depth) - 1;
	//求树的最后一层间隔宽度
	const double wideSize = 9 * wide;
	frametime[0] = 0;
	onlytotaltime = 0;
	history_wideSize[0] = wideSize;
	history_highSize[0] = highSize;
	// 调用inOrderPrint函数递归展示二叉树 单位宽度为 15 个像素
	inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, 0);
	//使用 animationDrawWithChar函数绘制动画
	for (int j = 0; j <= frametime[onlytotaltime]; j++) {
		animationDrawWithChar(onlytotaltime, j);
	}
	//适应窗口和适应网格
	m_editorView->fitToView();
	m_scene->addUndoState();
	timestamp = 0;
}
//清除二叉树的槽函数
void BinaryTreeUI::on_clearTree_btn_clicked() {
	//avlTree->destroy(root);
	m_scene->clearScreen();
}