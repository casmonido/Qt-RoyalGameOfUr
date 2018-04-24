#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QtWidgets>
#include <math.h>
#include "game.h"

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene():
        QGraphicsScene(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH)
    {
        game = new Game();
        game->setPos(0*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
        addItem(game);
    }
    ~GraphicsScene() {
        delete game;
    }
private:
    Game *game;
};


class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(GraphicsScene *scene) : QGraphicsView(scene)
    {
        setRenderHint(QPainter::Antialiasing);
        setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        setBackgroundBrush(backgoundColor);
        setWindowTitle("The royal game of Ur");
    }
protected:
    void resizeEvent(QResizeEvent *) override
    {
        this->fitInView(QRectF(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH,
                               16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH), Qt::KeepAspectRatio);
    }
private:
    QColor backgoundColor = QColor(32, 12, 75);
};

#endif // GAMEWINDOW_H
