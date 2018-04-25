#include "settingswindow.h"
#include "ui_settingswindow.h"


SettingsWindow::SettingsWindow(QWidget *parent, SettingsModel *model) :
    QMainWindow(parent)
{
    this->model = model;
    ui = new Ui::SettingsWindow;
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);

}

void SettingsWindow::saveSettings() {
    model->setPlayersColor(ui->comboBox->currentText());
    model->setFont(ui->fontComboBox->currentFont());
    model->setMoveTime(ui->horizontalSlider->value());
    this->close();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}


