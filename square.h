#ifndef SQUARE_H
#define SQUARE_H
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
    int getX() const;
    int getY() const;
    OccupySquareResults tryAndOccupy(Piece *p);
    void leave();
protected:
    int X, Y;
    int piecesNum = 0;
    Square(QGraphicsItem *parent = 0, int x=0, int y=0);
private:
    QPixmap pixmap;
    PieceColors color = NONE;
};


class ZeroSquare : public Square
{
public:
    ZeroSquare(QGraphicsItem *parent = 0, int x=0, int y=0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    int getX() const;
    int getY() const;
};

#endif // SQUARE_H
