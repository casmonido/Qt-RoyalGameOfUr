#include <QtWidgets>
#include <math.h>
#include "game.h"

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
    }

protected:
    void resizeEvent(QResizeEvent *) override
    {
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(-400, -300, 1000, 600);

    Game *game = new Game;
    game->setPos(0, 0);
    scene.addItem(game);
    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(255, 255, 240));
    view.setWindowTitle("The royal game of Ur");
    view.show();
    return app.exec();
}
