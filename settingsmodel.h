#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H
#include <QObject>
#include <QColor>
#include <QString>
#include <QFont>
#include "game.h"


class SettingsModel: public QObject
{
    Q_OBJECT
private:
    SettingsModel() {}
    static SettingsModel *model;
public:
    static SettingsModel *getInstance() {
        if (model == 0)
            model = new SettingsModel();
        return model;
    }
    QFont getFont() const {return font;}
    int getMoveTime() const {return moveTime;}
    QColor getPlayersColor() const {return playersColor;}
    void setFont(QFont);
    void setMoveTime(int);
    void setPlayersColor(QString);

signals:
    void fontChanged(QFont);
    void moveTimeChanged(int);
    void playersColorChanged(QColor);
private:
    QFont font = "Arial";
    int moveTime = 1000;
    QColor playersColor = Qt::white;
    const QString qStringWhite = QString("White");

};

#endif // SETTINGSMODEL_H
