#include "BinaryTreeUI.h"


void RBTree::Insert_Fixup(RBTNode *s)
{
	RBTNode *uncle;           //���㣨�������ֵܽ�㣩
	while (s->parent->color == RED) //���ڵ����ɫҲΪ��ɫ
	{
		//str[number]="Adjusting node "+QString::number(s->key);
		if (s->parent == s->parent->parent->left) //���ڵ�������
		{
			uncle = s->parent->parent->right;

			if (uncle->color == RED) //����Ϊ��ɫ
			{
				//���ڵ�����㶼��Ϊ��ɫ
				s->parent->color = BLACK;
				uncle->color = BLACK;
				//�游����Ϊ��ɫ
				s->parent->parent->color = RED;
				//��sָ��ָ���游��㣬��һ��ѭ�������ж��游�ĸ��ڵ��Ƿ�Ϊ��ɫ
				s = s->parent->parent;
				int depth = 0;
				depth = getHeight();
				//������ÿ���׼�߶�
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75) {
					highSize = 75;
				}
				//���������һ��������
				double wide = pow(2, depth) - 1;
				//���������һ�������
				double wideSize = 9 * wide;
				fixuptime[number] = 0;
				countfixup = number;
				inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
				str[number] = "Case 1: Recoloring " + QString::number(s->key) + " and "
					+ QString::number(uncle->key);
				number++;
			}
			else //û�����㣬������Ϊ��ɫ(�������ѭ��ת�����������Ϊ��)
			{
				if (s == s->parent->right) //��������Ľ�����ҽ��
				{
					s = s->parent; //�Ƚ�sָ��s�ĸ����
					LeftRotate(s); //����ת
					int depth = 0;
					depth = getHeight();
					//������ÿ���׼�߶�
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75) {
						highSize = 75;
					}
					//���������һ��������
					double wide = pow(2, depth) - 1;
					//���������һ�������
					double wideSize = 9 * wide;
					fixuptime[number] = 0;
					countfixup = number;
					inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
					str[number] = "Case 2: Left Rotation at " + QString::number(s->key);
					number++;
				}
				s->parent->color = BLACK;
				//��������Ľ��������,��s�ĸ��ڵ��Ϊ��ɫ�����游�Ľ���Ϊ��ɫ����s���游�����ת
				s->parent->color = BLACK;
				s->parent->parent->color = RED;
				RightRotate(s->parent->parent);
				int depth = 0;
				depth = getHeight();
				//������ÿ���׼�߶�
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75) {
					highSize = 75;
				}
				//���������һ��������
				double wide = pow(2, depth) - 1;
				//���������һ�������
				double wideSize = 9 * wide;
				fixuptime[number] = 0;
				countfixup = number;
				inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
				str[number] = "Case 3: Right Rotation at " + QString::number(s->key);
				number++;
			}
		}
		else
		{
			if (s->parent == s->parent->parent->right) //���ڵ����ҽ��
			{
				uncle = s->parent->parent->left;
				if (uncle->color == RED) //����Ϊ��ɫ
				{
					//���ڵ�����㶼��Ϊ��ɫ
					s->parent->color = BLACK;
					uncle->color = BLACK;
					//�游����Ϊ��ɫ
					s->parent->parent->color = RED;
					//��sָ��ָ���游��㣬��һ��ѭ�������ж��游�ĸ��ڵ��Ƿ�Ϊ��ɫ
					s = s->parent->parent;
					int depth = 0;
					depth = getHeight();
					//������ÿ���׼�߶�
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75) {
						highSize = 75;
					}
					//���������һ��������
					double wide = pow(2, depth) - 1;
					//���������һ�������
					double wideSize = 9 * wide;
					fixuptime[number] = 0;
					countfixup = number;
					inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
					str[number] = "Case 4: Recoloring " + QString::number(s->key) + " and "
						+ QString::number(uncle->key);
					number++;
				}
				else //û�����㣬������Ϊ��ɫ(�������ѭ��ת�����������Ϊ��)
				{
					if (s == s->parent->left) //��������Ľ��������
					{
						s = s->parent;  //�Ƚ�sָ��s�ĸ����
						RightRotate(s); //����ת
						int depth = 0;
						depth = getHeight();
						//������ÿ���׼�߶�
						double highSize = 2400 * 0.618 / (double)depth;
						if (highSize > 75) {
							highSize = 75;
						}
						//���������һ��������
						double wide = pow(2, depth) - 1;
						//���������һ�������
						double wideSize = 9 * wide;
						fixuptime[number] = 0;
						countfixup = number;
						inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
						str[number] = "Case 5: Right Rotation at " + QString::number(s->key);
						number++;
					}
					//��������Ľ�����ҽ��,��s�ĸ��ڵ��Ϊ��ɫ�����游�Ľ���Ϊ��ɫ����s���游�����ת
					s->parent->color = BLACK;
					s->parent->parent->color = RED;
					LeftRotate(s->parent->parent);
					int depth = 0;
					depth = getHeight();
					//������ÿ���׼�߶�
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75) {
						highSize = 75;
					}
					//���������һ��������
					double wide = pow(2, depth) - 1;
					//���������һ�������
					double wideSize = 9 * wide;
					fixuptime[number] = 0;
					countfixup = number;
					inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
					str[number] = "Case 6: Left Rotation at " + QString::number(s->parent->key);
					number++;					
				}
			}
		}
	}
	root->color = BLACK; //���ʼ�ս����ڵ���Ϊ��ɫ
	int depth = 0;
	depth = getHeight();
	//������ÿ���׼�߶�
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//���������һ��������
	double wide = pow(2, depth) - 1;
	//���������һ�������
	double wideSize = 9 * wide;
	fixuptime[number] = 0;
	countfixup = number;
	inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
	str[number] = "Change root to black";
	number++;
	countnumber[cnt] = number-1;
	cnt++;
}

