#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"
#include "piece.h"
#include "enums.h"
#include "board.h"
class Board;

class Game: public QGraphicsObject
{
public:
    static const int NUM_PIECES = 7;
    Game(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    Piece *opponentsPieces [NUM_PIECES];
    Piece *playersPieces [NUM_PIECES];
};

#endif // GAME_H
