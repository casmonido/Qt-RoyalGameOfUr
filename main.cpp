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
        this->fitInView(QRectF(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH,
                               16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH), Qt::KeepAspectRatio);
    }
};


int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(board);
    QApplication app(argc, argv);
    QGraphicsScene scene(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH);
    Game *game = new Game;
    game->setPos(0*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);

    scene.addItem(game);
    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(32, 12, 75));
    view.setWindowTitle("The royal game of Ur");
    view.show();
    return app.exec();
}
