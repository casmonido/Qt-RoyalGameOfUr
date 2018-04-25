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
public:
    static QFont FONT;
    static int MOVE_TIME;
    static QColor PLAYER_COLOR;
    static const QString Q_STRING_WHITE;
    static const QString Q_STRING_BLACK;
    SettingsModel() {}
    QFont getFont() const {return FONT;}
    int getMoveTime() const {return MOVE_TIME;}
    QColor getPlayersColor() const {return PLAYER_COLOR;}
    void setFont(QFont);
    void setMoveTime(int);
    void setPlayersColor(QString);
};

#endif // SETTINGSMODEL_H
