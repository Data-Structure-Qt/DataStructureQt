#include <iostream>
#include <queue>
#include<qpainter.h>
using namespace std;
const int MAX = 3;
//Ϊʲô����b����������ˣ�
// BP �ڵ���
class _Node {
public:

    int* key, size;// ��ֵ�ʹ�С
    _Node** ptr;// ���ӽڵ�
    _Node* parent;// ���ڵ�
    QPoint p;
    bool leaf;// �ж��Ƿ�ΪҶ�ӽڵ�
    friend class BPTree;// ��Ԫ��������ԣ��ѵ�ֻ����ͬһ���ļ����include�������ļ���������Ԫ����
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
    inline _Node* getroot() { return root; }//��ȡ���ڵ㣬ͨ���������ã�������Ԫ�ᱨ��˵��������Ԫ������������������ʹ��friend��û������
};

//δ�������������Ĳ���
int BPTree::insertNode(int x, _Node* cursor) {
    int i = 0;
    while (x > cursor->key[i] && i < cursor->size) i++;// �ҵ������i
    for (int j = cursor->size; j > i; j--) cursor->key[j] = cursor->key[j - 1];// i�������key����һλ����x�ڳ��ռ�
    cursor->key[i] = x;
    cursor->size++;
    return i;
}

//���뺯��
void BPTree::insert(int x) {
    // root Ϊ�մ������ĸ��ڵ㲢����ֵ
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

        while (cursor->leaf == false) {// ѭ����Ҷ�ӽڵ�
            parent = cursor;
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->key[i]) {// �ҵ�����㣬��һ��
                    cursor = cursor->ptr[i];
                    break;
                }

                if (i == cursor->size - 1) {// �ҵ����(Ҫ����ı���һ��Ķ���)����һ��
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        if (cursor->size < MAX) {// Ҷ�ӽڵ㣬δ��������
            insertNode(x, cursor);
            cursor->parent = parent;
            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = NULL;
        }
        else split(x, parent, cursor);// Ҷ�ӽ�����������Ѳ�����x
    }
}

void BPTree::split(int x, _Node* parent, _Node* cursor) {
    _Node* RLeaf = new _Node;// �ҷ���
    _Node* LLeaf = new _Node;// �����
    
    insertNode(x, cursor);// ����x
    RLeaf->size = (MAX + 1) - (MAX + 1) / 2;
    LLeaf->leaf = RLeaf->leaf = true;
    LLeaf->size = (MAX + 1) / 2;
    

    for (int i = 0; i < MAX + 1; i++)
        LLeaf->ptr[i] = cursor->ptr[i];// �������к��ӽڵ�ָ�루��������ָ�룩�������

    LLeaf->ptr[LLeaf->size] = RLeaf;// ��������

    RLeaf->ptr[RLeaf->size] = LLeaf->ptr[MAX];// ����ͬ����Ҳ�ڵ�
    LLeaf->ptr[MAX] = NULL;
    for (int i = 0; i < LLeaf->size; i++) {
        LLeaf->key[i] = cursor->key[i];
    }
    for (int i = 0, j = LLeaf->size; i < RLeaf->size; i++, j++) {
        RLeaf->key[i] = cursor->key[j];
    }
    if (cursor == root) {                       //���ڵ��   1   2   3   4   ����5 ��         1
        _Node* newRootNode = new _Node;              //                                          / \          //����ѧ�˰�
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

//�����ע�Ͷ��ǰ��յ�һ�εݹ�ʱ�����д��
void BPTree::splitedInsert(int x, _Node* cursor, _Node* LLeaf, _Node* RLeaf)
{

    if (cursor->size < MAX) {// ���ڵ�δ�� ���Ѻ�ĺ��ӿ�����������
        auto i = insertNode(x, cursor);
        for (int j = cursor->size; j > i + 1; j--) {
            cursor->ptr[j] = cursor->ptr[j - 1];
        }
        cursor->ptr[i] = LLeaf;
        cursor->ptr[i + 1] = RLeaf;
    }

    else {// ���ڵ�����

        //������Ѹ��ڵ�
        _Node* newLchild = new _Node;
        _Node* newRchild = new _Node;
        _Node* newPtr[MAX + 3];//��ֹ�����max+2������Χ����bugʱ̫��ĥ�˰���
        for (int i = 0; i < MAX + 1; i++) {
            newPtr[i] = cursor->ptr[i];
        }
        int i = insertNode(x, cursor);
        for (int j = MAX + 2; j > i + 1; j--) {//������� ������ƶ�һλ *********
            newPtr[j] = newPtr[j - 1];
        }
        newPtr[i] = LLeaf;
        newPtr[i + 1] = RLeaf;
        // ���Ϸ��Ѻ��ӽڵ��ĳ����ȵĸ��ڵ㹹������virtualPtr

        newLchild->leaf = newRchild->leaf = false;
        //�����Ҷ�ӽ�����������

        //������Ҷ�ӽ�㸸�ڵ�ķ��ѣ�ע������д��
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
        else {// ���������ϲ��Ұ�
            
            splitedInsert(cursor->key[newLchild->size], cursor->parent, newLchild, newRchild);
        }
    }
}

//��ӡ�����������Բ���
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