bool RBTree::Insert(const int &value, int i)
{
	RBTNode *pr = Nil; //pr������ס���ڵ�
	RBTNode *s = root; //�������sָ���
	while (s != Nil)
	{
		if (value == s->key)
		{
			return false;
		}
		pr = s; //ÿ�μ�סs�ĸ��ڵ�
		if (value < s->key)
		{
			s = s->left;
		}
		else
		{
			s = s->right;
		}
	}
	//ѭ����s==Nil
	s = BuyNode(value); //������
	if (pr == Nil)      //������ڵ�pr�Ǹ��ڵ㣬��һ��rootָ��Nil������pr==Nil
	{
		root = s;
		root->parent = pr;
	}
	else //������ڵ㲻�Ǹ��ڵ�
	{
		if (value < pr->key)
		{
			pr->left = s;
		}
		else
		{
			pr->right = s;
		}
		s->parent = pr; //�����½��s�ĸ��ڵ�
	}
	int depth = 0;
	depth = getHeight();
	//������ÿ���׼�߶�
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//���������һ��������
	double wide = pow(2, depth) - 1;
	//���������һ�������
	double wideSize = 9 * wide;
	inserttime[i] = 0;
    counttime = i;
	history_wide[i] = wideSize;
	history_high[i] = highSize;
	inOrderPrint_insert(root, Nil, 0, 0, wideSize, highSize, 0, 0, i);
	//����ƽ��
	Insert_Fixup(s);
	return true;
}

void RBTree::inOrderPrint_insert(RBTNode* root, RBTNode* Nil, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (root == Nil)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root->left != Nil)
	{
		int color;
		if (root->left->color == BLACK)
			color = 0;
		else
			color = 1;
		inserttime[frame]++;
		//insertIdCode[frametime[frame]] = 2;
		animationRecord_insert(counttime, inserttime[frame], x, y, root->left->key, -1, p_x, p_y, color);
		//��������
		inOrderPrint_insert(root->left, Nil, x - wideSize, y + highSize, wideSize, highSize, x, y, frame);
	}
	if (root->right != Nil)
	{
		int color;
		if (root->right->color == BLACK)
			color = 0;
		else
			color = 1;
		inserttime[frame]++;
		//insertIdCode[frametime[frame]] = 3;
		animationRecord_insert(counttime, inserttime[frame], x, y, root->right->key, -1, p_x, p_y, color);
		//�����Һ���
		inOrderPrint_insert(root->right, Nil, x + wideSize, y + highSize, wideSize, highSize, x, y,
			frame);
	}
	if (root != Nil)
	{
		int color;
		if (root->color == BLACK)
			color = 0;
		else
			color = 1;
		inserttime[frame]++;
		animationRecord_insert(counttime, inserttime[frame], x, y, root->key, -1, p_x, p_y, color);
		//insertIdCode[frametime[frame]] = 1;
	}
}


