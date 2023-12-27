#include "mainwindow.h"
#include "StackUI.h"


/*
			��N
		��W  x   ��E
			��S
*/

Status MainWindow::creat(linkstack* S) {//����һ����ջ
	S->top = S->bottom = (snode*)malloc(sizeof(snode));
	if (!S->top) {
		ui->label_3->setText("����ռ�ʧ��!");
		return ERROR;
	}
	S->top->next = NULL;
	S->bottom->next = NULL;
	S->length = 0;
	return OK;
}
bool MainWindow::empty(linkstack S) {//�ж�ջ�Ƿ�Ϊ��
	return !S.length;
}
int MainWindow::size(linkstack S) {//����ջ�Ĵ�С
	return S.length;
}
Status MainWindow::push(linkstack* S, node pos) {//Ԫ����ջ
	snode* newx = (snode*)malloc(sizeof(snode));//�½��
	if (!newx) {//����ʧ��
		ui->label_3->setText("����ռ�ʧ�ܣ�");
		return ERROR;
	}
	newx->pos = pos;//�½���pos��ֵ
	newx->next = S->top->next;//��ջ
	S->top->next = newx;
	if (!S->length)//length = 0
		S->bottom = S->bottom->next;
	S->length++;
	return OK;
}
Status MainWindow::pop(linkstack* S) {//����ջ��Ԫ��
	if (!S->length) {
		ui->label_3->setText("��ǰջ�Ѿ�Ϊ�գ�");
		return ERROR;
	}
	snode* del = S->top->next;
	S->top->next = del->next;
	free(del);
	S->length--;
	return OK;
}
Status MainWindow::gettop(linkstack S, node& pos) {//���ջ��Ԫ�� �浽pos��
	if (!S.length) {
		ui->label_3->setText("��ǰջ�Ѿ�Ϊ�գ�");
		return ERROR;
	}
	pos = S.top->next->pos;
	return OK;
}
Status MainWindow::showPath(linkstack S) {//�����ǰջ������
	qDebug() << "showPath��ʼִ��";
	if (!S.length) {
		ui->label_3->setText("�գ�");
		return ERROR;
	}
	snode* p = S.top->next;
	QString str = "ջ��";
	while (p) {
		QString s1 = QString::number(p->pos.x);
		QString s2 = QString::number(p->pos.y);
		QString s3;
		if (p->next && s1 == QString::number(p->next->pos.x) && s2 < QString::number(p->next->pos.y))//����<1,1,E>��<1,2,x>
			s3 = QString("E");
		if (p->next && s1 == QString::number(p->next->pos.x) && s2 > QString::number(p->next->pos.y))//����<2,2,W>��<2,1,x>
			s3 = QString("W");
		if (p->next && s2 == QString::number(p->next->pos.y) && s1 < QString::number(p->next->pos.x))//����<1,1,S>��<2,1,x>
			s3 = QString("S");
		if (p->next && s2 == QString::number(p->next->pos.x) && s1 > QString::number(p->next->pos.y))//����<2,1,N>��<1,1,x>
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
	qDebug() << "showPathִ�����";
	return OK;

}
Status MainWindow::destroyStack(linkstack* S) {//���ٵ�ǰջ
	snode* del;
	while (S->top) {
		del = S->top;
		S->top = S->top->next;
		free(del);
	}
	S->top = S->bottom = NULL;
	return OK;
}
void MainWindow::readInput()//��ȡ�û���lineedit�����������
{
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			maze[i][j] = 1;
		}
	}
	for (int i = 0, m = 1; i < row; i++, m++)//��ʾlineedit
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
	qDebug() << "readInputִ�����";
}
bool MainWindow::GenerateMaze(int irow, int icol, QString text)
{
	int k = 0;
	qDebug() << "GenerateMaze��ʼִ��";
	QFont font("����", 20, 75); //��һ�����������壨΢���źڣ����ڶ����Ǵ�С���������ǼӴ֣�Ȩ����75��
	row = irow;//�Թ��߶�������
	col = icol;//�Թ����������
	QRegExp regx("[0-1]+$");//lineeditֻ��������0��1
	for (int i = 0; i < row*col; i++)//����row*col��lineedit
	{
		input[i] = new QLineEdit(QString::asprintf("0"), this);//���һ������һ��Ϊһ���������塱��
		input[i]->setMaxLength(1);
		input[i]->setAlignment(Qt::AlignHCenter);//���ݾ�����ʾ
		input[i]->setFont(font);//��������
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
	if (col % 2)//col������
	{
		int k = 0;
		int x = 600 - 20 - col / 2 * 80;//�ؼ���ʼλ�ã�1200/2 = 600��20�ǿ��������ߵ�lineedit�������ߵľ��룬����lineedit����Ϊ40�������������col/2��lineedit�Ϳյ���
		int y = 40;//��һ��lineedit�ʹ��ڶ����ľ���
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				input[k++]->setGeometry(x + j * 80, y + i * 80, 40, 40);
			}
		}
	}
	else//col��ż��
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
	ui->pushButton->setEnabled(false);//һ�������Թ�֮��Ͳ����ٵ���ˣ���Ҫԭ����input�����Ѿ������ˣ�����ٵ������ô�����ɵ�inputҲ���������Ļ�ϣ�ԭ�ȵ�linneedit������ʧ
	qDebug() << "GenerateMazeִ�����";
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


