#include "messagetips.h"

#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QTimer>
#include <QApplication>

MessageTips::MessageTips(QString showStr,QWidget *parent) : QWidget(parent),
   opacityValue(0.6),
   textSize(10),
   textColor(QColor(0,0,0)),
   backgroundColor(QColor(255,255,102)),
   frameColor(QColor(222,222,222)),
   frameSize(1),
   showTime(1000),
   closeTime(500),
   closeSpeed(0.3),
   hBoxlayout(new QHBoxLayout(this)),
   mText(new QLabel(this))
{
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool|Qt::X11BypassWindowManagerHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    this->showStr = showStr;
    hBoxlayout->addWidget(mText);
    InitLayout();
}

void MessageTips::InitLayout()
{
    this->setWindowOpacity(opacityValue);
    font = new QFont("微软雅黑",textSize,QFont::Bold);
    mText->setFont(*font);
    mText->setText(showStr);
    mText->setAlignment(Qt::AlignCenter);
    QPalette label_pe;
    label_pe.setColor(QPalette::Background, QColor(255, 0, 0));
    mText->setPalette(label_pe);

    QTimer *mtimer = new QTimer(this);
    mtimer->setTimerType(Qt::PreciseTimer);
    connect(mtimer,&QTimer::timeout,this,[=](){
        if(opacityValue<=0){ this->close(); }
        opacityValue = opacityValue-closeSpeed;
        this->setWindowOpacity(opacityValue);
        });


    QTimer *mShowtimer = new QTimer(this);
    mShowtimer->setTimerType(Qt::PreciseTimer);
    connect(mShowtimer,&QTimer::timeout,this,[=](){
        mtimer->start(closeTime);
        });
    mShowtimer->start(showTime);

    QDesktopWidget* desktop = QApplication::desktop();
    this->move((desktop->width() - this->width())/1.5, (desktop->height() - this->height())/1.5);
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

void MessageTips::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(backgroundColor));

    painter.setPen(QPen(frameColor,frameSize));
    QRectF rect(0, 0, this->width(), this->height());
    painter.drawRoundedRect(rect, 15, 15); // round rect
}

void MessageTips::setCloseTimeSpeed(int closeTime, double closeSpeed)
{
    if(closeSpeed>0 && closeSpeed<=1){
       this->closeSpeed = closeSpeed;
    }
    this->closeTime = closeTime;
    InitLayout();
}

int MessageTips::getShowTime() const
{
    return showTime;
}

void MessageTips::setShowTime(int value)
{
    showTime = value;
    InitLayout();
}

int MessageTips::getFrameSize() const
{
    return frameSize;
}

void MessageTips::setFrameSize(int value)
{
    frameSize = value;
}

QColor MessageTips::getFrameColor() const
{
    return frameColor;
}

void MessageTips::setFrameColor(const QColor &value)
{
    frameColor = value;
}

QColor MessageTips::getBackgroundColor() const
{
    return backgroundColor;
}

void MessageTips::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}

QColor MessageTips::getTextColor() const
{
    return textColor;
}

void MessageTips::setTextColor(const QColor &value)
{
    textColor = value;
    InitLayout();
}

int MessageTips::getTextSize() const
{
    return textSize;
}

void MessageTips::setTextSize(int value)
{
    textSize = value;
    InitLayout();
}

double MessageTips::getOpacityValue() const
{
    return opacityValue;
}

void MessageTips::setOpacityValue(double value)
{
    opacityValue = value;
    InitLayout();
}
