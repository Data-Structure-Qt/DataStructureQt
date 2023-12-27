#include "CBiTree.h"

//���������
void CBiTree::preOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	qDebug() << root->key << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void CBiTree::inOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	qDebug() << root->key << " ";
	inOrder(root->right);
}
void CBiTree::postOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	qDebug() << root->key << " ";
}
CBiTreeNode* CBiTree::search(CBiTreeNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key < root->key)
		return search(root->left, key);
	else return search(root->right, key);
}
CBiTreeNode* CBiTree::minimus(CBiTreeNode* node)
{
	if (node->left == NULL)
		return node;
	return minimus(node->left);
}
CBiTreeNode* CBiTree::maximus(CBiTreeNode* node)
{
	if (node->right == NULL)
		return node;
	return maximus(node);
}
//���ؽ��ĸ߶�
int CBiTree::height(CBiTreeNode* node)
{
	if (node != NULL)
		return node->height;
	return 0;
}

CBiTreeNode* CBiTree::insert(CBiTreeNode* root, int key)
{
	if (root == NULL) {
		root = new CBiTreeNode(key, NULL, NULL);
		root->parent = nullptr;
	}
	else if (key < root->key) //����������
	{
		root->left = insert(root->left, key);
		root->left->parent = root;
	}
	else if (key > root->key) //����������
	{
		root->right = insert(root->right, key);
		root->right->parent = root;
	}

	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

CBiTreeNode* CBiTree::deleteNode(CBiTreeNode* root, CBiTreeNode* node)// ɾ���ڵ�
{
	if (root == NULL)
		return NULL;

	if (node->key < root->key) {
		root->left = deleteNode(root->left, node);
	}
	else if (node->key > root->key) {
		root->right = deleteNode(root->right, node);
	}
	else if (root->left != NULL && root->right != NULL)// ���ҽڵ������
	{
		root->key = minimus(root->right)->key;// �ҵ��Ҳ���Сֵ���
		root->right = deleteNode(root->right, root);
	}
	else // ���ҵ��ջ������Ҷ���
	{
		if (root->left == NULL && root->right == NULL) {
			root = NULL;
		}
		else if (root->right != NULL) {
			root->right->parent = root->parent;
			root = root->right;
		}
		else if (root->left != NULL) {
			root->left->parent = root->parent;
			root = root->left;
		}
		return root;
	}
	return root;
}

void CBiTree::destroy(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}
void CBiTree::InOrder(CBiTreeNode* root, string &In)
{
	if (root) {
		InOrder(root->left, In);
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
		InOrder(root->right, In);
	}
}
void CBiTree::TreePrint(CBiTreeNode* root)
{
	queue<CBiTreeNode *> q;
	q.push(root);
	string InOrd;
	InOrder(root, InOrd);//��������������
	int linenum = 10;
	for (int k = 0; k < linenum; k++)
	{
		qDebug() << ' ';
	}
	linenum = linenum - 1;
	while (!q.empty()) {
		vector<CBiTreeNode*> cache;
		//ȡ��������λ��ͬһ�еĽ�� �ŵ� cache ��
		while (!q.empty())
		{
			cache.push_back(q.front());
			q.pop();
		}
		string line = " ";
		for (int i = 0; i < cache.size(); i++)
		{
			CBiTreeNode* p = cache[i];
			//����ͬһ�еĽ�� �����������������е�λ�� �޸��� line �е�λ��
			if (p)
			{
				char inStr[10];
				itoa(p->key, inStr, 10);
				line[InOrd.find(p->key)] = char(p->key);
				for (int j = 0; j < InOrd.find(inStr); j++)
				{
					qDebug() << ' ';
				}
				qDebug() << p->key;
				//���������Һ������
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
		}
		//���֮ǰ�޸ĵ� line 
		qDebug() << endl;
	}
}
