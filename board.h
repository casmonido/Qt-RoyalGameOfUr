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
class LastSquare;
class Piece;

class Board: public QGraphicsObject
{
public:
    Board(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    ZeroSquare *getStartingSquare(PieceColors c);
    Square *destinationSquare(Piece *p, unsigned int crossedPathLength, unsigned int pathToCross);
private:
    static const int NUM_SQUARES = 20, PATH_LEN = 16;
    BoardSquare *squares [NUM_SQUARES];
    ZeroSquare *playersZeroGround, *opponentsZeroGround;
    LastSquare *lastSquare;
    Square *playersPath [PATH_LEN];
    Square *opponentsPath [PATH_LEN];
};

#endif // BOARD_H
