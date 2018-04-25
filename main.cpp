#include <QtWidgets>
#include "settingswindow.h"
#include "gamewindow.h"
#include "settingsmodel.h"

QFont SettingsModel::FONT = QFont("Arial", 30);
int SettingsModel::MOVE_TIME = 1000;
QColor SettingsModel::PLAYER_COLOR = Qt::white;
const QString SettingsModel::Q_STRING_WHITE = QString("White");
const QString SettingsModel::Q_STRING_BLACK = QString("Black");

int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(board);
    QApplication app(argc, argv);
    GameWindow window;
    window.show();
    return app.exec();
}
