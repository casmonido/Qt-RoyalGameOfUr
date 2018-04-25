#include "settingsmodel.h"


void SettingsModel::setFont(QFont nf) {
    if (nf != font)
    {
        font = nf;
        emit fontChanged(font);
    }
}

void SettingsModel::setMoveTime(int val) {
    if (moveTime != val)
    {
        moveTime = val;
        emit moveTimeChanged(moveTime);
    }
    Game::ONE_MOVE_TIME = 0;
}

void SettingsModel::setPlayersColor(QString c) {
    QColor qc;
    if (c == qStringWhite)
        qc = Qt::white;
    else
        qc = Qt::black;
    if (qc != playersColor)
    {
        playersColor = qc;
        emit playersColorChanged(playersColor);
    }
}
