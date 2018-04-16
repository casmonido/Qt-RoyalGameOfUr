#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsItem>

class Piece : public QGraphicsObject
{
public:
    Piece(QGraphicsItem *parent = 0);

    QRectF boundingRect() const override;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
};

#endif // PIECE_H
