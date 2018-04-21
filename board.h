#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"
#include "piece.h"
#include "enums.h"
class Square;
class ZeroSquare;
class BoardSquare;

class Board: public QGraphicsObject
{
public:
    static Board *getInstance(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    ZeroSquare *getStartingSquare(PieceColors c);
    Square *nextSquare(PieceColors c, int crossedPathLength);
private:
    static Board *instance;
    Board(QGraphicsItem *parent = 0);
    static const int NUM_SQUARES = 20, PATH_LEN = 14;
    QPixmap pixmap;
    BoardSquare *squares [NUM_SQUARES];
    ZeroSquare *playersZeroGround, *opponentsZeroGround;
    BoardSquare *playersPath [PATH_LEN];
    BoardSquare *opponentsPath [PATH_LEN];
};

#endif // BOARD_H
