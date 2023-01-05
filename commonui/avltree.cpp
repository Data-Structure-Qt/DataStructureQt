#include "avltree.h"
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
CBiTreeNode* CBiTree::creatThreeBitree(CBiTreeNode* root)
{
	CBiTreeNode* pb = new CBiTreeNode('b', NULL, NULL, NULL);
	CBiTreeNode* pc = new CBiTreeNode('c', NULL, NULL, NULL);
	CBiTreeNode* pd = new CBiTreeNode('d', NULL, NULL, NULL);
	CBiTreeNode* pe = new CBiTreeNode('e', NULL, NULL, NULL);
	CBiTreeNode* pf = new CBiTreeNode('f', NULL, NULL, NULL);
	CBiTreeNode* pg = new CBiTreeNode('g', NULL, NULL, NULL);
	CBiTreeNode* ph = new CBiTreeNode('h', NULL, NULL, NULL);
	CBiTreeNode* pi = new CBiTreeNode('i', NULL, NULL, NULL);
	CBiTreeNode* pj = new CBiTreeNode('j', NULL, NULL, NULL);
	CBiTreeNode* pk = new CBiTreeNode('k', NULL, NULL, NULL);
	CBiTreeNode* pl = new CBiTreeNode('l', NULL, NULL, NULL);
	CBiTreeNode* pm = new CBiTreeNode('m', NULL, NULL, NULL);
	CBiTreeNode* pn = new CBiTreeNode('n', NULL, NULL, NULL);
	CBiTreeNode* po = new CBiTreeNode('o', NULL, NULL, NULL);
	root = new CBiTreeNode('a', NULL, NULL, NULL);
	root->left = pb;
	root->right = pd;
	root->mid = pc;
	root->x_way = 0;
	root->y_way = 0;
	root->parent = NULL;
	pb->left = pe;
	pb->mid = pf;
	pb->right = pg;
	pb->x_way = -150;
	pb->y_way = 50;
	pb->parent = root;
	pc->left = ph;
	pc->x_way = 1;
	pc->y_way = 50;
	pc->parent = root;
	pd->left = pi;
	pd->mid = pj;
	pd->right = pk;
	pd->x_way = 150;
	pd->y_way = 50;
	pd->parent = root;
	pe->x_way = -200;
	pe->y_way = 100;
	pe->parent = pb;
	pf->x_way = -149;
	pf->y_way = 100;
	pf->parent = pb;
	pg->x_way = -100;
	pg->y_way = 100;
	pg->parent = pb;
	ph->left = pl;
	ph->mid = pm;
	ph->x_way =0;
	ph->y_way = 100;
	ph->parent = pc;
	pi->left = pn;
	pi->mid = po;
	pi->x_way = 100;
	pi->y_way = 100;
	pi->parent = pd;
	pj->x_way = 151;
	pj->y_way = 101;
	pj->parent = pd;
	pk->x_way = 200;
	pk->y_way = 100;
	pk->parent = pd;
	pl->x_way = -25;
	pl->y_way = 150;
	pl->parent = ph;
	pm->x_way = 25;
	pm->y_way = 150;
	pm->parent = ph;
	pn->x_way = 75;
	pn->y_way = 150;
	pn->parent = pi;
	po->x_way = 125;
	po->y_way = 150;
	po->parent = pi;
	return root;
}

CBiTreeNode* CBiTree::search(CBiTreeNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key < root->key)
		search(root->left, key);
	else search(root->right, key);
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
		root = new CBiTreeNode(key, NULL, NULL,NULL);
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
		if (height(root->right) - height(root->left) == 2) //删除导致二叉树失衡 
		{
			CBiTreeNode* rightNode = root->right;
			if (height(rightNode->left) > height(rightNode->right))
				root = rightLeftRotate(root);
			else root = rightRightRotate(root);
		}
	}
	else if (node->key > root->key) //要删除的结点在右子树 
	{
		root->right = deleteNode(root->right, node);
		if (height(root->left) - height(root->right) == 2) //删除导致二叉树失衡 
		{
			CBiTreeNode* leftNode = root->left;
			if (height(leftNode->left) > height(leftNode->right))
				root = leftLeftRotate(root);
			else root = leftRightRotate(root);
		}
	}
	else //找到了要删除的结点 
	{
		if (root->left != NULL && root->right != NULL) //结点的左右子树均不为空
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
			//遍历同一行的结点 按照它们在中序序列的位置 修改在 line中的位置
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