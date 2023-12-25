#include "LinklistUI.h" 
#include "ui_LinklistUI.h" 
#include "CNodeEditorScene.h" 
#include <QFile> 
#include <QTextStream> 
#include <QTime> 
#include <qDebug>
#include<vector>
#include<time.h>
#include<math.h>
#include<algorithm>
#include <QMessageBox>
LinklistUI::LinklistUI(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::LinklistUI),
	m_scene(NULL) {
	ui->setupUi(this);
}
void LinklistUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[0]; j++)
	{
		animationDraw(0, j);
	}
}
void LinklistUI::stepBackButton()
{
	if (createflag == 1)
	{
		endplaybuttonflag = 1;
		if (timestamp > 0)
		{
			timestamp--;
			m_scene->clearScreen();//清屏
			for (int j = 0; j <= frametime[timestamp]; j++)
			{
				animationDraw(timestamp, j);
			}
		}
	}
	else if (deleteflag == 1)
	{
		onlytotaltime++;
		endplaybuttonflag = 1;
		if (timestamp > 0)
		{
			timestamp--;
			m_scene->clearScreen();//清屏
			for (int j = 0; j <= frametime[timestamp]; j++)
			{
				animationDraw(timestamp, j);
			}
		}
	}
	else if (searchflag == 1)
	{
		endplaybuttonflag = 1;
		if (timestamp > 0)
		{
			timestamp--;
			m_scene->clearScreen();//清屏
			for (int j = 0; j <= frametime[timestamp]; j++)
			{
				animationDraw(timestamp, j);
			}
		}
	}
}
void LinklistUI::playButton()
{
	endplaybuttonflag = 0;
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
		m_quickHelp->head_insert_code(1);
	}
	timestamp = onlytotaltime;
	sleepTime(500);
}
void LinklistUI::suspendButton() {
	endplaybuttonflag = 1;
}
void LinklistUI::stepForwardButton() {

	if (createflag == 1)
	{
		endplaybuttonflag = 1;
		if (timestamp < onlytotaltime)
		{
			timestamp++;
			m_scene->clearScreen();//清屏
			for (int j = 0; j <= frametime[timestamp]; j++)
			{
				animationDraw(timestamp, j);
			}
		}
	}
	else if (deleteflag == 1)
	{
		endplaybuttonflag = 1;
		if (timestamp < onlytotaltime)
		{
			timestamp++;
			m_scene->clearScreen();//清屏
			for (int j = 0; j <= frametime[timestamp]; j++)
			{
				animationDraw(timestamp, j);
			}
		}
	}
	else if (searchflag == 1)
	{
		endplaybuttonflag = 1;
		if (timestamp < onlytotaltime)
		{
			timestamp++;
			m_scene->clearScreen();//清屏
			for (int j = 0; j <= frametime[timestamp]; j++)
			{
				animationDraw(timestamp, j);
			}
		}
	}
}
void LinklistUI::goToEndButton() {
	endplaybuttonflag = 1;
	m_scene->clearScreen();//清屏
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->head_insert_code(insertIdCode[timestamp]);
}
void LinklistUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//获取自定义休眠时间
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);//开启新线程，处理 qt 界面事件
	}
}
void LinklistUI::animationRecord(int totaltime, int frame, int x, int data)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].data = data;
}
void LinklistUI::animationSearchRecord(int totaltime, int frame, int x, int data, int flag, int
	codeid)
{
	animationSearch[totaltime][frame].x = x;
	animationSearch[totaltime][frame].data = data;
	animationSearch[totaltime][frame].flag = flag;
	animationSearch[totaltime][frame].codeid = codeid;
}
void LinklistUI::animationClean()
{
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			animation[i][j].x = 0;
			animation[i][j].data = 0;
		}
	}
}
void LinklistUI::animationPrint(int totaltime, int frametime)
{
	qDebug() << "totaltime" << totaltime;
	qDebug() << "frametime" << frametime;
	int i = totaltime;
	int j = frametime;
	qDebug() << "animation[i].x " << animation[i][j].x;
	qDebug() << " animation[i].data " << animation[i][j].data;
}
void LinklistUI::animationDraw(int totaltime, int frametime)// 画图链表可能修改指针指向
{
	//m_scene->insertnode(animation[totaltime][frametime].x,
	//	animation[totaltime][frametime].data); //链表只需要便利每个结点一次即可
}
void LinklistUI::animationDrawSearch(int totaltime, int frametime, int x)
{
	m_scene->insertfindnode(animation[totaltime][frametime].x,
		animation[totaltime][frametime].data);
}
//......
void LinklistUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void LinklistUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void LinklistUI::onSceneAttached(CEditorScene* scene)
{
}
void LinklistUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}
LinklistUI::~LinklistUI()
{
}
void LinklistUI::on_create_btn_clicked()
{
	//修改
	createflag = 1;
	deleteflag = 0;
	searchflag = 0;
	//m_scene->clearScreen(); 
	for (int i = 1; i <= QLinkList.size(); ++i) //删除所有节点
	{
		m_scene->deletenode(i);
	}
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	if (data == "") {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("输入为空，创建失败！"),
			QMessageBox::Cancel | QMessageBox::Ok);
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		LinklistNode* node = new LinklistNode();
		node->m_StrName = temp.at(i);
		//添加进链表
		QLinkList.append(*node);
	}
	m_scene->set(-300, -400);
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);//unsigned int
		if (!flag)
			return;
		m_scene->insertnode(x);//向屏幕绘制
	}
	for (int j = 0; j < temp.size(); ++j)
	{
		onlytotaltime = j;
		for (int i = 0; i < QLinkList.size(); ++i)
		{
			QString tmp = QLinkList.at(i).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			frametime[i] = i;
			animationRecord(onlytotaltime, frametime[i], i, x);
		}
	}
	m_quickHelp->head_insert_code(1);
	timestamp = 0;
}

