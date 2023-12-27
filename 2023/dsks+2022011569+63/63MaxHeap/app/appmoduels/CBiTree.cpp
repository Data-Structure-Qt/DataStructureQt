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
	// 使用广度优先搜索
	if (root == NULL) {
		return NULL;
	}

	queue<CBiTreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		CBiTreeNode* current = q.front();
		q.pop();

		if (current->key == key) {
			return current; // 找到目标节点
		}

		if (current->left != NULL) {
			q.push(current->left);
		}

		if (current->right != NULL) {
			q.push(current->right);
		}
	}

	// 未找到目标节点
	return NULL;
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
	if (root == NULL) {
		root = new CBiTreeNode(key, NULL, NULL);
	}
	else {
		// 执行广度优先插入
		queue<CBiTreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			CBiTreeNode* current = q.front();
			q.pop();

			if (current->left == NULL) {
				current->left = new CBiTreeNode(key, NULL, NULL);
				current->left->m_PParent = current;  // 设置新插入节点的父指针
				heapifyUp(root, current->left);  // 插入后调整为最大堆
				break;  // 节点插入，退出循环
			}
			else {
				q.push(current->left);
			}

			if (current->right == NULL) {
				current->right = new CBiTreeNode(key, NULL, NULL);
				current->right->m_PParent = current;  // 设置新插入节点的父指针
				heapifyUp(root, current->right);  // 插入后调整为最大堆
				break;  // 节点插入，退出循环
			}
			else {
				q.push(current->right);
			}
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

void CBiTree::heapifyUp(CBiTreeNode* root, CBiTreeNode* insertedNode)
{
	CBiTreeNode* current = insertedNode;

	while (current != root && current->key > current->m_PParent->key) {
		swap(current->key, current->m_PParent->key);
		current = current->m_PParent;
	}

}
CBiTreeNode* CBiTree::deleteNode(CBiTreeNode* root, CBiTreeNode* node) {
	if (root == NULL || node == NULL) {
		return root;
	}

	// 找到要删除的节点
	CBiTreeNode* target = search(root, node->key);
	if (target == NULL) {
		return root;  // 树中未找到该节点
	}

	// 用堆中最后一个节点的键值替换目标节点的键值
	CBiTreeNode* lastNode = findLastNode(root);
	target->key = lastNode->key;

	// 删除最后一个节点
	root = deleteLastNode(root, lastNode);

	// 如果删除的节点不是最后一个节点，执行堆向下调整以保持最大堆的性质
	if (target != lastNode) {
		heapifyDown(root, target);
	}

	return root;
}

CBiTreeNode* CBiTree::findLastNode(CBiTreeNode* root) {
	if (root == NULL) {
		return NULL;
	}

	queue<CBiTreeNode*> q;
	q.push(root);
	CBiTreeNode* lastNode = NULL;

	while (!q.empty()) {
		CBiTreeNode* current = q.front();
		q.pop();

		if (current != NULL) {
			lastNode = current;

			if (current->left != NULL) {
				q.push(current->left);
			}

			if (current->right != NULL) {
				q.push(current->right);
			}
		}
	}

	return lastNode;
}
CBiTreeNode* CBiTree::deleteLastNode(CBiTreeNode* root, CBiTreeNode* lastNode) {
	if (root == NULL || lastNode == NULL) {
		return root;
	}

	queue<CBiTreeNode*> q;
	q.push(root);
	CBiTreeNode* current = NULL;
	CBiTreeNode* previous = NULL;

	while (!q.empty()) {
		current = q.front();
		q.pop();

		if (current->left != NULL) {
			if (current->left == lastNode) {
				delete lastNode;
				current->left = NULL;
				break;
			}
			q.push(current->left);
		}

		if (current->right != NULL) {
			if (current->right == lastNode) {
				delete lastNode;
				current->right = NULL;
				break;
			}
			q.push(current->right);
		}
	}

	return root;
}
void CBiTree::heapifyDown(CBiTreeNode* root, CBiTreeNode* current) {
	CBiTreeNode* largest = current;
	CBiTreeNode* left = current->left;
	CBiTreeNode* right = current->right;

	if (left != NULL && left->key > largest->key) {
		largest = left;
	}

	if (right != NULL && right->key > largest->key) {
		largest = right;
	}

	if (largest != current) {
		swap(current->key, largest->key);
		heapifyDown(root, largest);
	}
}
int CBiTree::deleteTopNode(CBiTreeNode* root) {
	if (root == NULL) {
		return 0;  // 返回空字符表示无效值
	}

	// 找到堆顶节点（根节点）
	CBiTreeNode* topNode = root;
	int value = topNode->key;
	// 用堆中最后一个节点的键值替换堆顶节点的键值
	CBiTreeNode* lastNode = findLastNode(root);
	topNode->key = lastNode->key;

	// 获取被删除的堆顶节点的字符值
	char deletedValue = static_cast<char>(topNode->key); // 假设键值是整数类型，将其转换为字符
	
	// 删除最后一个节点
	root = deleteLastNode(root, lastNode);

	// 执行堆向下调整以保持最大堆的性质
	heapifyDown(root, topNode);

	return value;
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