#pragma once

#include <QDialog>


namespace Ui {
    class CCreateTreeDialog;
}


class CCreateTreeDialog : public QDialog
{
    Q_OBJECT

public:
    CCreateTreeDialog(QWidget *parent = 0);
    ~CCreateTreeDialog();

private:
    Ui::CCreateTreeDialog *ui;
};
