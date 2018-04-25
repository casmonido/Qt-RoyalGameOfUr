#ifndef GAMEENDDIALOG_H
#define GAMEENDDIALOG_H

#include <QDialog>

namespace Ui {
class GameEndDialog;
}

class GameEndDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameEndDialog(QWidget *parent = 0, const QString &strlabel = QString(""));
    ~GameEndDialog();

private:
    Ui::GameEndDialog *ui;
};

#endif // GAMEENDDIALOG_H