void LinklistUI::merge_3(std::vector<int>& arr, int l, int m1, int m2, int r) {
	std::vector<int> a(QLinkList.size());
	for (int i = l; i <= r; i++) a[i] = arr[i];
	int i = l, j = m1+1, k = m2+1, p = l;
	while (i <= m1 && j <= m2 && k <=r) {
		if (a[i] <= a[j] && a[i] <= a[k]) {
			arr[p++] = a[i++];
		}
		else if (a[j] <= a[i] && a[j] <= a[k]) {
			arr[p++] = a[j++];
		}
		else {
			arr[p++] = a[k++];
		}
	}

	while (i <= m1 && j <= m2) {
		if (a[i] <= a[j]) {
			arr[p++] = a[i++];
		}
		else {
			arr[p++] = a[j++];
		}
	}

	while (i <= m1 && k <=r ) {
		if (a[i] <= a[k]) {
			arr[p++] = a[i++];
		}
		else {
			arr[p++] = a[k++];
		}
	}

	while (j <= m2 && k <= r) {
		if (a[j] <= a[k]) {
			arr[p++] = a[j++];
		}
		else {
			arr[p++] = a[k++];
		}
	}

	while (i <= m1) {
		arr[p++] = a[i++];
	}

	while (j <= m2) {
		arr[p++] = a[j++];
	}

	while (k <= r) {
		arr[p++] = a[k++];
	}
}

int log3(int x) {
	if (x <= 2) return 1;
	int num = 1,i=0;
	while (num <= x) num *= 3, i++;
	return i;
}

