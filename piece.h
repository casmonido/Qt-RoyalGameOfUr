#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <math.h>
#include "square.h"
#include "board.h"
#include "enums.h"
#include "game.h"
class Square;
class Game;

class Piece : public QGraphicsObject
{
public:
    static const int R = 50;
    Piece(Game *game = 0, Square *location=0);
    QRectF boundingRect() const override;
    virtual PieceColors getColor() = 0;
protected:
    int crossedPathLength = 0;
    Square *location;
    Game *game;
    void move();
};


class OpponentsPiece : public Piece
{
public:
    OpponentsPiece(Game *game = 0, Square *location=0);
    PieceColors getColor();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
};

class PlayersPiece : public Piece
{
public:
    PlayersPiece(Game *game = 0, Square *location=0);
    PieceColors getColor();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
};

#endif // PIECE_H
