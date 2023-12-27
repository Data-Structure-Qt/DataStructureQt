#include "mainwindow.h"
#include "StackUI.h"


/*
			上N
		左W  x   东E
			下S
*/

Status MainWindow::creat(linkstack* S) {//创建一个空栈
	S->top = S->bottom = (snode*)malloc(sizeof(snode));
	if (!S->top) {
		ui->label_3->setText("申请空间失败!");
		return ERROR;
	}
	S->top->next = NULL;
	S->bottom->next = NULL;
	S->length = 0;
	return OK;
}
bool MainWindow::empty(linkstack S) {//判断栈是否为空
	return !S.length;
}
int MainWindow::size(linkstack S) {//返回栈的大小
	return S.length;
}
Status MainWindow::push(linkstack* S, node pos) {//元素入栈
	snode* newx = (snode*)malloc(sizeof(snode));//新结点
	if (!newx) {//创建失败
		ui->label_3->setText("申请空间失败！");
		return ERROR;
	}
	newx->pos = pos;//新结点的pos赋值
	newx->next = S->top->next;//入栈
	S->top->next = newx;
	if (!S->length)//length = 0
		S->bottom = S->bottom->next;
	S->length++;
	return OK;
}
Status MainWindow::pop(linkstack* S) {//弹出栈顶元素
	if (!S->length) {
		ui->label_3->setText("当前栈已经为空！");
		return ERROR;
	}
	snode* del = S->top->next;
	S->top->next = del->next;
	free(del);
	S->length--;
	return OK;
}
Status MainWindow::gettop(linkstack S, node& pos) {//获得栈顶元素 存到pos中
	if (!S.length) {
		ui->label_3->setText("当前栈已经为空！");
		return ERROR;
	}
	pos = S.top->next->pos;
	return OK;
}
Status MainWindow::showPath(linkstack S) {//输出当前栈的内容
	qDebug() << "showPath开始执行";
	if (!S.length) {
		ui->label_3->setText("空！");
		return ERROR;
	}
	snode* p = S.top->next;
	QString str = "栈：";
	while (p) {
		QString s1 = QString::number(p->pos.x);
		QString s2 = QString::number(p->pos.y);
		QString s3;
		if (p->next && s1 == QString::number(p->next->pos.x) && s2 < QString::number(p->next->pos.y))//比如<1,1,E>→<1,2,x>
			s3 = QString("E");
		if (p->next && s1 == QString::number(p->next->pos.x) && s2 > QString::number(p->next->pos.y))//比如<2,2,W>→<2,1,x>
			s3 = QString("W");
		if (p->next && s2 == QString::number(p->next->pos.y) && s1 < QString::number(p->next->pos.x))//比如<1,1,S>→<2,1,x>
			s3 = QString("S");
		if (p->next && s2 == QString::number(p->next->pos.x) && s1 > QString::number(p->next->pos.y))//比如<2,1,N>→<1,1,x>
			s3 = QString("N");

		if (!(p->next))
		{
			str += "<" + s1 + "," + s2 + ">";
		}
		else
		{
			str += "<" + s1 + "," + s2 + "," + s3 + ">";
		}
		path[pathCount] = QPointF(input[(p->pos.x - 1) * col + p->pos.y - 1]->pos().x() + 20, input[(p->pos.x - 1) * col + p->pos.y - 1]->pos().y() + 20);

		p = p->next;
		pathCount++;
		if (pathCount == 9)
			str += '\n';
		qDebug() << str;
	}
	ui->label_3->setText(str);
	qDebug() << "showPath执行完毕";
	return OK;

}
Status MainWindow::destroyStack(linkstack* S) {//销毁当前栈
	snode* del;
	while (S->top) {
		del = S->top;
		S->top = S->top->next;
		free(del);
	}
	S->top = S->bottom = NULL;
	return OK;
}
void MainWindow::readInput()//读取用户在lineedit里输入的数据
{
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			maze[i][j] = 1;
		}
	}
	for (int i = 0, m = 1; i < row; i++, m++)//显示lineedit
	{
		for (int j = 0, n = 1; j < col; j++, k++, n++) {
			if (j < col / 2)
				maze[m][n] = input[k]->text().toInt();
			else
				maze[m][n] = input[k]->text().toInt();
		}
	}
	for (int i = 0; i < col*row; i++) {
		qDebug() << input[i]->text();
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			qDebug() << "maze[i][j]" << i << j << maze[i][j];
		}
	}
	qDebug() << "readInput执行完毕";
}
bool MainWindow::GenerateMaze(int irow, int icol, QString text)
{
	int k = 0;
	qDebug() << "GenerateMaze开始执行";
	QFont font("黑体", 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
	row = irow;//迷宫高度是行数
	col = icol;//迷宫宽度是列数
	QRegExp regx("[0-1]+$");//lineedit只允许设置0或1
	for (int i = 0; i < row*col; i++)//生成row*col个lineedit
	{
		input[i] = new QLineEdit(QString::asprintf("0"), this);//最后一个参数一定为一个“父窗体”！
		input[i]->setMaxLength(1);
		input[i]->setAlignment(Qt::AlignHCenter);//内容居中显示
		input[i]->setFont(font);//字体设置
		if (i == 0)
			input[i]->setStyleSheet("background-color:green");
		if (i == row * col - 1)
			input[i]->setStyleSheet("background-color:red");
		QValidator *validator = new QRegExpValidator(regx, input[i]);
		input[i]->setValidator(validator);
		input[i]->hide();
		input[i]->show();
	}
	if (text != nullptr)
	{
		for (int i = 0; i < row*col; i++) {
			QString temp(text[i]);
			input[k++]->setText(temp);
		}
	}
	if (col % 2)//col是奇数
	{
		int k = 0;
		int x = 600 - 20 - col / 2 * 80;//控件初始位置，1200/2 = 600，20是靠近中轴线的lineedit与中轴线的距离，两个lineedit距离为40，中轴线左边有col/2个lineedit和空挡。
		int y = 40;//第一行lineedit和窗口顶部的距离
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				input[k++]->setGeometry(x + j * 80, y + i * 80, 40, 40);
			}
		}
	}
	else//col是偶数
	{
		int k = 0;
		int x = 600 - 20 - col / 2 * 40 - (col / 2 - 1) * 40;
		int y = 40;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				input[k++]->setGeometry(x + j * 80, y + i * 80, 40, 40);
			}
		}
	}
	for (int i = 0; i < row*col; i++) {
		points[i] = QPointF(input[i]->pos().x(), input[i]->pos().y());
	}
	ui->pushButton->setEnabled(false);//一旦生成迷宫之后就不能再点击了，主要原因是input数组已经生成了，如果再点击，那么新生成的input也会出现在屏幕上，原先的linneedit不会消失
	qDebug() << "GenerateMaze执行完毕";
	return OK;
}

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->pushButton_2->setEnabled(false);
	ui->pushButton_4->setEnabled(false);

}
MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_clicked()//生成迷宫按钮按下时
{
	GenerateMaze(ui->spinBox_2->value(), ui->spinBox->value(), nullptr);//出现迷宫
	for (int i = 0; i < row*col; i++)
		input[i]->show();
	ui->pushButton_2->setEnabled(true);
}
void MainWindow::on_pushButton_2_clicked()//运行按钮按下时
{
	readInput();
	useStack();
	//    PathType paths;
	//    paths.length = 0;	//初始化路径长度
	//    useRecursion(1, 1, row, col, paths, maze);
	//    ui->label_4->setText(str);
	//    if (b == 0)
	//        ui->label_4->setText("空！");
}
void MainWindow::on_pushButton_3_clicked()//导入txt文件
{
	int irow = 0, icol = 0;
	QString text;
	QStringList infoList;
	//获取文件名
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("导入文件"),
		"",
		tr("text(*.txt)"));
	if (fileName.isEmpty())
	{
		QMessageBox::warning(this, "错误", "打开文件失败！");
	}
	else
	{
		QFile file(fileName);
		//打开文件
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			qDebug() << "无法打开!" << endl;
		}
		//循环读取txt  并打印
		while (!file.atEnd())
		{
			QByteArray line = file.readLine();
			QString str(line);
			if (str.contains("\n"))
			{
				str = str.replace("\n", "");
			}
			qDebug() << str;

			icol = str.length() - 2;
			irow++;
			text += str.mid(1, icol);
		}

		irow -= 2;
		qDebug() << text;
		text = text.mid(icol, icol*irow);
		qDebug() << irow;
		qDebug() << icol;
		qDebug() << text;
		ui->pushButton_4->setEnabled(true);
	}
	GenerateMaze(irow, icol, text);

}
void MainWindow::on_pushButton_4_clicked()//导入txt文件后运行
{
	isCall = true;
	readInput();
	int sx = 1, sy = 1, ex = row, ey = col;//sx，sy是startx，starty即迷宫起始位置，对应的是迷宫的下标，ex，ey是endx，endy是endx，endy即迷宫终点位置。
	node now;//当前位置
	now.x = sx;
	now.y = sy;
	now.orientation = 'E';
	maze[sx][sy] = -1;//走过了

	linkstack s;
	creat(&s); 
		push(&s, now);//将now的信息亚展
	while (!empty(s)) {
		gettop(s, now);//获得栈顶元素 存到now中
		if (now.x == ex && now.y == ey)//now的x和y位置到达迷宫终点
			break;//终点

		if (!maze[now.x][now.y + 1]) {//右 为0表示可以走
			now.orientation = 'E';
			node next = now;
			next.y = now.y + 1;//向右走一步
			maze[next.x][next.y] = -1;//走过了置-1
			push(&s, next);
			continue;
		}
		//以下同理
		if (!maze[now.x + 1][now.y]) {//下
			now.orientation = 'S';
			node next = now;
			next.x = now.x + 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x][now.y - 1]) {//左
			now.orientation = 'W';
			node next = now;
			next.y = now.y - 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x - 1][now.y]) {//上
			now.orientation = 'N';
			node next = now;
			next.x = now.x - 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		pop(&s);
	}
	linkstack path;
	creat(&path);
	node step;
	while (!empty(s)) {
		gettop(s, step);
		push(&path, step);
		pop(&s);
	}//换成正向
	showPath(path);
	paintPath();
	qDebug() << "执行完毕";
	destroyStack(&s);
	destroyStack(&path);
}
void MainWindow::paintPath()//绘制路径函数
{
	timer = new QTimer(this);
	currentPoint = path[0];
	nextPoint = path[1];
	timer->start(50);
	qDebug() << "path0" << path[0];
	qDebug() << "path1" << path[1];
	qDebug() << "path2" << path[2];
	qDebug() << "path3" << path[3];
	qDebug() << "path4" << path[4];
	qDebug() << "path5" << path[5];
	qDebug() << "path6" << path[6];
	qDebug() << "path[][]" << path[pathCount - 1];
	connect(timer, &QTimer::timeout, this, [=]() {
		static int i = 0;
		static int j = 0;
		static int k = 2;
		double x = path[0].x() + 10 * i;
		qDebug() << "x" << x;
		qDebug() << "i" << i;
		double y = path[0].y() + 10 * j;
		qDebug() << "y" << y;
		qDebug() << "j" << j;
		update();
		if (x == nextPoint.x())
		{
			point.setX(x);
			point.setY(y);
			if (y <= nextPoint.y()) {
				++j;
			}
			else
				--j;
			if (y == nextPoint.y())
			{

				// --j;
				currentPoint = QPointF(nextPoint.x(), nextPoint.y());
				qDebug() << "currentPoint" << currentPoint;
				nextPoint = path[k++];
				qDebug() << "nextPoint" << nextPoint;
				qDebug() << "到达一个点了";
				pointCount++;
				if (x > nextPoint.x())
				{
					--j;
				}
				if (x < nextPoint.x())
				{
					--i;
					--j;
				}
				if (y < nextPoint.y()) {}
				if (nextPoint == QPointF(0, 0)) {
					input[row*col - 1]->setStyleSheet("background-color:green");
					qDebug() << "已经到达终点";
					timer->stop();
				}
			}

		}
		if (y == nextPoint.y())
		{
			point.setX(x);
			point.setY(y);
			if (x <= nextPoint.x())
				++i;
			else
				--i;
			if (x == nextPoint.x())
			{
				currentPoint = QPointF(nextPoint.x(), nextPoint.y());
				qDebug() << "currentPoint" << currentPoint;
				nextPoint = path[k++];
				qDebug() << "nextPoint" << nextPoint;
				qDebug() << "到达一个点了";
				pointCount++;
				if (x < nextPoint.x()) {}
				if (y > nextPoint.y())
					--i;
				if (y < nextPoint.y())
				{
					--i;
					--j;
				}
				if (nextPoint == QPointF(0, 0)) {
					input[row*col - 1]->setStyleSheet("background-color:green");
					qDebug() << "已经到达终点";
					timer->stop();
				}
			}
		}
		qDebug() << x << "," << y;
	});

}

