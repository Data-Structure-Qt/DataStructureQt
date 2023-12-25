#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct MyExpressionRPNNode {
	std::string data;
	MyExpressionRPNNode* left;
	MyExpressionRPNNode* right;
};

class MyExpressionRPNTree {
public:
	// 递归函数计算最大深度
	static int maxDepth(MyExpressionRPNNode* root) {
		if (root == nullptr) {
			return 0;
		}
		else {
			int left_depth = maxDepth(root->left);
			int right_depth = maxDepth(root->right);
			return max(left_depth, right_depth) + 1;
		}
	}

	static MyExpressionRPNNode* createNode(const std::string& data) {
		MyExpressionRPNNode* node = new MyExpressionRPNNode{ data, nullptr, nullptr };
		return node;
	}

	static  int getPrecedence(char op) {
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		return 0;
	}

	static bool isOperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/';
	}

	static std::vector<std::string> infixToPostfix(const std::string& infix) {
		std::stack<char> operators;
		std::vector<std::string> postfix;
		for (size_t i = 0; i < infix.length(); ++i) {
			char token = infix[i];
			if (isdigit(token)) {
				std::string number;
				while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
					number += infix[i++];
				}
				--i;
				postfix.push_back(number);
			}
			else if (token == '(') {
				operators.push(token);
			}
			else if (token == ')') {
				while (!operators.empty() && operators.top() != '(') {
					postfix.push_back(std::string(1, operators.top()));
					operators.pop();
				}
				operators.pop(); // Pop '(' from the stack
			}
			else if (isOperator(token)) {
				while (!operators.empty() && getPrecedence(token) <= getPrecedence(operators.top())) {
					postfix.push_back(std::string(1, operators.top()));
					operators.pop();
				}
				operators.push(token);
			}
		}
		while (!operators.empty()) {
			postfix.push_back(std::string(1, operators.top()));
			operators.pop();
		}
		return postfix;
	}

	static MyExpressionRPNNode* constructTreeFromPostfix(const std::vector<std::string>& postfix) {
		std::stack<MyExpressionRPNNode*> st;
		for (const std::string& token : postfix) {
			if (isOperator(token[0]) && token.length() == 1) {
				MyExpressionRPNNode* t = createNode(token);
				t->right = st.top(); st.pop();
				t->left = st.top(); st.pop();
				st.push(t);
			}
			else {
				st.push(createNode(token));
			}
		}
		return st.top();
	}

	static MyExpressionRPNNode* constructTree(const std::string& expression) {
		std::vector<std::string> postfix = infixToPostfix(expression);
		return constructTreeFromPostfix(postfix);
	}

	// Utility function for deleting the tree to prevent memory leaks
	static void deleteTree(MyExpressionRPNNode* node) {
		if (node) {
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	}

	static int evaluateTree(MyExpressionRPNNode* root, std::string& ret) {
		if (!root)
			return 0;
		if (!root->left && !root->right)
		{
			ret += root->data;

			return stoi(root->data);
		}

		int leftVal = evaluateTree(root->left, ret);
		int rightVal = evaluateTree(root->right, ret);
		ret += root->data;
		if (root->data == "+")
			return leftVal + rightVal;
		if (root->data == "-")
			return leftVal - rightVal;
		if (root->data == "*")
			return leftVal * rightVal;
		if (root->data == "/")
			return leftVal / rightVal;

		return 0;
	}
};




#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPen>
#include <QFont>
// 自定义图形项类，用于表示树的节点
class TreeItem : public QGraphicsItem {
public:
	TreeItem(const QString& data) : data(data) {}

	QRectF boundingRect() const override {
		return QRectF(-25, -25, 50, 50); // 定义节点所占的矩形区域
	}

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
		QBrush brush("#2a9cfd");
		QPen pen(Qt::black);
		QFont font;

		painter->setBrush(brush);
		painter->setPen(pen);
		painter->drawEllipse(-25, -25, 50, 50); // 绘制蓝色圆圈

		font.setPointSize(12);
		painter->setFont(font);
		painter->setPen(Qt::white);
		painter->drawText(QRectF(-25, -25, 50, 50), Qt::AlignCenter, data); // 绘制白色字体
	}

	void setParentItem(TreeItem* parent) {
		parentItem = parent;
	}

	void addChildItem(TreeItem* child) {
		childItems.push_back(child);
	}

	void connectChildItems(QGraphicsScene* scene) {
		for (TreeItem* child : childItems) {
			QPainterPath path;
			path.moveTo(mapToScene(0, 0));
			path.lineTo(child->mapToScene(0, 0));

			QGraphicsPathItem* line = new QGraphicsPathItem(path);
			line->setZValue(-1);
			scene->addItem(line);
			child->connectChildItems(scene);
		}
	}

private:
	QString data;
	TreeItem* parentItem = nullptr;
	QVector<TreeItem*> childItems;
};

// 递归遍历树的节点，并将每个节点转换为图形项类实例
TreeItem* addTreeItems(MyExpressionRPNNode* root, QGraphicsScene* scene, qreal x, qreal y, int maxDepth) {
	if (!root) {
		return nullptr;
	}

	qreal dx = 10; // 调整节点之间的水平间距
	qreal dy = 100; // 调整节点之间的垂直间距

	TreeItem* item = new TreeItem(QString::fromStdString(root->data));
	item->setPos(x, y);
	scene->addItem(item);
	int wide = pow(2, maxDepth) - 1;

	TreeItem* leftChildItem = addTreeItems(root->left, scene, x - dx* wide, y + dy, maxDepth-1);
	TreeItem* rightChildItem = addTreeItems(root->right, scene, x + dx * wide, y + dy, maxDepth-1);

	if (leftChildItem) {
		item->addChildItem(leftChildItem);
		leftChildItem->setParentItem(item);
	}

	if (rightChildItem) {
		item->addChildItem(rightChildItem);
		rightChildItem->setParentItem(item);
	}

	return item;
}
