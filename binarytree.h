#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<QChar>
#include<QString>
#include<QPoint>
#include<QLine>
#include <QMap>

typedef struct BinTreeNode
{
   double data;                 //数据
   BinTreeNode *left,*right,*parent;   //左孩子、右孩子
   QPoint point;               //结点的坐标
   Qt::GlobalColor eColor;
   BinTreeNode()               //默认构造函数
   {
       left=NULL;
       right=NULL;
       point=QPoint(0,0);
       eColor = Qt::blue;
   }

   //构造函数
   BinTreeNode(double data,QPoint point=QPoint(0,0),BinTreeNode *left=NULL,BinTreeNode *right=NULL,BinTreeNode *parent=NULL,
               Qt::GlobalColor eColor=Qt::blue)
   {
       this->data=data;
       this->left=left;
       this->right=right;
       this->point=point;
       this->eColor = eColor;
       this->parent = parent;
   }

    //修改坐标的值
   void setpoint(QPoint p)
   {
         point=p;
   }
}*BiTree;

typedef QPair<QPoint, double> Node_Pair;
class BinaryTree
{
public:

    //构造函数、析构函数
    BinaryTree();
    BinaryTree(QString str);
    ~BinaryTree();

    //前序、中序、后、层次遍历
    void preOrder();
    void inOrder();
    void postOrder();
    void LevelOrder();

    QString getParnt();

    void setMyPoints();      //为坐标组设置应的坐标,以及得到相应的线段
    int size();              //返回树结点的个数
    int height()
    {
        return height(root);
    }
    int height(BinTreeNode *Node);  //得到树的高度
    void swapTree();         //交换结点
    bool Find(double ch);     //查找值为key的结点
    bool Find(double ch,BinTreeNode *Node);                 //查找函数
    void Find1(double ch,BinTreeNode *Node);                 //查找函数
    void clear();
    Qt::GlobalColor findNodeByPoint(QPoint pt);
    BinTreeNode *BST_Search(BiTree T, double key, BinTreeNode *&p) {
        p = NULL;
        while (T != NULL && key != T->data) {
            p = T;
            if (key < T->data) {
                T = T->left;
            } else {
                T = T->right;
            }
        }
        return T; // 没有引用，不会造成影响
    }
//    BinTreeNode *findNodeByPoint(QString str);
    void initTreeColor();
    //获得前序、中序、后、层次遍历的字符串
    QString getPreStr();
    QString getInStr();
    QString getPostStr();
    QStringList getLevelStr();

    QPoint *getPoints();       //得到坐标
    QLine *getLines();         //得到线段

    BinTreeNode  *getRoot(); //获得根节点
    QString keyParent;      //关键值的父节点
    QStringList parentStrList;
    QStringList findStrList;
    bool isright;           //用于判断是否能够成功建树
    Qt::GlobalColor eColor;
    BinTreeNode *findNode;
    BiTree &getCurNode(){return  m_pCurNode;}
protected:
    BinTreeNode *root;      //树的根节点
    int Treesize;           //树的结点个数
    QPoint *Mypoints;       //树各个结点坐标的集合
    QLine *My_lines;        //线的条数
    QList<Node_Pair> m_nodeMap;//根据坐标存储节点，找颜色
//    QMap<QPoint, QChar> m_charNodeMap;//根据字符存节点，赋颜色
    QString preStr;         //前序遍历得到的字符串
    QString inStr;          //中序遍历得到的字符串
    QString postStr;        //后序遍历得到的字符串
    QString levelStr;       //层次遍历得到的字符串
    void CreateBinTree(QString &str,BinTreeNode *&Node,int &i);   //通过字符串，前序遍历建立树
    void destroy(BinTreeNode *Node);                       //删除
    void swapTree(BinTreeNode *Node);                      //交换


    //前序、中序、后序遍历
    void preOrder(BinTreeNode *Node);
    void inOrder(BinTreeNode *Node);
    void postOrder(BinTreeNode *Node);
    void BST_Insert(BiTree &node, double value);

    //通过前序和中序建树
    BinTreeNode *creatBinaryTree(QString pre,QString in,int n);
    BiTree m_pCurNode;
};

#endif // BINARYTREE_H
