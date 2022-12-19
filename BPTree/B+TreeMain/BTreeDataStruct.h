#include <iostream>
#include <queue>
#include<qpainter.h>
using namespace std;
const int MAX = 3;
//为什么不是b树啊！搞错了！
// BP 节点类
class _Node {
public:

    int* key, size;// 键值和大小
    _Node** ptr;// 孩子节点
    _Node* parent;// 父节点
    QPoint p;
    bool leaf;// 判断是否为叶子节点
    friend class BPTree;// 友元（这里可以，难道只能在同一个文件里（或include包含的文件）声明友元？）
    _Node() :key(new int[MAX + 3]), ptr(new _Node* [MAX + 3]), parent(NULL) { leaf = false; size = 0; p = QPoint(0, 0); }
    ~_Node() {};
    
};

// BP tree
class BPTree {
private:
    _Node* root;
    inline void splitedInsert(int x, _Node* cursor, _Node* LLeaf, _Node* RLeaf);
    inline void split(int x, _Node* parent, _Node* cursor);
    inline int insertNode(int, _Node*);
public:
    BPTree() :root(NULL) {}
    inline void insert(int x);
    inline void display();
    inline _Node* getroot() { return root; }//获取根节点，通过函数调用，声明友元会报错，说是声明友元不允许在数据声明中使用friend，没搞明白
};

//未满，进行正常的插入
int BPTree::insertNode(int x, _Node* cursor) {
    int i = 0;
    while (x > cursor->key[i] && i < cursor->size) i++;// 找到插入点i
    for (int j = cursor->size; j > i; j--) cursor->key[j] = cursor->key[j - 1];// i及后面的key后移一位，给x腾出空间
    cursor->key[i] = x;
    cursor->size++;
    return i;
}

//插入函数
void BPTree::insert(int x) {
    // root 为空创建树的根节点并输入值
    if (root == NULL) {
        root = new _Node;
        root->key[0] = x;
        root->leaf = true;
        root->size = 1;
        root->parent = NULL;
    }
    else {
        _Node* cursor = root;
        _Node* parent = NULL;

        while (cursor->leaf == false) {// 循环到叶子节点
            parent = cursor;
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->key[i]) {// 找到插入点，下一层
                    cursor = cursor->ptr[i];
                    break;
                }

                if (i == cursor->size - 1) {// 找到最后(要插入的比这一层的都大)，下一层
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        if (cursor->size < MAX) {// 叶子节点，未满，插入
            insertNode(x, cursor);
            cursor->parent = parent;
            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = NULL;
        }
        else split(x, parent, cursor);// 叶子结点已满，分裂并插入x
    }
}

void BPTree::split(int x, _Node* parent, _Node* cursor) {
    _Node* RLeaf = new _Node;// 右分裂
    _Node* LLeaf = new _Node;// 左分裂
    
    insertNode(x, cursor);// 插入x
    RLeaf->size = (MAX + 1) - (MAX + 1) / 2;
    LLeaf->leaf = RLeaf->leaf = true;
    LLeaf->size = (MAX + 1) / 2;
    

    for (int i = 0; i < MAX + 1; i++)
        LLeaf->ptr[i] = cursor->ptr[i];// 复制所有孩子节点指针（包括最后的指针）到左分裂

    LLeaf->ptr[LLeaf->size] = RLeaf;// 左右相连

    RLeaf->ptr[RLeaf->size] = LLeaf->ptr[MAX];// 连接同层的右侧节点
    LLeaf->ptr[MAX] = NULL;
    for (int i = 0; i < LLeaf->size; i++) {
        LLeaf->key[i] = cursor->key[i];
    }
    for (int i = 0, j = LLeaf->size; i < RLeaf->size; i++, j++) {
        RLeaf->key[i] = cursor->key[j];
    }
    if (cursor == root) {                       //根节点从   1   2   3   4   插入5 到         1
        _Node* newRootNode = new _Node;              //                                          / \          //不想学了啊
        newRootNode->key[0] = RLeaf->key[0];         //                                       1,2  3,4,5
        newRootNode->ptr[0] = LLeaf;
        newRootNode->ptr[1] = RLeaf;
        newRootNode->leaf = false;
        newRootNode->size = 1;
        root = newRootNode;
        LLeaf->parent = RLeaf->parent = newRootNode;
    }
    else { splitedInsert(RLeaf->key[0], parent, LLeaf, RLeaf); }

}

//这里的注释都是按照第一次递归时的情况写的
void BPTree::splitedInsert(int x, _Node* cursor, _Node* LLeaf, _Node* RLeaf)
{

    if (cursor->size < MAX) {// 父节点未满 分裂后的孩子可以正常保留
        auto i = insertNode(x, cursor);
        for (int j = cursor->size; j > i + 1; j--) {
            cursor->ptr[j] = cursor->ptr[j - 1];
        }
        cursor->ptr[i] = LLeaf;
        cursor->ptr[i + 1] = RLeaf;
    }

    else {// 父节点满了

        //下面分裂父节点
        _Node* newLchild = new _Node;
        _Node* newRchild = new _Node;
        _Node* newPtr[MAX + 3];//防止下面的max+2超出范围（找bug时太折磨了啊）
        for (int i = 0; i < MAX + 1; i++) {
            newPtr[i] = cursor->ptr[i];
        }
        int i = insertNode(x, cursor);
        for (int j = MAX + 2; j > i + 1; j--) {//插入点后的 都向后移动一位 *********
            newPtr[j] = newPtr[j - 1];
        }
        newPtr[i] = LLeaf;
        newPtr[i + 1] = RLeaf;
        // 以上分裂孩子节点后的超长度的父节点构建好了virtualPtr

        newLchild->leaf = newRchild->leaf = false;
        //这里和叶子结点上有区别的

        //下面是叶子结点父节点的分裂，注释懒得写了
        newLchild->size = (MAX + 1) / 2;
        newRchild->size = MAX - (MAX + 1) / 2;
        for (int i = 0; i < newLchild->size; i++) {
            newLchild->key[i] = cursor->key[i];
        }
        for (int i = 0, j = newLchild->size + 1; i < newRchild->size; i++, j++) {

            newRchild->key[i] = cursor->key[j];
        }
        for (int i = 0; i < LLeaf->size + 1; i++) {
            newLchild->ptr[i] = newPtr[i];
        }
        for (int i = 0, j = LLeaf->size + 1; i < RLeaf->size + 1; i++, j++) {
            newRchild->ptr[i] = newPtr[j];
        }
        if (cursor == root || cursor->parent==NULL) {
            _Node* newRoot = new _Node;
            newRoot->key[0] = cursor->key[newLchild->size];
            newRoot->ptr[0] = newLchild;
            newRoot->ptr[1] = newRchild;
            newRoot->leaf = false;
            newRoot->size = 1;
            root = newRoot;
            newLchild->parent = newRchild->parent = newRoot;
        }
        else {// 又满了向上查找吧
            
            splitedInsert(cursor->key[newLchild->size], cursor->parent, newLchild, newRchild);
        }
    }
}

//打印结果看看结果对不对
void BPTree::display() {
    queue<_Node*>q;
    q.push(root);
    while (!q.empty()) {

        int size_t = q.size();
        while (size_t--) {
            auto t = q.front();
            for (int i = 0; i < t->size + 1; i++) {
                if (!t->leaf) {
                    q.push(t->ptr[i]);
                }
            }
            for (int i = 0; i < t->size; i++) {
                cout << t->key[i] << ",";
            }
            cout << "  ";
            q.pop();
        }
        cout << endl;

    }

}
