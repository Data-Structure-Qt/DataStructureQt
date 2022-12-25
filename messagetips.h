#ifndef MESSAGETIPS_H
#define MESSAGETIPS_H

#include <QWidget>
#pragma execution_character_set("utf-8")

class QHBoxLayout;
class QLabel;
class MessageTips : public QWidget
{
    Q_OBJECT
public:
    explicit MessageTips(QString showStr="默认显示", QWidget *parent = nullptr);

    double getOpacityValue() const;
    void setOpacityValue(double value);

    int getTextSize() const;
    void setTextSize(int value);

    QColor getTextColor() const;
    void setTextColor(const QColor &value);

    QColor getBackgroundColor() const;
    void setBackgroundColor(const QColor &value);

    QColor getFrameColor() const;
    void setFrameColor(const QColor &value);

    int getFrameSize() const;
    void setFrameSize(int value);

    int getShowTime() const;
    void setShowTime(int value);

    void setCloseTimeSpeed(int closeTime = 100,double closeSpeed = 0.1);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void InitLayout();

    QHBoxLayout *hBoxlayout;

    QLabel *mText;

    QString showStr;

    double opacityValue;

    QFont *font;

    int     textSize;

    QColor  textColor;

    QColor  backgroundColor;

    QColor  frameColor;

    int     frameSize;

    int     showTime;

    int     closeTime;

    double  closeSpeed;

signals:

};

#endif // MESSAGETIPS_H
