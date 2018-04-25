#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include "settingsmodel.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SettingsWindow(QWidget *parent = 0, SettingsModel *model = 0);
    ~SettingsWindow();
public slots:
    void saveSettings();
private:
    Ui::SettingsWindow *ui;
    SettingsModel *model;
};

#endif // SETTINGSWINDOW_H
