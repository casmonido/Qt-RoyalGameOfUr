#include "settingsmodel.h"


void SettingsModel::setFont(QFont nf) {
    nf.setPointSize(30);
    FONT = nf;
}


void SettingsModel::setMoveTime(int val) {
    MOVE_TIME = val;
}

void SettingsModel::setPlayersColor(QString c) {
    QColor qc = Qt::black;
    if (c == Q_STRING_WHITE)
        qc = Qt::white;
    PLAYER_COLOR = qc;
}
