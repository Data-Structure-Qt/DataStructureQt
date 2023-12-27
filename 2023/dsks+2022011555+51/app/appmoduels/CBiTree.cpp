#include "CBiTree.h"
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
int CBiTree::height(CBiTreeNode* node)
{
	if (node != NULL)
		return node->height;
	return 0;
}
CBiTreeNode* CBiTree::leftLeftRotate(CBiTreeNode* root)
{
	CBiTreeNode* lchild = root->left;
	root->left = lchild->right;
	lchild->right = root;
	lchild->height = max(height(lchild->left), height(root)) + 1;
	root->height = max(height(root->left), height(root->right)) + 1;
	return lchild;
}
CBiTreeNode* CBiTree::rightRightRotate(CBiTreeNode* root)
{
	CBiTreeNode* rchild = root->right;
	root->right = rchild->left;
	rchild->left = root;
	rchild->height = max(height(root), height(rchild->right)) + 1;
	root->height = max(height(root->left), height(root->right)) + 1;
	return rchild;
}
CBiTreeNode* CBiTree::leftRightRotate(CBiTreeNode* root)
{
	root->left = rightRightRotate(root->left); //先对左子树右右旋转
	return leftLeftRotate(root); //再对根结点左左旋转
}
CBiTreeNode* CBiTree::rightLeftRotate(CBiTreeNode* root)
{
	root->right = leftLeftRotate(root->right);
	return rightRightRotate(root);
}
CBiTreeNode* CBiTree::insert(CBiTreeNode* root, int key)
{
	if (root == NULL)
		root = new CBiTreeNode(key, NULL, NULL);
	else if (key < root->key) //插入左子树
	{
		root->left = insert(root->left, key);
		if (height(root->left) - height(root->right) == 2) //插入二叉树导致失衡
		{
			if (key < root->left->key)
				root = leftLeftRotate(root);
			else root = leftRightRotate(root);
		}
	}
	else if (key > root->key) //插入右子树
	{
		root->right = insert(root->right, key);
		if (height(root->right) - height(root->left) == 2) //插入导致二叉树失衡
		{
			if (key > root->right->key)
				root = rightRightRotate(root);
			else root = rightLeftRotate(root);
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}
CBiTreeNode* CBiTree::deleteNode(CBiTreeNode* root, CBiTreeNode* node)
{
	if (root == NULL)
		return NULL;
	if (node->key < root->key) //要删除的结点在左子树
	{
		root->left = deleteNode(root->left, node);
	}
	else if (node->key > root->key) //要删除的结点在右子树
	{
		root->right = deleteNode(root->right, node);
	}
	else //找到了要删除的结点
	{ //结点的左右子树均不为空
		if (root->left != NULL && root->right != NULL)
		{
			if (height(root->left) > height(root->right))
			{
				CBiTreeNode* maxNode = maximus(root->left);
				root->key = maxNode->key;
				root->left = deleteNode(root->left, maxNode);
			}
			else
			{
				CBiTreeNode* minNode = minimus(root->right);
				root->key = minNode->key;
				root->right = deleteNode(root->right, minNode);
			}
		}
		else
		{
			CBiTreeNode* tmp = root;
			root = (root->left != NULL) ? root->left : root->right;
			delete tmp;
		}
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
	InOrder(root, InOrd);//获得中序遍历序列
	int linenum = 10;
	for (int k = 0; k < linenum; k++)
	{
		qDebug() << ' ';
	}
	linenum = linenum - 1;
	while (!q.empty()) {
		vector<CBiTreeNode*> cache;
		//取出队列中位于同一行的结点 放到 cache 中
		while (!q.empty())
		{
			cache.push_back(q.front());
			q.pop();
		}
		string line = " ";
		for (int i = 0; i < cache.size(); i++)
		{
			CBiTreeNode* p = cache[i];
			//遍历同一行的结点 按照它们在中序序列的位置 修改在 line 中的位置
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
					//将结点的左右孩子入队
					if (p->left) q.push(p->left);
					if (p->right) q.push(p->right);
				}
		}
		//输出之前修改的 line 
		qDebug() << endl;
	}
}

//////////////////////////////////////////////////////////////////////////
//排序二叉树
void CSiTree::preOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	qDebug() << root->key << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void CSiTree::inOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	qDebug() << root->key << " ";
	inOrder(root->right);
}
void CSiTree::postOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	qDebug() << root->key << " ";
}
CBiTreeNode* CSiTree::search(CBiTreeNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key < root->key)
		search(root->left, key);
	else search(root->right, key);
}
CBiTreeNode* CSiTree::minimus(CBiTreeNode* node)
{
	if (node->left == NULL)
		return node;
	return minimus(node->left);
}
CBiTreeNode* CSiTree::maximus(CBiTreeNode* node)
{
	if (node->right == NULL)
		return node;
	return maximus(node);
}
//返回结点的高度
int CSiTree::height(CBiTreeNode* node)
{
	if (node != NULL)
		return node->height;
	return 0;
}

CBiTreeNode* CSiTree::insert(CBiTreeNode* root, int key)
{
	if (root == NULL) {
		root = new CBiTreeNode(key, NULL, NULL);
		root->parent = nullptr;
	}
	else if (key < root->key) //插入左子树
	{
		root->left = insert(root->left, key);
		root->left->parent = root;
	}
	else if (key > root->key) //插入右子树
	{
		root->right = insert(root->right, key);
		root->right->parent = root;
	}

	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

CBiTreeNode* CSiTree::deleteNode(CBiTreeNode* root, CBiTreeNode* node)// 删除节点
{
	if (root == NULL)
		return NULL;

	if (node->key < root->key) {
		root->left = deleteNode(root->left, node);
	}
	else if (node->key > root->key) {
		root->right = deleteNode(root->right, node);
	}
	else if (root->left != NULL && root->right != NULL)// 左右节点均不空
	{
		root->key = minimus(root->right)->key;// 找到右侧最小值替代
		root->right = deleteNode(root->right, root);
	}
	else // 左右单空或者左右都空
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

void CSiTree::destroy(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}
void CSiTree::InOrder(CBiTreeNode* root, string &In)
{
	if (root) {
		InOrder(root->left, In);
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
		InOrder(root->right, In);
	}
}
void CSiTree::TreePrint(CBiTreeNode* root)
{
	queue<CBiTreeNode *> q;
	q.push(root);
	string InOrd;
	InOrder(root, InOrd);//获得中序遍历序列
	int linenum = 10;
	for (int k = 0; k < linenum; k++)
	{
		qDebug() << ' ';
	}
	linenum = linenum - 1;
	while (!q.empty()) {
		vector<CBiTreeNode*> cache;
		//取出队列中位于同一行的结点 放到 cache 中
		while (!q.empty())
		{
			cache.push_back(q.front());
			q.pop();
		}
		string line = " ";
		for (int i = 0; i < cache.size(); i++)
		{
			CBiTreeNode* p = cache[i];
			//遍历同一行的结点 按照它们在中序序列的位置 修改在 line 中的位置
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
				//将结点的左右孩子入队
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
		}
		//输出之前修改的 line 
		qDebug() << endl;
	}
}
