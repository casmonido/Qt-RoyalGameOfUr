#include "gameenddialog.h"
#include "ui_gameenddialog.h"

GameEndDialog::GameEndDialog(QWidget *parent, const QString &strlabel) :
    QDialog(parent),
    ui(new Ui::GameEndDialog)
{
    ui->setupUi(this);
    ui->label->setText(strlabel);
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(closeAndNewGame()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SIGNAL(closeApp()));
}

void GameEndDialog::closeAndNewGame() {
    this->close();
    emit newGame();
}

GameEndDialog::~GameEndDialog()
{
    delete ui;
}