void MainWindow::on_pushButton_clicked()//�����Թ���ť����ʱ
{
	GenerateMaze(ui->spinBox_2->value(), ui->spinBox->value(), nullptr);//�����Թ�
	for (int i = 0; i < row*col; i++)
		input[i]->show();
	ui->pushButton_2->setEnabled(true);
}
void MainWindow::on_pushButton_2_clicked()//���а�ť����ʱ
{
	readInput();
	useStack();
	//    PathType paths;
	//    paths.length = 0;	//��ʼ��·������
	//    useRecursion(1, 1, row, col, paths, maze);
	//    ui->label_4->setText(str);
	//    if (b == 0)
	//        ui->label_4->setText("�գ�");
}
void MainWindow::on_pushButton_3_clicked()//����txt�ļ�
{
	int irow = 0, icol = 0;
	QString text;
	QStringList infoList;
	//��ȡ�ļ���
	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("�����ļ�"),
		"",
		tr("text(*.txt)"));
	if (fileName.isEmpty())
	{
		QMessageBox::warning(this, "����", "���ļ�ʧ�ܣ�");
	}
	else
	{
		QFile file(fileName);
		//���ļ�
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			qDebug() << "�޷���!" << endl;
		}
		//ѭ����ȡtxt  ����ӡ
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
void MainWindow::on_pushButton_4_clicked()//����txt�ļ�������
{
	isCall = true;
	readInput();
	int sx = 1, sy = 1, ex = row, ey = col;//sx��sy��startx��starty���Թ���ʼλ�ã���Ӧ�����Թ����±꣬ex��ey��endx��endy��endx��endy���Թ��յ�λ�á�
	node now;//��ǰλ��
	now.x = sx;
	now.y = sy;
	now.orientation = 'E';
	maze[sx][sy] = -1;//�߹���

	linkstack s;
	creat(&s); 
		push(&s, now);//��now����Ϣ��չ
	while (!empty(s)) {
		gettop(s, now);//���ջ��Ԫ�� �浽now��
		if (now.x == ex && now.y == ey)//now��x��yλ�õ����Թ��յ�
			break;//�յ�

		if (!maze[now.x][now.y + 1]) {//�� Ϊ0��ʾ������
			now.orientation = 'E';
			node next = now;
			next.y = now.y + 1;//������һ��
			maze[next.x][next.y] = -1;//�߹�����-1
			push(&s, next);
			continue;
		}
		//����ͬ��
		if (!maze[now.x + 1][now.y]) {//��
			now.orientation = 'S';
			node next = now;
			next.x = now.x + 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x][now.y - 1]) {//��
			now.orientation = 'W';
			node next = now;
			next.y = now.y - 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x - 1][now.y]) {//��
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
	}//��������
	showPath(path);
	paintPath();
	qDebug() << "ִ�����";
	destroyStack(&s);
	destroyStack(&path);
}
void MainWindow::paintPath()//����·������
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
				qDebug() << "����һ������";
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
					qDebug() << "�Ѿ������յ�";
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
				qDebug() << "����һ������";
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
					qDebug() << "�Ѿ������յ�";
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
	int sx = 1, sy = 1, ex = row, ey = col;//sx��sy��startx��starty���Թ���ʼλ�ã���Ӧ�����Թ����±꣬ex��ey��endx��endy��endx��endy���Թ��յ�λ�á�
	node now;//��ǰλ��
	now.x = sx;
	now.y = sy;
	now.orientation = 'E';
	maze[sx][sy] = -1;//�߹���

	linkstack s;
	creat(&s); 
		push(&s, now);//��now����Ϣ��ջ
	while (!empty(s)) {
		gettop(s, now);//���ջ��Ԫ�� �浽now��
		if (now.x == ex && now.y == ey)//now��x��yλ�õ����Թ��յ�
			break;//�յ�

		if (!maze[now.x][now.y + 1]) {//�� Ϊ0��ʾ������
			now.orientation = 'E';
			node next = now;
			next.y = now.y + 1;//������һ��
			maze[next.x][next.y] = -1;//�߹�����-1
			push(&s, next);
			continue;
		}
		//����ͬ��
		if (!maze[now.x + 1][now.y]) {//��
			now.orientation = 'S';
			node next = now;
			next.x = now.x + 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x][now.y - 1]) {//��
			now.orientation = 'W';
			node next = now;
			next.y = now.y - 1;
			maze[next.x][next.y] = -1;
			push(&s, next);
			continue;
		}
		if (!maze[now.x - 1][now.y]) {//��
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
	}//��������
	showPath(path);
	paintPath();
	qDebug() << "ִ�����";
	destroyStack(&s);
	destroyStack(&path);
}

void MainWindow::useRecursion(int xis, int yis, int xes, int yes, PathType paths, int maze[8][8])
{
	int k, i, j;
	str = "�Թ���" + QString::number(num) + "��·�����£�";
	if (xis == xes && yis == yes)		//�ҵ�����,���·��
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
	else					//(xis,yis)���ǳ���
	{
		if (maze[xis][yis] == 0)//(xis,yis)����
		{
			for (int m = 0; m < 4; m++)		// ��(xis, yis)��һ������λ��(i, j)
			{
				i = xis + mov[m].x; j = yis + mov[m].y;
				paths.data[paths.length].rx = xis;
				paths.data[paths.length].cy = yis;
				paths.length++;
				maze[xis][yis] = -1;			//�����ظ���·��
				useRecursion(i, j, xes, yes, paths, maze);
				paths.length--;			//����һ��λ��
				maze[xis][yis] = 0;			//�ָ�(xis,yis)Ϊ����
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

