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
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    virtual PieceColors getColor();
private:
    int x, y;
    Square *location;
};

#endif // PIECE_H
