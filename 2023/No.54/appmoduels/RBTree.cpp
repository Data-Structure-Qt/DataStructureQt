#include "BinaryTreeUI.h"


void RBTree::Insert_Fixup(RBTNode *s)
{
	RBTNode *uncle;           //叔结点（父结点的兄弟结点）
	while (s->parent->color == RED) //父节点的颜色也为红色
	{
		//str[number]="Adjusting node "+QString::number(s->key);
		if (s->parent == s->parent->parent->left) //父节点是左结点
		{
			uncle = s->parent->parent->right;

			if (uncle->color == RED) //叔结点为红色
			{
				//父节点和叔结点都变为黑色
				s->parent->color = BLACK;
				uncle->color = BLACK;
				//祖父结点变为红色
				s->parent->parent->color = RED;
				//将s指针指向祖父结点，下一次循环继续判断祖父的父节点是否为红色
				s = s->parent->parent;
				int depth = 0;
				depth = getHeight();
				//求树的每层标准高度
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75) {
					highSize = 75;
				}
				//求树的最后一层间隔数量
				double wide = pow(2, depth) - 1;
				//求树的最后一层间隔宽度
				double wideSize = 9 * wide;
				fixuptime[number] = 0;
				countfixup = number;
				inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
				str[number] = "Case 1: Recoloring " + QString::number(s->key) + " and "
					+ QString::number(uncle->key);
				number++;
			}
			else //没有叔结点，或叔结点为黑色(经过多次循环转换，叔结点可能为黑)
			{
				if (s == s->parent->right) //如果调整的结点在右结点
				{
					s = s->parent; //先将s指向s的父结点
					LeftRotate(s); //再左转
					int depth = 0;
					depth = getHeight();
					//求树的每层标准高度
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75) {
						highSize = 75;
					}
					//求树的最后一层间隔数量
					double wide = pow(2, depth) - 1;
					//求树的最后一层间隔宽度
					double wideSize = 9 * wide;
					fixuptime[number] = 0;
					countfixup = number;
					inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
					str[number] = "Case 2: Left Rotation at " + QString::number(s->key);
					number++;
				}
				s->parent->color = BLACK;
				//如果调整的结点在左结点,将s的父节点变为黑色，将祖父的结点变为红色，将s的祖父结点右转
				s->parent->color = BLACK;
				s->parent->parent->color = RED;
				RightRotate(s->parent->parent);
				int depth = 0;
				depth = getHeight();
				//求树的每层标准高度
				double highSize = 2400 * 0.618 / (double)depth;
				if (highSize > 75) {
					highSize = 75;
				}
				//求树的最后一层间隔数量
				double wide = pow(2, depth) - 1;
				//求树的最后一层间隔宽度
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
			if (s->parent == s->parent->parent->right) //父节点是右结点
			{
				uncle = s->parent->parent->left;
				if (uncle->color == RED) //叔结点为红色
				{
					//父节点和叔结点都变为黑色
					s->parent->color = BLACK;
					uncle->color = BLACK;
					//祖父结点变为红色
					s->parent->parent->color = RED;
					//将s指针指向祖父结点，下一次循环继续判断祖父的父节点是否为红色
					s = s->parent->parent;
					int depth = 0;
					depth = getHeight();
					//求树的每层标准高度
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75) {
						highSize = 75;
					}
					//求树的最后一层间隔数量
					double wide = pow(2, depth) - 1;
					//求树的最后一层间隔宽度
					double wideSize = 9 * wide;
					fixuptime[number] = 0;
					countfixup = number;
					inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
					str[number] = "Case 4: Recoloring " + QString::number(s->key) + " and "
						+ QString::number(uncle->key);
					number++;
				}
				else //没有叔结点，或叔结点为黑色(经过多次循环转换，叔结点可能为黑)
				{
					if (s == s->parent->left) //如果调整的结点在左结点
					{
						s = s->parent;  //先将s指向s的父结点
						RightRotate(s); //再右转
						int depth = 0;
						depth = getHeight();
						//求树的每层标准高度
						double highSize = 2400 * 0.618 / (double)depth;
						if (highSize > 75) {
							highSize = 75;
						}
						//求树的最后一层间隔数量
						double wide = pow(2, depth) - 1;
						//求树的最后一层间隔宽度
						double wideSize = 9 * wide;
						fixuptime[number] = 0;
						countfixup = number;
						inOrderPrint_insertfixup(root, Nil, 0, 0, wideSize, highSize, 0, 0, number);
						str[number] = "Case 5: Right Rotation at " + QString::number(s->key);
						number++;
					}
					//如果调整的结点在右结点,将s的父节点变为黑色，将祖父的结点变为红色，将s的祖父结点右转
					s->parent->color = BLACK;
					s->parent->parent->color = RED;
					LeftRotate(s->parent->parent);
					int depth = 0;
					depth = getHeight();
					//求树的每层标准高度
					double highSize = 2400 * 0.618 / (double)depth;
					if (highSize > 75) {
						highSize = 75;
					}
					//求树的最后一层间隔数量
					double wide = pow(2, depth) - 1;
					//求树的最后一层间隔宽度
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
	root->color = BLACK; //最后始终将根节点置为黑色
	int depth = 0;
	depth = getHeight();
	//求树的每层标准高度
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//求树的最后一层间隔数量
	double wide = pow(2, depth) - 1;
	//求树的最后一层间隔宽度
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
	RBTNode *pr = Nil; //pr用来记住父节点
	RBTNode *s = root; //定义变量s指向根
	while (s != Nil)
	{
		if (value == s->key)
		{
			return false;
		}
		pr = s; //每次记住s的父节点
		if (value < s->key)
		{
			s = s->left;
		}
		else
		{
			s = s->right;
		}
	}
	//循环后s==Nil
	s = BuyNode(value); //申请结点
	if (pr == Nil)      //如果父节点pr是根节点，第一次root指向Nil，所以pr==Nil
	{
		root = s;
		root->parent = pr;
	}
	else //如果父节点不是根节点
	{
		if (value < pr->key)
		{
			pr->left = s;
		}
		else
		{
			pr->right = s;
		}
		s->parent = pr; //设置新结点s的父节点
	}
	int depth = 0;
	depth = getHeight();
	//求树的每层标准高度
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//求树的最后一层间隔数量
	double wide = pow(2, depth) - 1;
	//求树的最后一层间隔宽度
	double wideSize = 9 * wide;
	inserttime[i] = 0;
    counttime = i;
	history_wide[i] = wideSize;
	history_high[i] = highSize;
	inOrderPrint_insert(root, Nil, 0, 0, wideSize, highSize, 0, 0, i);
	//调整平衡
	Insert_Fixup(s);
	return true;
}

void RBTree::inOrderPrint_insert(RBTNode* root, RBTNode* Nil, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (root == Nil)
		return;
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
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
		//访问左孩子
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
		//访问右孩子
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
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
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
		//访问左孩子
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
		//访问右孩子
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
	while (x != root && x->color == BLACK) //当结点x不为根并且它的颜色不是黑色
	{
		if (x == x->parent->left) //x在左子树
		{
			RBTNode *w = x->parent->right; //w是x的兄结点

			if (w->color == RED) //情况1
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
			if (w->left->color == BLACK && w->right->color == BLACK) //情况2
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
				if (w->right->color == BLACK) //情况3
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
				//情况4
				w->color = w->parent->color;
				w->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotate(x->parent);
				x = root; //结束循环
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
		else //x在右子树
		{
			RBTNode *w = x->parent->left;
			if (w->color == RED) //情况1
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
			if (w->right->color == BLACK && w->right->color == BLACK) //情况2
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
				if (w->left->color == BLACK) //情况3
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
				//情况4
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				RightRotate(x->parent);
				x = root; //结束循环
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
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
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
		//访问左孩子
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
		//访问右孩子
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