void RBTree::animationRecord_insert(int totaltime, int frame, int x, int y, int
	data1, int data2, int p_x, int p_y, int color) {
	animationInsert[totaltime][frame].x = x;
	animationInsert[totaltime][frame].y = y;
	animationInsert[totaltime][frame].data1 = data1;
	animationInsert[totaltime][frame].data2 = data2;
	animationInsert[totaltime][frame].p_x = p_x;
	animationInsert[totaltime][frame].p_y = p_y;
	animationInsert[totaltime][frame].color = color;
}

void RBTree::inOrderPrint_insertfixup(RBTNode* root, RBTNode* Nil, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (root == Nil)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root->left != Nil)
	{
		int color;
		if (root->left->color == BLACK)
			color = 0;
		else
			color = 1;
		fixuptime[frame]++;
		//insertIdCode[frametime[frame]] = 2;
		animationRecord_insertfixup(countfixup, fixuptime[frame], x, y, root->left->key, -1, p_x, p_y, color);
		//��������
		inOrderPrint_insertfixup(root->left, Nil, x - wideSize, y + highSize, wideSize, highSize, x, y, frame);
	}
	if (root->right != Nil)
	{
		int color;
		if (root->right->color == BLACK)
			color = 0;
		else
			color = 1;
		fixuptime[frame]++;
		//insertIdCode[frametime[frame]] = 3;
		animationRecord_insertfixup(countfixup, fixuptime[frame], x, y, root->right->key, -1, p_x, p_y, color);
		//�����Һ���
		inOrderPrint_insertfixup(root->right, Nil, x + wideSize, y + highSize, wideSize, highSize, x, y,
			frame);
	}
	if (root != Nil)
	{
		int color;
		if (root->color == BLACK)
			color = 0;
		else
			color = 1;
		fixuptime[frame]++;
		animationRecord_insertfixup(countfixup, fixuptime[frame], x, y, root->key, -1, p_x, p_y, color);
		//insertIdCode[frametime[frame]] = 1;
	}
}

void RBTree::animationRecord_insertfixup(int totaltime, int frame, int x, int y, int
	data1, int data2, int p_x, int p_y, int color) {
	animation1[totaltime][frame].x = x;
	animation1[totaltime][frame].y = y;
	animation1[totaltime][frame].data1 = data1;
	animation1[totaltime][frame].data2 = data2;
	animation1[totaltime][frame].p_x = p_x;
	animation1[totaltime][frame].p_y = p_y;
	animation1[totaltime][frame].color = color;
}

