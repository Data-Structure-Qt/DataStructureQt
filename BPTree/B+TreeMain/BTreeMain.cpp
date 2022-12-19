#include "BTreeMain.h"
#include<qdebug.h>
BTreeMain::BTreeMain(QWidget *parent)
    : QMainWindow(parent)
{
    bPlusTree = new BPTree;
    ui.setupUi(this);

    connect(ui.insertNode, &QPushButton::clicked, this,&BTreeMain::insertList);//��bugʱ��lambda���ʽ�����ˣ���Ϊռ�ô�����ջ�ռ䣩
       
    connect(ui.exitNode, &QPushButton::clicked, this, &QWidget::close);
}

BTreeMain::~BTreeMain()
{}

void BTreeMain::insertList() {
    bPlusTree->insert(ui.data->text().toInt());
    //if (bPlusTree->getroot() != NULL)qDebug() << bPlusTree->getroot()->getKey();
    ui.data->clear();
    update();
}
void BTreeMain::paintEvent(QPaintEvent*)
{
    if (bPlusTree->getroot() == NULL)return;
    
    int i = 0;
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    queue<_Node*>q;//�ڵ�
    q.push(bPlusTree->getroot());// ��Ӹ��ڵ�
    q.front()->p = QPoint(500, 150);// Ϊ���ڵ���������
    painter.drawRect(500, 150, 70, 20);
    int mm = 4;

    while (!q.empty()) {//����B+��
        int size_t = q.size();
        
        while (size_t--) {
            auto t = q.front();
            for (int i = 0; i < t->size + 1; i++) {
                if (!t->leaf) {// ʹ��ʱ�� һ���ص���ÿһ���λ��
                    q.push(t->ptr[i]);
                    if (t->size+1 == 1) {
                        t->ptr[i]->p=(t->p + QPoint(0, 50));
                    }
                    else if (t->size+1 == 2) {
                        if (i == 0)t->ptr[i]->p = (t->p + QPoint(-45 - mm * 58, 50));
                        if (i == 1)t->ptr[i]->p = (t->p + QPoint(45 + mm * 58, 50));
                    }
                    else if (t->size+1 == 3) {
                        if (i == 0)t->ptr[i]->p = (t->p + QPoint(-60 - mm * 70, 50));
                        if (i == 1)t->ptr[i]->p = (t->p + QPoint(0, 50));
                        if (i == 2)t->ptr[i]->p = (t->p + QPoint(60 + mm * 70, 50));
                    }
                    else if (t->size+1 == 4) {
                        if (i == 0)t->ptr[i]->p = (t->p + QPoint(-120 - mm * 20, 50));
                        if (i == 1)t->ptr[i]->p = (t->p + QPoint(-45 - mm * 10, 50));
                        if (i == 2)t->ptr[i]->p = (t->p + QPoint(45 + mm * 10, 50));
                        if (i == 3)t->ptr[i]->p = (t->p + QPoint(120 + mm * 20, 50));
                    }
                    else if (t->size + 1 == 5) {
                        if (i == 0)t->ptr[i]->p = (t->p + QPoint(-200 - mm * 20, 50));
                        if (i == 1)t->ptr[i]->p = (t->p + QPoint(-70 - mm * 20, 50));
                        if (i == 2)t->ptr[i]->p = (t->p + QPoint(0, 50));
                        if (i == 3)t->ptr[i]->p = (t->p + QPoint(70 + mm * 20, 50));
                        if (i == 4)t->ptr[i]->p = (t->p + QPoint(200 + mm * 20, 50));
                    }
                    painter.setRenderHint(QPainter::HighQualityAntialiasing);//���ΪɶЧ�������ԣ�
                    painter.drawLine(t->p + QPoint(35, 20), t->ptr[i]->p + QPoint(35, 0));
                    painter.drawRect(t->ptr[i]->p.x(), t->ptr[i]->p.y(), 70, 20);
                }
                for (int i = 0; i < t->size; i++) {
                    QString a = QString::number(t->key[i]);
                    //QString a = "dd";�����õ�
                    painter.drawText(t->p + QPoint(20 * i, 15), a);
                }
            }
            q.pop();
        }
        mm=1;//�ڶ����Ҫ����Զ��ֹ��������ص�
    }
    
}