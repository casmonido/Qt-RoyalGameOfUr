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
signals:
    void closeApp();
    void newGame();
private:
    Ui::GameEndDialog *ui;
public slots:
    void closeAndNewGame();
};

#endif // GAMEENDDIALOG_H
