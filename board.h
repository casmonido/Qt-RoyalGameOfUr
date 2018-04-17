#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"
#include "piece.h"

class Board: public QGraphicsObject
{
public:
    Board(QGraphicsItem *parent = 0);
    ~Board();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    Square *getStartingSquare();
private:
    static const int X = -300, Y = -100, XW = 600, YW = 300;
    static const int NUM_SQUARES = 20;
    QPixmap pixmap;
    Square *squares [NUM_SQUARES];
    ZeroSquare *zeroGround;
};

#endif // BOARD_H
