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

Board *Board::instance = 0;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(-1*Square::WIDTH, -2*Square::WIDTH, 10*Square::WIDTH, 8*Square::WIDTH);

    Game *game = new Game;
    game->setPos(0, Square::WIDTH);
    scene.addItem(game);

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(255, 255, 240));
    view.setWindowTitle("The royal game of Ur");
    view.showMaximized();
    return app.exec();
}
