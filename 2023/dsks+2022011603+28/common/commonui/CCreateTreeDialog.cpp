#include "CCreateTreeDialog.h"
#include "ui_CCreateTreeDialog.h"


CCreateTreeDialog::CCreateTreeDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::CCreateTreeDialog)
{
    ui->setupUi(this);
}


CCreateTreeDialog::~CCreateTreeDialog()
{
}


