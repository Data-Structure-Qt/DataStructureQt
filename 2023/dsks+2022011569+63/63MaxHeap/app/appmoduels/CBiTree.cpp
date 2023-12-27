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
	// ʹ�ù����������
	if (root == NULL) {
		return NULL;
	}

	queue<CBiTreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		CBiTreeNode* current = q.front();
		q.pop();

		if (current->key == key) {
			return current; // �ҵ�Ŀ��ڵ�
		}

		if (current->left != NULL) {
			q.push(current->left);
		}

		if (current->right != NULL) {
			q.push(current->right);
		}
	}

	// δ�ҵ�Ŀ��ڵ�
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
	root->left = rightRightRotate(root->left); //�ȶ�������������ת
	return leftLeftRotate(root); //�ٶԸ����������ת
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
		// ִ�й�����Ȳ���
		queue<CBiTreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			CBiTreeNode* current = q.front();
			q.pop();

			if (current->left == NULL) {
				current->left = new CBiTreeNode(key, NULL, NULL);
				current->left->m_PParent = current;  // �����²���ڵ�ĸ�ָ��
				heapifyUp(root, current->left);  // ��������Ϊ����
				break;  // �ڵ���룬�˳�ѭ��
			}
			else {
				q.push(current->left);
			}

			if (current->right == NULL) {
				current->right = new CBiTreeNode(key, NULL, NULL);
				current->right->m_PParent = current;  // �����²���ڵ�ĸ�ָ��
				heapifyUp(root, current->right);  // ��������Ϊ����
				break;  // �ڵ���룬�˳�ѭ��
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

	// �ҵ�Ҫɾ���Ľڵ�
	CBiTreeNode* target = search(root, node->key);
	if (target == NULL) {
		return root;  // ����δ�ҵ��ýڵ�
	}

	// �ö������һ���ڵ�ļ�ֵ�滻Ŀ��ڵ�ļ�ֵ
	CBiTreeNode* lastNode = findLastNode(root);
	target->key = lastNode->key;

	// ɾ�����һ���ڵ�
	root = deleteLastNode(root, lastNode);

	// ���ɾ���Ľڵ㲻�����һ���ڵ㣬ִ�ж����µ����Ա������ѵ�����
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
		return 0;  // ���ؿ��ַ���ʾ��Чֵ
	}

	// �ҵ��Ѷ��ڵ㣨���ڵ㣩
	CBiTreeNode* topNode = root;
	int value = topNode->key;
	// �ö������һ���ڵ�ļ�ֵ�滻�Ѷ��ڵ�ļ�ֵ
	CBiTreeNode* lastNode = findLastNode(root);
	topNode->key = lastNode->key;

	// ��ȡ��ɾ���ĶѶ��ڵ���ַ�ֵ
	char deletedValue = static_cast<char>(topNode->key); // �����ֵ���������ͣ�����ת��Ϊ�ַ�
	
	// ɾ�����һ���ڵ�
	root = deleteLastNode(root, lastNode);

	// ִ�ж����µ����Ա������ѵ�����
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