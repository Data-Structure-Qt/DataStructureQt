#include "binarytree.h"
#include<QDebug>
#include<QStack>
#include<QQueue>
//默认构造函数
BinaryTree::BinaryTree()
{
    root=nullptr;
    Treesize=0;
    Mypoints=nullptr;
    isright=true;
    eColor = Qt::blue;
}

//构造函数
BinaryTree::BinaryTree(QString str)
{
    QStringList tmpList = str.split(",");
    Treesize = 0;
    root = nullptr;
    int i = 0;
    while (i < tmpList.size()) {
        BST_Insert(root, tmpList[i].toDouble()); // 把某一结点放入二叉排序树
        i++;
    }
    this->LevelOrder();
    this->setMyPoints();
}

//析构函数
BinaryTree::~BinaryTree()
{
    this->clear();
}


void BinaryTree::LevelOrder()
{
    QQueue<BinTreeNode *>Q;         //调用队列
    BinTreeNode *p=root;
    Q.enqueue(root);
    while(!Q.isEmpty())
    {
        p=Q.dequeue();
        parentStrList.append(QString::number(p->data));
        if(p->left!=nullptr)
        {
            Q.enqueue(p->left);
//            qDebug() << p->left->data;
        }
        if(p->right!=nullptr)
        {
            Q.enqueue(p->right);
//            qDebug() << p->right->data;
        }
    }
}
//为坐标组设置应的坐标,以及得到相应的线段
void BinaryTree::setMyPoints()
{
    //设置父节点和子节点间横坐标相差的距离

    int i=0;
    //    int H=height();
    Mypoints=new QPoint[Treesize];  //动态分配空间
    My_lines=new QLine[Treesize-1];

    QQueue<BinTreeNode *>Q;         //调用队列
    BinTreeNode *p=root;
    root->setpoint(QPoint(500,150));  //为根节点设置坐标
    Q.enqueue(root);
    Mypoints[i]=root->point;
    m_nodeMap.push_back(Node_Pair(Mypoints[i],root->data));
    //    m_charNodeMap[root->point] = root->data;
    //通过层次遍历，完成各个坐标的匹配
    while(!Q.isEmpty())
    {
        p=Q.dequeue();
        if(p->left!=nullptr)
        {
            i++;
            int h=height(p);
//            qDebug() <<h;
            p->left->setpoint(p->point-QPoint(45*h,-100));
            Mypoints[i]=p->left->point;
            m_nodeMap.push_back(Node_Pair(Mypoints[i],p->left->data));
            //            m_charNodeMap[p->left->point] = p->left->data;
            My_lines[i-1].setP1(p->point+QPoint(0,25));
            My_lines[i-1].setP2(p->left->point-QPoint(0,25));
            Q.enqueue(p->left);
        }

        if(p->right!=nullptr)
        {
            i++;
            int h=height(p);
            p->right->setpoint(p->point+QPoint(45*h,100));
            Mypoints[i]=p->right->point;
            m_nodeMap.push_back(Node_Pair(Mypoints[i],p->right->data));
            //            m_charNodeMap[p->right->point] = p->right->data;
            My_lines[i-1].setP1(p->point+QPoint(0,25));
            My_lines[i-1].setP2(p->right->point-QPoint(0,25));
            Q.enqueue(p->right);
            h--;
        }

    }

}

//返回节点个数
int BinaryTree::size()
{
    return Treesize;
}

//交换结点
void BinaryTree::swapTree()
{
    delete[]  Mypoints;
    delete[]  My_lines;
    preStr.clear();
    inStr.clear();
    postStr.clear();
    levelStr.clear();
    keyParent.clear();
    parentStrList.clear();

    this->swapTree(root);
    this->setMyPoints();
    this->LevelOrder();

}


bool BinaryTree::Find(double str, BinTreeNode *Node)
{
    if(Node==nullptr)
        return true;
    if(Node->data==str)
    {
        m_pCurNode = Node;
//        findStrList << QString::number(Node->data);
        return true;
    }
    if(Find(str,Node->left)||Find(str,Node->right))
    {
        findStrList << QString::number(Node->data);
    }
}

void BinaryTree::Find1(double ch, BinTreeNode *Node)
{
    while (Node) {
        if(Node->data == ch)
        {
            findStrList << QString::number(Node->data);
            return;
        }

        if(Node->data < ch)
        {
            findStrList << QString::number(Node->data);
            Node = Node->right;
            continue;

        }

        if(Node->data > ch)
        {
            findStrList << QString::number(Node->data);
            Node = Node->left;
            continue;

        }
    }
}

void BinaryTree::clear()
{
    this->destroy(root);
    Treesize=0;
    delete[]  Mypoints;
    delete[]  My_lines;
    preStr.clear();
    inStr.clear();
    postStr.clear();
    levelStr.clear();
    keyParent.clear();
    parentStrList.clear();
}

Qt::GlobalColor BinaryTree::findNodeByPoint(QPoint pt)
{
    for(int i=0; i<m_nodeMap.size(); i++)
    {
        if(pt == m_nodeMap[i].first)
        {
            Find(m_nodeMap[i].second, root);
            return m_pCurNode->eColor;
        }
    }
    return Qt::GlobalColor();
}

//BinTreeNode *BinaryTree::findNodeByChar(QString str)
//{
//    Find()
//    return m_charNodeMap[str];
//}

void BinaryTree::initTreeColor()
{
    for(int i=0; i<m_nodeMap.size(); i++)
    {
        Find(m_nodeMap[i].second, root);
        m_pCurNode->eColor = Qt::blue;
    }
}

//获得前序、中序、后、层次遍历的字符串
QString BinaryTree::getPreStr()
{
    return preStr;
}

QString BinaryTree::getInStr()
{
    return inStr;
}

QString BinaryTree::getPostStr()
{
    return postStr;
}

QStringList BinaryTree::getLevelStr()
{
    return parentStrList;
}

QPoint *BinaryTree::getPoints()
{
    return Mypoints;
}

QLine *BinaryTree::getLines()
{
    return My_lines;
}

BinTreeNode *BinaryTree::getRoot()
{
    return root;
}

int BinaryTree::height(BinTreeNode *Node)
{
    if(Node==nullptr)
        return 0;
    else
    {
        int i=height(Node->left);
        int j=height(Node->right);
        return (i<j)? j+1:i+1;
    }
}

//删除函数
void BinaryTree::destroy(BinTreeNode *Node)
{
    if(Node!=nullptr)
    {
        this->destroy(Node->left);
        this->destroy(Node->right);
        delete Node;
    }

}

void BinaryTree::swapTree(BinTreeNode *Node)
{
    if(Node==nullptr)
        return;
    BinTreeNode *p=Node->left;
    Node->left=Node->right;
    Node->right=p;
    this->swapTree(Node->left);
    this->swapTree(Node->right);
}

void BinaryTree::BST_Insert(BiTree &T, double k)
{
    if (T == NULL) { // 第一个结点作为树根
        T = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        T->data = k;
        T->eColor = Qt::blue;
        T->left = T->right = NULL;
//        T->parent = NULL;
        Treesize++;
        return;
    } else if (k == T->data) {
        return; // 发现相同元素，不插入
    } else if (k  < T->data) {
        return BST_Insert(T->left, k); // 插入结点小于当前结点，插入左边
    } else {
        return BST_Insert(T->right, k); // 插入结点小于当前结点，插入右边
    }
}


