
#include <QtWidgets>

#include "board.h"

#include <math.h>

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
    QGraphicsScene scene(-200, -200, 400, 400);

    Board *board = new Board;
    board->setPos(0, -20);
    scene.addItem(board);
    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(230, 200, 167));
    view.setWindowTitle("The royal game of Ur");
     view.show();

    return app.exec();
}
