#include "settingswindow.h"
#include "ui_settingswindow.h"


SettingsWindow::SettingsWindow(QWidget *parent, SettingsModel *model,
                               const QFont &font, int time, const QString &color) :
    QMainWindow(parent)
{
    this->model = model;
    ui = new Ui::SettingsWindow;
    ui->setupUi(this);
    ui->fontComboBox->setCurrentFont(font);
    ui->comboBox->setCurrentText(color);
    ui->horizontalSlider->setValue(time);
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


