#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsItem>
#include "square.h"
#include "enums.h"
class Square;

class Piece : public QGraphicsObject
{
public:
    static const int R = 50;
    Piece(QGraphicsItem *parent = 0, Square *location=0);

    QRectF boundingRect() const override;
    virtual PieceColors getColor() = 0;
protected:
    int x, y;
    Square *location;
};


class OpponentsPiece : public Piece
{
public:
    OpponentsPiece(QGraphicsItem *parent = 0, Square *location=0);
    PieceColors getColor();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
};

class PlayersPiece : public Piece
{
public:
    PlayersPiece(QGraphicsItem *parent = 0, Square *location=0);
    PieceColors getColor();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
};

#endif // PIECE_H