void RBTree::Remove_Fixup(RBTNode *x)
{
	while (x != root && x->color == BLACK) //�����x��Ϊ������������ɫ���Ǻ�ɫ
	{
		if (x == x->parent->left) //x��������
		{
			RBTNode *w = x->parent->right; //w��x���ֽ��

			if (w->color == RED) //���1
			{
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(x->parent);
				w = x->parent->right;
				str1[Dnumber] = "Case 1: Left Rotation at " + QString::number(x->parent->key);
				int depth = 0;
				depth = getHeight();
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75)
					highSize = 75;
				double wide = pow(2, depth) - 1;
				double wideSize = 9 * wide;
				countremove=Dnumber;
				removetime[countremove] = 0;
				inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
				Dnumber++;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) //���2
			{
				w->color = RED;
				x = x->parent;
				str1[Dnumber] = "Case 2: Recoloring " + QString::number(w->key);
				int depth = 0;
				depth = getHeight();
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75)
					highSize = 75;
					double wide = pow(2, depth) - 1;
					double wideSize = 9 * wide;
					countremove = Dnumber;
					removetime[countremove] = 0;
					inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
					Dnumber++;
			}
			else
			{
				if (w->right->color == BLACK) //���3
				{
					w->color = RED;
					w->left->color = BLACK;
					RightRotate(w);
					w = x->parent->right;
					str1[Dnumber] = "Case 3: Right Rotation at " + QString::number(w->key);
					int depth = 0;
					depth = getHeight();
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75)
						highSize = 75;
					double wide = pow(2, depth) - 1;
					double wideSize = 9 * wide;
					countremove = Dnumber;
					removetime[countremove] = 0;
					inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
					Dnumber++;
				}
				//���4
				w->color = w->parent->color;
				w->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotate(x->parent);
				x = root; //����ѭ��
				str1[Dnumber] = "Case 4: Left Rotation at " + QString::number(x->parent->key);
				int depth = 0;
				depth = getHeight();
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75)
					highSize = 75;
				double wide = pow(2, depth) - 1;
				double wideSize = 9 * wide;
				countremove = Dnumber;
				removetime[countremove] = 0;
				inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
				Dnumber++;
			}
		}
		else //x��������
		{
			RBTNode *w = x->parent->left;
			if (w->color == RED) //���1
			{
				w->parent->color = RED;
				w->color = BLACK;
				RightRotate(x->parent);
				w = x->parent->left;
				str1[Dnumber] = "Case 5: Right Rotation at " + QString::number(x->parent->key);
				int depth = 0;
				depth = getHeight();
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75)
					highSize = 75;
				double wide = pow(2, depth) - 1;
				double wideSize = 9 * wide;
				countremove = Dnumber;
				removetime[countremove] = 0;
				inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
				Dnumber++;
			}
			if (w->right->color == BLACK && w->right->color == BLACK) //���2
			{
				w->color = RED;
				x = x->parent;
				str1[Dnumber] = "Case 6: Recoloring " + QString::number(w->key);
				int depth = 0;
				depth = getHeight();
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75)
					highSize = 75;
				double wide = pow(2, depth) - 1;
				double wideSize = 9 * wide;
				countremove = Dnumber;
				removetime[countremove] = 0;
				inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
				Dnumber++;
			}
			else
			{
				if (w->left->color == BLACK) //���3
				{
					w->right->color = BLACK;
					w->color = RED;
					LeftRotate(w);
					w = x->parent->left;
					str1[Dnumber] = "Case 7: Left Rotation at " + QString::number(w->key);
					int depth = 0;
					depth = getHeight();
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75)
						highSize = 75;
					double wide = pow(2, depth) - 1;
					double wideSize = 9 * wide;
					countremove = Dnumber;
					removetime[countremove] = 0;
					inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
					Dnumber++;
				}
				//���4
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				RightRotate(x->parent);
				x = root; //����ѭ��
				str1[Dnumber] = "Case 8: Right Rotation at " + QString::number(x->key);
				int depth = 0;
				depth = getHeight();
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75)
					highSize = 75;
				double wide = pow(2, depth) - 1;
				double wideSize = 9 * wide;
				countremove = Dnumber;
				removetime[countremove] = 0;
				inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
				Dnumber++;
			}
		}
	}
	x->color = BLACK;
	str1[Dnumber] = "Change " +QString::number(x->key)+ " to black";
	int depth = 0;
	depth = getHeight();
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
		highSize = 75;
	double wide = pow(2, depth) - 1;
	double wideSize = 9 * wide;
	countremove = Dnumber;
	removetime[countremove] = 0;
	inOrderPrint_removefixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, countremove);
}

void RBTree::inOrderPrint_removefixup(RBTNode* root, RBTNode* Nil, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (root == Nil)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root->left != Nil)
	{
		int color;
		if (root->left->color == BLACK)
			color = 0;
		else
			color = 1;
		removetime[frame]++;
		//insertIdCode[frametime[frame]] = 2;
		animationRecord_removefixup(countremove, removetime[frame], x, y, root->left->key, -1, p_x, p_y, color);
		//��������
		inOrderPrint_removefixup(root->left, Nil, x - wideSize, y + highSize, wideSize, highSize, x, y, frame);
	}
	if (root->right != Nil)
	{
		int color;
		if (root->right->color == BLACK)
			color = 0;
		else
			color = 1;
		removetime[frame]++;
		//insertIdCode[frametime[frame]] = 3;
		animationRecord_removefixup(countremove, removetime[frame], x, y, root->right->key, -1, p_x, p_y, color);
		//�����Һ���
		inOrderPrint_removefixup(root->right, Nil, x + wideSize, y + highSize, wideSize, highSize, x, y,
			frame);
	}
	if (root != Nil)
	{
		int color;
		if (root->color == BLACK)
			color = 0;
		else
			color = 1;
		removetime[frame]++;
		animationRecord_removefixup(countremove, removetime[frame], x, y, root->key, -1, p_x, p_y, color);
		//insertIdCode[frametime[frame]] = 1;
	}
}

void RBTree::animationRecord_removefixup(int totaltime, int frame, int x, int y, int
	data1, int data2, int p_x, int p_y, int color) {
	animation2[totaltime][frame].x = x;
	animation2[totaltime][frame].y = y;
	animation2[totaltime][frame].data1 = data1;
	animation2[totaltime][frame].data2 = data2;
	animation2[totaltime][frame].p_x = p_x;
	animation2[totaltime][frame].p_y = p_y;
	animation2[totaltime][frame].color = color;
}

void RBTree::Remove(int key)
{
	RBTNode *t;
	if ((t = Search(root, key)) != Nil)
	{
		Remove(t);
	}
	else
	{
		return ;
	}
}