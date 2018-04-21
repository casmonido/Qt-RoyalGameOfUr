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
        this->fitInView(QRectF(-8*BoardSquare::WIDTH, -4*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 8*BoardSquare::WIDTH), Qt::KeepAspectRatio);
    }
};

Board *Board::instance = 0;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene(-8*BoardSquare::WIDTH, -4*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 8*BoardSquare::WIDTH);
    Game *game = new Game;
    game->setPos(0*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);

    scene.addItem(game);
    GraphicsView view(&scene);
    //view.fitInView(QRectF(-8*Square::WIDTH, -4*Square::WIDTH, 16*Square::WIDTH, 8*Square::WIDTH), Qt::KeepAspectRatio);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(220, 255, 255));
    view.setWindowTitle("The royal game of Ur");
    //view.showMaximized();
    view.show();
    return app.exec();
}
