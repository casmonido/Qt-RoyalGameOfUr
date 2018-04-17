#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <QGraphicsItem>
#include <QPainter>
#include "enums.h"
#include "piece.h"
class Piece;

class Square : public QGraphicsObject
{
public:
    static const int WIDTH =100;
    Square(QGraphicsItem *parent = 0, QImage image = QImage (":/square1.png"), int x=0, int y=0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual int getX() const;
    virtual int getY() const;
    virtual OccupySquareResults tryAndOccupy(PieceColors c);
    virtual void leave();
protected:
    int X, Y;
    int piecesNum = 0;
    PieceColors color = NONE;
    Square(QGraphicsItem *parent = 0, int x=0, int y=0);
private:
    QPixmap pixmap;
};


class ZeroSquare : public Square
{
public:
    ZeroSquare(QGraphicsItem *parent = 0, int x=0, int y=0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    int getX() const;
    int getY() const;
    OccupySquareResults tryAndOccupy(PieceColors c);
    void leave();
};

#endif // SQUARE_H