void MainWindow::useStack()
{
	isCall = true;
	int sx = 1, sy = 1, ex = row, ey = col;//sx，sy是startx，starty即迷宫起始位置，对应的是迷宫的下标，ex，ey是endx，endy是endx，endy即迷宫终点位置。
	node now;//当前位置
	now.x = sx;
	now.y = sy;
	now.orientation = 'E';
	maze[sx][sy] = -1;//走过了

	linkstack s;
	creat(&s); 
		push(&s, now);//将now的信息入栈
	while (!empty(s)) {
		gettop(s, now);//获得栈顶元素 存到now中
		if (now.x == ex && now.y == ey)//now的x和y位置到达迷宫终点
			break;//终点

		if (!maze[now.x][now.y + 1]) {//右 为0表示可以走
			now.orientation = 'E';
			node next = now;
			next.y = now.y + 1;//向右走一步
			maze[next.x][next.y] = -1;//走过了置-1
			push(&s, next);
			continue;
		}
		//以下同理
		if (!maze[now.x + 1][now.y]) {//下
			now.orientation = 'S';
			node next = now;
			next.x = now.x + 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x][now.y - 1]) {//左
			now.orientation = 'W';
			node next = now;
			next.y = now.y - 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x - 1][now.y]) {//上
			now.orientation = 'N';
			node next = now;
			next.x = now.x - 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		pop(&s);
	}
	linkstack path;
	creat(&path);
	node step;
	while (!empty(s)) {
		gettop(s, step);
		push(&path, step);
		pop(&s);
	}//换成正向
	showPath(path);
	paintPath();
	qDebug() << "执行完毕";
	destroyStack(&s);
	destroyStack(&path);
}

