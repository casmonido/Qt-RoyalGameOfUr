#include "settingsmodel.h"


void SettingsModel::setFont(QFont nf) {
    nf.setPointSize(30);
    FONT = nf;
}


void SettingsModel::setMoveTime(int val) {
    MOVE_TIME = val;
}

void SettingsModel::setPlayersColor(QString c) {
    QColor qp = Qt::black, qo = Qt::white;
    if (c == Q_STRING_WHITE)
    {
         qp = Qt::white;
         qo = Qt::black;
    }
    PLAYER_COLOR = qp;
    OPPONENT_COLOR = qo;
}
