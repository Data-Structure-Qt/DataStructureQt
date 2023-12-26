#include "painterDemo.h"
#include "ui_painterDemo.h"

#include "CNodeEditorScene.h"

void painterDemo::showMes()
{
   //btn1->setEnabled(false);
    color =QColorDialog::getColor(Qt::white,this); //选择画笔颜色
    m_scene->color = color;

}

//处理自定义信号的槽函数
void painterDemo::say_mes()
{
   // speech.say(btn2->text());
    QMessageBox::information(this,"错误","您没有权限！");
    //this->close();
}
//负责改变画笔的粗细
void painterDemo::chg_pen()
{
    QString str=ui->spinBox->text();
    pensize=str.toDouble();
    m_scene->pensize = pensize;
}

painterDemo::painterDemo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::painterDemo)
    , m_scene(NULL)
{
    ui->setupUi(this);
        //设置画板尺寸
    // this->setFixedSize(1024,768);
    //myPix = new QPixmap(this->size()); //将自定义的绘制版大小设置为画板大小
    //myPix->fill(Qt::white);  //默认将自定义绘制版填充为白色
    //pensize = 1;
}

void painterDemo::cleanPix() {
    m_scene->clearScreen();
}

painterDemo::~painterDemo()
{
    delete ui;
}

//void painterDemo::mousePressEvent(QMouseEvent *e) //鼠标按下事件
//{
//    startPoint=e->pos();
//}
//void painterDemo::mouseMoveEvent(QMouseEvent *e) //鼠标移动事件
//{
//    //申请一个画家类
//    QPainter painter(myPix); //依附于自定义的画板
//    QPen pen;
//    //此处需要添加画板自定义颜色
//    //pen.setColor(Qt::green);
//    pen.setColor(color);
//    //此处需要设置画笔粗细
//    //pen.setWidth(10);
//    pen.setWidth(pensize);
//    //pen.setStyle()
//
//    painter.setPen(pen);
//
//    //开始画线
//    painter.drawLine(startPoint,e->pos());
//
//    //将当前点设为新的起点
//    startPoint =e->pos();
//
//    //实时更新
//    update();
//
//
//}
//void painterDemo::paintEvent(QPaintEvent *) //绘制事件
//{
//    //1.请一个画家，依附于this画板
//    QPainter painter(this);
//
//    //2.将自定义的绘制版
//    painter.drawPixmap(0,0,*myPix);
//}

void painterDemo::setScene(CNodeEditorScene* scene)
{
    if (m_scene)
        onSceneDetached(m_scene);
    m_scene = scene;

    setEnabled(m_scene);

    if (m_scene)
        onSceneAttached(m_scene);
}
void painterDemo::onSceneDetached(CEditorScene* scene)
{
    scene->disconnect(this);

}
void painterDemo::onSceneAttached(CEditorScene* scene)
{

}