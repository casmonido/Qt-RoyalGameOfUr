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
const double Piece::R = 0.6;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(0, 0, 2000, 1000); //tyle px

    Game *game = new Game;
    game->setPos(0, 0);
    scene.addItem(game);
    GraphicsView view(&scene);
    view.showMaximized();
    QRectF bounds = scene.itemsBoundingRect();
    view.fitInView( scene.sceneRect(), Qt::KeepAspectRatio );
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(255, 255, 240));
    view.setWindowTitle("The royal game of Ur");
    view.show();
    return app.exec();
}