void MainWindow::useRecursion(int xis, int yis, int xes, int yes, PathType paths, int maze[8][8])
{
	int k, i, j;
	str = "迷宫第" + QString::number(num) + "条路径如下：";
	if (xis == xes && yis == yes)		//找到出口,输出路径
	{
		paths.data[paths.length].rx = xis;
		paths.data[paths.length].cy = yis;
		paths.length++; num++;
		if (paths.length < minpath)
		{
			minpath = paths.length;
			b = num;
		}
		for (k = 0; k < paths.length; k++)
			str += "(" + QString::number(paths.data[k].rx) + "," + QString::number(paths.data[k].cy) + ")" + " ";
	}
	else					//(xis,yis)不是出口
	{
		if (maze[xis][yis] == 0)//(xis,yis)可走
		{
			for (int m = 0; m < 4; m++)		// 找(xis, yis)的一个相邻位置(i, j)
			{
				i = xis + mov[m].x; j = yis + mov[m].y;
				paths.data[paths.length].rx = xis;
				paths.data[paths.length].cy = yis;
				paths.length++;
				maze[xis][yis] = -1;			//避免重复找路径
				useRecursion(i, j, xes, yes, paths, maze);
				paths.length--;			//回退一个位置
				maze[xis][yis] = 0;			//恢复(xis,yis)为可走
			}
		}
	}
}
void MainWindow::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing, true);
	p.setPen(QPen(Qt::green, 3));
	if (isCall)
	{
		p.drawPolyline(path, pointCount);
		p.drawLine(currentPoint, point);
	}
	else {}
}

