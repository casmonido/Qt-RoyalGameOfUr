#include "gameenddialog.h"
#include "ui_gameenddialog.h"

GameEndDialog::GameEndDialog(QWidget *parent, const QString &strlabel) :
    QDialog(parent),
    ui(new Ui::GameEndDialog)
{
    ui->setupUi(this);
    ui->label->setText(strlabel);
}

GameEndDialog::~GameEndDialog()
{
    delete ui;
}
