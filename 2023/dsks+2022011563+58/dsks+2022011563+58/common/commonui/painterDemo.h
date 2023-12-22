#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPoint>
#include <QMouseEvent>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QChar>
#include "CNodeEditorScene.h"
#include <QGraphicsPixmapItem>


QT_BEGIN_NAMESPACE
namespace Ui { class painterDemo; }
QT_END_NAMESPACE

class painterDemo : public QWidget
{
    Q_OBJECT
signals:
    void signal_1();
public slots:
    void showMes(); //选择颜色.
    void say_mes(); //关闭画板
    void chg_pen(); //画笔粗细
    void cleanPix(); //创建画布


public:
    painterDemo(QWidget *parent = nullptr);
    ~painterDemo();
    //void mousePressEvent(QMouseEvent *e); //鼠标按下事件
    //void mouseMoveEvent(QMouseEvent *e); //鼠标移动事件
    //void paintEvent(QPaintEvent *e); //绘制事件

    void setScene(CNodeEditorScene* scene);
    void onSceneDetached(CEditorScene* scene);
    void onSceneAttached(CEditorScene* scene);

private:
    Ui::painterDemo*ui;
    QGraphicsPixmapItem *pix;
    QPixmap *myPix;  //定义绘制类的指针
    QPoint startPoint;  //画笔的起始位置
    QColor color;  //画笔颜色
    QFont font;  //画笔粗细
    double pensize; //画笔粗细调整

   // Ui::Widget *ui;
   CNodeEditorScene* m_scene;
};
#endif // WIDGET_H
