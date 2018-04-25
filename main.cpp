#include <QtWidgets>
#include "settingswindow.h"
#include "gamewindow.h"
#include "settingsmodel.h"

int Game::ONE_MOVE_TIME = 1000;
SettingsModel *SettingsModel::model = 0;

int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(board);
    QApplication app(argc, argv);
    GameWindow window;
    window.show();

//    SettingsModel settingsModel;
    return app.exec();
}
