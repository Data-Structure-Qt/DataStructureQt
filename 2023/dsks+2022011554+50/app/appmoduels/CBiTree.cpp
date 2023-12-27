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
bool CFibonacciTree::LookUpFibAndIsFib(int val, int& ksum1)
{
	//首先判断是否是一个Fbi数和找到一个Fbi数两步可以合并为一步
	ksum1 = -1;
	if (val < 0)
	{
		return false;
	}

	for (int i = 0; i < fibls.size(); i++)
	{
		if (val == fibls[i])
		{
			ksum1 = i;
			return true;
		}
		else if (val < fibls[i])
		{
			ksum1 = i;
			return false;
		}
	}

	return false;
}

//生成Fib树
void CFibonacciTree::GenerateFibTree(CBiTreeNode* node, int k, int val)
{
	if (k - 2 < 0) return;
	int key = node->key - fibls[k - 2];
	if (key == node->key) return;

	if (node->key != 1)
	{
		node->left = new CBiTreeNode(key, NULL, NULL);
		node->left->key = key;
		node->left->parent = node;
	}

	int keyR = node->key + fibls[k - 2];
	if (key > 1 && keyR != root->key/* && keyR <= keyls.back()*/) //范围内的值才会显示
	{
		if (keyR != node->parent->key || node->parent == nullptr)
		{
			if (node->parent->parent != nullptr && keyR != node->parent->parent->key)
			{
				node->right = new CBiTreeNode(keyR, NULL, NULL);
				node->right->key = keyR;
				node->right->parent = node;
			}
			if (node->parent->parent == nullptr)
			{
				node->right = new CBiTreeNode(keyR, NULL, NULL);
				node->right->key = keyR;
				node->right->parent = node;
			}
		}
	}

	if (node->left != nullptr)
		GenerateFibTree(node->left, k - 1, val);
	if (node->right != nullptr)
		GenerateFibTree(node->right, k - 2, val);

	node->height = max(height(node->left), height(node->right)) + 1;
}

void CFibonacciTree::InitGenerateFibTree(int k, int val)
{
	int key = fibls[k];
	root = new CBiTreeNode(key, NULL, NULL);

	key = fibls[k] - fibls[k - 2];
	root->left = new CBiTreeNode(key, NULL, NULL);
	root->left->parent = root;
	GenerateFibTree(root->left, k - 1, val);

	key = fibls[k] + fibls[k - 2];
	root->right = new CBiTreeNode(key, NULL, NULL);
	root->right->parent = root;
	GenerateFibTree(root->right, k - 2, val);

	root->height = max(height(root->left), height(root->right)) + 1;
}

void CFibonacciTree::FibTreeMinusM(int m, CBiTreeNode* node)
{
	if (node->left != nullptr)
	{
		node->left->key -= m;
		FibTreeMinusM(m, node->left);
		if (node->left->key < 1)
			node->left = nullptr;
	}
	if (node->right != nullptr)
	{
		node->right->key -= m;
		FibTreeMinusM(m, node->right);
		if (node->right->key < 1 || node->right->key > keyls.back())
			node->right = nullptr;
	}
}

void CFibonacciTree::FibLookUpArithmetic(int val)
{
	int ksum1 = 0;
	if (LookUpFibAndIsFib(val, ksum1))
	{
		int k = ksum1 - 1;
		InitGenerateFibTree(k, val);
		FibTreeMinusM(0, root);
	}
	else
	{
		int k = ksum1 - 1;
		InitGenerateFibTree(k, val);
		int m = fibls[ksum1] - (val + 1);
		root->key -= m;
		FibTreeMinusM(m, root);
	}
}


void CFibonacciTree::FibCalc(int n)
{
	fibls.clear();
	fibls.push_back(0);
	for (int i = 1; i < n; i++)
	{
		if (i < 3)
		{
			fibls.push_back(1);
		}
		else
		{
			fibls.push_back(fibls[i - 1] + fibls[i - 2]);
		}
	}
}

//斐波那契二叉树
void CFibonacciTree::preOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	qDebug() << root->key << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void CFibonacciTree::inOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	qDebug() << root->key << " ";
	inOrder(root->right);
}
void CFibonacciTree::postOrder(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	qDebug() << root->key << " ";
}
CBiTreeNode* CFibonacciTree::search(CBiTreeNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key < root->key)
		return search(root->left, key);
	else return search(root->right, key);
}
CBiTreeNode* CFibonacciTree::minimus(CBiTreeNode* node)
{
	if (node->left == NULL)
		return node;
	return minimus(node->left);
}
CBiTreeNode* CFibonacciTree::maximus(CBiTreeNode* node)
{
	if (node->right == NULL)
		return node;
	return maximus(node);
}
//返回结点的高度
int CFibonacciTree::height(CBiTreeNode* node)
{
	if (node != NULL)
		return node->height;
	return 0;
}

CBiTreeNode* CFibonacciTree::insert(CBiTreeNode* root, int key)
{
	if (root == NULL) {
		root = new CBiTreeNode(key, NULL, NULL);
		root->left = nullptr;
		root->right = nullptr;
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

CBiTreeNode* CFibonacciTree::deleteNode(CBiTreeNode* root, CBiTreeNode* node)// 删除节点
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

void CFibonacciTree::destroy(CBiTreeNode* root)
{
	if (root == NULL)
		return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}
void CFibonacciTree::InOrder(CBiTreeNode* root, string &In)
{
	if (root) {
		InOrder(root->left, In);
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
		InOrder(root->right, In);
	}
}
void CFibonacciTree::TreePrint(CBiTreeNode* root)
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


CBiTreeNode* CFibonacciTree::createFibonacciBinaryTree(const vector<int>& data) {
	if (data.empty()) {
		return NULL;
	}
	return createFibonacciBinaryTreeHelper(data, 0, data.size() - 1, 1);
}

CBiTreeNode* CFibonacciTree::createFibonacciBinaryTreeHelper(const vector<int>& data, int start, int end, int depth) {
	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	CBiTreeNode* node = new CBiTreeNode(data[mid], NULL, NULL);
	node->height = depth;
	node->left = createFibonacciBinaryTreeHelper(data, start, mid - 1, depth + 1);
	node->right = createFibonacciBinaryTreeHelper(data, mid + 1, end, depth + 1);

	if (node->left)
		node->left->parent = node;
	if (node->right)
		node->right->parent = node;

	return node;
}

//生成二叉树
bool CFibonacciTree::makeTree(QString dataArray)
{
	keyls.clear();
	QStringList list;
	list = dataArray.split(",");
	for (int i = 0; i < list.size(); ++i) {
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return false;

		keyls.push_back(x);//存为数组
	}

	//root = createFibonacciBinaryTree(keyls);
	FibCalc(30);
	FibLookUpArithmetic(keyls.back());

	return true;
}