void LinklistUI::merge_sort_3(std::vector<int>& arr, int l, int r,int needcen,int nowcen) {
	if (nowcen == needcen && l <= r) {
		int kong = 1;  //空格个数
		int Cen = log3(QLinkList.size());  //最大层数
		for (int i = 1; i <= Cen - needcen; i++) kong *= 3;
		if (l == 0) {  //输出头部空格
			int fst = 0;
			if (needcen == Cen) fst = 0;
			else fst = (pow(3, Cen - needcen) - 1) / 2;
			m_scene->set(-300, -(2 * (Cen - needcen) + 1) * 50);
			for (int i = 1; i <= fst; i++) m_scene->insertnode(-666);
		}
		else for (int i = 1; i <= kong; i++) m_scene->insertnode(-666);
		for (int i = l; i <= r; i++) m_scene->insertnode(arr[i]);
		this->sleepTime(700);
	}
	else if (l <= r) {
		int num = r - l + 1;
		if (num % 3 == 0) {
			num /= 3;
			merge_sort_3(arr, l, l + num - 1, needcen, nowcen + 1);
			merge_sort_3(arr, l + num, l + 2 * num - 1, needcen, nowcen + 1);
			merge_sort_3(arr, l + 2 * num, r, needcen, nowcen + 1);
		}
		else if (num % 3 == 1) {
			num /= 3;
			merge_sort_3(arr, l, l + num, needcen, nowcen + 1);
			merge_sort_3(arr, l + num + 1, l + 2 * num, needcen, nowcen + 1);
			merge_sort_3(arr, l + 2 * num + 1, r, needcen, nowcen + 1);
		}
		else {
			num /= 3;
			merge_sort_3(arr, l, l + num, needcen, nowcen + 1);
			merge_sort_3(arr, l + num + 1, l + 2 * num + 1, needcen, nowcen + 1);
			merge_sort_3(arr, l + 2 * num + 2, r, needcen, nowcen + 1);
		}
	}
	return;
}

void swap(int &x, int &y) {
	int t = x; x = y; y = t;
}
void sort1(std::vector<int> &arr ,int l,int r) {
	for (int i = l; i < r; ++i) {
		for (int j = i + 1; j <= r; ++j) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}
void LinklistUI::merge_3_sort(std::vector<int>& arr, int l, int r, int needcen, int nowcen) {
	if (l > r) return;
	int num = r - l + 1, m1, m2;
	if (num % 3 == 0) num /= 3,m1 = l + num - 1, m2 = l + 2 * num - 1;
	else if (num % 3 == 1) num /= 3, m1 = l + num, m2 = l + 2 * num;
	else num /= 3, m1 = l + num, m2 = l + 2 * num + 1;
	if (nowcen == needcen) {
		int Cen = log3(QLinkList.size());  //最大层数
		if (needcen == Cen) {
			if (l == r - 1 && arr[l] > arr[r]) swap(arr[l], arr[r]);
			if (l == r - 2) sort1(arr, l, r);
		}
		else merge_3(arr, l, m1, m2, r);
		int kong = 1;  //空格个数
		for (int i = 1; i <= Cen - needcen; i++) kong *= 3;
		if (l == 0) {  //输出头部空格
			int fst = 0;
			if (needcen == Cen) fst = 0;
			else fst = (pow(3, Cen - needcen) - 1) / 2;
			m_scene->set(-300, (2 * (Cen - needcen) + 1) * 50);
			for (int i = 1; i <= fst; i++) m_scene->insertnode(-666);
		}
		else for (int i = 1; i <= kong; i++) m_scene->insertnode(-666);
		for (int i = l; i <= r; i++) m_scene->insertnode(arr[i]);
		this->sleepTime(700);
	}
	else {
		merge_3_sort(arr, l, m1, needcen, nowcen + 1);
		merge_3_sort(arr, m1 + 1, m2, needcen, nowcen + 1);
		merge_3_sort(arr, m2 + 1, r, needcen, nowcen + 1);
	}
	return;
}

void LinklistUI::on_three_way_merge_sort() {  //主函数
	m_scene->clear();
	std::vector<int> arr;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		arr.push_back(x);
	}
	for (int i = 1; i <= log3(QLinkList.size()); i++) {
		merge_sort_3(arr, 0, QLinkList.size() - 1, i, 1);
	}
	for (int i = log3(QLinkList.size()); i >= 1; i--) {
		merge_3_sort(arr, 0, QLinkList.size() - 1, i, 1);
	}
	this->sleepTime(700);
	m_scene->drawText(7);
}
void LinklistUI::on_clean_btn_clicked() //清除按钮槽函数
{
	m_scene->clear();
	ui->dataEdit->clear();
	for (int i = 1; i <= QLinkList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	QLinkList.clear();
}
