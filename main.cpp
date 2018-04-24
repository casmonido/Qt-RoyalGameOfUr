#include <QtWidgets>
#include "settingswindow.h"
#include "gamewindow.h"


int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(board);
    QApplication app(argc, argv);
    GraphicsScene scene;
    GraphicsView view(&scene);
    view.show();

    SettingsWindow settings;
    settings.show();
    return app.exec();
}
