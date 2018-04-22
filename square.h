#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <QGraphicsItem>
#include <QPainter>
#include "enums.h"
#include "piece.h"
#include "game.h"
class Piece;
class Game;

class Square: public QGraphicsObject
{
public:
    Square(QGraphicsItem *parent = 0): QGraphicsObject(parent) {}
    virtual QPointF getChildCenterPos(Piece *) const = 0;
    virtual OccupySquareResults tryAndOccupy(Piece *) = 0;
    virtual void leave(Piece *) = 0;
};

class BoardSquare: public Square
{
public:
    static const int WIDTH = 100;
    BoardSquare(QGraphicsItem *parent = 0, QImage image = QImage(":/square1.png"), int x=0, int y=0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QPointF getChildCenterPos(Piece *) const;
    OccupySquareResults tryAndOccupy(Piece *);
    void leave(Piece *);
private:
    int piecesNum = 0;
    PieceColors color = NONE;
    QPixmap pixmap;
};


class ZeroSquare: public Square
{
public:
    ZeroSquare(QGraphicsItem *parent = 0, int x=0, int y=0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    QPointF getChildCenterPos(Piece *) const;
    OccupySquareResults tryAndOccupy(Piece *);
    void leave(Piece *);
private:
    Piece *pieces[7]; //Game::NUM_PIECES
};

class LastSquare: public Square
{
public:
    LastSquare(QGraphicsItem *parent = 0, int x=0, int y=0);
    QPointF getChildCenterPos(Piece *) const;
    OccupySquareResults tryAndOccupy(Piece *);
    void leave(Piece *);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // SQUARE_H
